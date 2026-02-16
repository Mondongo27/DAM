#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define LONGITUD 100000
#define LIMITE 100
void ordenar_a_lo_bruto(int[]);
void inicializar(int[]);
void mostrar_contenido(int[]);
void ordenar_burbuja(int []);
void ordenar_burbuja_mejorado(int []);

int main(){
    srand(time(NULL));
    clock_t inicio,fin;
    double tiempo;

    int array[LONGITUD];
    inicializar(array);
    //mostrar_contenido(array);
    inicio=clock();
    //ordenar_a_lo_bruto(array);
    //ordenar_burbuja(array);
    ordenar_burbuja_mejorado(array);
    fin=clock();
    tiempo=(double)(fin-inicio)/CLOCKS_PER_SEC;
    printf("\n--------- duracion: %f segundos --------------", tiempo);

    //mostrar_contenido(array);
    return 0;
}

void inicializar(int datos[]){
    for(int i=0;i<LONGITUD;i++){
        datos[i]=rand()%LIMITE;
    }
}

void ordenar_a_lo_bruto(int array[]){
    bool hay_cambios;
    int aux;
    do{
        hay_cambios=false;
        for(int i=0;i<LONGITUD-1;i++){
            if(array[i]>array[i+1]){
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                hay_cambios=true;
            }
        }
    }while(hay_cambios);
}

void mostrar_contenido(int array[]){
    printf("\n");
    for(int i=0;i<LONGITUD;i++){
        printf("%d ",array[i]);
    }
}

void ordenar_burbuja(int d[]){
    int aux;
    for(int ronda=1;ronda<LONGITUD;ronda++){
        for(int i=0;i<LONGITUD-ronda;i++){
            if(d[i]>d[i+1]){
                aux=d[i];
                d[i]=d[i+1];
                d[i+1]=aux;
            }
        }
    }
}

void ordenar_burbuja_mejorado(int d[]){
    bool hay_cambios;
    int aux;
    for(int ronda=1;ronda<LONGITUD;ronda++){
        hay_cambios=false;
        for(int i=0;i<LONGITUD-ronda;i++){
                if(d[i]>d[i+1]){
                aux=d[i];
                d[i]=d[i+1];
                d[i+1]=aux;
                hay_cambios=true;
            }
        }
        if(!hay_cambios)break;
    }
}
