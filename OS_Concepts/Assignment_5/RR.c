
#include "rr_header.c"

//easiest way I found to print the gantt for the linked list rr was to print processes as they are assigned and requeued in rr algo
float round_robin(queue* processes, int *num_process){
    
	int elapsed = 0, wait_time;
	float wait_total = 0;

    printf("\nGANTT\n\n");
    printf("%d", elapsed);

    //while there are still processes left in queue
    //do Quantum ms of process and if there is remaining time put back into queue
    //otherwise free the process
	while (processes->front != NULL) {

        process* curr_process = dequeue(processes);

        if(curr_process->remaining_time > QUANTUM){

            curr_process->remaining_time -= QUANTUM;
            elapsed += QUANTUM;
            printf(" -- %s -- %d", curr_process->process_name, elapsed);
            usleep(QUANTUM*1000);

            enqueue(curr_process, processes);
        }
        else{

            elapsed += curr_process->remaining_time;
            
            printf(" -- %s -- %d", curr_process->process_name, elapsed);

            usleep(curr_process->remaining_time*1000);

            curr_process->remaining_time = 0;
            wait_time = elapsed - curr_process->arrival_time - curr_process->burst_time;
            wait_total += wait_time;

            free(curr_process->process_name);
            free(curr_process);
        }
	}
    return wait_total/ *num_process;
}

int main(){

    int num_process, i, j;

    scanf("%d", &num_process);

    queue* processes = malloc(sizeof(queue));
    processes->front = NULL; processes->back = NULL;
    
    //start and end timval struct are passed into runtime function for algo runtimes
    gettimeofday(&algo_start, NULL);

    //for each process read in its info and enqueue it
    
    //originaly the enqueue function also did the scaning of process info 
    //this was moved to being done before the function  so that the rr function can requeue properly using the enqueue function
    for(i=0; i<num_process; i++){
        process* new_process = malloc(sizeof(process));
        new_process->next = NULL;
        new_process->process_name = malloc(NAME_SIZE * sizeof(char));
        scanf("%s %d %d", new_process->process_name, &new_process->arrival_time, &new_process->burst_time);
        new_process->remaining_time = new_process->burst_time;

        enqueue(new_process, processes);
    }
    float avg_wait = round_robin(processes, &num_process);
    gettimeofday(&algo_end, NULL);

	float runtime = get_runtime(algo_start, algo_end);
	printf("\n\nAverage wait time for RR = %.2f ms\n", avg_wait);
	printf("RR runtime = %f ms\n", runtime * 1000);

	

    return 0;
}
