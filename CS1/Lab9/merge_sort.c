#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int* arr, int L, int M, int R){
    int L_size = M - L + 1;
    int R_size = R - M;

    int* L_arr = malloc(L_size*sizeof(int));
    int* R_arr = malloc(R_size*sizeof(int));

    for(int i=0; i<L_size; i++){
        L_arr[i] = arr[L + i];
    }
    for(int i=0; i<R_size; i++){
        R_arr[i] = arr[M + 1 + i];
    }

    int i = 0; int j = 0; int k = L;
    while(i<L_size && j<R_size){
        if(L_arr[i] < R_arr[j]){
            arr[k] = L_arr[i];
            i++; k++;
        }
        else{
            arr[k] = R_arr[j];
            j++; k++;
        }
    }
    while(i<L_size){
        arr[k] = L_arr[i];
        i++; k++;
    }
    while(j<R_size){
        arr[k] = R_arr[j];
        j++; k++;
    }


    free(L_arr); free(R_arr);
}

void merge_sort(int* arr, int L, int R){
    if(R > L){
        int M = (R + L)/2;
        merge_sort(arr, L, M);
        merge_sort(arr, M+1, R);

        merge(arr, L, M, R);
    }
};

void print_arr(int* arr, int arr_size){
    for(int i=0; i<arr_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

long timediff(clock_t t1, clock_t t2) {
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed; 
}

int main(){
    clock_t start, end;
    
    int arr[] = {1,56,7,23,4,78,2,3};
    int arr_size = sizeof(arr)/sizeof(int);

    print_arr(arr, arr_size);
    
    start = clock();
    merge_sort(arr, 0, arr_size-1);
    end = clock();

    long elapsed = timediff(start, end);

    print_arr(arr, arr_size);
    printf("merge sort sorting time for array of size %d: \n %ld milliseconds\n", arr_size, elapsed);

    return 0;
}
