// This is a serial program for vector scalar multiplication
// Author: Prathamesh Mehare

#include <stdio.h>
#include <omp.h>

int main() {
    int n = 500000;
    int arr[500000];
    int scalar_multiplier = 10;

    for(int i = 0; i < 500000; i++){
        arr[i] = i+1;
    }

    double start_time = omp_get_wtime();

    for(int i = 0; i < 500000; i++){
        arr[i] *= scalar_multiplier;
        
    }

    double end_time = omp_get_wtime();

    printf("\nTotal Time required for serial execution: %lf", end_time - start_time);
    return 0;
}       