#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>
#define NUM_THREADS 1000


typedef struct ThreadData {
	int count;
	pthread_mutex_t lock;
}ThreadData;

void* increment(void* arg){
	ThreadData* data = (ThreadData*)arg;
	for(int i=0; i<1000; i++){
		//mutex lock will not be modifyable by this thread  until the one using it prior unlocks it		
		//once another thread unlocks then lock for current thread to use 
		pthread_mutex_lock(&data->lock);
		data->count++;
		//once the thread is done using crit section unlock for next thread
		pthread_mutex_unlock(&data->lock);
		
	}

	return NULL;	
}

int main(){
	ThreadData count = {0};	
	pthread_t threads[NUM_THREADS];
	//initialize the mutex in unlocked state for the first thread
	pthread_mutex_init(&count.lock, NULL);

	for(int i=0; i<NUM_THREADS; i++){
		pthread_create(&threads[i], NULL, increment, &count);
	}
	for(int i=0; i<NUM_THREADS; i++){
		pthread_join(threads[i], NULL);
	}
	
	printf("%d", count.count);
	//destroys the initialized mutex
	pthread_mutex_destroy(&count.lock);
	return 0;
}
