#include<stdio.h>
#include<omp.h>

#define n 100000

int sort(int arr[])
{
    int i, j;
   
    for (i = 0; i < n; i++){
        int turn = i % 2;
        #pragma omp parallel for
        for (j = turn; j < n - 1; j+=2){
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int sort_des(int arr[])
{
    int i,j;
    
    for (i = 0; i < n; ++i)
    {
        int turn = i % 2;
        #pragma omp parallel for
        for (j = turn; j < n - 1; j += 2)
        {
            if (arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
//fill the code;
    
    int arr1[n], arr2[n];
    int i;
    for(i = 0; i < n ; i++)
    {
        arr1[i] = i;
    }
    for(i = 0; i < n ; i++)
    {
        arr2[i] = n-i;
    }

    double start_time = omp_get_wtime();
    sort(arr1);
    sort_des(arr2);
    long long sum = 0;
    
    #pragma omp parallel for reduction(+:sum)
    for(i = 0; i < n ; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }
    printf("%ld",sum);
    double end_time = omp_get_wtime();
    double total_time = end_time - start_time;
    printf("\nTotal time required by the program to execute in paralled %lf ", total_time);
    return 0;
}
