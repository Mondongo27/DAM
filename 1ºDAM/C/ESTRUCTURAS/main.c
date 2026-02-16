#include <stdio.h>
#include <stdlib.h>
#define LONG_NOMBRE 20
#define CANT_NOTAS 6

typedef struct{
    int fila;
    int columna;
}Posicion;

typedef struct{
    char nombre[LONG_NOMBRE];
    int edad;
    float notas[CANT_NOTAS];
    Posicion posicion;
}Alumno;

void mostrar_alumno(Alumno);

int main(){
    Alumno a1={"Antonio", 19, {5,4,3,7,1,6.2}, {2,3}};
    mostrar_alumno(a1);
    return 0;
}

void mostrar_alumno(Alumno x){
    printf("\n%s",x.nombre);
    printf("\n%d\n",x.edad);
    for(int i=0;i<CANT_NOTAS;i++) printf("%.2f\t",x.notas[i]);
    printf("\n(%d,%d)",x.posicion.fila,x.posicion.columna);
}

