#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "binary_tree.h"

/**
 *  Descripción: Programa de muestra el uso
 *  e implementación de Hash Table.
 *
 *  Autor: Luisángel Martín Marcia Palma alias
 *  Fecha: Domingo 15 de Marzo de 2020.
 *
 **/

// En esta función se puede apreciar el momento de creación
// de un nuevo nodo estableciendose como un nodo interno
// en sí mismo y definiendo por ende sus nodos externos.
nodo* nuevoNodo(int elemento)
{
    nodo* temp = (struct nodo*) malloc(sizeof(nodo));
    temp->dato = elemento;
    temp->izquierdo = temp->derecho = NULL;
    return temp;
}

// Esta función permite ver los elementos del
// ABB a través de su elemento medio antes
// de las ramificaciones izquierda y derecha
void imprimirEntre(nodo* raiz)
{
    if(raiz != NULL)
    {
        imprimirEntre(raiz->izquierdo);
        printf("%d \n", raiz->dato);
        imprimirEntre(raiz->derecho);
    }
}

// Método de Búsqueda Binaria implementado en Arbol de Búsqueda Binaria
bool buscar(int n, nodo* raiz)
{
    if(raiz == NULL)
        return false;
    else if(n < raiz->dato)
        return buscar(n, raiz->izquierdo);
    else if(n > raiz->dato)
        return buscar(n, raiz->derecho);
    else
        return true;
}

nodo* insertar(nodo* raiz, int elemento)
{
    // Si el árbol está vacío, retornará a un nuevo nodo
    if(raiz == NULL)
        return nuevoNodo(elemento);

    //De lo contrario, recurrirá a irse abajo del árbol
    if(elemento < raiz->dato)
        raiz->izquierdo = insertar(raiz->izquierdo, elemento);
    else if(elemento > raiz->dato)
        raiz->derecho = insertar(raiz->derecho, elemento);

    // retornará el puntero de nodo sin cambios
    return raiz;
}

// Dado un ABB que no está vacío, retornará aquel nodo
// con el dato de menor valor encontrado en el arbol.
// Observa que todo el arbol no necesita ser buscado.
nodo* minValorNodo(nodo* raiz)
{
    nodo* actual = raiz;

    // hará un ciclo que recorrerá
    // mayormente las hojas de más a la izquierda
    while(actual && actual->izquierdo != NULL)
        actual = actual->izquierdo;

    return actual;
}

nodo* borrarNodo(nodo* raiz, int elemento)
{
    // caso base
    if(raiz == NULL)
        return raiz;

    // Si el dato a ser eliminado es más pequeño
    // que el dato de la raíz, entonces se ubicará
    // en el lado izquierdo del sub arbol. Lo mismo si
    // fuese para el caso de la derecha
    if(elemento < raiz->dato)
        raiz->izquierdo = borrarNodo(raiz->izquierdo, elemento);
    else if(elemento > raiz->dato)
        raiz->derecho = borrarNodo(raiz->derecho, elemento);
    // si el elemento a borrar es el mismo de la raíz, entonces
    // este será el nodo a borrar
    else
    {
        // nodo con solamente un hijo o ninguno
        if(raiz->izquierdo == NULL)
        {
            nodo* temp = raiz->derecho;
            free(raiz);
            return temp;
        }
        else if(raiz->derecho == NULL)
        {
            nodo* temp = raiz->izquierdo;
            free(raiz);
            return temp;
        }

        // nodo con dos hijos: Según entre el orden de sucesor
        // (el más pequeño en la subraíz derecha)
        nodo* temp = minValorNodo(raiz->derecho);

        // Copia entre el contenido segun el órden al que
        // irá el sucesor de este nodo
        raiz->dato = temp->dato;

        // Borrará al sucesor entre orden
        raiz->derecho = borrarNodo(raiz->derecho, temp->dato);
    }

    return raiz;
}

int main(void)
{
    nodo* raiz = NULL;

    /*
            8
        /       \
       3        10
      / \      /  \
      1  6         14
        / \        /
       4   7      13
    */
    raiz = insertar(raiz, 8);
    insertar(raiz, 3);
    insertar(raiz, 10);
    insertar(raiz, 1);
    insertar(raiz, 6);
    insertar(raiz, 14);
    insertar(raiz, 4);
    insertar(raiz, 7);
    insertar(raiz, 13);

    // Imprimirá entre órden transversal del ABB
    printf("Impresión entreorden: \n");
    imprimirEntre(raiz);
    printf("\n\n");

    if(buscar(7, raiz))
    {
        printf("Elemento ha sido encontrado con éxito en el Árbol Binario\n");
    }
    else
    {
        printf("Elemento no ha sido encontrado con éxito en el Árbol Binario\n");
    }

    borrarNodo(raiz, 7);

    printf("Nueva Impresión entreorden: \n");
    imprimirEntre(raiz);
    printf("\n\n");

    if(buscar(7, raiz))
    {
        printf("Elemento ha sido encontrado con éxito en el Árbol Binario\n");
    }
    else
    {
        printf("Elemento no ha sido encontrado con éxito en el Árbol Binario\n");
    }

    return 0;
}