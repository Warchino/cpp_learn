#include <cstdio>

struct A
{
    int a;
};

struct B : A
{
};

struct C : A
{
};

struct D : B, C
{
};

int main()
{
    D d;
    d.B::a = 648;
    d.C::a = 5;
    printf("%d\n", d.B::a);
    printf("%d\n", d.C::a);
}