#include <stdio.h>
#include <stdlib.h>

void mostrar_contenido();
int anadir_numero();
const char* MENU="Elige una opcion:\na)Nuevo numero\nb)Mostrar numeros\nz)Salir\n>";
const int capacidad_array=100;
int datos[capacidad_array];

int main()
{
    char opcion;
    do{
        opcion=elige_opcion();
    }while(opcion!='z')
    printf(MENU);
    scanf("%c",&opcion);
    while(getchar()!='\n');
    switch(opcion){
    case 'a':
        printf(">");
        anadir_numero();
    break;
    case 'b':
        mostrar_contenido();
    break;
    default:
    }
    return 0;
}

void mostrar_contenido(){
    for(int i=0;i<LARGO;i++) printf("\n%dº -> %d",i,datos[i]);
}

char elige_opcion(){

}

int anadir_numero(){
    int numero_usuario;
    scanf("%d",&numero_usuario);
    while(getchar()!='\n');


    return numero_usuario;
}
