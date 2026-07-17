#include "array_header.c"


//struct process{process_name, arrival_time, burst_time}
//timeval algo_start, algo_end

int main(){

	int num_process, i, j;

    scanf("%d", &num_process);

	gettimeofday(&algo_start, NULL);

    process* processes = init(num_process);
	
	for(i=0; i<num_process; i++){
		for(j=0; j<num_process; j++){
			if(processes[j].arrival_time > processes[j+1].arrival_time){
				swap(&processes[j], &processes[j+1]);
			}
		}
	}
	

	int count = 1, wait_time = 0, seconds; 
	float avg_wait, wait_total = 0;
	while(count < num_process){
		wait_time += processes[count].burst_time;
		wait_total += wait_time;
		count++;
	}
	for(i=0; i<num_process; i++){
		//convert to milliseconds
		seconds = (processes[i].burst_time * 1000);
		
		usleep(seconds);
	}


	gettimeofday(&algo_end, NULL);

	int time = 0;
	printf("\nGANTT\n\n");
	printf("%d", time);

	for (i = 0; i < num_process; i++) {
		time += processes[i].burst_time;
		printf(" -- %s -- %d", processes[i].process_name, time);
	}

	printf("\n");

	avg_wait = wait_total/num_process;
	float runtime = get_runtime(algo_start, algo_end);
	printf("\nAverage wait time for FCFS = %.2f ms\n", avg_wait);
	printf("FCFS runtime = %f ms\n", runtime * 1000);

    return 0;
}
