#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hash_table.h"

/**
 *  Descripción: Programa de muestra para el uso
 *  e implementación de Hash Table.
 *
 *  Autor: Luisángel Martín Marcia Palma alias
 *  Fecha: Sábado 14 de Marzo de 2020.
 *
 **/

// Defino las instancias de estructuras Hash
// para poder manipular valores.

DataItem* hashArray[SIZE];
DataItem* itemCarnada;
DataItem* item;

DataItem* buscar(char* llave)
{
    // Obtenemos el valor Hash de la función Hash
    int hashIndex = hash_function(llave);

    // Se mueve a través del arreglo hasta
    // que llegue a un vacío
    while (hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->palabra == llave)
            return hashArray[hashIndex];

        // se dirige a la siguiente celda
        hashIndex++;

        // se envuelve alrededor de la tabla
        hashIndex %= SIZE;

    }

    return NULL;
}

void insert(int llave, char* palabra)
{
    item = (DataItem*) malloc(sizeof(DataItem));
    item->palabra = palabra;
    item->llave_hash = llave;

    // obtenemos el hash
    int hashIndex = hash_function(palabra);

    // movemos en el arreglo hasta un vacío o celda eliminada
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->llave_hash != -1)
    {
        // se dirige a la siguiente celda
        hashIndex++;

        // aborda a través de la tabla
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

DataItem* delete(DataItem* itemAEliminar)
{
    char* llave = itemAEliminar->palabra;
    int llave_index = itemAEliminar->llave_hash;

    // tomamos el hash
    int hashIndex = hash_function(llave);

    // nos desplazamos en el arreglo hasta llegar a un vacío
    while(hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->llave_hash == llave_index)
        {
            DataItem* temp = hashArray[hashIndex];

            // asignamos un item carnada a la posición eliminada
            hashArray[hashIndex] = itemCarnada;
            return temp;
        }

        // vamos a la siguiente celda
        hashIndex++;

        // le damos vuelta a la tabla
        hashIndex %= SIZE;
    }

    return NULL;
}

void mostrar()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(hashArray[i] != NULL)
            printf(" (0%d, %s)\n", hashArray[i]->llave_hash, hashArray[i]->palabra);
        else
            printf(" ~~~ \n");
    }

    printf("\n");
}

int main(void)
{
    itemCarnada = (DataItem*) malloc(sizeof(DataItem));
    itemCarnada->palabra = "";
    itemCarnada->llave_hash = -1;

    insert(0, "apple");
    insert(1, "banana");
    insert(2, "cat");

    // Vista de todos los elementos dentro de la Hash Table
    printf("Vista de todos los elementos\n");
    mostrar();

    // Busqueda del elemento antes de eliminarse
    item = buscar("cat");

    printf("Búsqueda del elemento antes de eliminarse\n");
    if(item != NULL)
    {
        printf("Elemento encontrado: %s\n", item->palabra);
    }
    else
    {
        printf("¡Elemento no encontrado!\n");
    }

    delete(item);

    // Busqueda del elemento después de eliminarse
    item = buscar("cat");

    printf("Búsqueda del elemento después de eliminarse\n");
    if(item != NULL)
    {
        printf("Elemento encontrado: %s\n", item->palabra);
    }
    else
    {
        printf("¡Elemento no encontrado!\n");
    }

    insert(0, "ant");

    return 0;
}