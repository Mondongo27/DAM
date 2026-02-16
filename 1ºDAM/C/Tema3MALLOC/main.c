#include <stdio.h>
#include <stdlib.h>

int main(){
    short* pin=malloc(10*sizeof(short));

    for(int i=0;i<10;i++){
        pin[i]=(i+1)*5;
    }

    printf("\nContenido de pin: ");
    for(int i=0;i<10;i++){
        printf("\n%d\t%d\t%x",i,pin[i],&pin[i]);
    }

    for(int i=10;i<20;i++){
        pin[i]=(i+1)*5;
    }

    printf("\nContenido extendido: ");
    for(int i=10;i<20;i++){
        printf("\n%d\t%d\t%x",i,pin[i],&pin[i]);
    }

    free(pin);
    return 0;
}
