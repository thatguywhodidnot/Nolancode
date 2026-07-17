#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define THRESHOLD 25
#define maxVal 1000

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){
    int i, j,temp;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){//then swap
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionSort(int arr[], int n){
    int i, item, j;

    for (i = 1; i < n; i++){
        item = arr[i];
        /*
         * Move elements of arr[0..i-1] that are
         * greater than item one position ahead
         * of their current position.
         */
        for (j = i - 1; j >= 0; j--){
            if (arr[j] > item){
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j + 1] = item;
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* Create temp arrays */
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    /* Merge the temp arrays back into arr[l..r] */
    i = 0;  // Initial index of first subarray
    j = 0;  // Initial index of second subarray
    k = l;  // Initial index of merged subarray

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        // Get the midpoint
        int m = (l + r) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // printf("Testing l=%d r=%d m=%d\n", l, r, m);
        merge(arr, l, m, r);
    }
}

void merge_insert(int arr[], int l, int r, int t){
    //t is threshold
    if(l < r){
        int size = r - l + 1;
        if(size > t){
            int m = (l+r)/2;
            merge_insert(arr, l, m, t);
            merge_insert(arr, m+1, r, t);
            merge(arr, l, m, r);
        }
        else{
            int i, j, num;
            for(i=(l+1); i<=r; i++){
                num = arr[i];
                for(j=(i-1); j>=l; j--){
                    if(arr[j]> num){
                        arr[j+1] = arr[j];
                    }
                    else{
                        break;
                    }
                }
                arr[j+1] = num;
            }
        }
    }
}

int partition(int *vals, int low, int high){
    // Pick a random partition element and swap it into index low.
    int i = low + rand() % (high - low + 1);
    swap(&vals[low], &vals[i]);
    int lowpos = low; // Here is where our pivot is located.
    low++; // Our starting point is after the pivot.
    // Run the partition so long as the low and high counters don't cross.
    while (low <= high){
        // Move the low pointer until we find a value too large for this side.
        while (low <= high && vals[low] <= vals[lowpos]){
            low++;
        }
        // Move the high pointer until we find a value too small for this side.
        while (high >= low && vals[high] > vals[lowpos]){
            high--;
        }
        // Now that we've identified two values on the wrong side, swap them.
        if (low < high){
            swap(&vals[low], &vals[high]);
        }
    }
    // Swap the pivot element into its correct location.
    swap(&vals[lowpos], &vals[high]);

    return high; // Return the partition point.
}

void quickSort(int *numbers, int low, int high){
    // Only have to sort if we are sorting more than one number.
    if (low < high){
        int split = partition(numbers, low, high);

        quickSort(numbers, low, split - 1);
        quickSort(numbers, split + 1, high);
    }
}

void selectionSort(int arr[], int n){
    int i, j, min_idx, temp;

    // One by one move boundary of unsorted subarray.
    for (i = 0; i < n - 1; i++){
        // Find the minimum element in unsorted array.
        min_idx = i;

        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element.
        swap(&arr[i], &arr[min_idx]);

    }
}

long timediff(clock_t t1, clock_t t2) {
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}

void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
        printf("\n");
    }
}

int main(){
    clock_t start, end;

    int arr_size, i, j;
    for(i=0; i<6; i++){
        arr_size = (1000*(i+1));
        int* arr = malloc(arr_size*sizeof(int));
        for(j=0; j<arr_size; j++){
            arr[j] = rand() % maxVal + 1;
        }
        int* copy = malloc(arr_size*sizeof(int));
        long runtime;
        
        memcpy(copy, arr, arr_size*sizeof(int)); 
        start = clock();
        merge_insert(copy, 0, arr_size-1, THRESHOLD);
        end = clock();
        runtime = timediff(start, end);
        printf("Sorting %d values will take %ld milliseconds for Merge-Insert Sort\n", arr_size, runtime);
        
        memcpy(copy, arr, arr_size*sizeof(int));
        start = clock();
        mergeSort(copy, 0, arr_size-1);
        end = clock();
        runtime = timediff(start, end);
        printf("Sorting %d values will take %ld milliseconds for Merge Sort\n", arr_size, runtime);

        memcpy(copy, arr, arr_size*sizeof(int)); 
        start = clock();
        insertionSort(copy, arr_size);
        end = clock();
        runtime = timediff(start, end);
        printf("Sorting %d values will take %ld milliseconds for Insertion Sort\n", arr_size, runtime);

        memcpy(copy, arr, arr_size*sizeof(int));
        start = clock();
        selectionSort(copy, arr_size);
        end = clock();
        runtime = timediff(start, end);
        printf("Sorting %d values will take %ld milliseconds for Selection Sort\n", arr_size, runtime);

        memcpy(copy, arr, arr_size*sizeof(int)); 
        start = clock();
        quickSort(copy, 0, arr_size-1);
        end = clock();
        runtime = timediff(start, end);
        printf("Sorting %d values will take %ld milliseconds for Quick Sort\n", arr_size, runtime);

        memcpy(copy, arr, arr_size*sizeof(int)); 
        start = clock();
        bubbleSort(copy, arr_size);
        end = clock();
        runtime = timediff(start, end);
        printf("Sorting %d values will take %ld milliseconds for Buubble Sort\n", arr_size, runtime);

        free(arr); free(copy);
        printf("\n");
    
    }

    
    


    return 0;
}