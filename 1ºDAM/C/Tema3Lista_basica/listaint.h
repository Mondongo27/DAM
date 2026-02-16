#ifndef LISTAINT_H_INCLUDED
#define LISTAINT_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>

#define CAP_INI_LI 5
#define INC_CAP_LI 5

typedef struct{
    int* datos;
    int cantidad;
    int capacidad;
}ListaInt;

bool inicia(ListaInt*);
bool extender(ListaInt*);
bool aniadir(ListaInt*,int);
bool insertar(ListaInt*,int,int);
bool sustituir(ListaInt*,int,int);
bool eliminar(ListaInt*,int);
int recuperar(ListaInt*,int);

#endif
