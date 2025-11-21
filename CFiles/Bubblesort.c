#include <stdio.h>
#include <stdlib.h>

void Bubblesort(int *arr, int arrlen);

//sort arr by comparing from one end to another, comparing adjacent indexes to each other


void Bubblesort(int *arr, int arrlen){
    for(int j = 0;j<arrlen-1;j++){
        for(int i = 0;i<arrlen-j-1;i++){
            if (arr[i+1]<arr[i]){
            int tmp = arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=tmp; 
        }
        
        }
    }
}





int main(void){

    int len;
    printf("how many values you sorting?");
    scanf("%d",&len);
    int *vals = malloc(len* sizeof(int));

    for(int i = 0; i<len; i++){
        scanf("%d",&vals[i]);
    }

    Bubblesort(vals, len);
    printf("\n");
    for(int i = 0; i<len; i++){
        printf("%d ",vals[i]);
    }
    printf("\n\n");
    free(vals);
    return 0;


}