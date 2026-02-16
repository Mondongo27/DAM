#include <stdio.h>
#include <stdlib.h>

// Continuing with exercise 2, show on screen: the memory address where the pointer is stored, the memory
// address where the pointer points to, and the value the pointer points to.

int main(){
    int cost=5;
    int* p_cost=&cost;
    printf("%p %p %d",&p_cost,&cost,*p_cost);

    return 0;
}
