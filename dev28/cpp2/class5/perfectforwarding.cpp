#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

/**
 * Puede utilizar el operador copia
 * o la movida y el compilador sabe cual usar.
 */

char* clone_str(const char* s)
{
    auto len = strlen(s);
    auto ns = new char[len + 1];
    memcpy(ns, s, len + 1);
    return ns;
}

class mystring
{
    char* str;
public:
    mystring(const char* s)
    : str{clone_str(s)}
    {
    }
    ~mystring()
    {
        delete[] str;
    }

    // constructor copia
    mystring(const mystring& src)
    : str{clone_str(src.str)}
    {
        puts("mystring COPY constructor");
    }

    mystring& operator=(const mystring& src)
    {
        puts("mystring COPY operator=");
        this->~mystring();
        str = clone_str(src.str);
        return *this;
    }

    const char* data() const
    {
        return str;
    }

    // Movida

    // constructor de movida
    mystring(mystring&& src)
    : str{src.str}
    {
        src.str = nullptr;
        puts("mystring MOVE constructor");
    }

    // Operador de movida
    mystring& operator=(mystring&& src)
    {
        this->~mystring();
        str = src.str;
        src.str = nullptr;  
        puts("mystring MOVE operator=");
        return *this;
    }
};

class person
{
    mystring fn;
    mystring ln;
    // Genera constructor de movida, como no esta implementado
    // quie llama a los contructores de los objetos.
    // Pero hace una copia al crear el objeto asi nomas
public:
    // person(const mystring& fn, const mystring& ln)
    // : fn{fn}, ln{ln}
    // {
    //     puts("Constructor persona 1");
    // }
    // se podria hacer este constructor con puras movidas porque eso es lo que se espra
    // person(const mystring& fn, const mystring& ln)
    // : fn{fn}, ln{ln}
    // {
    //     puts("Constructor persona 1");
    // }

    // aqui entra la solucion perfectforwarding

    template<typename S1, typename S2>
    person(S1&& fn, S2&& ln)
    // Transforma el tipo de fn al tipo del que recibe
    : fn{std::forward<S1>(fn)},
    ln{std::forward<S2>(ln)}
    {
        puts("persona Constructor perfectforward");

    }

    void show() const
    {
        printf("%s,%s\n", fn.data(), ln.data());
    }
};
void inc(int& n)
{
    n++;
}
// Hay varias posibilidades para N entonces se hace un forward
template <typename N, typename Proc>
void invoke (N&& n, Proc p)
{
    p(std::forward<N>(n));
}

int main()
{

    // mystring s = "ll";
    // puts(s.data());
    mystring j = "john";
    mystring s = "snow";

    // Genera constrcutor copia de estos
    // pero lo ideal es que deberain de usar el std::move
    // Estos datos lo transforam en rvalue reference y hara la movida
    person p1{"Tyrion", "Vadin"};
// deberai de llamar a los consturcotres copia
    auto p2 = p1;
    // deberia de llamar a los constructuores de movida de mystring
    auto p3 = std::move(p1);
    p2.show();
    p3.show();
    p1.show();

// Aqui genera otro constructor que recibe const rvalue y por lo tanto hara una COPIA
    person p4{j, s};
    p4.show();


// PerfectForwarding sirve para evitar varios constrcutores
// Incluso invocadores

    int n = 4;
    invoke(n, inc);
    printf("%d\n", n);
    return 0;


}