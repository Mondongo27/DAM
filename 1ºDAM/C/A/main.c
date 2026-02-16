#include <stdio.h>

int main (){
    int entero;
    float decimal;
    float resultado;
    int datos_leidos;

    do{
        printf("Dame un entero: ");
        datos_leidos=scanf("%d", &entero);
        while(getchar()!='\n');
    }while(datos_leidos!=1);


    printf("Dame un numero con decimales: ");
    scanf("%f", &decimal);
    resultado=entero*decimal;
    printf("%d* %.2f = %.2f",entero,decimal,resultado);

return 0;
}
