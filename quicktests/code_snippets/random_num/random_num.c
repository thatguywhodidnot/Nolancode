// C program for generating a
// random number in a given range.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// numbers in range [min, max].
int rand_int(int min, int max) {
    unsigned int seed = time(0);
    return rand_r(&seed) % (max - min + 1) + min;
}

int main() {
    int min = 0, max = 10;
    printf("%d", rand_int(min, max));
    return 0;
}