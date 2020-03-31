
/**
 *  Descripción: Librería Binary Tree para almacenar las
 *  declaraciones de la estructura
 *
 *  Autor: Luisángel Martín Marcia Palma alias
 *  Fecha: Sábado 14 de Marzo de 2020.
 *
 **/


// Se declara la estructura
// con su sobrenombre nodo para la estructura
// haciendo más sencillo su uso
typedef struct nodo {
    int dato;
    struct nodo *izquierdo;
    struct nodo *derecho;
}
nodo;
