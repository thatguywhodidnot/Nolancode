#include <stdio.h>

void calculate_speedup(double P, int N) {
    double S = 1 / (1 - P + P / N);     // S = Theoretical Speedup
    printf("For P = %.2f and N = %d, S ≈ %.2f\n", P, N, S);
}

int main() {
    double P[] = {0.5, 0.8, 0.95};  // Percentage of parallelized program
    int N[] = {4, 8, 16};           // Number of processors

    printf("Theoretical Speedup (S):\n");

    for (int i = 0; i < 3; i++) {
        calculate_speedup(P[i], N[i]);
    }
    return 0;
}