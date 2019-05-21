#include <string>

// template <class T, class U>
// std::string join_2(const char* sep, const T& a, const T& b)
// {

//     return std::to_string(a) + sep + std::to_string(b);
// }
void print(int q)
{
    printf("%d", q);
}

void print(const char* s)
{
    printf("%s", s);
}

void print(bool s)
{
    printf("%s", (s ? "true" : "false"));
}

template <class P>
void join(const char* sep, const P& p)
{
    print(p);
    printf("\n");
}

template <class Type, class...Args>
void join(const char* sep, const Type& a,const Args&...args)
{
    // std::string joined = "";
    // joined += join_2(sep, a, args...);
    // puts(joined.data());
    print(a);
    print(sep);
    join(sep, args...);
}

int main()
{

    join(",", "Juan", "Maria", 24, true, "hola");
    join(".", 192, 168, 0, 1);
// cadenas numeros enteros y booleanos
    return 0;
}