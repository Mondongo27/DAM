#include <stdio.h>
#include <stdlib.h>

const char* ERROR_ARCHIVO="\nError al acceder al archivo";

int main(){
    char archivo[30];
    //char letra;
    //int contador=0;

    printf("Dime como se llama el archivo:\n");
    scanf("%s",archivo);
    while(getchar()!='\n');

    FILE* f=fopen(archivo,"r");
    if(f==NULL){
        printf(ERROR_ARCHIVO);
        return 1;
    }

//    printf("Dime que letra quieres buscar:\n");
//    scanf("%c",&letra);
//    while(getchar()!='\n');
//
//    do{
//        char leido=fgetc(f);
//        if(leido==EOF) break;
//        if(leido==letra) contador++;
//    }while(true);
//
//    printf("\n-- %d --\n",contador);
    int contador[95][2];//pos 0 caracter pos 1 contador
    //Inicializo contadores
    for(int i=0;i<95;i++){
        contador[i][0]=i+32;
        contador[i][1]=0;
    }

    //Procesa
    do{
        char leido=fgetc(f);
        if(leido==EOF) break;
        for(int i=0;i<95;i++){
            if(contador[i][0]==leido) contador[i][1]++;
        }
    }while(1);

    for(int i=0;i<95;i++){
        printf("\n%c -> %d",contador[i][0],contador[i][1]);
    }

    fclose(f);
    return 0;
}


