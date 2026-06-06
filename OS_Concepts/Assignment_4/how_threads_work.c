
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2

typedef struct ThreadData{
    int *arr;
    int start, end;
}ThreadData;

//the function detailing the work the threads will do is structured as follows
void* thread_work(void* arg){
    //void pointers are used in threads functions to allow them to take in a range of data types
    //in this example the data is a ThreadData struct so we write this line to specify that
    ThreadData* data = (ThreadData*)arg;
    for(int i=data->start; i<data->end; i++){
        data->arr[i] += 1;
    }
    
    
    return NULL;
}

//this code will create two threads one will ad a number to the first half of the list and the other to the second 
    //both threads will work at the same time (concurrently)
    /*
    each thread will need:
        a pointer to the array its working on
        its starting point
        and its ending point
    */
   //this is what threaddata struct is for
int main(){
    
    int arr[] = {1,2,3,4,5,6}, arr_len = 6, thread_size;
    
    thread_size = arr_len/NUM_THREADS;
    ThreadData* thread_data = malloc(NUM_THREADS * sizeof(ThreadData));
    int start = 0;
    for(int i=0; i<NUM_THREADS; i++){
        thread_data[i].arr = arr;
        thread_data[i].start = start;
        thread_data[i].end = start + thread_size;
        start += thread_size;
    }

    pthread_t threads[NUM_THREADS]; //this line creates your threads using struct defined in pthreads library
    
    for(int i=0; i<NUM_THREADS; i++){
        //this function is what actually starts the pthread_t struct previously created
        pthread_create(&threads[i]/*thread created with pthreads_t struct*/, NULL/*default attribute settings*/,
             thread_work/*function of thread*/, &thread_data[i]/*parameter for function of thread*/);
    }

    for(int i=0; i<NUM_THREADS; i++){
        
        pthread_join(threads[i], NULL);
    }

    free(thread_data);
    
    for(int i=0; i<arr_len; i++){
        
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}