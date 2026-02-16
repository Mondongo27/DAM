#include <stdio.h>
#include <stdlib.h>

const char* NOMBRE="prueba.txt";

int lectura();
int escritura();

int main(){
    //escritura();
    lectura();
    return 0;
}

int lectura(){
    FILE* archivo=fopen(NOMBRE,"r");
        if(archivo==NULL) {
        printf("Error al acceder al archivo");
        return 1;
    }
//    for(int i=1;i<=1000000;i++){
//        int letra=fgetc(archivo);
//        if(letra==EOF) break;
//        printf("%c",letra);
//    }
    int letra;
//    while((letra=fgetc(archivo))!=EOF) printf("%c",letra);

    do{
        letra=fgetc(archivo);
        if(letra==EOF) continue;
        printf("%c",letra);
    }while(!feof(archivo));
    printf("\n-----------------------------------------------------\n");

    char contenedor[251];
    fseek(archivo,0,SEEK_SET);
    while(fgets(contenedor,250,archivo)!=NULL) printf("%s",contenedor);


    fclose(archivo);
    return 0;
}

int escritura(){
        FILE* prueba=fopen(NOMBRE,"w");
    if(prueba==NULL) {
        printf("Error creando el fichero");
        return 1;
    }
    printf("Fichero creado");

    //fputc: caracter a caracter
    char* cadena="Hola\nComo estas\nAdios";
    char* puntero=cadena;
    while(*puntero!='\0'){
        fputc(*puntero,prueba);
        puntero++;
    }

    //fputs: cadena entera
    char* cadena2="\nEsta tiene un salto de linea delante";
    fputs(cadena2,prueba);

    //fprintf: printf en archivos
    int numero=14;
    char* cadena3="\nEsta con salto y un numero aleatorio: %d";
    fprintf(prueba,cadena3,numero);

    fclose(prueba);
    return 0;
}
