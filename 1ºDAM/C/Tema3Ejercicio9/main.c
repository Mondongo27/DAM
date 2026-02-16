#include <stdio.h>
#include <stdlib.h>
#define LONG 5
// Declare an array of integer numeros of size 5 and initialize it with values {1, 2, 3, 4, 5}.
// Using a pointer, multiply each element by 2 and display the modified array

int main(){
    int numeros[LONG]={1, 2, 3, 4, 5};
    for(int i=0;i<LONG;i++){
        *(numeros+i)=(*(numeros+i))*2;
    }
    for(int i=0;i<LONG;i++){
        printf("%d ",*(numeros+i));
    }
    return 0;
}
