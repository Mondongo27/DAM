#include "lvj.h"

#define CAPACIDAD_INICIAL 3
#define INC_CAPACIDAD 2

const char* MENU_1="\n1) Añadir un videojuego";
const char* MENU_2="\n2) Mostrar el ranking";
const char* MENU_3="\n3) Salir\n";
const char* MENU_ERROR="\nOpción no válida";
const char* PIDE_TITULO="\nTítulo: ";
const char* PIDE_PLATAFORMA="\nPlataforma: ";
const char* PIDE_PUNTUACION="\nPuntuación: ";
const char* PIDE_VENTAS="\nUnidades vendidas: ";
const char* LINEA_LISTADO="\n%d. %s / %s -> %d puntos (%duds.)";
const char* ERROR_MEMORIA="\nERROR al intentar reservar memoria";
const char* OK_MEMORIA="\nMemoria reservada para %d videojuegos";

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

Juego* reasignar(int* pc, Juego* r){
    Juego* nuevo=realloc(r,(*pc+INC_CAPACIDAD)*sizeof(Juego));
    if(nuevo==NULL){
        printf(ERROR_MEMORIA);
        return NULL;
    }
    *pc+=INC_CAPACIDAD;
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
        if( nuevo.puntuacion>(lista+i)->puntuacion ||
           (nuevo.puntuacion==(lista+i)->puntuacion && nuevo.ventas>(lista+i)->ventas) ){//a)
            strcpy((lista+i+1)->titulo,(lista+i)->titulo);
            strcpy((lista+i+1)->plataforma,(lista+i)->plataforma);
            (lista+i+1)->puntuacion=(lista+i)->puntuacion;
            (lista+i+1)->ventas=(lista+i)->ventas;
            if(i==0){
                strcpy((lista+i)->titulo,nuevo.titulo);
                strcpy((lista+i)->plataforma,nuevo.plataforma);
                (lista+i)->puntuacion=nuevo.puntuacion;
                (lista+i)->ventas=nuevo.ventas;
                //break;
            }
        }else{//b)
            lista[i+1]=nuevo;
            break;
        }
    }
}

void mostrar_ranking(Juego* lista,int n){
//    Juego j;
//    for(int i=0;i<n;i++){
//        j=*(lista+i);//j=lista[i];
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



