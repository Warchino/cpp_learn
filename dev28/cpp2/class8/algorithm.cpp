#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> ints;

    for (size_t i = 0; i < 1000000; i++)
    {
        ints.push_back(i);
    }

    auto pos = std::find(ints.begin(), ints.end(), 9999999);
    if (pos == ints.end())
    {
        std::cerr << "Not found" << std::endl;
    }else
    {
        std::cout << *pos << std::endl;
    }
    
    
}