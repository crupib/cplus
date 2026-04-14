
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "../common/book.h"
#include <iostream>

int main()
{
    int count;
    HANDLE_ERROR(cudaGetDeviceCount(&count));
    printf("Number of CUDA devices: %d\n", count);

    int currentDevice;
    HANDLE_ERROR(cudaGetDevice(&currentDevice));
    printf("Current CUDA device ID: %d\n", currentDevice);

    cudaDeviceProp prop;
    HANDLE_ERROR(cudaGetDeviceProperties(&prop, currentDevice));

    printf("Compute Capability: %d.%d\n", prop.major, prop.minor);

    return 0;
}
