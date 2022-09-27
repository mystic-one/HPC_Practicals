// Author: Prathamesh A Mehare
// Note: The array are of same size


#include <stdio.h>
#include <omp.h>

int main() {

    size_t length = 80000;
    long long v1[length];
    long long v2[length];
    
    long long v3[length];

    for(size_t i = 0; i < length; i++){
        v1[i] = i*10;
        v2[i] = i*5;
    }
    

    double start_time = omp_get_wtime();
    for(size_t i = 0; i < length; i++){
        v3[i] = v1[i] + v2[i];
        printf("\nThread number: %d is running i: %d", omp_get_thread_num(),i);
    }
    double end_time = omp_get_wtime();
    double total_time = end_time - start_time;

    

    printf("\nTotal time taken to execute sum in serial order: %lf", total_time);

    return 0;
}