#include <stdio.h>
#include <stdlib.h>

// Declare two variables a and b with values 5 and 10. Create a intercambiar function that
// receives pointers to a and b and swaps them.
// Prints the values before and after the function call.
void intercambiar(int*,int*);

int main(){
    int a=5;
    int b=10;
    // Antes del intercambio:
    printf("\n a = %d\tb = %d\n", a, b);
    intercambiar(&a,&b);
    // Despues del intercambio:
    printf("\n a = %d\tb = %d\n", a, b);

    return 0;
}

void intercambiar(int* a, int* b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
