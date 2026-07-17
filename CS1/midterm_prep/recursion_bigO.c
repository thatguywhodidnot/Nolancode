
#include <math.h>
#include <stdio.h>


int main(){

    float a; //number of recursive calls
    float n; //size of each recursive sub problem
    float d; //num of loops
    float b; //how much smaller recursixe problem is with each increment
    //ex: rec(int x){rec(x/2)}; b would = 2. for something like rec(int x){rec(x-1)} dont use master theorem;
    
    float nd = pow(n,d); //big o of loops in the function is n ^ d

    float n_b = n/b;
    //each recursion call is n/b
    printf("%d", (1%10));
    //master formula is time_complexity = 
    return 0;
}