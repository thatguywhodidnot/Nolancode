#include <stdio.h>
#include <stdlib.h>
#define ARRLEN 5

typedef struct node{
    struct node* next;
    int val;
}node;

node* init_node(int val){
    node* new_node = malloc(sizeof(node));
    new_node->next = NULL;
    new_node->val = val;

    return new_node;
}

void free_node(node* node){
    free(node);
}

int pop_node(node** top){
    
    node* tmp = *top;
    int val = tmp->val;
    *top = (*top)->next;
    free_node(tmp);

    return val;

}

node* create_stack(int* num_list){
    node* top = NULL;
    for(int i=0; i<ARRLEN; i++){
        node* tmp = init_node(num_list[i]);
        tmp->next = top;   
        top = tmp;
    }
    return top;
}

void print_stack(node* top){
    node* tmp = top;
    printf("\nCurrent Stack\n");
    while (tmp != NULL){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(){

    int num_list[ARRLEN] = {1,2,3,4,5};
    node* top = create_stack(num_list);
    print_stack(top);
    int popped = pop_node(&top);
    printf("%d was popped from the stack\n", popped);
    print_stack(top);

    return 0; 
}