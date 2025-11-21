#include <stdlib.h>
#include <stdio.h>


void merge(int *left, int *right, int *arr, int arrlen);
void Mergesort(int *arr, int arrlen );

int main(void){
    int len;
    printf("how many values you sorting?");
    scanf("%d",&len);
    int *vals = malloc(len* sizeof(int));

    for(int i = 0; i<len; i++){
        scanf("%d",&vals[i]);
    }

    /*int vals[] = {};
    int len = sizeof(vals)/ sizeof(int);
    */
    Mergesort(vals, len);
        

    printf("\n");
    for(int i = 0; i<len; i++){
        printf("%d ",vals[i]);
    }
    printf("\n\n");
    free(vals);
    return 0;
}

void Mergesort(int *arr, int arrlen ){
    if (arrlen <=1){
        return;
    }
    // at each call split passed arr into 2 new arrs
    int L_len = arrlen/2;
    int R_len = arrlen - L_len;
    int *left = malloc(L_len * sizeof(int));
    int *right = malloc(R_len * sizeof(int));

    for(int i =0; i<L_len; i++){
        if (i< L_len){
            left[i] = arr[i];

        }
    }
    for(int i =0; i<R_len; i++){
        if (i< R_len){
            right[i] = arr[L_len+i];

        }
    
    }
    //recursive call of both created arrays
    Mergesort(left, L_len);
    Mergesort(right,R_len);
    // recursion loops through all array slices and sorts each, merge them all back again
    //to get the sorted original arr
    merge(left,right,arr, arrlen);
    
    free(left);
    free(right);

}

void merge(int *left, int *right, int *arr, int arrlen){
    int L_len = arrlen/2;
    int R_len = arrlen - L_len;
    int i=0,R=0,L= 0;
//sort values as main arr is recreated
    while(L<L_len && R<R_len){
        if (left[L]<right[R]){
            arr[i] = left[L];
            i++; L++;

        }
        else {
            arr[i] = right[R];
            i++; R++;
        }
    }
    //first while loop left out some values, these whiles catch them
    while(L<L_len){
        arr[i] = left[L];
            i++; L++;
    }
    while(R<R_len){
        arr[i] = right[R];
            i++; R++;
    }
}
