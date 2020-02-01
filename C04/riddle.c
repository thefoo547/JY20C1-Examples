#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cs50.h>

int main(void)
{
    // leer limite para el numero aleatorio
    int lim = get_int("Elige un numero entre 0 y: ");

    // generar numero aleatorio
    srand(time(NULL));

    // en esta variable se almacena el numero aleatorio, limitado desde 0 hasta lim
    int rnum = rand() % (lim+1);

    // en esta variable se almacenará la respuesta
    int ans = 0;

    do{
        // se lee la respuesta del usuario
        ans = get_int("Adivina el numero: ");
    // si no se acertó, se repite
    }while(ans!=rnum);

    printf("Al fin lo adivinaste!\n");

    return 0;
}