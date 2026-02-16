#ifndef LEV_H_INCLUDED
#define LEV_H_INCLUDED
#include <stdbool.h>
#include "juego.h"

typedef struct nodo_lev{
    Juego juego;
    struct nodo_lev* siguiente;
}NodoLev;


typedef struct{
    NodoLev* primero;
    int  cantidad;
    NodoLev* ultimo;
}Lev;

void LevIniciar(Lev*);
NodoLev* LevCrearNodo(Juego*);
void LevDestruirNodo(NodoLev*);
bool LevInsertarPrincipio(Lev*,Juego*);
bool LevInsertarFinal(Lev*,Juego*);
bool LevInsertarEn(Lev*, Juego*, int);
Juego* LevRecuperarEn(Lev*,int);
bool LevBorrarPrincipio(Lev*);
bool LevBorrarFinal(Lev*);
bool LevBorrarEn(Lev*,int);
void LevDestruirLista(Lev*);

#endif // LEV_H_INCLUDED
