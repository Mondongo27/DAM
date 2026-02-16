#include <stdio.h>

/*
!= ¿Es distinto?
== ¿Es igual que?
*/



int main()
{
    int edad;
//////////////////////////////PRIMERA VERSION
//    do{
//        printf("Dime tu edad: ");
//        scanf("%d",&edad);
//        if(edad>100) break;//ruptura adelanta
//        if(edad>80) continue;//me salto lo que queda de esta iteración
//        if(edad>5){
//            printf("Tienes %d años\n",edad);
//        }else if (edad>0){
//            printf("no deberias estar manejando un ordenador\n");
//        }else if (edad==0){
//            printf("No me lo creo\n");
//        }else{
//            printf("%d no es una edad aceptable\n",edad);
//        }
//    }while(edad>=0);
//
//    printf("\nAdios");
//////////////////////////////SEGUNDA VERSION
//    printf("\nDime tu edad: ");
//    scanf("%d",&edad);
//
//    (edad>=18)? printf("\nMayorcito")   :   printf("\nMenor");

/////////////////////////////TERCERA VERSION
    int nota;
    do{
        printf("\nDime tu nota: ");
        scanf("%d",&nota);

        switch(nota){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            printf("Suspenso");
            break;
        case 5:
        case 6:
            printf("Aprobado");
            break;
        case 7:
        case 8:
            printf("Notable");
            break;
        case 9:
        case 10:
            printf("Sobresaliente");
            break;
        default:
            printf("No es una nota valida");
        }
        printf("\n");

    }while(nota>=0);

    return 0;
}
