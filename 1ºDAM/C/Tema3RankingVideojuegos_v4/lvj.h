#ifndef LVJ_H_INCLUDED
#define LVJ_H_INCLUDED

#include "juego.h"

int mostrar_menu();
void introducir_videojuego(Juego*);
void mostrar_ranking(Juego*,int);
void colocar_en_ranking(Juego*,Juego,int);
Juego* asignar(int*);
Juego* reasignar(int*,Juego*);

#endif // LVJ_H_INCLUDED
