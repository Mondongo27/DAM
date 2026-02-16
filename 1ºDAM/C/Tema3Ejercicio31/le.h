#ifndef LE_H_INCLUDED
#define LE_H_INCLUDED

typedef struct nodo_le {
    int entero;
    struct nodo_le* siguiente;
}NodoLE;

typedef struct{
    NodoLE* primero;
    int cantidad;
    NodoLE* ultimo;
}LE;

void LeIniciar(LE*);
NodoLE* LeCrearNodo(int*);
bool LeInsertarPrincipio(LE*, int*);
bool LeInsertarFinal(LE*,int*);
bool LeInsertarMedio(LE*,int*,int);
void LeDestruirNodo(NodoLE*);
bool LeBorrarPrincipio(LE*);

#endif // LE_H_INCLUDED
