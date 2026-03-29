
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "../common/book.h"
#include <iostream>

int main()
{
	cudaDeviceProp prop;
	int dev;
	HANDLE_ERROR(cudaGetDeviceCount(&dev));
	printf("ID of current CUDA device: %d\n", dev);
	memset(&prop, 0, sizeof(cudaDeviceProp));
	prop.major = 1;
	prop.minor = 3;
	HANDLE_ERROR(cudaChooseDevice(&dev, &prop));
	printf("ID of CUDA device closest to revision 1.3: %d", dev);
	HANDLE_ERROR(cudaSetDevice(dev));
}
