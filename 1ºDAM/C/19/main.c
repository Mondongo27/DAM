#include <stdio.h>
#include <stdlib.h>

int edad;

int main()
{
    printf("Dime tu edad: "); scanf("%d", &edad);
    if(edad<18 && edad>8){
            printf("Eres menor");
    }else if(edad>=65){
        printf("Eres senior");
        }else if(edad<=8){
            printf("Eres enano");
            }else{
            printf("Eres adulto");
            }
    return 0;
}
