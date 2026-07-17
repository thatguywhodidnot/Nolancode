#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 20


// COP 3502C Assignment 3
// This program is written by: Nolan Milligan

typedef struct store{
    float x, y;
    char* name;
}store;

typedef struct distance{
    //store a and b will be the indexes of the two store in stores array
    int storeA;
    int storeB;       
    float distance;
}distance;

float calc_distance(float xA, float yA, float xB, float yB){
    float dx = xA - xB; float dy = yA - yB;
    return (sqrt(pow(dx,2)+pow(dy,2)));

}

void dist_perm(int* used, int* perm, int count, int reduce, int num_stores, int* dist_count, store* stores, distance* distances){

    if (count == 2){
        //for each unique tore pair calc and store distance
        distances[*dist_count].distance = calc_distance(stores[perm[0]].x, stores[perm[0]].y, stores[perm[1]].x, stores[perm[1]].y);
        distances[*dist_count].storeA = perm[0]; distances[*dist_count].storeB = perm[1];
       
        (*dist_count)++;
        return;
    }
    else{
        //main perm logic
        //reduce is used to ensure pairs are not repeated
        for(int i=reduce; i<num_stores; i++){
            if(used[i] == 0){
                perm[count] = i;
                used[i] = 1;
                dist_perm(used, perm, count+1, i+1, num_stores, dist_count, stores, distances);
                used[i] = 0;
            }
        }
    }
}

distance* best_distances(
    distance* distances, int num_best_dist, int num_distances
){
    distance* best_distances = malloc(num_best_dist*sizeof(distance));

    int* used = calloc(num_best_dist*2, sizeof(int));

    //these count variables will make sure that only num_pairs amount of distances are in final array
    int current_spot = 0; 
    int current_best_spot = 0;
    float current_best_dist;
    int best_index;
    //loop to get num_pairs ditances into array
    while(current_best_spot < num_best_dist){
        while (current_spot < (num_best_dist*2) && used[current_spot] == 1){
            current_spot++;
        }
        //first distance will be tested against 1000
        current_best_dist = 1000;
        best_index = -1;

        for(int i=0; i<num_distances; i++){
            int curr_a = distances[i].storeA;
            int curr_b = distances[i].storeB;

            //check if the stores have been used alrady using their indexes
            //if so skip the pair
            bool check1 = (used[curr_a] == 1 || used[curr_b] == 1);
            bool check2 = (curr_a != current_spot && curr_b != current_spot);
            
            if(check1 || check2){
                continue;
            }
            if(distances[i].distance < current_best_dist){
                current_best_dist = distances[i].distance;
                best_index = i;
            }

        }

        if(best_index != -1){
            //if a best distance was found it is added to return array
            best_distances[current_best_spot] = distances[best_index];

            //and then marked as used
            int curr_a = distances[best_index].storeA;
            int curr_b = distances[best_index].storeB;
            used[curr_a] = 1;
            used[curr_b] = 1;

            current_best_spot++;
        }
        current_spot++;
    }
    free(used);
    return best_distances;
}

void print_distances(distance* distances, store* stores, int num_dist){
    //function will calulate total dist and print formatted output
    float total_dist = 0;
    for(int i=0; i<num_dist; i++){
        total_dist += distances[i].distance;
    }
    printf("%.3f\n", total_dist);
    for(int i=0; i<num_dist; i++){
        int a = distances[i].storeA, b = distances[i].storeB;
        float curr_dist = distances[i].distance;
        printf("(%s, %s, %.3f)\n", stores[a].name, stores[b].name, curr_dist);

    }
}

int main(){

    int num_cases;
    scanf("%d", &num_cases);
    for(int i=0; i<num_cases; i++){
        //integer inits
        int num_pairs; scanf("%d", &num_pairs);
        int num_stores = num_pairs*2;
        int *used = calloc(num_stores, sizeof(int));
        int *perm = malloc(2*sizeof(int));

        //store info initialization
        store* stores = malloc(num_stores*sizeof(store));
        char storename[MAX_NAME];
        for(int i=0; i<num_stores; i++){
            scanf("%f %f %s", &stores[i].x, &stores[i].y, storename);
            stores[i].name = malloc((strlen(storename))*sizeof(char));
            strcpy(stores[i].name, storename);
        }

        //distance array init 
        int num_distances = (num_stores*(num_stores-1))/2;
        distance* distances = malloc(num_distances*sizeof(distance));
        int dist_count = 0;
        //perm that gives all unique ordered pairs
        dist_perm(used, perm, 0, 0, num_stores, &dist_count, stores, distances);
        //sorts permed array and returns new num_pair-sized best distances arr
        distance* best = best_distances(distances, num_pairs, num_distances);
        
        print_distances(best, stores, num_pairs);        

        for(int i=0; i< num_stores; i++){
            free(stores[i].name);
        }
        free(stores);
        free(distances);
        free(perm);
        free(used);
        free(best);
    }
    return 0;
}