#include <stdio.h>
#include <stdlib.h>
#define LONGITUD 50

typedef struct{
    char nombre[LONGITUD];
    int nota;
}Estudiante;

int pide_cantidad();
void pide_datos(Estudiante[],int);
void muestra_datos(Estudiante[],int);

const char* PREGUNTA_CANTIDAD="\nCantidad de estudiantes\n>";
const char* PREGUNTA_NOMBRE="\nNombre\n>";
const char* PREGUNTA_NOTA="\nNota\n>";

int main(){
    int cantidad=pide_cantidad();
    Estudiante estudiantes[cantidad];
    pide_datos(estudiantes,cantidad);
    muestra_datos(estudiantes,cantidad);
    return 0;
}


int pide_cantidad(){
    int cantidad=0;
    while(cantidad<1){
        printf(PREGUNTA_CANTIDAD);
        scanf("%d",&cantidad);
        while(getchar()!='\n');
    }
    return cantidad;
}
void pide_datos(Estudiante e[],int cantidad){
    char formato[10];
    int numero;
    sprintf(formato,"%%%ds",LONGITUD-1);
    for(int i=0;i<cantidad;i++){
        printf(PREGUNTA_NOMBRE);
        scanf(formato,e[i].nombre);
        while(getchar()!='\n');
        numero=-1;
        do{
            printf(PREGUNTA_NOTA);
            scanf("%d",&numero);
            while(getchar()!='\n');
        }while(numero<0);
        e[i].nota=numero;
    }
}

void muestra_datos(Estudiante e[],int cantidad){
    for(int i=0;i<cantidad;i++){
        printf("\n%s: %d",e[i].nombre,e[i].nota);
    }
}
