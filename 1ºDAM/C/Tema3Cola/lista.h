#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "cliente.h"
#include <stdbool.h>

typedef struct nodo{
    Cliente cliente;
    struct nodo* siguiente;
}Nodo;

typedef struct lista{
    Nodo* primero;
    Nodo* ultimo;
}Lista;

Nodo* CrearNodo(Cliente*);
void ListaDestruirNodo(Nodo*);

void ListaIniciar(Lista*);
bool ListaInsertar(Lista*,const Cliente*);
bool ListaConsultar(const Lista*,Cliente*);
bool ListaSacar(Lista*);
bool ListaVaciar(Lista*);

#endif // LISTA_H_INCLUDED
