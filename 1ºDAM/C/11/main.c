#include <stdio.h>
#include <stdlib.h>

int value1,value2,auxiliar1;

int main()
{
    do{
        printf("Dame dos numeros enteros: \n");
        scanf("%d %d",&value1,&value2);
        auxiliar1=value1;
        value1=value2;
        value2=auxiliar1;
        printf("Los valores intercambiados son: %d , %d", value1, value2);
    }while(getchar()!='\n');
    return 0;
}
