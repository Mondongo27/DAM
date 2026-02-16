#include <stdio.h>
#include <stdlib.h>

//Escribe un programa que te pida el nombre de un archivo de texto y cuente las líneas que tiene.
//Debe dar error si el archivo no existe.

int lectura(char*);

int main(){
    char* archivo;
    printf("Nombre archivo: ");
    scanf("%s",&archivo);
    return 0;
}

int lectura(char* archivo){
    FILE* fichero=fopen(fichero,"r");
        if(archivo==NULL) {
        printf("Error al acceder al archivo");
        return 1;
    }

    return 0;
}
