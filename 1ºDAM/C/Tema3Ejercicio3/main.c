#include <stdio.h>
#include <stdlib.h>

// Continuing with exercise 2, how would you assign the value 100 to the variable cost using both direct
// access and indirect access?

int main(){
    int cost=5;
    int* p_cost=&cost;
    //Directo
    cost=100;
    //Indirecto
    *p_cost=100;

    return 0;
}
