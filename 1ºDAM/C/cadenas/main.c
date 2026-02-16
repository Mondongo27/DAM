#include <stdio.h>
#include <stdlib.h>
#define LONGITUD 30

int main()
{
    char nombre[LONGITUD];
    printf("Dime tu nombre:\n");
    scanf("%s",nombre);
    printf("\nHola %s",nombre);
    for(int i=0;i<LONGITUD;i++){
        printf("%c",nombre[i]);
    }
    return 0;
}
