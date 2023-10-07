#include <functional>
#include <iostream>
template<typename T, typename U>
auto simple_plus(T lhs, U rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}
using namespace std;
auto main() -> int {
    int result;
    cout << plus<int>{} (static_cast<const int>(1.23), 1) << '\n';
    cout << plus<>{} (1,1.23) << '\n';
    result = simple_plus(20,40);
    printf("%d\n",result);
}
