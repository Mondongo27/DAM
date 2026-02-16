#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

int main(){
    srand(time(NULL));
    int datos[TAM];

//    ------Con indices------
//    for(int i=0;i<TAM;i++){
//        datos[i]=rand()%100;
//    }

//    ------Con puntero------
    for(int i=0;i<TAM;i++){
        *(datos+i)=rand()%100;
    }
    for(int i=0;i<TAM;i++){
        printf("\ni=%d\t-> %d\t-> %d",i,*(datos+i),datos[i]);
    }

    return 0;
}
