#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_NAME 20

//no recursion, initial submission

// COP 3502C Assignment 3
// This program is written by: Nolan Milligan

typedef struct distance{
    float distance;
    char* storeA;
    char* storeB;
}distance;

float calc_distance(float xA, float yA, float xB, float yB){
    float dx = xA - xB; float dy = yA - yB;
    return (sqrt(pow(dx,2)+pow(dy,2)));

}

distance* read_case(int num_distances){
    
    distance* distances = malloc(num_distances*sizeof(distance));
    
    float xA, yA, xB, yB;
    float total_distance = 0;
    char storename[MAX_NAME];
    for(int i=0; i<num_distances; i++){
        scanf("%f %f %s", &xA, &yA, storename);
        distances[i].storeA = malloc((strlen(storename)+1)*sizeof(char)); strcpy(distances[i].storeA, storename);
 
        scanf("%f %f %s", &xB, &yB, storename);
        distances[i].storeB = malloc((strlen(storename)+1)*sizeof(char)); strcpy(distances[i].storeB, storename);
        
        distances[i].distance = calc_distance(xA, yA, xB, yB);
        total_distance += distances[i].distance;
    }
    printf("%.3f\n", total_distance);
    for(int i=0; i<num_distances; i++){
        printf("(%s, %s, %.3f)\n", distances[i].storeA, distances[i].storeB, distances[i].distance);
    }
    return distances;

}

void free_distances(distance* distances, int num_distances){
    for(int i=0; i<num_distances; i++){
        free(distances[i].storeA); free(distances[i].storeB);
    }
    free(distances);
}

int main(){

    int num_cases;
    scanf("%d", &num_cases);
    for(int i=0; i<num_cases; i++){
        int num_distances;
        scanf("%d", &num_distances);
        distance* distances = read_case(num_distances);

        free_distances(distances, num_distances);
    }


    return 0;
}