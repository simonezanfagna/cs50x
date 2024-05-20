from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# IL MODULO session E' UN DIZIONARIO ( CHIAVE - VALORE) CHE PERMETTE DI GESTIRE/MEMORIZZARE I DATI DELLA SESSIONE

# Configure session
app.config["SESSION_PERMANENT"] = False # QUESTO SAREBBE UN SESSION COOKIE, QUALDO SI CHIUDE IL BROWSER IL CONTENUTO
                                        # DELLA SESSIONE VERRA' ELIMINATO

app.config["SESSION_TYPE"] = "filesystem" # QUESTO GARANTISCE CHE IL CONTENUTO DELLA SESSIONE (AD ESEMPIO IL CARRELLO DI UN ECOMMERCE)
                                          # VENGA ARCHIVIATO NEI FILES DEL SERVER (in questo caso tra le cartelle del progetto inquanto
                                          # ho usato "filesystem", se voglio salvare le sessioni su un server devo usare la path del server)
                                          # E NON NEI COOKIES PER MOTIVI DI PRIVACY
                                          # QUINDI ANCHE SE IL COMPUTER SI SPEGNE O SI RIAVVIA, I FILE DELLA SESSIONE SARANNO ANCORA LI

Session(app) # ATTIVA LA SESSIONE


@app.route("/")
def index():
    return render_template("index.html", name=session.get("name"))


@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("login.html")


@app.route("/logout")
def logout():
    session.clear()
    return redirect("/")
