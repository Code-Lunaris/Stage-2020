#include <stdio.h>

#define N 32
#define M 4

__global__ void reverse(int *tab, int n){

    __shared__ int s[N];
    int t = threadIdx.x;
    int tr = n-t-1;
    s[t] = tab[t];
    __syncthreads();
    tab[t] = s[tr];
}


int main (void){

    int *array;
    //int *result;

    int *d_array;


    int size = N*sizeof(int);

    // Alocate memory space for nvidia GPU
    cudaMalloc((void **)&d_array, size);

    array = (int *)malloc(size);
    

    for(int i=0; i<N; i++){
        array[i] = i;
    }

    //copy inputs to device
    cudaMemcpy(d_array, array, size, cudaMemcpyHostToDevice);

    
    reverse<<<1, N>>>(d_array, N);

    cudaMemcpyAsync(array, d_array, size, cudaMemcpyDeviceToHost);

    for(int i=0; i<N; i++)
        printf("%d\n", array[i]);

    cudaFree(d_array);

    free(array);

    return 0;
}