#include "le.h"
#include <stdlib.h>

void LeIniciar(LE* le){
    le->primero=NULL;
    le->ultimo=NULL;
    le->cantidad=0;
}

NodoLE* LeCrearNodo(int* p_le){
    NodoLE* nodo=malloc(sizeof(NodoLE));
    if(nodo==NULL) return NULL;
    nodo->entero=*p_le;
    nodo->siguiente=NULL;
    return nodo;
}

bool LeInsertarPrincipio(LE* le, int* nuevo){
    NodoLE* nodo=LeCrearNodo(nuevo);
    if(nodo==NULL) return false;
    nodo->siguiente=le->primero;
    le->primero=nodo;
    if(le->cantidad==0) le->ultimo=nodo;
    le->cantidad++;
    return true;
}

bool LeInsertarFinal(LE* le, int* nuevo){
    NodoLE* nodo=LeCrearNodo(nuevo);
    if(nodo==NULL) return false;
    le->ultimo->siguiente=nodo;
    le->ultimo=nodo;
    le->cantidad++;
    return true;
}

bool LeInsertarMedio(LE* le, int* nuevo, int posicion){
    if(posicion<0 || posicion>le->cantidad) return false;
    if (posicion==0){
        LeInsertarPrincipio(le,nuevo);
    }else if(posicion==le->cantidad){
        LeInsertarFinal(le,nuevo);
    }else{
        NodoLE* nodo=LeCrearNodo(nuevo);
        if(nodo==NULL) return false;
        NodoLE* actual=le->primero;
        for(int i=1;i<posicion;i++){
            actual=actual->siguiente;
        }
        nodo->siguiente=actual->siguiente;
        actual->siguiente=nodo;
    }
    le->cantidad++;
    return true;
}

void LeDestruirNodo(NodoLE* nodo){
    free(nodo);
}

bool LeBorrarPrincipio(LE* le){
    if(le->cantidad=0) return false;
    NodoLE* eliminado=le->primero;
    if(le->cantidad=1){
        le->primero=NULL;
        le->ultimo=NULL;
    }else{
        le->primero=le->primero->siguiente;
    }
    LeDestruirNodo(eliminado);
    le->cantidad--;
    return true;
}






