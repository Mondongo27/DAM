#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG_FRASE 255

const char* ERROR_ARCHIVO="\nError al acceder al archivo";

int main(){
    char archivo[50];
    char frase[LONG_FRASE];

    printf("Dime como se llama el archivo:\n");
    scanf("%s",archivo);
    while(getchar()!='\n');

    FILE* f=fopen(archivo,"a");
    if(f==NULL){
        printf(ERROR_ARCHIVO);
        return 1;
    }

    do{
        printf("\nDime una frase: ");
        scanf("%[^\n]",frase);
        frase[LONG_FRASE-1]='\0';
        getchar();
        if(strcmp(frase,"FIN")) break;
        //Si el archivo tiene algo \n antes de la frase
        if(ftell(f)>0) fprintf(f,"\n");

        fprintf(f,"%s;%d",frase,strlen(frase));
    }while(1);

    fclose(f);
    return 0;
}
