#include <iostream>
#include <vector>
#include <algorithm>

// Adds two binary-digit arrays a and b, returns the sum as a binary-digit vector.
std::vector<int> addBinaryArrays(const std::vector<int>& a, const std::vector<int>& b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    std::vector<int> result;

    // Process from least significant bit to most
    while (i >= 0 || j >= 0 || carry) {
        int bitA = (i >= 0 ? a[i] : 0);
        int bitB = (j >= 0 ? b[j] : 0);
        int sum  = bitA + bitB + carry;
        
        result.push_back(sum % 2);    // current bit
        carry = sum / 2;              // new carry
        --i; --j;
    }

    // The bits are in reverse order, so reverse them
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    // Example input: you can modify these or read from std::cin
    std::vector<int> A = {1,0,1,1};  // binary 1011 (decimal 11)
    std::vector<int> B = {1,1,0,1};  // binary 1101 (decimal 13)

    std::vector<int> C = addBinaryArrays(A, B);  // should be 11000 (decimal 24)

    // Print the result
    std::cout << "Sum: ";
    for (int bit : C) {
        std::cout << bit;
    }
    std::cout << std::endl;

    return 0;
}

