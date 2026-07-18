#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
//#include "leak_detector_c.h"


// Nolan Milligan Programming assignment 4

typedef struct pos{
    int x, y;
}pos;

pos my_pos;

float calc_distance(pos pos1, pos pos2){
    float dx = pos1.x - pos2.x; float dy = pos1.y - pos2.y;
    return (sqrt(pow(dx,2)+pow(dy,2)));
}

int compareTo(pos* pos1, pos* pos2){
//shops will be compared based on their distance from the my_pos stuct
    float dist1 = calc_distance(*pos1, my_pos);
    float dist2 = calc_distance(*pos2, my_pos);
//if ptr1 comes first return -1, if ptr2 comes first return 1, if they are equal return 0
    if(dist1 < dist2){
        return -1;
    }
    else if(dist1 > dist2){
        return 1;
    }

    if(pos1->x < pos2->x){
        return -1;
    }
    else if(pos1->x > pos2->x){
        return 1;
    }

    if(pos1->y < pos2->y){
        return -1;
    }
    else if(pos1->y > pos2->y){
        return 1;
    }

    return 0;
}

void merge(pos* arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    //create and fill a left and right array
    pos* L = malloc(n1 * sizeof(pos));
    pos* R = malloc(n2 * sizeof(pos));

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }

    i = 0; j = 0; k = l;  
    //combine arrays into arr
    while (i < n1 && j < n2){
        
        if (compareTo(&L[i], &R[j]) != 1){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //cleanup for extra values
    while (i < n1){
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++; k++;
    }

    free(L); free(R);
}

void merge_insert(pos* arr, int l, int r, int t){
    //t is threshold
    if(l < r){
        int size = r - l + 1;
        //threshold check
        if(size > t){
            int m = (l+r)/2;
            merge_insert(arr, l, m, t);
            merge_insert(arr, m+1, r, t);
            merge(arr, l, m, r);
        }
        //quicksort logic snippet for <= threshold
        //modified int arr quicksort algo to work with pos structs
        else{
            int i, j;
            pos tmp;
            float num;
            for(i=(l+1); i<=r; i++){
                //tmp added to properly reset arr[j+1] 
                tmp = arr[i]; 
                for(j=(i-1); j>=l && compareTo(&arr[j], &tmp) > 0; j--){
                        arr[j+1] = arr[j];
                }
                arr[j+1] = tmp;
            }
        }
    }
}

pos* ReadData(int num_pos){
    //will be used to read both shop positions and points 
    //since both are arrays of pos structs
    pos* positions = malloc(num_pos* sizeof(pos));

    int x, y;
    for(int i=0; i<num_pos; i++){
        scanf("%d %d", &x, &y);
        positions[i].x = x;
        positions[i].y = y;
    }
    return positions;
}

void print_shops(pos* shops, int num_shops){
    
    for(int i=0; i<num_shops; i++){
        printf("%d %d\n", shops[i].x, shops[i].y);
    }
}

int BinarySearch(pos* shops, pos* point, int num_shops){
    //used to find the rank of a position if it exists in the sorted array
    //rank will be index + 1
    int l=0; int h = num_shops-1; int mid;

    while(l<=h){
        mid = (l+h)/2;
        if(compareTo(&shops[mid], point) == 0){
            return mid;
        }
        else if(compareTo(&shops[mid], point) == -1){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return -1;

}

int main(){
    //atexit(report_mem_leak);
    
    int num_shops, num_points, t;

    scanf("%d %d %d %d %d", &my_pos.x, &my_pos.y, &num_shops, &num_points, &t);

    pos* shops = ReadData(num_shops);
    pos* points = ReadData(num_points);

    merge_insert(shops, 0, num_shops-1, t);

    print_shops(shops, num_shops);
    
    int rank;
    for(int i=0; i<num_points; i++){
        rank = BinarySearch(shops, &points[i], num_shops);
        
        printf("%d %d ", points[i].x, points[i].y);

        if(rank == -1){
            printf("not found\n");
        }
        else{
            printf("found at rank %d\n", (rank+1));
        }
    }

    free(shops); free(points);

    return 0; 
}