// Linear program for matrix addition
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 2000
#define TOTAL_THREADS 8

void fillMatrix(int** matrix, int num){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            matrix[i][j] = num;
        }
    }
}

int main() {
    int** matrixOne;
    int** matrixTwo;
    int** resultMatrix;

    matrixOne = malloc(sizeof(int*) * N);
    matrixTwo = malloc(sizeof(int*) * N);
    resultMatrix = malloc(sizeof(int*) * N);

    for(int i=0; i<N; i++){
        matrixOne[i] = malloc(sizeof(int) * N);
        matrixTwo[i] = malloc(sizeof(int) * N);
        resultMatrix[i] = malloc(sizeof(int) * N);
    }
    
    fillMatrix(matrixOne, 1);
    fillMatrix(matrixTwo, 2);
    double start_time = omp_get_wtime();
    
    omp_set_num_threads(TOTAL_THREADS);
    #pragma omp parallel
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            resultMatrix[i][j] = matrixOne[i][j] + matrixTwo[i][j];
        }
    }

    double end_time = omp_get_wtime();

    printf("Time required to perfrom the 2d matrix addition of size %dX%d using %d threads is %.10lf s", N, N, TOTAL_THREADS, end_time - start_time);


    return 0;
}