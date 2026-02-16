#include <stdio.h>
#include <stdlib.h>
#include "crp.h"


void CrpIniciar(CrpRep* crprep){
    crprep->tope=NULL;
}

bool CrpDesechar(CrpRep* crprep,Producto* producto){
    Nodo* nuevo=malloc(sizeof(Nodo));
    if (!nuevo) return false;
    nuevo->datos=*producto;
    nuevo->siguiente=crprep->tope;
    crprep->tope=nuevo;
    return true;
}

bool CrpReciclar(CrpRep* crprep,Producto* producto){
    if (crprep->tope==NULL) return false;
    Nodo* sup=crprep->tope;
    if (producto){
        *producto=sup->datos;
    }
    crprep->tope=sup->siguiente;
    free(sup);
    return true;
}

void CrpVaciar(CrpRep* crprep){
    Nodo* act=crprep->tope;
    while (act!=NULL){
        Nodo* sig =act->siguiente;
        free(act);
        act=sig;
    }
    crprep->tope=NULL;
}

bool CrpComprobarVacio(CrpRep* crprep){
    if(crprep->tope==NULL){
        return true;
    }else{
        return false;
    }
}

