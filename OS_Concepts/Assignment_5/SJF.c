#include "array_header.c"


//struct process{process_name, arrival_time, burst_time}
//timeval algo_start, algo_end



int main(){

	int num_process, i, j;

    scanf("%d", &num_process);

	gettimeofday(&algo_start, NULL);

    process* processes = init(num_process);
	
	//nested loop to sort process array by burst times
	for(i=0; i<num_process - 1; i++){
		for(j=0; j<num_process - i -1; j++){
			if(processes[j].burst_time > processes[j+1].burst_time){
				swap(&processes[j], &processes[j+1]);
			}
		}
	}


	int count = 1, wait_time = 0, seconds; 
	int elapsed = processes[0].burst_time;
	float avg_wait, wait_total = 0;
	//while loop will calculate the total ms that processes had to wait for the calculation of avg wait
	while (count < num_process) {
		wait_total += elapsed;              
		elapsed += processes[count].burst_time;
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
	//gantt chart output of process execution order
	for (i = 0; i < num_process; i++) {
		time += processes[i].burst_time;
		printf(" -- %s -- %d", processes[i].process_name, time);
	}

	printf("\n");

	avg_wait = wait_total/num_process;
	float runtime = get_runtime(algo_start, algo_end);
	printf("\nAverage wait time for SJF = %.2f ms\n", avg_wait);
	printf("SJF runtime = %f ms\n", runtime * 1000);


    return 0;
}
