#include <list>
#include <string>
#include <iostream>

// La clase list es una lista doblemente enlazada

using namespace std::string_literals;

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
    std::list<std::string> s;
    // push_back puede mover o copiar, es decir usa forward
    // aqui mueve al final
    s.push_back("two");
    s.push_back("three");
    // crea el string del "four" const char* dentro de la estructura
    // lo cual no hace movida ni copia
    // y es mas eficiente
    s.emplace_back("four");
    s.push_back("five");
    s.push_front("one");
    auto z = "zero"s; // c++14 es un string
    // aqui copia al frente
    s.push_front(z);
    show(s);
}
