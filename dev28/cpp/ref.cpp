#include <cstdio>
void sum(int a, int b, int& c)
{
    c = a + b;
}

int main()
{
    int a = 4;
    int& b = a;
    b++;
    printf("%d\n", a++);
    printf("%d\n", b);
    int c = 8;
    b = c;
    printf("%d\n", b);
    int p = 4, q = 9, r;
    sum(p, q, r);
    printf("%d\n", r);
}