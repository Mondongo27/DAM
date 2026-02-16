#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    printf("\n%d",rand()%26+100);
    return 0;
}
