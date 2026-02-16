#include "lvj.h"
#include <stdlib.h>

bool iniciar_lvj(Lvj* lvj){
    bool resultado;

    lvj->datos=malloc(CAP_INI_LVJ*sizeof(Juego));
    if(lvj->datos==NULL){
        resultado=false;
    }else{
        lvj->cantidad=0;
        lvj->capacidad=CAP_INI_LVJ;
        resultado=true;
    }

    return resultado;
}

bool extender_lvj(Lvj* lvj){
    bool resultado;
    int nueva_capacidad=lvj->capacidad+INC_CAP_LVJ;
    Juego* temporal=realloc(lvj->datos,nueva_capacidad*sizeof(Juego));
    if(temporal==NULL){
        resultado=false;
    }else{
        lvj->datos=temporal;
        lvj->capacidad=nueva_capacidad;
        resultado=true;
    }

    return resultado;
}

bool aniadir_lvj(Lvj* lvj,Juego juego){
    if(lvj->cantidad>=lvj->capacidad){
        if(!extender_lvj(lvj)) return false;
    }
    lvj->datos[lvj->cantidad]=juego;
    lvj->cantidad++;

    return true;
}

Juego* recuperar_lvj(Lvj* lvj,int posicion){
    if(posicion<0 || posicion>=lvj->cantidad) return NULL;
    return(&(lvj->datos[posicion]));
}

bool sustituir_lvj(Lvj* lvj,int posicion,Juego nuevo){
    if(posicion<0 || posicion>=lvj->cantidad) return false;
    lvj->datos[posicion]=nuevo;
    return true;
}

bool eliminar_lvj(Lvj* lvj,int posicion){
    if(posicion<0 ||posicion>=lvj->cantidad) return false;
    for(int i=posicion;i<lvj->cantidad-1;i++) lvj->datos[i]=lvj->datos[i+1];
    lvj->cantidad--;
    return true;
}

bool insertar_lvj(Lvj* lvj,int posicion, Juego nuevo){
    if(posicion<0 || posicion > lvj->cantidad) return false;
    if(lvj->cantidad>=lvj->capacidad){
        if(!extender_lvj(lvj)) return false;
    }
    for(int i=lvj->cantidad-1;i>=posicion;i--) lvj->datos[i+1]=lvj->datos[i];
    lvj->datos[posicion]=nuevo;
    return true;
}

void vaciar_lvj(Lvj* lvj){
    free(lvj->datos);
}
