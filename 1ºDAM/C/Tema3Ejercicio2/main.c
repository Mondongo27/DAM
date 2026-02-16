#include <stdio.h>
#include <stdlib.h>

//If you have a type int variable named cost, how would you declare and initialize
// a pointer named p_cost that points to that variable?

int main(){
    int cost=5;
    int* p_cost=&cost;
    return 0;
}
