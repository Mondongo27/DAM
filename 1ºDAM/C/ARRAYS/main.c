#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valores[4]={23,45,0,34};
    valores[3]=24;
    int x=valores[1]; //x==45
    for(int i=0;i<4;i++){
        printf("%d ",valores[i]);
    }
    return 0;
}
