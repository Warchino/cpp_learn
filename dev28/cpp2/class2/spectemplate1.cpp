#include <cstdio>

template <typename T>
void f(T n)
{
    printf("%d\n", n);
}


// Especializacion
template <>
void f<double> (double n)
{
    printf("%f\n", n);
}

int main()
{
    f(2);
    f(5.2);

}