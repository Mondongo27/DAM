#include <stdio.h>
#include <stdlib.h>
#define longitud 5
#define array 20
char digitos[longitud]={'1','2','3','4','.'};
char caracteres[array][longitud]={{'A','B','C','D','.'}, {'A','B','C','D','.'},{'A','B','C','D','.'},
{'A','B','C','D','.'},{'A','B','C','D','.'},{'A','B','C','D','.'},{'A','B','C','D','.'},
{'A','B','C','D','.'},{'A','B','C','D','.'},{'A','B','C','D','.'},{'A','B','C','D','.'},
{'A','B','C','D','.'},{'A','B','C','D','.'},{'A','B','C','D','.'},{'A','B','C','D','.'},
{'A','B','C','D','.'},{'A','B','C','D','.'},{'A','B','C','D','.'},{'A','B','C','D','.'}};

int main(){
    printf("Array numeros: %s",digitos[longitud]);
    for(int i=0;i<array;i++){
            printf("\nArray caracteres: %s",caracteres[i][longitud]);
    }
    return 0;
}
