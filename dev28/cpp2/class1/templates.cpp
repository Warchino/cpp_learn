#include <cstdio>
#include <string>

// int sum(int a, int b)
// {
//     return a + b;
// }

// double sum(double a, double b)
// {
//     return a + b;
// }

// Por edsta razon al tener la misma estructura se crearon los templates

struct U
{
    int n;
    
};

// 
// Sobre carga de operador
U operator+(const U& a, const U& b)
{
    return U{a.n + b.n};
}
// typename == class es lo mismo
template <class T>
T sum(T a, T b)
{
    return a + b;
}

int main()
{
    auto p = sum(6,8);
    printf("%d\n", p);

    auto q = sum(5.25, 6.48);
    printf("%f\n", q);

// Hay casos qie se le da explicitamente T = string
// Hay casos qie se le da explicitamente T = string
// Hay casos qie se le da explicitamente T = string
    auto s = sum<std::string>("hello", "world");
    puts(s.data());

    auto w = sum(U{6}, U{5});
    printf("%d\n", w.n);
}
