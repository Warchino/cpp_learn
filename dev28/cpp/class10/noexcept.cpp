#include <cstdio>

struct Int
{
    int n;
    ~Int()
    {
        puts("Bye int");
    }
};

struct W
{
    Int* n;
    ~W()
    {
        delete n;
    }
};

void m()
{
    W w{new Int{64}};
    printf("%d\n", w.n->n);
    throw true;
}

int main()
{
    try
    {
        m();
    }
    catch(...)
    {
        puts("error");
    }
    
}