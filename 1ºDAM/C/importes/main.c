#include <stdio.h>
#include <stdlib.h>

int main()
{
    float importes[1000];
    float maximo=0.0f;
    float minimo=0.0f;
    float suma=0.0f;
    printf("Dame los importes de tus facturas uno a uno(0 para terminar)\n");
    //Ir leyendo los importes uno a uno
    int contador=0;
    float dato;
    for(int i=0;i<1000;i++){
        dato=0;
        scanf("%f",&dato);
        if (dato==0)break;
        importes[i]=dato;

        suma+=dato;
        if(i==0){
            maximo=dato;minimo=dato;
        }else{
            if(dato>maximo)maximo=dato;
            if(dato<minimo)minimo=dato;
        }
        contador++;
        while(getchar()!='\n');
    }

    if(contador==0) return 0;
    //Mostrar la media
    printf("\nLa media es: %.2f",suma/contador);
    //Mostrar el mayor
    printf("\nMaximo: %.2f",maximo);
    //Mostrar el menor
    printf("\nMinimo: %.2f",minimo);
    //Mostrarlos todos
    for(int i=0;i<contador;i++){
        printf("\n%.2f",importes[i]);
    }
    return 0;
}
