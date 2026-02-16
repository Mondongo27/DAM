#include <stdio.h>
#include <stdlib.h>

int numero,previo,siguiente;

int main()
{
    do{
        printf("Dame un numero entero: \n");
        scanf(" %d", &numero);
    }while(numero<1);

    previo=numero-1;
    siguiente=numero+1;
    printf("Los numeros anterior y siguiente son: %d y %d",previo, siguiente);

    return 0;
}
