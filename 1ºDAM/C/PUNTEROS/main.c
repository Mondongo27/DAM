#include <stdio.h>
#include <stdlib.h>

void numeros();
void arrays();

int main(){
    int x;
    printf("\n%d",sizeof(x));
    //numeros();
    arrays();
    return 0;
}

void arrays(){
    int datos[]={2,-3,8,15,4};
    int* otro=datos;
    for (int i=0;i<5;i++){
        printf("\nIndice: %d\tValor: %d\tDireccion: %x",i,datos[i],&datos[i]);
    }
    printf("\n\nDireccion del array: %x",datos);
//    otro+=2;
    printf("\n\nDireccion del otro: %x",otro);

    for (int i=0;i<5;i++){
        printf("\nIndice: %d\tValor: %d\tDireccion: %x",i,*(otro+i),otro+i);
//        otro++;
    }
}

void numeros(){
    int edad=8;
    float saldo=25.50f;
    int* p_edad=&edad;
    float* p_saldo=&saldo;

    printf("\n-----------------Usando las propias variables-----------------");
    printf("\nEdad: %d,esta en la direccion %x",edad,&edad);
    printf("\nSaldo: %.2f,esta en la direccion %x",saldo,&saldo);

    printf("\n\n\n");

    printf("\n-----------------------Usando punteros------------------------");
    printf("\nEdad: %d,esta en la direccion %x",*p_edad,p_edad);
    printf("\nSaldo: %.2f,esta en la direccion %x",*p_saldo,p_saldo);

    printf("\n\n\n");
}
