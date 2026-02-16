#include <stdio.h>
#include <stdlib.h>

int main(){
    char saludo[6]={'H','e','l','l','o','\0'};

    for(int i=0;i<5;i++){
//        if(*(saludo+i)>='a'&&*(saludo+i)<='z') *(saludo+i)-=32;
        if(*(saludo+i)>='97'&&*(saludo+i)<='122') *(saludo+i)-=32;
    }
    printf("%s",saludo);
    return 0;
}
