#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crp.h"

const char* CRP_VACIO="\nEl cubo de reciclaje de productos esta vacio\n";
const char* CRP_NOVACIO="\nEl cubo de reciclaje de productos no esta vacio\n";
const char* MOSTRAR_DESC="\nDescripcion del producto: %s\n";
const char* MOSTRAR_PESO="\nPeso del producto: %d\n";
const char* ERROR="\nNo puedes reciclar si no hay nada que reciclar\n";
const char* DIVISOR="\n_____________________________________\n"; //Para que se vea mas claro en la consola cada ejercicio
const char* DESC_LAPIZ="Lapiz";
const char* DESC_BOTELLA="Botella oxidada";
const char* DESC_ESTUCHE="Estuche";
const char* DESC_GORRA="Gorra fea";
const char* DESC_GOMA="Goma";

int main(){
    //Inicio crp
    CrpRep crprep;
    CrpIniciar(&crprep);

    printf(DIVISOR);

    //Compruebo si esta vacío
    if(CrpComprobarVacio(&crprep)==true){
        printf(CRP_VACIO);
    }else{
        printf(CRP_NOVACIO);
    }

    printf(DIVISOR);
    //Desechar 5 productos
    Producto producto1, producto2, producto3, producto4, producto5;
    strcpy(producto1.descripcion,DESC_LAPIZ);
    producto1.peso=10;
    strcpy(producto2.descripcion,DESC_BOTELLA);
    producto2.peso=50;
    strcpy(producto3.descripcion,DESC_ESTUCHE);
    producto3.peso=20;
    strcpy(producto4.descripcion,DESC_GORRA);
    producto4.peso=25;
    strcpy(producto5.descripcion,DESC_GOMA);
    producto5.peso=2;

    CrpDesechar(&crprep,&producto1);
    CrpDesechar(&crprep,&producto2);
    CrpDesechar(&crprep,&producto3);
    CrpDesechar(&crprep,&producto4);
    CrpDesechar(&crprep,&producto5);

    printf(DIVISOR);
    //Compruebo si esta vacío
    if(CrpComprobarVacio(&crprep)==true){
        printf(CRP_VACIO);
    }else{
        printf(CRP_NOVACIO);
    }

    printf(DIVISOR);
    //Reciclo dos productos y muestro sus caracteristicas
    printf(MOSTRAR_DESC,producto3.descripcion);
    printf(MOSTRAR_PESO,producto3.peso);
    CrpReciclar(&crprep,&producto3);
    printf(MOSTRAR_DESC,producto4.descripcion);
    printf(MOSTRAR_PESO,producto4.peso);
    CrpReciclar(&crprep,&producto4);

    printf(DIVISOR);
    //Compruebo si esta vacío
    if(CrpComprobarVacio(&crprep)==true){
        printf(CRP_VACIO);
    }else{
        printf(CRP_NOVACIO);
    }

    printf(DIVISOR);
    //Vacio
    CrpVaciar(&crprep);

    printf(DIVISOR);
    //Compruebo si esta vacío
    if(CrpComprobarVacio(&crprep)==true){
        printf(CRP_VACIO);
    }else{
        printf(CRP_NOVACIO);
    }

    printf(DIVISOR);
    //Intento reciclar con la lista vacia
    printf(MOSTRAR_DESC,producto3.descripcion);
    printf(MOSTRAR_PESO,producto3.peso);
    if(CrpReciclar(&crprep,&producto3)==false){
        printf(ERROR);
    }
    printf(MOSTRAR_DESC,producto4.descripcion);
    printf(MOSTRAR_PESO,producto4.peso);
    if(CrpReciclar(&crprep,&producto4)==false){
        printf(ERROR);
    }

    return 0;
}
