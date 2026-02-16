#include <stdio.h>
#include <stdlib.h>

// Declare a char called letra and assign it the value 'A'. Declare a pointer puntero_letra
// that points to letra, and change its value to 'Z' using the pointer. Shows the value of
// letra before and after the modification.


int main(){
    char letra='A';
    char* puntero_letra=&letra;
    printf("Antes: %c\t", letra);
    *puntero_letra='Z';
    printf("Despues: %c", letra);
    return 0;
}
