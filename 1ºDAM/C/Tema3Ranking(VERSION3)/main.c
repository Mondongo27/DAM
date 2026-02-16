#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LONG_TIT 99
#define LONG_PLAT 19

#define CAPACIDAD_INICIAL 3
#define INC_CAPACIDAD 2


typedef struct{
    char titulo[LONG_TIT+1];
    char plataforma[LONG_PLAT+1];
    int puntuacion;
    int ventas;
}Juego;


int mostrar_menu();
void introducir_videojuego(Juego*);
void mostrar_ranking(Juego*,int);
void colocar_en_ranking(Juego*,Juego,int);
Juego* asignar(int*);
Juego* reasignar(int*);

const char* MENU_1="\n1) Agregar un videojuego";
const char* MENU_2="\n2) Mostrar el ranking";
const char* MENU_3="\n3) Salir\n";
const char* MENU_ERROR="\nOpción no válida";
const char* DESPEDIDA="\n¡Hasta otra!";
const char* PIDE_TITULO="\nTitulo: ";
const char* PIDE_PLATAFORMA="\nPlataforma: ";
const char* PIDE_PUNTUACION="\nPuntuacion: ";
const char* PIDE_VENTAS="\nUnidades vendidas: ";
const char* INFO_AGREGADO="\n%s para %s, con %d puntos y %d uds.vendidas agregado";
const char* ERROR_CONTENIDO="\nEl ranking está vacio";
const char* LINEA_LISTADO="\n%d. %s / %s -> %d puntos (%duds.)";
const char* ERROR_MEMORIA="\nERROR al intentar reservar memoria";
const char* OK_MEMORIA="\nMemoria reservada para %d videojuegos";

int main(){
    int opcion;
    Juego* ranking=NULL;
    int contador=0;
    int capacidad=0;

    ranking=asignar(&capacidad);


    do{
        opcion=mostrar_menu();
        switch(opcion){
        case 1:
            if(contador>=capacidad){
                ranking=reasignar(&capacidad);
            }
            Juego nuevo;
            introducir_videojuego(&nuevo);
            colocar_en_ranking(ranking,nuevo,contador);
            contador++;
            printf(INFO_AGREGADO,nuevo.titulo,nuevo.plataforma,nuevo.puntuacion,nuevo.ventas);
            break;
        case 2:
            if(contador==0){
                printf(ERROR_CONTENIDO);
            }else{
                mostrar_ranking(ranking,contador);
            }
        }
    }while(opcion!=3);
    printf(DESPEDIDA);
    free(ranking);

    return 0;
}

Juego* reasignar(int* pc){
    Juego* nuevo=realloc(ranking,(*pc+INC_CAPACIDAD)*sizeof(Juego));
    if(nuevo==NULL){
        printf(ERROR_MEMORIA);
        return NULL;
    }
    capacidad+=INC_CAPACIDAD;
    printf(OK_MEMORIA,capacidad);
    ranking=nuevo;
}

Juego* asignar(int* pc){
    Juego* nuevo=malloc(CAPACIDAD_INICIAL*sizeof(Juego));

    if(nuevo==NULL){
        printf(ERROR_MEMORIA);
        exit(-1);
    }
    *pc=CAPACIDAD_INICIAL;
    printf(OK_MEMORIA,*pc);

    return nuevo;
}

void colocar_en_ranking(Juego* lista,Juego nuevo,int n){
    //lista[n]=nuevo;

    //Si es el primer dato -> lo pongo directamente

    //Si es otro posterior:
    //Empezando en la última posición ocupada(contador-1) y avanzando hasta la pos. 0:
    // a) Si nuevo>lista[i] -> copio lista[i] en lista[i+1]
    //      a.1 Si, además, i=0 guardo nuevo en lista[i]
    // b) Si no guardo nuevo en lista[i+1]
    if(n==0){
        lista[0]=nuevo;
        return;
    }

    for(int i=n-1;i>=0;i--){
        if( nuevo.puntuacion>lista[i].puntuacion ||
           (nuevo.puntuacion==lista[i].puntuacion && nuevo.ventas>lista[i].ventas) ){//a)
            strcpy(lista[i+1].titulo,lista[i].titulo);//lista[i+1].titulo=lista[i].titulo; No
            strcpy(lista[i+1].plataforma,lista[i].plataforma);//lista[i+1].plataforma=lista[i].plataforma; No
            lista[i+1].puntuacion=lista[i].puntuacion;
            lista[i+1].ventas=lista[i].ventas;
            if(i==0){
                strcpy(lista[i].titulo,nuevo.titulo);//lista[i].titulo=nuevo.titulo; No
                strcpy(lista[i].plataforma,nuevo.plataforma);//lista[i].plataforma=nuevo.plataforma; No
                lista[i].puntuacion=nuevo.puntuacion;
                lista[i].ventas=nuevo.ventas;
                //break;
            }
        }else{//b)
            lista[i+1]=nuevo;
            break;
        }
    }
}

void mostrar_ranking(Juego lista[],int n){
//    Juego j;
//    for(int i=0;i<n;i++){
//        j=*(lista+i);
//        printf(LINEA_LISTADO,i+1,j.titulo,j.plataforma,j.puntuacion,j.ventas);
//    }
    for(int i=0;i<n;i++){
        printf(LINEA_LISTADO,i+1,(lista+i)->titulo,(lista+i)->plataforma,(lista+i)->puntuacion,(lista+i)->ventas);
    }
}

void introducir_videojuego(Juego* punt){
    //Título
    char formato[15];
    sprintf(formato,"%%%d[^\n]",LONG_TIT);
    printf(PIDE_TITULO);
    scanf(formato,punt->titulo);
    while(getchar()!='\n');
    //Plataforma
    sprintf(formato,"%%%d[^\n]",LONG_PLAT);
    printf(PIDE_PLATAFORMA);
    scanf(formato,punt->plataforma);
    while(getchar()!='\n');
    //Puntuación
    punt->puntuacion=-1;
    while(punt->puntuacion<0 || punt->puntuacion>10){
        printf(PIDE_PUNTUACION);
        scanf("%d",&punt->puntuacion);
        while(getchar()!='\n');
    }
    //Ventas
    punt->ventas=-1;
    while(punt->ventas<0){
        printf(PIDE_VENTAS);
        scanf("%d",&punt->ventas);
        while(getchar()!='\n');
    }
}

int mostrar_menu(){
    int opcion=0;
    do{
        printf(MENU_1);
        printf(MENU_2);
        printf(MENU_3);
        scanf("%d",&opcion);
        while(getchar()!='\n');
        if(opcion<1 || opcion>3){
            printf(MENU_ERROR);
        }else{
            break;
        }
    }while(true);
    return opcion;
}
