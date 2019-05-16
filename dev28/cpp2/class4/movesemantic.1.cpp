#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctime>


char* clone(const char* s)
{
    auto len = strlen(s);
    char* aux = new char[len +1];
    memcpy(aux, s, len + 1);
    return aux;
}

class N
{
private:
    char* aux;
public:
    N(const char* s) : aux {clone(s)}
    {
        // puts("new");
    }
    N(const N& s) : aux {clone(s.aux)}
    {
        // puts("copy");
    }
    ~N()
    {
        delete[] aux;
    }

    N& operator=(const N& src)
    {
        // puts("=");
        this -> ~N();
        aux = clone(src.aux);
        return *this;
    }

    void print() const
    {
        puts(aux);
    }
    // Entonces se soportara el move semantic
    // es necesario el contrcutor dee movida

    N(N&& src) 
    : aux {src.aux}
    {
        src.aux = nullptr;
        // puts("Se ha robado el valor  MOVE");
    }

    N& operator=(N&& src)
    {
        this->~N();
        aux = src.aux;
        src.aux = nullptr;
        // puts("MOVE =");
        return *this;
    }

    
};

N factory(const char* s)
{
    N x{s};
    return x;
}
/** 
 * se tiene el problema de que este codigo es mas caro
 * porque hace copias al salir factory.
 */

 class ParN
 {
    N a,b;
public:
    ParN(const N& a, const N& b)
    : a{a}, b{b}
    {
    }
    ParN(N&& a, N&& b)
    : a{std::move(a)}, b{std::move(b)}
    {
    }

 };
template <typename T>
void intercambiar(T& a , T& b)
{
    T aux = std::move(a);
    a = std::move(b);
    b = std::move(aux);
}

int main()
{
    N a{"Luisito comunica esta en cochabamba"};
    N b{"y nada quedo despues del fuego del dragon"};

    for (size_t i = 0; i < 100'000'001; i++)
    {
        intercambiar(a, b);
    }
    
    a.print();
    b.print();

    return 0;
}
