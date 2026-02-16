#include "lista.h"
#include <stdlib.h>
#include <string.h>

void ListaIniciar(Lista* lista){//Iniciar lista (Cola)
    lista->primero=NULL;
    lista->ultimo=NULL;
}

Nodo* CrearNodo(Cliente* cliente){//Crear nodo (Persona)
    Nodo* nodo=malloc(sizeof(Nodo));
    if(nodo==NULL) return NULL;
    nodo->cliente=*cliente;
    nodo->siguiente=NULL;
    return nodo;
}

void ListaDestruirNodo(Nodo* nodo){//Destruir nodo
    free(nodo);
}

bool ListaInsertar(Lista* lista,const Cliente* cliente){//Insertar nodo en lista
    Nodo* nodo=CrearNodo(cliente);
    if(nodo==NULL) return false;
    //Caso: lista vacía
    if(lista->primero==NULL){
        lista->primero=nodo;
        lista->ultimo=nodo;
    }else{//Caso general:
        lista->ultimo->siguiente=nodo;
        lista->ultimo=nodo;
    }
    return true;
}

bool ListaConsultar(const Lista* lista,Cliente* cliente){//Consultar primer
    if(lista->primero==NULL){
        return false;
    }
    strcpy(cliente->iniciales,lista->primero->cliente.iniciales);
    strcpy(cliente->nif,lista->primero->cliente.nif);
    return true;
}

bool ListaSacar(Lista* lista){//Eliminar primero
    if(lista->primero!=NULL){
        Nodo* condenado=lista->primero;
        lista->primero=lista->primero->siguiente;
        ListaDestruirNodo(condenado);
        return true;
    }else return false;
}

bool ListaVaciar(Lista* lista){//Vaciar lista
    if(lista->primero==NULL) return false;
    do{
        ListaSacar(lista);
    }while(lista->primero!=NULL);
    return true;
}



