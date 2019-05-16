/**
 * Polimorfismo
 * 
 * cuando.-
 *  Dos instancias de dos subclases de una misma clase base,
 * al recibir un mismo mensaje, reaccionan de diferente manera
 * 
 * mensaje == metodo -> cpp
 * 
 * 
 * -> Se implementa con sobreescritura
 */


#include <string>

using namespace std;

class person
{
    string name;
    size_t id;

    public:
    person(const string& name, size_t id)
    :name{name}, id{id}
    {

    }

    // virtual para polimorfismo
    // virtual void print() const
    virtual void print() const
    {
        printf("(%lu) %s", id, name.c_str());
    }
    
    virtual ~person()
    {
        puts("bye");
    }
};

class student: public person
{
    size_t score;
    public:
    student(const string& name, size_t id, size_t score)
    :person{name, id},
    score{score}
    {
    }

    ~student()
    {
        puts("Bye student");
    }

    void print() const override
    {
        // person::print(); // HIDING esconde el metodo de la clase padre
        printf(" Score %lu ", score);
    }
};

int main()
{
    person* c = new person{"Juan", 123};
    c->print();
    delete c;

    student* d = new student{"Omar", 456, 70};
    d->print();
    delete d;

    puts("******");
    person* e = new student("Axel", 32434, 60);
    e->print();
    delete e; // llama al destructor de la clase base
}

/**
 * Si se pone virtual entonces se crea un puntero extra en tu objecto
 * que se llama VTABLE
 * que son tablas de elementos virtuales y crece en memoria
 * Y llamar a mtodos virtuales cuesta
 * De un objeto->vtable->ejecutaMetodo
 * el compilador no tiene poder sobre el virtual
 * 
 * 
 */