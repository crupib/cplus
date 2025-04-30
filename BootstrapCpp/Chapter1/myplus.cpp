#include <iostream>
#include <functional>

int main()
{
    std::cout << std::plus<int>{}(1, static_cast<int>(1.23)) << '\n';

    std::cout << std::plus<void>{}(1, 1.23) << '\n';

    return 0;
}

