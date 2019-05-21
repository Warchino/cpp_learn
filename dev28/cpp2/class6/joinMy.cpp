#include <string>

template <typename T>
std::string join_2(const T& a)
{
    return std::to_string(a);
}


template <class...Args>
std::string join_2(const Args&...args)
{

    return join_2(args...);
}

template<>
std::string join_2<bool> (const bool& a)
{
    return a ? "true" : "false";
}

template <class...Args>
void join(const char* sep, const Args&...args)
{
    std::string joined = "";
    joined += join_2(args...) + sep;
    puts(joined.data());
}


int main()
{

    join(",", "Juan", "Maria", 24, true, "hola");
    join(".", 192, 168, 0, 1);
// cadenas numeros enteros y booleanos
    return 0;
}