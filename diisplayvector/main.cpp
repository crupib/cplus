#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-loop-convert"
#include <iostream>
#include <vector>
void generate_triangle()
{
    std::vector<int> data {1,2,3,4,5};
    std::vector<int> data1 (5);
    for (auto number : data)
    {
        std::cout << number << ' ';
    }
    std::cout << std::endl;
    for (auto position = data1.begin(); position != data1.end(); ++position) {
        std::cout << *position << ' ';
    }

    std::cout << std::endl;
}

int main() {
    generate_triangle();
    return 0;
}

#pragma clang diagnostic pop