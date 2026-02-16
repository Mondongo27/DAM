#include <stdio.h>
#include <stdlib.h>

int main()
{

    char respuesta;
    int numero1;
    int numero2;

    printf("Que quiere hacer?[+,-,*,/]: \n");
    scanf("%c", &respuesta);
    printf("Numero1: ");
    scanf("%d", &numero1);
    printf("Numero2: ");
    scanf("%d", &numero2);

    switch(respuesta){
        case('+'):
            printf("%d", numero1+numero2);
        break;
        case('-'):
            printf("%d", numero1-numero2);
        break;
        case('*'):
            printf("%d", numero1*numero2);
        break;
        case('/'):
            printf("%d", numero1/numero2);
        break;
        default:
            printf("No es valido");
    }


    return 0;
}
