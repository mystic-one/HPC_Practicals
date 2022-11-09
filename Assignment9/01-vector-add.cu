#include <stdio.h>

void initWith(float num, float *a, int N)
{
  for(int i = 0; i < N; ++i)
  {
    a[i] = num;
  }
}

__global__ void addVectorsInto(float *result, float *a, float *b, int N)
{
  // calculating the thread mapping and strides
  int current = threadIdx.x + blockIdx.x * blockDim.x;
  int gridStride = gridDim.x * blockDim.x;
  for(int i = current; i < N; i += gridStride)
  {
    result[i] = a[i] + b[i];
  }
}

void checkElementsAre(float target, float *array, int N)
{
  for(int i = 0; i < N; i++)
  {
    if(array[i] != target)
    {
      printf("FAIL: array[%d] - %0.0f does not equal %0.0f\n", i, array[i], target);
      exit(1);
    }
  }
  printf("SUCCESS! All values added correctly.\n");
}

int main()
{
  const int N = 2<<20;
  size_t size = N * sizeof(float);

  float *a;
  float *b;
  float *c;

  // allocating the memory using cudaMallocManaged
  cudaMallocManaged(&a, size);
  cudaMallocManaged(&b, size);
  cudaMallocManaged(&c, size);

  initWith(3, a, N);
  initWith(4, b, N);
  initWith(0, c, N);
   
  // fixing number of threads in a block
  int no_of_threads = 256;
  // calculating number of blocks required
  int no_of_blocks = N-1+no_of_threads/no_of_threads;

  // invoking the kernel with specific environment configuration
  addVectorsInto<<<no_of_blocks, no_of_threads>>>(c, a, b, N);
  
  // synchronizing GPU and CPU
  cudaDeviceSynchronize();
    
  checkElementsAre(7, c, N);

  // deallocating the memory using cudaFree()
  cudaFree(a);
  cudaFree(b);
  cudaFree(c);
}
