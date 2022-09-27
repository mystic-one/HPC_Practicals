#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 10

void hello(){
printf("Hello\n");
}
void hi(int i){
printf("Hi: %d\n", i);
}

int main(){
    int* sample = malloc(sizeof(int) * N);
    for(int i=0; i<N; i++){
        sample[i] = 1;
    }
    
    #pragma omp parallel
    {
    #pragma omp for
    // using nowait clause
    // #pragma omp for nowait
    for(int i=0; i<N; i++){
        hi(i);
    }
        hello();
    }
}
