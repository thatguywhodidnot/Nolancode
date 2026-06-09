#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 15

typedef struct customer{
    char* name;
    int time_in, line_num, num_smoothies;
}customer;

typedef struct node{
    customer* customer;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* back;
}queue;

//add item
void enqueue(queue* line_queue){
    char name[MAX_STR];
    int t, m, x;

    node* temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->customer = malloc(sizeof(customer));
    
    scanf("%d %d %s %d", &t, &m, name, &x);
    
    temp->customer->time_in = t;
    temp->customer->line_num = m;
    temp->customer->num_smoothies = x;
    
    temp->customer->name = malloc((strlen(name)+1) * sizeof(char));
    strcpy(temp->customer->name,name);

    if(line_queue->front == NULL){
        line_queue->front = temp;
        line_queue->back = temp;
    }
    else if(line_queue->front == line_queue->back){
        line_queue->back->next = temp;
        line_queue->back = temp;
    }
    else{
        node* compare = line_queue->front;

        while(compare->customer->num_smoothies < temp->customer->num_smoothies){
            compare =compare->next;
        }
        temp->next = line_queue->front->next;
        line_queue->front->next = temp;
        

    }
}

void print_queue(queue* line_queue){
    node* customer = line_queue->front;
    
    int count = 1;

    printf("\n");
    while(customer){
        printf("customer %d  is %s\n", count, customer->customer->name);
        customer = customer->next;
        count++;
    }

}

void init(queue* line_queue){

    line_queue->front = NULL;
    line_queue->back = NULL;

    int num_customers, i;
    scanf("%d", &num_customers);

    
    for(i=0; i<num_customers; i++){
        enqueue(line_queue);    
    }
}



//check if list empty
int isEmpty(queue* line_queue){
    return line_queue->front == NULL;
}

// //remove item
// void dequeue();

// //get front of list
// int peek();

int main(){

    int num_tests, i;
    scanf("%d", &num_tests);

    queue* line_queue = malloc(sizeof(queue));

    for(i=0; i<num_tests; i++){
        init(line_queue);
        print_queue(line_queue);
    }

}