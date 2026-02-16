#include <stdio.h>
#include <time.h>
#include "listaint.h"

void muestra_info();

ListaInt lista;

int main(){
    clock_t start_t,end_t;
    double total_t;
    int volume=10000;

    if(!inicia(&lista)){
        printf("\nNo se ha podido iniciar la lista");
        return -1;
    }
//    muestra_info();
//
//    for(int i=1;i<=13;i++){
//        if(!aniadir(&lista,i)) printf("ERROR.");
//    }
//    muestra_info();
//
//
//    sustituir(&lista,88,3);
//    sustituir(&lista,88,-1);
//    sustituir(&lista,88,13);
//    muestra_info();
//
//    eliminar(&lista,2);
//    eliminar(&lista,-1);
//    eliminar(&lista,8);
//    eliminar(&lista,11);
//    muestra_info();

    printf("\n\n--------------Midiendo tiempos--------------");
    start_t=clock();
    for(int i=1;i<=1000;i++) aniadir(&lista,1);
    end_t=clock();
    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("\ntiempo invertido en aniadir %d elementos: %f",volume,total_t);
    printf("\n\n");

    inicia(&lista);
    start_t=clock();
    for(int i=1;i<=1000;i++) insertar(&lista,1,0);
    end_t=clock();
    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("\ntiempo invertido en aniadir %d elementos: %f",volume,total_t);
    printf("\n\n");

    return 0;
}

void muestra_info(){
    printf("\n%d de %d[",lista.cantidad,lista.capacidad);
    for(int i=0;i<lista.cantidad-1;i++) printf("%d, ",lista.datos[i]);
    if(lista.cantidad>0) printf("%d",lista.datos[lista.cantidad-1]);
    printf("]\n");
}
