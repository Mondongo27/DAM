#ifndef CRP_H_INCLUDED
#define CRP_H_INCLUDED
#include "producto.h"

typedef struct nodo{
    Producto datos;
    struct nodo* siguiente;
}Nodo;

typedef struct crprep{
    Nodo* tope;
}CrpRep;

void CrpIniciar(CrpRep*);
bool CrpDesechar(CrpRep*,Producto*);
bool CrpReciclar(CrpRep*,Producto*);
void CrpVaciar(CrpRep*);
bool CrpComprobarVacio(CrpRep*);

#endif // CRP_H_INCLUDED
