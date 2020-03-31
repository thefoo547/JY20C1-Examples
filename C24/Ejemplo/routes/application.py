from flask import Flask

app = Flask(__name__)

@app.route("/")
def index():
    return "¡Te encuentras en página principal!"

@app.route("/sample")
def ejemplo():
    return "¡Te encuentras en página ejemplo!"

@app.route("/hola")
def hola():
    return "Hola mundo"