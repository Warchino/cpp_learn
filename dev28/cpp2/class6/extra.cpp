#include <iostream>

class P
{
    int a, b, c;
public:
    P(int a, int b, int c)
    : a{a}, b{b}, c{c}
    {
    }

    void print() const
    {
        printf("%d \n", a+b+c);
    }

    ~P()
    {
        puts("bye");
    }
};

template <class T>
struct W
{
    T* p;

    ~W()
    {
        delete p;
    }

    T* operator->()
    {
        return p;
    }
};


// es como una especie de factory
// pero el problema es que probablemente nos pasen movidad o
//  referencias constantes por lo que se hara un forward
// template <class Type, class...Args>
// W<Type> create(const Args&...args)
// {
//     return W<Type> { new Type{args...}};
// }
template <class Type, class...Args>
W<Type> create(Args&&...args)
{
    // con esto nos aseguramos que funcione con todo
    return W<Type> { new Type{std::forward<Args>(args)...}};
}


// por alguna razon se oriena al problema de los factoris

int main()
{
    auto x = create<P>(10, 15, 4);
    x->print();
    return 0;
}