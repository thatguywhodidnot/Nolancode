#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100


typedef struct stack{
    char items[SIZE];
    int top;
}stack;

int checkBalance(char exp[]){
    stack myStack;
    int i, val = 1;
    for(i=0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            val ++;
        }
        else if(exp[i] == ')'){
            val--;
        }
    }
    if(val != 1){
        val = 0;
    }
    return val;
}


int main(){
    char exp[SIZE];
    scanf("%s", exp);
    int Balance = checkBalance(exp);
    printf("%d\n", Balance);
    return 0;
}