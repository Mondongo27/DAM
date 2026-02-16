#include <stdio.h>
#include <stdlib.h>

void mi_funcion(int);
void otra_funcion(int []);

int main()
{
    int x=4;
    int numeros[5]={1,2,3,4,5};

    printf("\nANTES   x=%d", x);
    mi_funcion(x);
    printf("\nDESPUES x=%d", x);

    printf("\n---------------------------------------------------");

    printf("\nANTES numeros: ");
    for(int i=0;i<5;i++) printf(" %d",numeros[i]);
    otra_funcion(numeros);
    printf("\nDESPUES numeros: ");
    for(int i=0;i<5;i++) printf(" %d",numeros[i]);

    return 0;
}

void otra_funcion(int numeros[]){
    for(int i=0;i<5;i++) numeros [i]=i*2;
    printf("\nDURANTE numeros:");
    for(int i=0;i<5;i++) printf(" %d",numeros[i]);
}

void mi_funcion(int x){
    x++;
    printf("\nDURANTE x=%d", x);
}
