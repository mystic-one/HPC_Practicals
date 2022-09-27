#include <stdio.h>
#include <omp.h>

#define TOTAL_NUMS 200000000
#define NUM_THREADS 8

int main() {
    long long ans = 0;
    double start_time = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel for reduction(+: ans)
    for(long long int i=1; i <= TOTAL_NUMS; i++){
        ans += i*i;
    }
    
    double total_time = omp_get_wtime() - start_time;

    printf("The sum of squares from 1 to %ld -> %lld",TOTAL_NUMS, ans);
    printf("\nTime Required: %lf", total_time);


    return 0;
}