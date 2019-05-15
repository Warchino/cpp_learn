#include <cstdio>
#include <cstdlib>
#include <cstring>

// template <typename T>
// struct W
// {
//     T* val;
//     ~W()
//     {
//         delete val;
// Esta implementacion no sirve porque no siempre le van a llegar 
// punteros por new, porque es posible que le lleguen punteros por malloc
//     }
// };
template <typename T>
struct deleter
{
    void release(T* x)
    {
        delete x;
    }
};
// especializacion
template <>
struct deleter<char>
{
    void release(char* x)
    {
        free(x);
    }
};


template <typename T, typename Deleter = deleter<T> >
struct W
{
    T* val;
    ~W()
    {
        Deleter d;
        d.release(val);
    }
};



struct A
{
    A()
    {
        puts("Hi");
    }
    ~A()
    {
        puts("Bye");
    }
};

struct file_deleter
{
    void release(FILE* f)
    {
        fclose(f);
        puts("That's all folks!!");
    }
};

int main()
{
    W<A> a{new A{}};
    char* aux = (char*) malloc(5);
    strcpy(aux, "hola");
    W<char> b{aux};
    puts(b.val);

    FILE* f = fopen("h.txt", "w");

    fprintf(f, "Hola \n");
    W<FILE, file_deleter> wf{f};

    return 0;
}

/**
 * Es genial porque se trta de evitar el poliformismo con estas cosas
 * pero el rendimiento del programa es mejor a comparacion de objetos
 */