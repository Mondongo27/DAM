#include <stdio.h>
#include <stdlib.h>

int main()
{
    int notas[5];
    float notafinal;
    float notamedia;
    printf("Dime tus notas:");
    scanf("%f %f %f %f %f",&notas[0],&notas[1],&notas[2],&notas[3],&notas[4]);
    while(getchar()!='\n');
    notafinal=notas[0]+notas[1]+notas[2]+notas[3]+notas[4];
    notamedia=notafinal/5;
    printf("Tu nota media es: %.1f",notamedia);
    return 0;
}
