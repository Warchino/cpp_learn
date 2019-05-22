#include <array>
#include <iostream>

// template <typename Container>
// void show(const Container& c)
// {

// }
// template <int N>
// void show(const std::array<int, N>& c)
// {
//     std::array<int, N>::iterator i = c.begin();
    
// }

//  sin const 
// void show(std::array<int, 5>& c)
// {
//     // Existen los iteradores como si fuerea un array normal.
//     std::array<int, 5>::iterator i = c.begin();
//     std::array<int, 5>::iterator z = c.end();

//     for (auto p = i; p != z; p++)
//     {
//         std::cout << *p << std::endl;
//     }
// }


// con const se usa iteradfore sconstantes
// void show(const std::array<int, 5>& c)
// {
//     std::array<int, 5>::const_iterator i = c.begin();
//     std::array<int, 5>::const_iterator z = c.end();
//     for (auto p = i; p != z; p++)
//     {
//         std::cout << *p << std::endl;
//     }
// }

// Mejora 1 == N en vez de 5
// template <unsigned long N>
// void show(const std::array<int, N>& c)
// {
//     // Cuando se tiene un tipo de dato declarado dentro de otro tipo de dato el compilador 
//     // no reconoce cuando es template
//     typename std::array<int, N>::const_iterator i = c.begin();
//     typename std::array<int, N>::const_iterator z = c.end();
//     for (auto p = i; p != z; p++)
//     {
//         std::cout << *p << std::endl;
//     }
// }

// Mejora 2 == mas generico aun
// template <typename Container>
// void show(const Container& c)
// {
//     for (typename Container::const_iterator i = c.begin(); i != c.end(); ++i)
//     {
//         std::cout << *i << std::endl;
//     }
// }

// Pseudo Mejora 3 ==> auto
// template <typename Container>
// void show(const Container& c)
// {
//     for (auto i = c.begin(); i != c.end(); ++i)
//     {
//         std::cout << *i << std::endl;
//     }
// }

// Pseudo Mejora 4 ==> azucar sintactico
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
    std::array<int, 5> a;
    a[0] = 20;
    a[1] = 10;
    a[2] = 3;
    a[3] = 8;
    a[4] = 5;

    show(a);

    std::string s = "hola";
    show(s);

// Malo usar at() porque en c++ nos preocupa el rendimiento
    // std::cout << a.at(5) << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << a.max_size() << std::endl;

    return 0;
}