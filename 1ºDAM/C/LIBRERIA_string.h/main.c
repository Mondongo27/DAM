#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //Buscar carácter en cadena
    char* cadena="Aurelianisimo";
    char letra='i';
    printf("%s",strchr(cadena,letra));
    //Empalmar dos cadenas
    char primera[20];
    printf("\nDime algo:");
    scanf("%s",primera);
    strcat(primera,": hola\n");
    printf(primera);
    //Copiar
    strcpy(primera,cadena);
    printf(primera);
    return 0;
}
