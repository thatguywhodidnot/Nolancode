#include <stdio.h>
#include <stdlib.h>
void quicksort(int *arr, int start, int end);
int pivot_locate(int *arr, int start, int end);

int main(void)
{
    int len;
    printf("how many values you sorting?");
    scanf("%d", &len);
    int *vals = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &vals[i]);
    }

    quicksort(vals, 0, len-1);

    printf("\n");
    for(int i = 0; i<len; i++){
        printf("%d ",vals[i]);
    }
    printf("\n\n");
    free(vals);
    return 0;
}

void quicksort(int *arr, int start, int end)
{
    if (end <= start)
        return;

    int pivot = pivot_locate(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
}
int pivot_locate(int *arr, int start, int end){
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++){
        if (arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;

    return i;
}