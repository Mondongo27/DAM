#include <stdio.h>
#include <stdlib.h>

char respuesta;
const char* TEXTO_MENU="MENU PRINCIPAL (elige una opcion):\na)Comprobar si un numero es impar o esta entre 10 y 100\nb)Comprobar si es mayuscula\nc)Lanzar moneda\nd)Salir\n";

int main()
{
    char opcion_valida;
    do{
        char opcion_valida=respuesta();
        switch(opcion_valida){
        case 'a':
            comprueba_numero();
            break;
        case 'b':
            comprueba_letra();
            break;
        case 'c':
            lanza_moneda();
            break;
        case 'd':
            //...
            break;
        }
    }while(opcion_valida!='d');

    return 0;
}

char respuesta(){
    char opcion;
    do{
        printf(TEXTO_MENU);
        scanf("%c", &opcion);
        if(opcion!='\n') while(getchar()!='\n')
    }while(opcion<'a' || opcion>'d');
    return opcion;
}

void comprueba_numero(){
    printf("\nComprobando numero...");
}

void comprueba_letra(){
    printf("\nComprobando letra...");
}

void lanza_moneda(){
    printf("\nLanzando moneda...");
}
