#include <cstdio>

int sum(int a, int b)
{
    return a+b;
}

struct accumulator
{
    int& n;
    int operator()(int a, int b)
    {
        int r = a + b;
        n += r;
        return r;
    }
};

template <typename Proc>
void f(Proc proc, int a, int b)
{
    auto r = proc(a, b);
    printf("%d\n", r);
}

int main()
{
    f(sum, 10, 25);

    int n = 0;
    accumulator acc{n};
    f(acc, 10, 15);
    f(acc, 50, 49);
    f(acc, 70, 80);
    printf("%d\n", n);

    f([](int x, int y){return x+y;}, 50, 50);
    // funcion anonima o lambda
    // puede ser functor o simplemente un puntero a funcion
    int p = 100;
    f([p](int x, int y){return x+y+p;}, 10, 10);

}

// Funtion Object = Functor