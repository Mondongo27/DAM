#include <stdio.h>
#include <stdlib.h>
#define CANT 4

// Declare an array of float values called valores with 4 elements initialized to whatever you want. Using a
// pointer, add 0.5 to each element and display the result.

void aniadir_0con5(float*);

int main(){
    float valores[CANT]={2.1,3.2,5.2,9.0};
    float *p_valores=valores;
    aniadir_0con5(p_valores);
    for(int i=0;i<CANT;i++){
        printf("%.2f ",*(valores+i));
    }
    return 0;
}

void aniadir_0con5(float* valores2){
    for(int i=0;i<CANT;i++){
        *(valores2+i)+=0.5;
    }
}
