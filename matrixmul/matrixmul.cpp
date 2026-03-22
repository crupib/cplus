#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void MatrixMultiplication(float* M, float* N, float* P, int Width)
{
    for (int i = 0; i < Width; ++i)
    {
        for (int j = 0; j < Width; ++j)
        {
            float sum = 0.0f;
            for (int k = 0; k < Width; ++k)
            {
                float a = M[i * Width + k];
                float b = N[k * Width + j];
                sum += a * b;
            }
            P[i * Width + j] = sum;
        }
    }
}

// Helper function to print a matrix
void PrintMatrix(const char* name, float* M, int width)
{
    printf("%s:\n", name);
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%6.3f ", M[i * width + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int width = 4;

    // Seed random number generator
    srand((unsigned int)time(NULL));

    // Allocate memory for width x width matrices
    float* A = (float*)malloc(width * width * sizeof(float));
    float* B = (float*)malloc(width * width * sizeof(float));
    float* C = (float*)malloc(width * width * sizeof(float));

    // Check allocation
    if (A == NULL || B == NULL || C == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize matrices with random floats [0,1]
    for (int i = 0; i < width * width; i++)
    {
        A[i] = (float)rand() / RAND_MAX;
        B[i] = (float)rand() / RAND_MAX;
        C[i] = 0.0f; // Initialize result matrix
    }

    // Print input matrices
    PrintMatrix("Matrix A", A, width);
    PrintMatrix("Matrix B", B, width);

    // Perform multiplication
    MatrixMultiplication(A, B, C, width);

    // Print result
    PrintMatrix("Matrix C = A * B", C, width);

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}