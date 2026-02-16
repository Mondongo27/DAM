#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void espera(double);

int main(){

    float numero;
    printf("Dame un entero positivo:\n");
    scanf("%f",&numero);

    for (int i=numero;i>=0;i--){
        printf(" %d ",i);
        espera(1.0);
    }
    return 0;
}

void espera(double rato){
    clock_t inicio,ahora;
    double transcurrido;
    inicio=clock();
    do{
        ahora=clock();
        transcurrido=(double)(ahora-inicio)/CLOCKS_PER_SEC;
        if(transcurrido>=rato) break;
    }while(true);
}
