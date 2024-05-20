import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        checkResult = checkData(request.form.get("name"), request.form.get("month"), request.form.get("day"))

        if checkResult["error"]:
            return redirect("/")
        else:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?);", checkResult["data"]["name"], checkResult["data"]["month"], checkResult["data"]["day"])
            return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", birthdays=birthdays)


@app.route("/update", methods=["POST"])
def update():
    id = request.form.get("id")
    if not id:
        return redirect("/")

    try:
        id = int(id)
    except ValueError:
        return redirect("/")

    checkResult = checkData(request.form.get("name"), request.form.get("month"), request.form.get("day"))

    if checkResult["error"]:
            return redirect("/")
    else:
        check_ID = db.execute("SELECT * FROM birthdays WHERE id = (?)", id)

        if check_ID:
            try:
                db.execute("UPDATE birthdays SET name = (?), month = (?), day = (?) WHERE id = (?)", checkResult["data"]["name"], checkResult["data"]["month"], checkResult["data"]["day"], id)
            except Exception:
                return redirect("/")
        else:
            return redirect("/")

    return redirect("/")

@app.route("/delete", methods=["POST"])
def delete():
    id = request.form.get("id")
    if not id:
        return redirect("/")

    try:
        id = int(id)
    except ValueError:
        return redirect("/")

    check_ID = db.execute("SELECT * FROM birthdays WHERE id = (?)", id)

    if check_ID:
        try:
            db.execute("DELETE FROM birthdays WHERE id = (?)", id)
        except Exception:
            return redirect("/")

    return redirect("/")

# check incoming data

def checkData(name, month, day):
    result = {"error": False, "data": {}, "messages": []}

    # check name
    if not name:
        result["error"] = True
        result["messages"].append("Add Name")
    # check month
    try:
        month = int(month)
        if month < 1 or month > 12:
            result["error"] = True
            result["messages"].append("The month must be between 1 and 12")
    except ValueError:
        result["error"] = True
        result["messages"].append("The month must be a number")
    #check day
    try:
        day = int(day)
        if day < 1 or day > 31:
            result["error"] = True
            result["messages"].append("The day must be between 1 and 31")
    except ValueError:
        result["error"] = True
        result["messages"].append("The day must be a number")

    if not result["error"]:
        result["data"] = {"name": name, "month": month, "day": day}

    return result
