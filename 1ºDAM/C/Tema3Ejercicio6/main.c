#include <stdio.h>
#include <stdlib.h>

// Declare an integer variable numero and initialize it with a value, for example 10.
// Declare a pointer puntero_numero that points to numero and modify the value of numero
// through the pointer to be 20. Display the value of numero before and after the modification.


int main(){
    int numero=10;
    int* puntero_numero=&numero;
    printf("Antes: %d\t",numero);
    *puntero_numero=20;
    printf("Despues: %d",numero);
    return 0;
}
