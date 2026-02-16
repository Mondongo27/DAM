#include <stdio.h>
#include <stdlib.h>

// Continuing with exercise 2, how would you print the value of the pointer,
// plus the value being pointed to?

int main(){
    int cost=5;
    int* p_cost=&cost;
    printf("%d %d",*p_cost,cost);
    return 0;
}
