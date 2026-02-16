#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <stdbool.h>

#define MAX_DESCRIPCION 20

typedef struct{
    char descripcion[MAX_DESCRIPCION+1];
    int peso;
}Producto;

void Producto_Inicializar(Producto *p, const char *descripcion, int peso);


#endif // PRODUCTO_H_INCLUDED
