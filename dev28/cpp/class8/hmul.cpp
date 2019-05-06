#include <cstdio>

struct A
{
    int x;
};
struct B
{
    int y;
};

struct Punto: A,B
{
    void mostrar() const
    {
        printf("%d, %d\n", x, y);
    }
};

int main()
{
    Punto p;
    p.x = 2;
    p.y = 4;
    p.mostrar();
}
