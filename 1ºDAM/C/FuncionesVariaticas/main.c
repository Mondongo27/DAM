#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
int suma(int,...);
int acumulacion(char,...);

int main()
{
    int suma1,suma2;
    suma1=acumulacion('s',6,89,20,0);
    //int suma1=suma(3,6,89,20);    estrategia 1
    printf("\n%d",suma1);
    suma2=acumulacion(' ',6,89,20,5,23,0);
    //int suma2=suma(5,6,89,20,5,23);   estrategia 1
    printf("\n%d",suma2);
    return 0;
}

int suma(int cantidad,...) //estrategia 1
{
    int valor;
    int suma=0;
    va_list lista;
    va_start(lista,cantidad);
    for(int i=1;i<=cantidad;i++)
    {
        valor=va_arg(lista,int);
        suma+=valor;
    }
    va_end(lista);
    return suma;
}


int acumulacion(char x,...) //estrategia 2
{
    int acumulado=0;
    int valor;
    va_list lista;
    va_start(lista,x);
    do
    {
        valor=va_arg(lista,int);
        acumulado+=valor;
    }while(valor!=0);
    va_end(lista);
    return acumulado;
}
