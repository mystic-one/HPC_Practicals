#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(){
    
    #pragma omp parallel
    {
        printf("Hello World... : from thread no = %d\n", omp_get_thread_num());
    }
    return 0;
}