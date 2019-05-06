# include <cstring>
# include <cstdio>

class Person
{
    // en C los struct todo es publico por defect
    // en c++ las clases son publicas por defecto
    // Atributos
    char fn[32];
    char ln[32];
    size_t ci;
    
    public:
    // Metodo
    // El const al final dice que no se modificara los atributos de la clase
    // y solo llama a metodos constantes 
    void mostrar() const
    {
        printf("(%zu) %s %s\n",ci, ln, fn);
    }

    Person(const char* fn, const char* ln, size_t ci)
    {
        // this representa la instancia y es un puntero
        strcpy(this->fn, fn);
        strcpy(this->ln, ln);
        this->ci = ci;
    }
    Person():Person("", "", 0) // C++11
    {
        
    }

    void set_fn(const char* fn)
    {
        strcpy(this->fn, fn);
    }

    void set_ln(const char* ln)
    {
        strcpy(this->ln, ln);
    }

    void set_ci(size_t ci)
    {
        this->ci = ci;
    }
};
/**
 * El constructor tiene el mismo nombre del struct pero sin tipo de retorno
 */

auto main() -> int
{
    Person p;
    p.mostrar();
    p.set_fn("John");
    p.set_ln("Smith");
    p.set_ci(468952);
    p.mostrar();
    Person q{"Julian", "Assange", 1961};
    // Inicializacion uniforme y es por eso que se crea un objeto con llaves {}
    // para que no se raye el compilador cuando lee parentesis
    q.mostrar();
    int r{25};
    int m{2};
    printf("%d\n", r);
    printf("%d\n", m);
    // Otra manera de inicializar
    auto w = int{22};

}