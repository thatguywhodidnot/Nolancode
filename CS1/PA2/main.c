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
    if(isEmpty(line)){
        return NULL;
    }
    
    return line->front->customer;

}

void print_customer(customer* customer, int base_time){

    printf("At time %d, %s left the counter from line %d.\n", base_time, customer->name, customer->line_num);

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

int find_earliest(queue* line_queue){
    int best = 12;
    for(int i=0; i<NUM_LINES; i++){
        
            customer* curr = peek(&line_queue[i]);
            
            if(curr != NULL){
                if(best == 12){
                    best = i;
                }
                else{
                    customer* compare = peek(&line_queue[best]);
                    if(curr->time_in < compare->time_in){
                            best = i;
                    }
                }
            }
        }
        return best;
}

int find_next_customer(queue* line_queue, int base_time){
    int best = 12;
    for(int i=0; i<NUM_LINES; i++){
        
        customer* curr = peek(&line_queue[i]);
        
        if(curr != NULL && curr->time_in <= base_time){
            if(best == 12){
                best = i;
            }
            else{
                customer* compare = peek(&line_queue[best]);
                
                if(curr->num_smoothies < compare->num_smoothies){
                    best = i; 
                }
                else if(curr->num_smoothies == compare->num_smoothies && curr->time_in < compare->time_in){
                    best = i;
                }
            }
        }   
    }
    return best;
}

void sort_and_print(queue* line_queue, int num_customers){

    int best, i, curr_time = 0;
    for(i=0; i<num_customers; i++){
        
        best = find_next_customer(line_queue, curr_time);
        
        if(best == 12){
            best = find_earliest(line_queue);
            curr_time = peek(&line_queue[best])->time_in;
            
        }

        customer* curr_customer = dequeue(&line_queue[best]);

        curr_time += 30 + (5 * curr_customer->num_smoothies);

        print_customer(curr_customer, curr_time);

        free(curr_customer->name);
        free(curr_customer);
    }


}

//add items to respective lines
void enqueue(queue* line_queue){
    
    node* temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->customer = create_customer();

    int line_num = temp->customer->line_num - 1;

    if(isEmpty(&line_queue[line_num])){
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

        sort_and_print(line_queue, num_customers);
        free(line_queue);
    }
    

}