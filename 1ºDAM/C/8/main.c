#include <stdio.h>
#include <stdlib.h>

float x,y;

int main()
{
    do{
        printf("Pon dos numeros: \n");
        scanf("%f %f", &x,&y);
        printf("Los numeros son: %0.1f y %0.1f",x,y);
    }while(getchar()!='\n');
    return 0;
}
