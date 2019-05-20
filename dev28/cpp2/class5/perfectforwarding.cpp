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
    person(const mystring& fn, const mystring& ln)
    : fn{fn}, ln{ln}
    {
        puts("Constructor persona 1");
    }

    void show() const
    {
        printf("%s,%s\n", fn.data(), ln.data());
    }
};


int main()
{

    // mystring s = "ll";
    // puts(s.data());
    mystring j = "john";
    mystring s = "snow";

    // Genera constrcutor copia de estos
    // pero lo ideal es que deberain de usar el std::move
    person p1{"Tyrion", "Vadin"};
// deberai de llamar a los consturcotres copia
    auto p2 = p1;
    // deberia de llamar a los constructuores de movida de mystring
    auto p3 = std::move(p1);
    p2.show();
    p3.show();
    p1.show();

    return 0;
}