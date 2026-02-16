#include <stdio.h>
#include <stdbool.h>

char pedir_inicial();
bool inicial_valida(char);

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
        while(getchar()!='\n');
    }while(!inicial_valida(letra));

    return letra;
}


bool inicial_valida(char inicial){
    if((inicial>=65 && inicial<=90) || (inicial>=97 && inicial<=122)){
        return true;
    }else{
        return false;
    }
}
