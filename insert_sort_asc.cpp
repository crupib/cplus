#include <iostream>
#include <vector>
#include <algorithm>

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

    // 3) Insertion sort in increasing order:
    for (int j = 1; j < n; ++j) {
        int key = A[j];
        int i = j - 1;
        // <-- shift any element > key to the right
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            --i;
        }
        A[i + 1] = key;
    }

    // 4) Output sorted array
    std::cout << "Sorted array (increasing):\n";
    for (int x : A) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}

