#include <cstdio>
#include <string>

template <typename T>
struct linked_list_node
{
    T elem;
    linked_list_node<T>* next;
};

template <typename T>
class linked_list
{
    linked_list_node<T>* first;
    linked_list_node<T>* last;
public:
    linked_list(): first{nullptr},
    last{nullptr}
    {}
    void add(const T& x)
    {
        auto nn = new linked_list_node<T>{x, nullptr};
        if (first == nullptr)
        {
            first = last = nn;
            return;
        }
        last->next = nn;
        last = nn;
    }

    void iterate(void (*p)(const T&))
    {
        auto aux = first;
        while (aux)
        {
            p(aux->elem);
            aux = aux->next;
        }
        
    }

    // Destruye a su manera segun el tipo que ese esta enviando
    ~linked_list()
    {
        auto aux = first;
        while (aux)
        {
            auto next = aux->next;
            delete aux;
            aux = next;
        }
        
    }
};
// template <typename T>
// void pepe(const T& a)
// {

// }

void si(const int& e)
{
    printf("%d\n", e);
}

void ss(const std::string& e)
{
    puts(e.data());
}

int main()
{
    // VENTAJA: codigo optimo para el tipo de dato usado
    // pero el binario es mas binario.
    // El compilador tiene que conocer la i,plementacion
    // por ello toda la implementacion esta en el h
    // Solo genera codigo de las funciones que se usa
    linked_list<int> x;
    x.add(10);
    x.add(50);
    x.add(35);
    x.iterate(si);

    linked_list<std::string> y;
    y.add("hello"); 
    y.add("world");
    y.add("bye");
    y.iterate(ss);
    return 0;
}