#include <ctype.h>
#include <conio.h>

#define SIZE 7

/**
 *  Descripción: Librería Hash Table para almacenar las
 *  declaraciones de la estructura y hash_function
 *
 *  Autor: Luisángel Martín Marcia Palma alias
 *  Fecha: Sábado 14 de Marzo de 2020.
 * 
 **/


typedef struct
{
   char* palabra;
   int llave_hash;
}DataItem;

int hash_function(char* llave)
{
    int llave_hash = toupper(llave[0]) - 'A';
    return llave_hash % SIZE;
}
