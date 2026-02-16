#include <stdio.h>
#include <stdbool.h>

char pedir_inicial();
bool mayuscula_valida(char);

int main()
{
    char nombre, ape1, ape2;

    nombre=pedir_inicial();
    ape1=pedir_inicial();
    ape2=pedir_inicial();

    printf("\n%c.%c.%c.",nombre,ape1,ape2);

    return 0;
}


char pedir_inicial(){
    char letra;
    printf("Dame una inicial: ");
    do{
        scanf("%c",&letra);
        if(letra>=97 && letra<=122){
            letra-=32;
        }
        if(letra!='\n')while(getchar()!='\n');
    }while(!mayuscula_valida(letra));

    return letra;
}


bool mayuscula_valida(char mayuscula){
//    if( (mayuscula>=65 && mayuscula<=90)){
//        return true;
//    }else{
//        return false;
//    }
    return (mayuscula>=65 && mayuscula<=90);
}
