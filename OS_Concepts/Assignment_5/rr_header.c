#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>

#define NAME_SIZE 3
#define QUANTUM 5

struct timeval algo_start, algo_end;

//each process will have a name, arrivaltime, and a burst time
// because this is the linked list implementation for tracking the processes we will also store a pointer to the next process in line
typedef struct process{

    int arrival_time, burst_time, remaining_time;
    char* process_name; 
    struct process* next;


}process;

//this struct will store which proces is at the front and back of the queue
typedef struct queue{
    process* front;
    process* back;
}queue;

//runtime calc function 
float get_runtime(struct timeval start_time, struct timeval end_time){
    return (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
}

//if queue is empty new process is assign to front and back of queue
//if the queue has only one value addnew process to the end and point front next to new process
//if the queue already has multiple values just insertt at back
void enqueue(process* new_process, queue* processes){

    if(processes->front == NULL && processes->back == NULL){
        processes->front = new_process;
        processes->back = new_process;
    }
    else if(processes->front == processes->back){
        processes->back = new_process;
        processes->front->next = new_process;
    }
    else{
        processes->back->next = new_process;
        processes->back = new_process;
    }
}

//remove front process from queue and return it
process* dequeue(queue* processes){

    process* temp = processes->front;
    processes->front = processes->front->next;
    
    if (processes->front == NULL) {
        processes->back = NULL;
    }

    temp->next = NULL;
    return temp;
}


