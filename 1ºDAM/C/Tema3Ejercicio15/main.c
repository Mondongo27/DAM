#include <stdio.h>
#include <stdlib.h>

int longitud(char*);

int main(){
    char* mensaje="";
    char* mensaje2="1";
    char* mensaje3="123";

    longitud(mensaje);
    printf("\nLa longitud es: %d",longitud(mensaje));
    printf("\nLa longitud es: %d",longitud(mensaje2));
    printf("\nLa longitud es: %d",longitud(mensaje3));

    return 0;
}

int longitud(char* m){
    int contador=0;
    while(*m!='\0'){
        m++;
        contador++;
    }
    return contador;
}
