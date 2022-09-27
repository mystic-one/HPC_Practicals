#include <stdio.h>
#include <omp.h>
static long long int TOTAL = 200000000;
int main(){

    double start_time = omp_get_wtime();
    printf("Start time: %lf", start_time);

    long long ans = 0;

    for(long long int i = 0LL; i <= TOTAL; i++){
        ans += i * i;
    }

    printf("\nEnd time: %lf", omp_get_wtime());

    double total_time = omp_get_wtime() - start_time;
    printf("\nThe sum of squares from 1 to %lld -> %lld",TOTAL, ans);
    printf("\nTime Required: %lf seconds", total_time);

    return 0;
}