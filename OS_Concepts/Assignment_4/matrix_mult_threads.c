#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

#define SIZE 1000
#define NUM_THREADS 2

typedef struct threadData{
    int** x;
    int** y;
    int** z;
    int start, end;
}threadData;
// in order to split the multiplying of the two matrices into two concurrent threads


void* multiply_section(void* arg){
    threadData* data = (threadData*)arg;
    int i,j,k;
    //using same method as single thread loop used each thread will go through only SIZE/numthreads rows of the array
    for (i = data->start; i < data->end; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                data->z[i][j] += data->x[i][k] * data->y[k][j];
            }
        }
    }
	return NULL;
};

void print_times(struct timeval multi_start,struct timeval multi_end, struct timeval single_start, struct timeval single_end){
    double multi_time =
    (multi_end.tv_sec - multi_start.tv_sec) +
    (multi_end.tv_usec - multi_start.tv_usec) / 1000000.0;

    double single_time =
        (single_end.tv_sec - single_start.tv_sec) +
        (single_end.tv_usec - single_start.tv_usec) / 1000000.0;

    printf("\nMulti-thread time: %f seconds\n", multi_time);
    printf("\nSingle-thread time: %f seconds\n", single_time);
}

int main() {
    int **A, **B, **C;
    int i, j, k;

    // Allocate memory for matrices
    A = malloc(SIZE * sizeof(int *));
    B = malloc(SIZE * sizeof(int *));
    C = malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        A[i] = malloc(SIZE * sizeof(int));
        B[i] = malloc(SIZE * sizeof(int));
        C[i] = malloc(SIZE * sizeof(int));
    }

    srand(time(NULL)); // Seed random number generator

    // Initialize matrices A and B with random numbers between 1 and 10
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i][j] = (rand() % 10) + 1;
            B[i][j] = (rand() % 10) + 1;
            C[i][j] = 0; // Initialize result matrix
        }
    }

    struct timeval multi_start, multi_end;
    struct timeval single_start, single_end;

    gettimeofday(&multi_start, NULL);
    //determine how much of the calulation each thread will do 
    int thread_size = SIZE/NUM_THREADS;
    //for each thread create a threaddata struct to store references to the arrays and start and end points
    threadData* thread_data = malloc(NUM_THREADS * sizeof(threadData));
    int start = 0;
    for(int i=0; i<NUM_THREADS; i++){
        thread_data[i].x = A;
        thread_data[i].y = B;
        thread_data[i].z = C;
        thread_data[i].start = start;
        thread_data[i].end = start + thread_size;
        start += thread_size;
    }
    //this line creates your threads using struct defined in pthreads library
    pthread_t threads[NUM_THREADS];
    //these loops start every thread on its concurrent task and then rejoins them when done
    for(int i=0; i<NUM_THREADS; i++){
        //this function is what actually starts the pthread_t struct previously created
        //for me to better understand the thread libray functions I put notes explaining what each parameter is
        pthread_create(&threads[i]/*thread created with pthreads_t struct*/, NULL/*default attribute settings*/,
             multiply_section/*function of thread*/, &thread_data[i]/*parameters for function of thread*/);
    }
    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    free(thread_data);
    
    gettimeofday(&multi_end, NULL);

    //multi-thread result
    printf("Sample 5x5 section of the multi-thread result matrix:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    gettimeofday(&single_start, NULL);

    // Multiply matrices A and B, store result in C
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    gettimeofday(&single_end, NULL);

    //single-thread result
    printf("\nSample 5x5 section of the sinlge-thread result matrix:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    print_times(multi_start, multi_end, single_start, single_end);

    // Free allocated memory
    for (i = 0; i < SIZE; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
