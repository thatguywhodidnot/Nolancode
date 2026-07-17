// Arup Guha
// 6/20/07
// Written in COP 3502 to illustrate an array implementation of a stack.
//modified by Tanvir Ahmed 6/1/2020

//Modified by Adam Betinsky on 2/3/2025 to save time while doing Lab #7
//UPDATED ON 2/4/2025 to allow for a character stack instead of an integer stack
//Updated again on 10/2/2025 to account for issues encountered by students

//Lab #7: Stack Implementation Skeleton Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //needed for isdigit

// The array will store the items in the stack, first in
// index 0, then 1, etc. top will represent the index
// to the top element in the stack. If the stack is
// empty top will be -1.

#define SIZE 100
#define EMPTY -1

struct stack 
{
    char items[SIZE];
    int top;
};

//Provided functions
void initialize(struct stack* stackPtr);
int full(struct stack* stackPtr);
int push(struct stack* stackPtr, char value);
int empty(struct stack* stackPtr);
char pop(struct stack* stackPtr);
int peek(struct stack* stackPtr);

//---------------------------------------------
//Functions you need to complete (in addition to main)
int checkBalance(char exp[]);
int priority(char ch);
int isOperator(char ch);
char *infixToPostfix(char infix[]);
int isParentheses(char ch1);

int main() 
{   
    char exp[SIZE];
    printf("Enter Expression: ");
    
    scanf("%[^\n]s", exp);

    printf("Your input expression: %s\n", exp);
    printf("Checking balance...\n");

    int Balance = checkBalance(exp);
    if(Balance == 1){
        char *postfix = infixToPostfix(exp);
        printf("the postfix is: %s\n", postfix);

        free(postfix);
    }
    

    return 0;
}

void initialize(struct stack* stackPtr) 
{
    stackPtr->top = -1;
}

// If the push occurs, 1 is returned. If the
// stack is full and the push can't be done, 0 is
// returned.
int push(struct stack* stackPtr, char value) 
{
    // Check if the stack is full.
    if (full(stackPtr))
        return 0;

    // Add value to the top of the stack and adjust the value of the top.
    stackPtr->items[stackPtr->top+1] = value;
    (stackPtr->top)++;
    return 1;
}

// Returns true iff the stack pointed to by stackPtr is full.
int full(struct stack* stackPtr) 
{
    return (stackPtr->top == SIZE - 1);
}

// Returns true iff the stack pointed to by stackPtr is empty.
int empty(struct stack* stackPtr) 
{
    return (stackPtr->top == -1);
}

// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is popped and returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
char pop(struct stack* stackPtr)
{
    char retval;

    // Check the case that the stack is empty.
    if (empty(stackPtr))
        return 'I';

    // Retrieve the item from the top of the stack, adjust the top and return
    // the item.
    retval = stackPtr->items[stackPtr->top];
    (stackPtr->top)--;
    return retval;
}

// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
int peek(struct stack* stackPtr) 
{
    // Take care of the empty case.
    if (empty(stackPtr))
        return EMPTY;

    // Return the desired item.
    return stackPtr->items[stackPtr->top];
}

/*
 * -------------------------------------------------------------------
 *
 * This marks the start of the functions you must complete
 */

int checkBalance(char exp[]){
    struct stack myStack;

    initialize(&myStack);

    int i, val = 0;
    for(i=0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(&myStack, exp[i]);
        }
        else if(exp[i] == ')'){
            char a = pop(&myStack);
            if(a == 'I' || a != '('){
                printf("INVALID for )!!!\n");
                return val;
            }

        }
        else if(exp[i] == '}'){
            char a = pop(&myStack);
            if(a == 'I' || a != '{'){
                printf("INVALID for }!!!\n");
                return val;
            }

        }
        else if(exp[i] == ']'){
            char a = pop(&myStack);
            if(a == 'I' || a != '['){
                printf("INVALID for ]!!!\n");
                return val;
            }

        }
    }
    if(pop(&myStack) != ){
        printf("INVALID. You have extra!!\n");

    }

    printf("VALID\n");
    
    return 1;
}

int priority(char ch)
{

}

int isOperator(char ch)
{

}

char *infixToPostfix(char infix[])
{

}

int isParentheses(char ch1)
{

}
