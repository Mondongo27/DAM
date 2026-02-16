#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lvj.h"
#include "juego.h"
#include "lvj.c"


const char* INFO_AGREGADO="\n%s para %s, con %d puntos y %d uds.vendidas añadido";
const char* ERROR_CONTENIDO="\nEl ranking está vacío";
const char* DESPEDIDA="\n¡Hasta otra!";

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
                Juego* nuevo=reasignar(&capacidad,ranking);
                if (nuevo==NULL) continue;
                ranking=nuevo;
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

