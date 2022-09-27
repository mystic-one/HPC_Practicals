#include <stdio.h>
#include <omp.h>

#define N 200
#define CHUNK_SIZE 2
int main() {
    int arr[N];
    int b = 10;

    omp_set_num_threads(6);
    
    for(int i = 0; i < N; i++){
        arr[i] = i;
    }

    double start_time = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic, CHUNK_SIZE)
    for(int i = 0; i < N; i++){
        arr[i] += b;
    }

    double end_time = omp_get_wtime();

    printf("\nTime taken is %.10lf s\nChunk Size: %d", end_time-start_time, CHUNK_SIZE);

    return 0;
}