#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "../common/book.h"
#include <stdio.h>

#define N 10000

__global__ void add(int* a, int* b, int* c) {
    int tid = blockIdx.x;

    if (tid < N)
        c[tid] = a[tid] + b[tid];
}

int main()
{
    int a[N], b[N], c[N];
    int* dev_a, * dev_b, * dev_c;

    // CUDA timing events
    cudaEvent_t start, stop;
    float kernelTime = 0.0f;
    float h2dTime = 0.0f;
    float d2hTime = 0.0f;
    float totalGPUTime = 0.0f;

    HANDLE_ERROR(cudaEventCreate(&start));
    HANDLE_ERROR(cudaEventCreate(&stop));

    HANDLE_ERROR(cudaMalloc((void**)&dev_a, N * sizeof(int)));
    HANDLE_ERROR(cudaMalloc((void**)&dev_b, N * sizeof(int)));
    HANDLE_ERROR(cudaMalloc((void**)&dev_c, N * sizeof(int)));

    for (int i = 0; i < N; i++) {
        a[i] = -i;
        b[i] = i * i;
    }

    // -------------------------------
    // Host -> Device transfer timing
    // -------------------------------
    HANDLE_ERROR(cudaEventRecord(start, 0));

    HANDLE_ERROR(cudaMemcpy(dev_a, a, N * sizeof(int), cudaMemcpyHostToDevice));
    HANDLE_ERROR(cudaMemcpy(dev_b, b, N * sizeof(int), cudaMemcpyHostToDevice));

    HANDLE_ERROR(cudaEventRecord(stop, 0));
    HANDLE_ERROR(cudaEventSynchronize(stop));
    HANDLE_ERROR(cudaEventElapsedTime(&h2dTime, start, stop));

    // -------------------------------
    // Kernel execution timing
    // -------------------------------
    HANDLE_ERROR(cudaEventRecord(start, 0));

    add << <N, 1 >> > (dev_a, dev_b, dev_c);

    HANDLE_ERROR(cudaEventRecord(stop, 0));
    HANDLE_ERROR(cudaEventSynchronize(stop));
    HANDLE_ERROR(cudaEventElapsedTime(&kernelTime, start, stop));

    // -------------------------------
    // Device -> Host transfer timing
    // -------------------------------
    HANDLE_ERROR(cudaEventRecord(start, 0));

    HANDLE_ERROR(cudaMemcpy(c, dev_c, N * sizeof(int), cudaMemcpyDeviceToHost));

    HANDLE_ERROR(cudaEventRecord(stop, 0));
    HANDLE_ERROR(cudaEventSynchronize(stop));
    HANDLE_ERROR(cudaEventElapsedTime(&d2hTime, start, stop));

    totalGPUTime = h2dTime + kernelTime + d2hTime;

    // Print results
    for (int i = 0; i < N; i++) {
        printf("%d + %d = %d\n", a[i], b[i], c[i]);
    }

    // Timing output
    printf("\n--- CUDA Timing Results ---\n");
    printf("Host to Device Transfer : %f ms\n", h2dTime);
    printf("Kernel Execution Time   : %f ms\n", kernelTime);
    printf("Device to Host Transfer : %f ms\n", d2hTime);
    printf("Total GPU Time          : %f ms\n", totalGPUTime);

    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);

    cudaEventDestroy(start);
    cudaEventDestroy(stop);

    return 0;
}