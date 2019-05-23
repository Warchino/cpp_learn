// Arbol y equilibrado
// Tiempo de busqueda O(log_2(N))
#include <set>
// Tiempo de busqueda O(1)
#include <unordered_set>
#include <iostream>
#include <string>

template <typename Container>
void show(const Container& c)
{
    for (auto& i : c)
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    // cuand ose usa el set de un objeto,
    // se tiene que implementar el operador<
    std::unordered_set<std::string> s;
    s.insert("java");
    s.insert("javascript");
    s.insert("python");
    s.insert("python");
    s.insert("cobol");

    show(s);

    auto i = s.find("javascript");

    if (i == s.end() )
    {
        puts("Not found");
    }else
    {
        std::cout << *i << std::endl;
    }
    
    

    return 0;
}