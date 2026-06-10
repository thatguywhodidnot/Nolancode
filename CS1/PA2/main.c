#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 15
#define EMPTY -1

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

customer* create_customer(){
    char name[MAX_STR];
    int t, m, x;

    customer* customer = malloc(sizeof(customer));
    
    scanf("%d %d %s %d", &t, &m, name, &x);
    
    customer->time_in = t;
    customer->line_num = m;
    customer->num_smoothies = x;
    
    customer->name = malloc((strlen(name)+1) * sizeof(char));
    strcpy(customer->name,name);
    return customer;
}

//add item
void enqueue(queue* line_queue){
    
    node* temp = malloc(sizeof(node));
    temp->next = NULL;

    temp->customer = create_customer();

    if(line_queue->front == NULL){
        line_queue->front = temp;
        line_queue->back = temp;
    }
    else if(line_queue->front == line_queue->back){
        line_queue->back->next = temp;
        line_queue->back = temp;
    }
    else{
        node* compare = line_queue->front->next;
        node* prev = line_queue-> front;

        while(compare != NULL && (compare->customer->num_smoothies < temp->customer->num_smoothies || 
        (compare->customer->num_smoothies == temp->customer->num_smoothies && compare->customer->time_in < temp->customer->time_in))){
            prev = compare;
            compare = compare->next;
        }
        temp->next = compare;
        prev->next = temp;
        

    }
}

void print_queue(queue* line_queue){
    node* customer = line_queue->front;
    
    int count = 1, base_time = 0;

    while(customer){
        if(base_time < customer->customer->time_in){
            base_time = customer->customer->time_in;
        }
        base_time += (30 + (5 * customer->customer->num_smoothies));
        printf("At time %d, %s left the counter from line %d.\n", base_time, customer->customer->name, customer->customer->line_num);
        customer = customer->next;
        count++;
    }
}

//remove item
void dequeue(queue* line_queue){

    if(line_queue->front == NULL){
        return;
    }

    node* temp = line_queue->front;
    line_queue->front = line_queue->front->next;

    free(temp->customer->name);
    free(temp->customer);
    free(temp);

}

void init(queue* line_queue){

    line_queue->front = NULL;
    line_queue->back = NULL;

    int num_customers, i;
    scanf("%d", &num_customers);

    
    for(i=0; i<num_customers; i++){
        enqueue(line_queue);    
    }
    print_queue(line_queue);
    for(i=0; i<num_customers; i++){
        dequeue(line_queue);    
    }

}



//check if list empty
int isEmpty(queue* line_queue){
    return line_queue->front == NULL;
}



// //get front of list
// int peek();

// stiil need
// - array of 12 queues
// - peek() function
// - dequeue should return customer, not free customer
// - processing should choose among 12 line fronts
// - avoid accessing queue internals outside queue functions

int main(){

    int num_tests, i, base_time = 0;
    scanf("%d", &num_tests);

    queue* line_queue = malloc(sizeof(queue));

    for(i=0; i<num_tests; i++){
        init(line_queue);
    }
    free(line_queue);

}