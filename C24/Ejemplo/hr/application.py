from flask import Flask
from datetime import datetime
from pytz import timezone


app = Flask(__name__)


@app.route("/")
def tiempo():
    ahora = datetime.now(timezone('America/Managua'))
    return f"La hora actual es {ahora}."