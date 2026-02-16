#include <stdio.h>
#include <stdlib.h>
int suma_con_anteriores(int);

int main()
{
    int numero;
    int suma=0;
    printf("Dame un numero\n>");
    scanf("%d",&numero);
    suma=suma_con_anteriores(numero);
    for(int i=0;i<=numero;i++) suma+=i;
    printf("\nLa suma de todos los numeros hasta el %d da %d",numero,suma);
    return 0;
}

int suma_con_anteriores(int n){
    int resultado;
    if(n==0){
        resultado=0;
    }else{
        resultado=n+suma_con_anteriores(n-1);
    }
    return resultado;
}
