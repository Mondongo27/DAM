#include  "listaint.h"
#include <limits.h>

bool inicia(ListaInt* pli){
    bool resultado;

    pli->datos=malloc(CAP_INI_LI*sizeof(int));
    if(pli->datos==NULL){
        resultado=false;
    }else{
        pli->cantidad=0;
        pli->capacidad=CAP_INI_LI;
        resultado=true;
    }

    return resultado;
}

bool extender(ListaInt* pli){
    bool resultado;
    int nueva_capacidad=pli->capacidad+INC_CAP_LI;
    int* temporal=realloc(pli->datos,nueva_capacidad*sizeof(int));
    if(temporal==NULL){
        resultado=false;
    }else{
        pli->datos=temporal;
        pli->capacidad=nueva_capacidad;
        resultado=true;
    }

    return resultado;
}

bool aniadir(ListaInt* pli,int valor){
    if(pli->cantidad>=pli->capacidad){
        bool puedo_extender=extender(pli);
        if(!puedo_extender) return false;
    }
    pli->datos[pli->cantidad]=valor;
    pli->cantidad++;

    return true;
}

bool insertar(ListaInt* pli,int valor,int posicion){
    //Si el indice no es valido no hago nada
    if(posicion<0 || posicion>pli->cantidad) return false;
    if(posicion==pli->cantidad) return aniadir(pli,valor);
    //Si ya tengo ocupada toda la capacidad, he de ampliar
    if(pli->cantidad>=pli->capacidad){
        bool puedo_extender=extender(pli);
        if(!puedo_extender) return false;
    }
    //Ahora que tengo capacidad suficiente, abro hueco
    for(int i=pli->cantidad-1;i>=posicion;i--) pli->datos[i+1]=pli->datos[i];
    //En el hueco abierto coloco el valor que me han dicho
    pli->datos[posicion]=valor;
    pli->cantidad++;
    return true;
}

bool sustituir(ListaInt* pli,int valor,int posicion){
    if(posicion<0 || posicion>=pli->cantidad) return false;
    pli->datos[posicion]=valor;
    return true;
}

bool eliminar(ListaInt* pli,int posicion){
    //Si el indice no es valido no hago nada
    if(posicion<0 || posicion>=pli->cantidad) return false;
    //Elimino desplazando a la izquierda y acortando
    for(int i=posicion;i<pli->cantidad;i++) pli->datos[i]=pli->datos[i+1];
    pli->cantidad--;
    return true;
}

int recuperar(ListaInt* pli,int posicion){
    //Si el indice no es valido devuelvo un valor extremo
    if(posicion<0 || posicion>=pli->cantidad) return INT_MIN;
    //Si es valido devuelvo lo que este en esa posicion
    return pli->datos[posicion];
}
