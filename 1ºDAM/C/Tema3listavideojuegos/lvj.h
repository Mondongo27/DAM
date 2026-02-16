#ifndef LVJ_H_INCLUDED
#define LVJ_H_INCLUDED

#include "juego.h"
#include <stdbool.h>

#define CAP_INI_LVJ 5
#define INC_CAP_LVJ 5

typedef struct{
    Juego* datos;
    int cantidad;
    int capacidad;
}Lvj;

bool iniciar_lvj(Lvj*);
bool extender_lvj(Lvj*);
bool aniadir_lvj(Lvj*,Juego);
Juego* recuperar_lvj(Lvj*,int);
bool sustituir_lvj(Lvj*,int,Juego);
bool eliminar_lvj(Lvj*,int);
bool insertar_lvj(Lvj*,int, Juego);
void vaciar_lvj(Lvj* lvj);

#endif // LVJ_H_INCLUDED
