#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>


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
        puts("new");
    }
    N(const N& s) : aux {clone(s.aux)}
    {
        puts("copy");
    }
    ~N()
    {
        delete[] aux;
    }

    N& operator=(const N& src)
    {
        puts("=");
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
        puts("Se ha robado el valor  MOVE");
    }

    N& operator=(N&& src)
    {
        this->~N();
        aux = src.aux;
        src.aux = nullptr;
        puts("MOVE =");
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

int main()
{
    N a{""};
    a = factory("hello world");

    ParN b{N{"buenos dias"},
        N{"bonjour"}};

        // por debajo
    // N a = b;
    // int a = 2;
    // int b = a;
    // por si queremos robar el espacio de a
    // entonces se llama rvalue references ->   N&&
    /**
     * Se crea objetos temporales el cual dentro de ParN
     * copia y tarda.
     */

    std::string h = "luisito comunica esta en cocha";

    std::cout << h << std::endl;

    std::string r = std::move(h);

    std::cout << r << std::endl;
    std::cout << "h->" << h.c_str() << std::endl;



    return 0;
}
/** Move semantic
 * Es robar el puntero de donde se estan almacenando los objetos temporales
 * sin necesidad de copiar y asi se mejora el rendimiento harto.
 */
