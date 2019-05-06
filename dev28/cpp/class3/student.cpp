#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>


class student
{
    size_t id;
    char *name;

public:
    student(size_t id, const char *name)
        : id{id} //Initialization list
    // forma preferida para inicializar atributos
    {
        auto len = strlen(name);
        this->name = (char *)malloc(len + 1);
        memcpy(this->name, name, len + 1);
    }

    void print() const
    {
        printf("(%lu) %s \n", id, name);
    }

    ~student()
    {
        printf("CHAU %s\n", name);
        free(name);
    }

    // constructor que utiliza para copiar o clonar los objetos
    // student(const student &src)
    //     : id{src.id}
    // {
    //     auto len = strlen(src.name);
    //     name = (char *)malloc(len + 1);
    //     memcpy(name, src.name, len + 1);
    // }
    // C11 se puede llamar al mimso constructor
    student(const student &src)
        : student{src.id, src.name}
    {
    }

    // regla de 3
    // si hay malloc es necesario que se reimplemente el destructor, contructor e igual

    // void operator = (const student& src)
    student &operator=(const student &src)
    {
        if (this == &src)
        {
            return *this;
        }
        this->~student();
        id = src.id;
        auto len = strlen(src.name);
        name = (char *)malloc(len + 1);
        memcpy(name, src.name, len + 1);
        return *this;
        this->~student();
        // supuestamente se puede hacer un realloc
    }
};

class grupos_de_a_2
{
    student a;
    student b;

    public:
        grupos_de_a_2(const student& a, const student& b)
        :a{a}, b{b}
        {
        }
        void print() const
        {
            puts("Integrantes");
            printf("-"); a.print();
            printf("-"); b.print();
        }
        // ~grupos_de_a_2();
};

int main()
{
    student p{2, "Omar Vera"};
    p.print();
    // RAII: Resource adquisition is initialization
    // el destructor se ejecuta cuando se sale del scope
    // if (1 == 1)
    // {
    //     return -1;
    // }

    // p.print();

    // {
    //     student q{3, "Eva peron"};
    //     q.print();
    // }
    // puts("xD");
    student z{2, "Antonio jose de sucre"};
    auto q = z; // copy
    q.print();
    // por este problema donde se libera la memoria crea un crash 1(arriba)

    student r{666, "romulo rojas"};
    r = q; // assignment
    r.print();



    // // grupos dos
    // student x{4, "Favio salinas"};
    // grupos_de_a_2 g{x, student{6, "pepe el toro"}};
    // g.print();
    return 0;
}
