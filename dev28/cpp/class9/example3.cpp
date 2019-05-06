#include <cstdio>

struct P
{
    int a, b;
public:
    P(int a, int b)
    :a{a}, b{b}
    {
    }
    virtual ~P(){}
};

struct Q : public virtual P
{
    int c;
    public:
    Q(int a, int b, int c)
    :P(a,b), c{c}
    {
    }
};

struct R : public virtual Q
{
    int d;
    public:
    R(int a, int b, int c, int d)
    :P(a, b), Q(a, b, c),  d{d}
    {
    }
};

int main()
{
    R r{1, 2, 3, 4};
    // explicitamente tenemos que llamar a los constructores de los padres
    printf("%d %d %d %d", r.a, r.b, r.c, r.d);
}
