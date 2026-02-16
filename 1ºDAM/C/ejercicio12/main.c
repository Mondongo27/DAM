#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    clock_t inicio, fin;
    double tiempo;
    int i,j,k;

    inicio = clock();
    printf("inicio = %ld\n", inicio);

    for(i=0;i<1000;i++){
        for(j=0;j<1000;j++){
            for(k=0;k<1000;k++){
            }
        }
    }
    fin=clock();
    printf("fin = %ld\n",fin);

    tiempo=(double)(fin-inicio) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n",tiempo);

    return 0;
}
