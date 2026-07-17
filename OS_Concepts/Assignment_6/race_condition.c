#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>
#define NUM_THREADS 10000


typedef struct ThreadData {
	int count;
}ThreadData;

void* increment(void* arg){
	ThreadData* data = (ThreadData*)arg;
	for(int i=0; i<1000; i++){
		data->count++;	
	}
	return NULL;	
}

int main(){
	ThreadData count = {0};	
	pthread_t threads[NUM_THREADS];

	for(int i=0; i<NUM_THREADS; i++){
		pthread_create(&threads[i], NULL, increment, &count);
	}
	for(int i=0; i<NUM_THREADS; i++){
		pthread_join(threads[i], NULL);
	}
	
	printf("%d", count.count);
	return 0;
}
