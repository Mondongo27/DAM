#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1,numero2,numero3,mayor;
    printf("Dame 3 numeros enteros: ");
    scanf("%d%d%d",&numero1,&numero2,&numero3);

    mayor=numero2>numero1? numero2 : numero1;
    mayor=numero3>mayor? numero3 : mayor;

    printf("\nEl mayor es %d",mayor);


    return 0;
}
