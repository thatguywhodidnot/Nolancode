#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>

#define NAME_SIZE 3

struct timeval algo_start, algo_end;

//each process will have a name, arrivaltime, and a burst time
typedef struct process{

    int arrival_time, burst_time;
    char* process_name;

}process;

float get_runtime(struct timeval start_time, struct timeval end_time){
    return (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
}

process* init(int num_process){
	
	int i;

    process* processes = malloc(num_process * sizeof(process));

    
    //printf("format: process_name arrival_time burst_time\n\n");

    for(i=0; i<num_process; i++){

        processes[i].process_name = malloc(NAME_SIZE * sizeof(char));
        scanf("%s %d %d", processes[i].process_name, &processes[i].arrival_time, &processes[i].burst_time);
        
    }

    return processes;
}

void swap(process* p1, process* p2){
	
	process temp = *p1;
	*p1 = *p2;
	*p2 = temp;

}