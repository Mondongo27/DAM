#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LONG 10

// Declare an array of 10 integers.
// Fill it with random numbers betwen 0-99 and show them on screen, without using index notation.

int main(){
    srand(time(NULL));
    int array[LONG];
////  Con indices:
//    for(int i=0;i<LONG;i++){
//        array[i]=rand()%100;
//    }

//  Con punteros:
    for(int i=0;i<LONG;i++){
        *(array+i)=rand()%100;
    }
    for(int i=0;i<LONG;i++){
        printf("%d %d %d\n", i, *(array+i), array[i]);
    }
//  array==&array[0], poner solo array es lo mismo que poner la dirección en memoria
//  del primer elemento del array.
    return 0;
}
