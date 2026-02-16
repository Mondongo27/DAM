#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 100
#define LONGT 99
#define LONGP 19

typedef struct{
    char titulo[LONGT+1];
    char plataforma[LONGP+1];
    int puntuacion;
    int ventas;
}videojuego;

int menu();
videojuego agregar_videojuego();
void mostrar_rank(videojuego[],int);
void ordenar(videojuego[],videojuego,int);

const char* MENU="\n     --MENU--\n1)Agregar un videjuego\n2)Mostrar Ranking\n3)Salir\n>";
const char* PEDIR_TITULO="Titulo del videojuego:\n";
const char* PEDIR_PLAT="\nPlataformas:\n";
const char* PEDIR_PUNT="\nPuntuacion:\n";
const char* PEDIR_VENT="\nVentas:\n";
const char* JUEGO_AGREGADO="\nHas agregado-> Titulo: %s, Plataforma: %s, Puntuacion: %d, Ventas: %d";
const char* ADIOS="\nAdios";
const char* ERROR_CAPACIDAD="\nNo se pueden agregar mas videojuegos, lista llena.";
const char* ERROR_CONTENIDO="\nLa lista de videojuegos esta vacia. ";
const char* LINEA_LISTADO="\n%d. %s / %s / %d puntos / (%duds.) ";

int main(){
    videojuego lista[CANTIDAD];
    int opcion;
    int contador=0;
    do{
        opcion=menu();
        switch(opcion){
        case 1:
            if(contador>=CANTIDAD){
                printf(ERROR_CAPACIDAD);
            }else{
                videojuego nuevo=agregar_videojuego();
                ordenar(lista,nuevo,contador);
                contador++;
            }
            break;
        case 2:
            mostrar_rank(lista,contador);
        }
    }while(opcion!=3);
    printf(ADIOS);
    return 0;
}

int menu(){
    int opcion;
    do{
        printf(MENU);
        scanf("%d",&opcion);
        while(getchar()!='\n');
    }while(opcion<1||opcion>3);
    return opcion;
}

videojuego agregar_videojuego(){
    videojuego v;
    char formato[10];
    //Titulo
    printf(PEDIR_TITULO);
    sprintf(formato,"%%%d[^\n]",LONGT);
    scanf(formato,v.titulo);
    while(getchar()!='\n');
    //Plataforma
    printf(PEDIR_PLAT);
    sprintf(formato,"%%%d[^\n]",LONGP);
    scanf(formato,v.plataforma);
    while(getchar()!='\n');
    //Puntuacion
    v.puntuacion=-1;
    while(v.puntuacion<0||v.puntuacion>10){
        printf(PEDIR_PUNT);
        scanf("%d",&v.puntuacion);
        while(getchar()!='\n');
    }
    //Ventas
    v.ventas=-1;
    while(v.ventas<0){
        printf(PEDIR_VENT);
        scanf("%d",&v.ventas);
        while(getchar()!='\n');
    }

    printf(JUEGO_AGREGADO,v.titulo,v.plataforma,v.puntuacion,v.ventas);

    return v;
}

void mostrar_rank(videojuego lista[],int n){
    for(int i=0;i<n;i++){
        printf(LINEA_LISTADO,i+1,lista[i].titulo,lista[i].plataforma,lista[i].puntuacion,lista[i].ventas);
    }
    printf("\n" );
}

void ordenar(videojuego lista[],videojuego nuevo,int n){
    //lista[n]=nuevo;

    //Si es el primer dato lo pongo directamente

    //Si es otro posterior:
    //Empezando en la última posición ocupada(n-1) y avanzando hasta la pos. 0:
    // a) Si nuevo>lista[i] -> copio lista[i] en lista[i+1]
    //         a.1 Si llego a i=0 guardo nuevo en lista[0]
    // b) Si no guardo nuevo en lista[i+1]
    if(n==0){
        lista[0]=nuevo;
        return;
    }
    for(int i=n-1;i>=0;i--){
        if(nuevo.puntuacion>lista[i].puntuacion||
           (nuevo.puntuacion==lista[i].puntuacion && nuevo.ventas>lista[i].ventas)){ //a
                strcpy(lista[i+1].titulo,lista[i].titulo);
                strcpy(lista[i+1].plataforma,lista[i].plataforma);
                lista[i+1].puntuacion=lista[i].puntuacion;
                lista[i+1].ventas=lista[i].ventas;
                if(i==0){
                    strcpy(lista[i].titulo,nuevo.titulo);
                    strcpy(lista[i].plataforma,nuevo.plataforma);
                    lista[i].puntuacion=nuevo.puntuacion;
                    lista[i].ventas=nuevo.ventas;
                }
           }else{   //b
                lista[i+1]=nuevo;
                break;
           }
    }
}
