#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numero;

    printf("Introduce un numero: \n");
    scanf("%d",&numero);
    (numero%2==1)? printf("El numero es impar") : printf("El numero es par");

    return 0;
}
