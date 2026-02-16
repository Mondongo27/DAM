#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero=0;
    int contador=0;
    int original;

    while(numero<=0){
       printf("Dame un numero entero positivo: ");
       scanf("%d",&numero);
       while(getchar()!='\n');
    }

    original=numero;
    do{
        numero=numero/10;
        contador++;
    }while(numero>0);ç

    printf("El numero tiene %d cifras",contador);


    return 0;
}
