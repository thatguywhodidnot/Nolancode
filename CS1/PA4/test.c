
#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int l, int m, int r){

    int left_size = m-l+1;
    int right_size = r-m;
    
    int i, j, k;
    
    int* L = malloc(left_size*sizeof(int));
    int* R = malloc(right_size*sizeof(int));
    
    for(i=0; i<left_size; i++){
        L[i] = arr[i+l];
    }
    for(j=0; j<right_size; j++){
        R[j] = arr[m+1+j];
    }
    i = 0; j = 0; k = l;  
    while(i < left_size && j < right_size){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<left_size){
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j<right_size){
        arr[k] = R[j];
        k++;
        j++;
    }
    free(L); free(R);
}

void mergeSort(int* arr, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    
}


int main(){
    int arr[] = {5,6,7,8,1,3,2,4};
    int arr_size = 8;
    
    mergeSort(arr, 0, arr_size-1);
    
    for(int i=0; i<arr_size; i++){
        printf("%d", arr[i]);
    }

    return 0;
}