#include <iostream>
#include <vector>

int main() {
    // 1) Read number of elements
    std::cout << "Enter number of elements: ";
    int n;
    std::cin >> n;
    if (n <= 0) {
        std::cerr << "Array must have at least one element.\n";
        return 1;
    }

    // 2) Read the array
    std::vector<int> A(n);
    std::cout << "Enter " << n << " integers:\n";
    for (int idx = 0; idx < n; ++idx) {
        std::cin >> A[idx];
    }

    // 3) Insertion sort, translating:
    //    For j <- 2 to length[A]
    //      key <- A[j]
    //      i <- j - 1
    //      While i > 0 and A[i] > key
    //        A[i+1] <- A[i]
    //        i <- i - 1
    //      A[i+1] <- key
    //
    // Note: pseudocode is 1-based; in C++ we use 0-based,
    // so j = 1..n-1, and while i >= 0.
    for (int j = 1; j < n; ++j) {
        int key = A[j];
        int i = j - 1;
        // Shift elements of A[0..j-1] that are greater than key
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            --i;
        }
        A[i + 1] = key;
    }

    // 4) Output sorted array
    std::cout << "Sorted array:\n";
    for (int x : A) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

