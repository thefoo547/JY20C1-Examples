from flask import Flask, render_template ##Importar el framework


app=Flask(__name__)##Declarar que es una aplicacion


@app.route("/")##si route es vacio la funcion es la que se ejecuta
def main():
    return render_template("index.html")
    ##return "Hola"##Lo que se muestra

########################################
@app.route("/<string:nombre>")
def hello(nombre):
    return render_template("index.html",name=nombre)

########################################
@app.route("/hola")
def hola_todos():
    return render_template("hola.html")
