// Author: Prathamesh A Mehare
// Note: The array are of same size


#include <stdio.h>
#include <omp.h>

#define THREAD_NUM 8
int main() {

    int length = 80000;
    int v1[length];
    int v2[length];
    
    int v3[length];

    for(int i = 0; i < length; i++){
        v1[i] = i*10;
        v2[i] = i*5;
    }

    double start_time = omp_get_wtime();
    omp_set_num_threads(THREAD_NUM);
    // int nthreads;
    #pragma omp parallel for
    for(int i = 0; i < length; i++){
        v3[i] = v1[i] + v2[i];
        printf("\nThread number: %d is running i: %d", omp_get_thread_num(),i);
    }
    double total_time = omp_get_wtime() - start_time;

    printf("\n\nTotal time taken to execute in parallel using threads: %lf", total_time);

    return 0;
}