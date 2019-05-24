#include <map>
#include <unordered_map> // c++11
#include <string>
#include <iostream>


int main()
{
    // en el key tiene que estar el operador < implementado
    std::unordered_map<std::string, int> ss;
    ss.insert(std::pair<std::string, int>{"one", 1});
    ss.insert(std::make_pair("two", 2));
    ss["three"] = 3;
    ss["four"] = 4;
    ss["five"] = 5;
    
    // Nunca usen para buscar
    // auto n = ss["six"];
    // std::cout << n << std::endl;
    for(auto& e : ss)
    {
        std::cout << e.first << " " << e.second << std::endl;
    }

    auto it = ss.find("fourf");

    if (it == ss.end())
    {
        std::cerr << "NF\n";
    }else
    {
        std::cout << it->second << std::endl;
    }
    
    

}