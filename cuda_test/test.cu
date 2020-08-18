#include <stdio.h>
#include <iostream>
#include <npp.h>

#define N 5 
#define M 2

__global__ void add(int *m1, int *m2, int *res, int n){
    //int index = threadIdx.x + blockIdx.x * blockDim.x;
    int ix = threadIdx.x+blockIdx.x*blockDim.x;

    if(ix<M*N) 
        res[ix] = m1[ix] + m2[ix];
}


int main (void){

    int *mtx1, *mtx2, *mtx_res;
    int *d_mtx1, *d_mtx2, *d_mtx_res;

    int size = M*N*sizeof(int);

    // Alocate memory space for nvidia GPU
    cudaMalloc((void **)&d_mtx1, size);
    cudaMalloc((void **)&d_mtx2, size);
    cudaMalloc((void **)&d_mtx_res, size);

    mtx1 = (int *)malloc(size);
    mtx2 = (int *)malloc(size);
    mtx_res = (int *)malloc(size);

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            mtx1[N*i+j] = i*N+j;
            mtx2[N*i+j] = i*N+j;
            //printf("%d (%d)\t", mtx1[N*i+j], N*i+j);
        }
        //printf("\n");
    }


    // //copy inputs to device
    cudaMemcpy(d_mtx1, mtx1, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_mtx2, mtx2, size, cudaMemcpyHostToDevice);

    
    add<<<N, M>>>(d_mtx2, d_mtx1, d_mtx_res, N);

    cudaMemcpy(mtx_res, d_mtx_res, size, cudaMemcpyDeviceToHost);

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            printf("%d\t", mtx_res[N*i+j]);
        }
        printf("\n");
    }

    cudaFree(d_mtx1);
    cudaFree(d_mtx2);
    cudaFree(d_mtx_res);

    free(mtx1);
    free(mtx2);
    free(mtx_res);

    return 0;
}