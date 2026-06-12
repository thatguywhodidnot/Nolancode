#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LINES 12
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

//check if a line is empty
int isEmpty(queue* line){
    return line->front == NULL;
}



customer* peek(queue* line){
    
    return line->front->customer;

}

void print_customer(customer* customer, int base_time){

    printf("At time %d, %s left the counter from line %d.\n", base_time, customer->customer->name, customer->customer->line_num);

}

//remove item
customer* dequeue(queue* line){

    node* temp = line->front;
    customer* customer = temp->customer;

    line->front = line->front->next;
    if(isEmpty(line)){
        line->back = NULL;
    }
    
    free(temp);
    return customer;

}
//combine these functions??
int find_least_smoothie(queue* line_queue, int base_time){
    int best = 12;
    for(int i=0; i<NUM_LINES; i++){
        
        customer* curr = peek(&line_queue[i]);
        
        if(curr != NULL && curr->time_in <= base_time){
            if(best == 12){
                best = i;
            }
            
        }
        
    }
    

}

// int find_earliest(){}

void sort_and_print(queue* line_queue){

    int best, curr_time = 0;
    best = find_least_smoothie(line_queue);
    if(best = 12){
        best = find_earliest();
    }

    customer* curr_customer = dequeue(&line_queue[best]);

    print_customer(curr_customer, curr_time);


}

//add items to respective lines
void enqueue(queue* line_queue){
    
    node* temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->customer = create_customer();

    int line_num = temp->customer->line_num - 1;

    if(line_queue[line_num].front == NULL){
        line_queue[line_num].front = temp;
        line_queue[line_num].back = temp;
    }
    else {
        line_queue[line_num].back->next = temp;
        line_queue[line_num].back = temp;
    }
}

int init(queue* line_queue){
    for(int i=0; i<NUM_LINES; i++){
        line_queue[i].front = NULL;
        line_queue[i].back = NULL;
    }
    

    int num_customers, i;
    scanf("%d", &num_customers);

    
    for(i=0; i<num_customers; i++){
        enqueue(line_queue);    
    }
    return num_customers;
    

}

// stiil need
// find best line function to be written logically

int main(){

    int num_tests, num_customers, i, j, base_time = 0;
    scanf("%d", &num_tests);

    for(i=0; i<num_tests; i++){
        queue* line_queue = malloc(NUM_LINES * sizeof(queue));

        num_customers = init(line_queue);

        sort_and_print(line_queue);

    }
    free(line_queue);

}