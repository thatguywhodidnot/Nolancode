#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthreads.h>

#define SIZE 1000
#define THREAD_COUNT 2


// in order to split the multiplying of the two matrices into two concurrent threads
//

int main() {
    int **A, **B, **C;
    int i, j, k;

    // Allocate memory for matrices
    A = malloc(SIZE * sizeof(int *));
    B = malloc(SIZE * sizeof(int *));
    C = malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        A[i] = malloc(SIZE * sizeof(int));
        B[i] = malloc(SIZE * sizeof(int));
        C[i] = malloc(SIZE * sizeof(int));
    }



    srand(time(NULL)); // Seed random number generator

    // Initialize matrices A and B with random numbers between 1 and 10
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i][j] = (rand() % 10) + 1;
            B[i][j] = (rand() % 10) + 1;
            C[i][j] = 0; // Initialize result matrix
        }
    }

    // Multiply matrices A and B, store result in C
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Optional: Print a small section of the result matrix
    printf("Sample 5x5 section of the result matrix:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < SIZE; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
