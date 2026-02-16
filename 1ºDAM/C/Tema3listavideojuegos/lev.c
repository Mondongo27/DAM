#include "lev.h"
#include <stdlib.h>
#include <stdbool.h>

void LevIniciar(Lev* lev){
    lev->primero=NULL;
    lev->cantidad=0;
    lev->ultimo=NULL;
}

NodoLev* LevCrearNodo(Juego* pj){
    NodoLev* nodo=malloc(sizeof(NodoLev));
    if(nodo==NULL) return NULL;
    nodo->juego=*pj;
    nodo->siguiente=NULL;
    return nodo;
}

void LevDestruirNodo(NodoLev* pn){
    free(pn);
}

bool LevInsertarPrincipio(Lev* lev, Juego* nuevo){
    NodoLev* nodo=LevCrearNodo(nuevo);
    if(nodo==NULL) return false;
    //Inserto al principio de la lista
    nodo->siguiente=lev->primero;
    lev->primero=nodo;
    if(lev->cantidad==0) lev->ultimo=nodo;
    lev->cantidad++;
    return true;
}

bool LevInsertarFinal(Lev* lev, Juego* nuevo){
    NodoLev* nodo=LevCrearNodo(nuevo);
    if(nodo==NULL) return false;
    //Inserto al final de la lista
    if(lev->cantidad==0){
        lev->primero=nodo;
        lev->ultimo=nodo;
    }else{
        lev->ultimo->siguiente=nodo;
        lev->ultimo=nodo;
    }
    lev->cantidad++;
    return true;
}

bool LevInsertarEn(Lev* lev, Juego* nuevo,int posicion){
    if(posicion<0 || posicion>lev->cantidad) return false;
    NodoLev* nodo=LevCrearNodo(nuevo);
    if(nodo==NULL) return false;
    if (posicion==0){
        LevInsertarPrincipio(lev,nuevo);
    }else if(posicion==lev->cantidad){
        LevInsertarFinal(lev,nuevo);
    }else{
        NodoLev* actual=lev->primero;
        for(int i=1;i<posicion;i++){//Avanzar posicion -1
            actual=actual->siguiente;
        }
        nodo->siguiente=actual->siguiente;
        actual->siguiente=nodo;
    }
    lev->cantidad++;
    return true;
}

Juego* LevRecuperarEn(Lev* lev,int posicion){
    if(posicion<0 || posicion>=lev->cantidad) return NULL;
    NodoLev* actual=lev->primero;
    for(int i=1;i<=posicion;i++) actual=actual->siguiente;
    return &(actual->juego);
}

bool LevBorrarPrincipio(Lev* lev){
    //Si la lista esta vacía, no puedo borrar
    if(lev->cantidad=0) return false;

    NodoLev* condenado=lev->primero;
    //Si tiene un único elemento -> queda vacía
    if(lev->cantidad==1){
        lev->primero=NULL;
        lev->ultimo=NULL;
    }else{
        lev->primero=lev->primero->siguiente;
    }

    LevDestruirNodo(condenado);
    lev->cantidad--;
    return true;
}

bool LevBorrarFinal(Lev* lev){
    //Si la lista esta vacía, no puedo borrar
    if(lev->cantidad=0) return false;

    NodoLev* condenado;
    //Si tiene un único elemento -> queda vacía
    if(lev->cantidad==1){
        lev->primero=NULL;
        lev->ultimo=NULL;
        condenado=lev->primero;
    }else{
        NodoLev* actual=lev->primero;
        while(actual->siguiente->siguiente!=NULL) actual=actual->siguiente;
        condenado=actual->siguiente;
        actual->siguiente=NULL;
        lev->ultimo=actual;
    }

    LevDestruirNodo(condenado);
    lev->cantidad--;
    return true;
}

bool LevBorrarEn(Lev* lev,int posicion){
    //Si la lista esta vacía no puedo borrar
    if(lev->cantidad==0) return false;
    //Si la posición no es  valida no puedo borrar
    if(posicion<0 || posicion>=lev->cantidad) return false;
    //Si la posicion es un extremo -> tengo funciones específicas
    if(posicion==0){
        LevBorrarPrincipio(lev);
    }else if(posicion==lev->cantidad-1){
        LevBorrarFinal(lev);
    }else{
        NodoLev* actual=lev->primero;
        for(int i=1;i<posicion;i++) actual=actual->siguiente;
        NodoLev* condenado=actual->siguiente;
        actual->siguiente=actual->siguiente->siguiente;
        lev->cantidad--;
        LevDestruirNodo(condenado);
    }

    return true;
}

void LevDestruirLista(Lev* lev){
    while(lev->cantidad>0){
        LevBorrarPrincipio(lev);
    }
}
