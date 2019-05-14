#include <cstdio>
#include <string>

template <class T, class U>
struct Q
{
    T a;
    U b;
    auto sum() const -> decltype(a + b)
    {
        return a + b;
    }
};

template <typename T>
struct Q<T, std::string>
{
    T a;
    std::string b;

    void print() const
    {
        puts((b + std::to_string(a)).data());
    }
};


int main()
{
    Q<int, int> q{10, 10};
    printf("%d\n", q.sum());

    Q<int, std::string> q2{10, "hola"};
    q2.print();
    
    Q<double, std::string> q3{3.14, "hola"};
    q3.print();
    // decltype te devuelve el tipo de dato
    int a = 2;
    decltype(a) b = a;

    return 0;
}