#include<stdio.h>
#include<omp.h>

#define n 100000

int sort(int arr[])
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int sort_des(int arr[])
{
    int i,j;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
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
    
    for(i = 0; i < n ; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }
    printf("%ld",sum);
    double end_time = omp_get_wtime();
    double total_time = end_time - start_time;
    printf("\nTotal time required by the program to execute in serial order %lf ", total_time);
    return 0;
}
