// bookmat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define N 10
void add(int* a, int* b, int* c) {
    int tid = 0;
    while (tid < N) {
        c[tid] = a[tid] + b[tid];
        tid += 1;
    }
}

int main()
{
    std::cout << "Hello World!\n";
    int a[N], b[N], c[N];
    for (int i = 0; i < N; i++) {
        a[i] = -i;
        b[i] = i * i;
    }
    add(a, b, c);
    for (int i = 0; i < N; i++) {
        printf("%d + %d = %d\n",a[i], b[i], c[i]);
    }
}
