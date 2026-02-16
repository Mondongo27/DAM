#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    char respuesta;
    void lanza_moneda();
    void comprueba_mayuscula();
    void comprueba_numero();


    srand(time(NULL));
    printf("MENU PRINCIPAL (Elige una opcion): \na) Comprueba impar entre 10 y 100\nb) Comprueba letra mayuscula\nc) Lanza moneda\nd) Salir\n");
    printf("\nOpcion: ");
    scanf("%c", &respuesta);
    while(getchar()!='\n');




    switch(respuesta){
    case 'a':
    comprueba_numero();
        break;
    case 'b':
    comprueba_mayuscula();
        break;
    case 'c':
    lanza_moneda();
        break;
    case 'd':
        printf("Saliendo del programa...\n");
        exit(0);
        break;
    default:
        printf("No es una opcion valida");
    }


    return 0;
}

void comprueba_mayuscula(){
    char letra;
    printf("Dime una letra: ");
    scanf("%c", &letra);
    while(getchar()!='\n');

    if(isupper(letra)){
        printf("%c Es una letra mayuscula", letra);
    }else{printf("Es una letra minuscula");}

}


void lanza_moneda(){
    int tirada = rand()%2;
    if(tirada==1){
        printf("Cara");
    }else{
        printf("Cruz");}
    }

void comprueba_numero(){
    int numero=1;
    do{
        printf("Dame un entero: ");
        scanf("%d", &numero);
        while(getchar()!='n');
    }while(numero<=0);



}
