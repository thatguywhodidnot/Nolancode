
#define NAME_SIZE 3

//each process will have a name, arrivaltime, and a burst time
typedef struct process{

    int arrival_time, burst_time;
    char* process_name;

}process;

process* init(){
    
    int num_process, i, time_quantum;

    scanf("%d", &num_process);

    process* processes = malloc(num_process * sizeof(process));

    printf("\nPROCESSES\n\n");
    //printf("format: process_name arrival_time burst_time\n\n");

    for(i=0; i<num_process; i++){

        processes[i].process_name = malloc(NAME_SIZE * sizeof(char));
        scanf("%s %d %d", processes[i].process_name, &processes[i].arrival_time, &processes[i].burst_time);
        printf("%s - %d - %d\n", processes[i].process_name, processes[i].arrival_time, processes[i].burst_time);
    }

    return processes;
}
