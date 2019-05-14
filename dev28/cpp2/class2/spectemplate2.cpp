#include <cstdio>
#include <string>

template <class T>
class Wrapper
{
    T value;
public:
    Wrapper(const T& x) : value{x}
    {}
    const T& get() const
    {
        return value;
    }
};

struct Point
{
    int x, y;
};

// Especializacion de clase
template <>
class Wrapper<Point>
{
    Point p;
public:
    Wrapper(const Point& p) : p{p} {}
    void print() const
    {
        printf("(%d %d)\n", p.x, p.y);
    }
};


struct A
{
    ~A(){puts("Adios mundo cruel");}
    void say_hi() const
    {
        puts("Hi");
    }
};

// Si queremos recibir una referencia
// template <>
// class Wrapper<A*>
// {
//     A* val;
// public:
//     Wrapper(A* val) : val{val} {}
//     const A& get() const
//     {
//         return *val;
//     }
//     ~Wrapper(){delete val;}
// };

struct B : A
{
    /* data */
};

// Se creo el tipo de especializacion
template <typename T>
class Wrapper<T*>
{
    T* val;
public:
    Wrapper(T* val) : val{val} {}
    const A& get() const
    {
        return *val;
    }
    ~Wrapper(){delete val;}
};

int main()
{
    Wrapper<int> p{10};
    printf("%d\n", p.get());

    Wrapper<std::string> q{"hola"};
    puts(q.get().data());

    Wrapper<Point> r{Point{5, 25}};
    r.print();

    Wrapper<Point*> r2{new Point{10, 10}};
    // printf("%d\n", r2.get()->x);
    // delete r2.get();

    Wrapper <A*> w{new A{}};
    w.get().say_hi();
    
    Wrapper<B*> w2{new B{}};
    w2.get().say_hi(); // deberia de comportarse como A

    return 0;
}
