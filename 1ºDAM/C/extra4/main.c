#include <stdio.h>
#include <stdbool.h>

int main()
{
    int numero=0;
    bool bisiesto;

    while(numero<=0){
        printf("Dime un entero positivo: ");
        scanf("%d", &numero);
        while(getchar()!='\n');
    }
    if(numero%4==0 && !(numero%100==0 && numero%400!=0)){
        bisiesto=true;
    }else{
        bisiesto=false;
    }


    if(bisiesto){
        printf("El anio %d SI es bisiesto", numero);
    }else{
        printf("El anio %d NO es bisiesto", numero);
    }


    return 0;
}
