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

//This function was written using chatgpt
distance* best_distances(
    distance* distances, int num_best_dist, int num_distances
){
    int num_stores = num_best_dist * 2;

    distance* best_distances =
        malloc(num_best_dist * sizeof(distance));

    if(best_distances == NULL){
        return NULL;
    }

    /*
     * A bit in the mask is 1 when that store has already
     * been placed into a pair.
     *
     * This implementation uses unsigned long long, so the
     * number of stores must be below 64.
     */
    if(num_stores >= 64){
        free(best_distances);
        return NULL;
    }

    int total_masks = 1ULL << num_stores;
    int final_mask = total_masks - 1;

    float* current_best_dist =
        malloc(total_masks * sizeof(float));

    int* previous_mask =
        malloc(total_masks * sizeof(int));

    int* best_index =
        malloc(total_masks * sizeof(int));

    /*
     * pair_index[a * num_stores + b] gives the position
     * of pair (a, b) inside the distances array.
     */
    int* pair_index =
        malloc(num_stores * num_stores * sizeof(int));

    if(current_best_dist == NULL ||
       previous_mask == NULL ||
       best_index == NULL ||
       pair_index == NULL){

        free(best_distances);
        free(current_best_dist);
        free(previous_mask);
        free(best_index);
        free(pair_index);

        return NULL;
    }

    for(int i = 0; i < num_stores * num_stores; i++){
        pair_index[i] = -1;
    }

    for(int i = 0; i < num_distances; i++){
        int curr_a = distances[i].storeA;
        int curr_b = distances[i].storeB;

        pair_index[curr_a * num_stores + curr_b] = i;
        pair_index[curr_b * num_stores + curr_a] = i;
    }

    for(int i = 0; i < total_masks; i++){
        current_best_dist[i] = INFINITY;
        previous_mask[i] = 0;
        best_index[i] = -1;
    }

    /*
     * No stores have been used yet, so the starting
     * total distance is zero.
     */
    current_best_dist[0] = 0;

    for(int used = 0;
        used < total_masks;
        used++){

        if(current_best_dist[used] == INFINITY){
            continue;
        }

        if(used == final_mask){
            continue;
        }

        /*
         * Find the first store that has not been used.
         * Always selecting the first unused store avoids
         * generating the same pairing in different orders.
         */
        int current_spot = -1;

        for(int i = 0; i < num_stores; i++){
            if((used & (1ULL << i)) == 0){
                current_spot = i;
                break;
            }
        }

        /*
         * Try pairing current_spot with every other
         * unused store.
         */
        for(int i = current_spot + 1; i < num_stores; i++){
            if((used & (1ULL << i)) != 0){
                continue;
            }

            int current_best_spot =
                pair_index[current_spot * num_stores + i];

            if(current_best_spot == -1){
                continue;
            }

            int new_used =
                used |
                (1ULL << current_spot) |
                (1ULL << i);

            float new_distance =
                current_best_dist[used] +
                distances[current_best_spot].distance;

            if(new_distance < current_best_dist[new_used]){
                current_best_dist[new_used] = new_distance;
                previous_mask[new_used] = used;
                best_index[new_used] = current_best_spot;
            }
        }
    }

    /*
     * Reconstruct the chosen pairs by moving backward
     * from the mask where every store has been used.
     */
    int used = final_mask;

    for(int current_best_spot = num_best_dist - 1;
        current_best_spot >= 0;
        current_best_spot--){

        if(best_index[used] == -1){
            free(best_distances);
            free(current_best_dist);
            free(previous_mask);
            free(best_index);
            free(pair_index);

            return NULL;
        }

        best_distances[current_best_spot] =
            distances[best_index[used]];

        used = previous_mask[used];
    }

    free(current_best_dist);
    free(previous_mask);
    free(best_index);
    free(pair_index);

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