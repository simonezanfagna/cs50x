import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user = session["user_id"]
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user)
    ownStocks = db.execute(
        "SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0", user)
    current_total = cash[0]["cash"]

    if len(ownStocks) > 0:
        for stock in ownStocks:
            check_stock = lookup(stock["symbol"])
            stock["current_price"] = check_stock["price"]
            stock["total_current_value"] = round(check_stock["price"] * stock["total_shares"], 2)
            current_total = round(current_total + stock["total_current_value"], 2)

        return render_template("index.html", ownStocks=ownStocks, cash=round(cash[0]["cash"], 2), total=current_total)
    else:
        return render_template("index.html", ownStocks=False, cash=round(cash[0]["cash"], 2), total=current_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("missing symbol", 400)

        elif not request.form.get("shares"):
            return apology("missing shares", 400)

        quote = lookup(request.form.get("symbol"))

        if not quote:
            return apology("invalid symbol", 400)

        user = session["user_id"]

        shares = request.form.get("shares")

        try:
            shares = int(shares)
        except (ValueError, TypeError):
            return apology("invalid value", 400)

        if shares < 1:
            return apology("invalid value", 400)

        cash = db.execute("SELECT cash FROM users WHERE id = ?", user)

        total = shares * quote["price"]

        balance = cash[0]["cash"] - total

        if balance < 0:
            return apology("can't afford", 400)
        else:
            db.execute("INSERT INTO transactions (user_id, symbol, shares, price, total_cost) VALUES (?, ?, ?, ?, ?)",
                       user, quote["symbol"], shares, quote["price"], total)
            # update user balance
            db.execute("UPDATE users SET cash = ? WHERE id = ?", balance, user)

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user = session["user_id"]
    transactions = db.execute(
        "SELECT symbol, shares, price, transacted FROM transactions WHERE user_id = ?", user)

    if len(transactions) > 0:
        return render_template("history.html", transactions=transactions)
    else:
        return render_template("history.html", transactions=False)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("missing symbol", 400)
        else:
            quote = lookup(request.form.get("symbol"))
            if not quote:
                return apology("invalid symbol", 400)
            else:
                return render_template("quoted.html", quote=quote)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":

        if not request.form.get("username"):
            return apology("must provide username", 400)

        elif not request.form.get("password"):
            return apology("must provide password", 400)

        elif not request.form.get("confirmation"):
            return apology("must provide confirmation password", 400)

        elif not (request.form.get("password") == request.form.get("confirmation")):
            return apology("password and confirmation password are different", 400)

        user_DB = db.execute("SELECT username FROM users WHERE username = ?",
                             request.form.get("username"))

        if user_DB and user_DB[0]["username"] == request.form.get("username"):
            return apology("already registered", 400)

        username = request.form.get("username")
        password_hash = generate_password_hash(
            request.form.get("password"), method='scrypt', salt_length=16)

        db.execute("INSERT INTO users (username, hash) VALUES (?, ?);", username, password_hash)

        return redirect("/login")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user = session["user_id"]
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user)
    ownStocks = db.execute(
        "SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0", user)

    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("missing symbol", 400)

        elif not request.form.get("shares"):
            return apology("missing shares", 400)

        quote = lookup(request.form.get("symbol"))

        if not quote:
            return apology("invalid symbol", 400)

        check_symbol_owned = any(stock['symbol'] == request.form.get("symbol")
                                 for stock in ownStocks)

        if not check_symbol_owned:
            return apology("symbol not owned", 400)

        shares = request.form.get("shares")

        try:
            shares = int(shares)
        except (ValueError, TypeError):
            return apology("invalid value", 400)

        selected_stocks = db.execute(
            "SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? AND symbol = ? GROUP BY symbol HAVING total_shares > 0", user, request.form.get("symbol"))

        if int(selected_stocks[0]['total_shares']) < shares or shares <= 0:
            return apology("too many shares", 400)

        sell_total = shares * quote["price"]

        balance = cash[0]["cash"] + sell_total

        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, total_cost) VALUES (?, ?, -?, ?, -?)",
                   user, quote["symbol"], shares, quote["price"], sell_total)
        # update user balance
        db.execute("UPDATE users SET cash = ? WHERE id = ?", balance, user)

        return redirect("/")

    else:
        return render_template("sell.html", ownStocks=ownStocks)


@app.route("/addCash", methods=["GET", "POST"])
@login_required
def addCash():
    """Add Cash."""
    user = session["user_id"]

    if request.method == "POST":

        cash = request.form.get("cash").replace(',', '.')
        print(cash)
        try:
            cash = float(cash)
        except (ValueError, TypeError):
            return apology("invalid value", 400)

        if cash < 1:
            return apology("add more cash", 400)

        current_cash = db.execute("SELECT cash FROM users WHERE id = ?", user)

        cash = cash + current_cash[0]["cash"]

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user)

        return redirect("/")

    else:
        return render_template("addCash.html")
