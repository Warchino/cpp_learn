#include <cstdio>
#include <cstdlib>
#include <iostream>

template <class T, class U>
auto sum(const T& a, const U& b)
{
    return a + b;
}

template <typename T, typename...Args>
auto sum(const T& a, const Args&...args)
{
    return a + sum(args...);
    // pack expansion
}

int main()
{
    auto s = sum(6, 8.5);
    auto r = sum (9 ,5, 4, 10.2);
    auto p = sum (6, 5, 4, 2, 8, 4, 20);

    std::cout << s << std::endl;
    std::cout << r << std::endl;
    
    return 0;
}