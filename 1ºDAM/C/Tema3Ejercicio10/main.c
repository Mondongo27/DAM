#include <stdio.h>
#include <stdlib.h>
#define LONG 6
// Declare a char array called mensaje with the text "Hello".
// Use a pointer to loop through the array and
// convert each lowercase letter to uppercase and displays the result.

int main(){
    char mensaje[LONG]={'H','e','l','l','o','\0'};
    for(int i=0;i<LONG-1;i++){
        if(i==0)continue;
        *(mensaje+i)=(*(mensaje+i))-32;
    }
    for(int i=0;i<LONG-1;i++){
        printf("%c",*(mensaje+i));
    }
    return 0;
}
