#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lvj.h"
#include "proveedorvj.h"
#include "lev.h"

int main(){
    srand(time(NULL));
    Lvj lvj;
    iniciar_lvj(&lvj);
    printf("\n%d de %d",lvj.cantidad,lvj.capacidad);
    for(int i=1;i<=7;i++){
        Juego nuevo;
        inicia_vj_aleat(&nuevo);
        aniadir_lvj(&lvj,nuevo);
    }
    printf("\n%d de %d",lvj.cantidad,lvj.capacidad);
    for(int i=0;i<lvj.cantidad;i++){
        Juego* item=recuperar_lvj(&lvj,i);
        printf("\n%d %d %s %s",item->puntuacion,item->ventas,item->titulo,item->plataforma);
    }

    Juego nuevo;
    inicia_vj_aleat(&nuevo);
    sustituir_lvj(&lvj,3,nuevo);
    sustituir_lvj(&lvj,-1,nuevo);
    sustituir_lvj(&lvj,7,nuevo);
    printf("\n---Sustituyendo---\n");
    for(int i=0;i<lvj.cantidad;i++){
        Juego* item=recuperar_lvj(&lvj,i);
        printf("\n%d %d %s %s",item->puntuacion,item->ventas,item->titulo,item->plataforma);
    }
    printf("\n---Eliminando---\n");
    eliminar_lvj(&lvj,2);
    eliminar_lvj(&lvj,4);
    eliminar_lvj(&lvj,8);
    for(int i=0;i<lvj.cantidad;i++){
        Juego* item=recuperar_lvj(&lvj,i);
        printf("\n%d %d %s %s",item->puntuacion,item->ventas,item->titulo,item->plataforma);
    }
    printf("\n%d de %d",lvj.cantidad,lvj.capacidad);

    Lev lev;
    LevIniciar(&lev);

    return 0;
}
