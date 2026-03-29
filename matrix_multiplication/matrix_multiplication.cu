#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cuda_runtime.h>


// CUDA kernel for matrix multiplication
__global__ void multKernel(int* C, const int* A, const int* B, unsigned int width)
{
    int row =  blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < width && col < width)
    {
        int sum = 0;
        for (int k = 0; k < width; ++k)
        {
            sum += A[row * width + k] * B[k * width + col];
        }
        C[row * width + col] = sum;
    }
}

cudaError_t multWithCuda(int* c, const int* a, const int* b, unsigned int size)
{
    int* dev_a = nullptr;
    int* dev_b = nullptr;
    int* dev_c = nullptr;

    unsigned int width = size;
    unsigned int total = width * width;

    cudaError_t status;

    // Helper cleanup lambda
    auto cleanup = [&]() {
        cudaFree(dev_c);
        cudaFree(dev_a);
        cudaFree(dev_b);
        };

    // Set device
    status = cudaSetDevice(0);
    if (status != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed!\n");
        return status;
    }

    // Allocate memory
    if ((status = cudaMalloc((void**)&dev_c, total * sizeof(int))) != cudaSuccess) {
        cleanup();
        return status;
    }

    if ((status = cudaMalloc((void**)&dev_a, total * sizeof(int))) != cudaSuccess) {
        cleanup();
        return status;
    }

    if ((status = cudaMalloc((void**)&dev_b, total * sizeof(int))) != cudaSuccess) {
        cleanup();
        return status;
    }

    // Copy inputs
    if ((status = cudaMemcpy(dev_a, a, total * sizeof(int), cudaMemcpyHostToDevice)) != cudaSuccess) {
        cleanup();
        return status;
    }

    if ((status = cudaMemcpy(dev_b, b, total * sizeof(int), cudaMemcpyHostToDevice)) != cudaSuccess) {
        cleanup();
        return status;
    }

    // Launch kernel
    dim3 threadsPerBlock(16, 16);
    dim3 blocksPerGrid((width + 15) / 16, (width + 15) / 16);
    multKernel <<< blocksPerGrid, threadsPerBlock >>> (dev_c, dev_a, dev_b, width);

    // Check kernel launch
    status = cudaGetLastError();
    if (status != cudaSuccess) {
        fprintf(stderr, "Kernel launch failed: %s\n", cudaGetErrorString(status));
        cleanup();
        return status;
    }

    // Wait for GPU
    status = cudaDeviceSynchronize();
    if (status != cudaSuccess) {
        fprintf(stderr, "cudaDeviceSynchronize failed!\n");
        cleanup();
        return status;
    }

    // Copy result back
    status = cudaMemcpy(c, dev_c, total * sizeof(int), cudaMemcpyDeviceToHost);
    if (status != cudaSuccess) {
        cleanup();
        return status;
    }

    cleanup();
    return cudaSuccess;
}
// Helper to print only the first 5 values of a matrix
void printMatrixFirst5(const char* name, int* M, int width)
{
    printf("%s (first 5 values):\n", name);
    for (int i = 0; i < width && i < 5; i++)
    {
        for (int j = 0; j < width && j < 5; j++)
        {
            printf("%4d ", M[i * width + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int width = 50;
    int total = width * width;

    srand((unsigned int)time(NULL));

    // Allocate host memory
    int* A = (int*)malloc(total * sizeof(int));
    int* B = (int*)malloc(total * sizeof(int));
    int* C = (int*)malloc(total * sizeof(int));

    if (A == NULL || B == NULL || C == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize matrices
    for (int i = 0; i < total; i++)
    {
        A[i] = rand() % 5;
        B[i] = rand() % 5;
        C[i] = 0;
    }

    // Print first 5 values of inputs
    printMatrixFirst5("Matrix A", A, width);
    printMatrixFirst5("Matrix B", B, width);

    // Create CUDA events for timing
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    // Start timer
    cudaEventRecord(start, 0);

    // Run CUDA multiplication
    cudaError_t status = multWithCuda(C, A, B, width);

    // Stop timer
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);

    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);

    if (status != cudaSuccess)
    {
        fprintf(stderr, "multWithCuda failed!\n");
        return 1;
    }

    // Print first 5 values of result
    printMatrixFirst5("Matrix C = A * B", C, width);

    // Print timing
    printf("Matrix multiplication took %.3f milliseconds on GPU.\n", milliseconds);

    // Cleanup
    cudaEventDestroy(start);
    cudaEventDestroy(stop);

    free(A);
    free(B);
    free(C);

    cudaDeviceReset();

    return 0;
}