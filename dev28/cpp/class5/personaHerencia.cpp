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
    void print() const
    {
        printf("(%lu) %s", id, name.c_str());
    }
    
    ~person()
    {
        puts("bye");
    }
};
// si es private todo lo que se hereda, es privado hacia afuera
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

    void print() const
    {
        person::print(); // HIDING esconde el metodo de la clase padre
        printf(" Score %lu ", score);
    }
};

int main()
{
    // person p{"Jau pepe", 1235423};
    // p.print();
    // puts("");
    
    // student s{"Pablo Palti", 1235, 95};
    // s.print();
    // puts("");

    person* c = new person{"Juan", 123};
    c->print();
    delete c;

    student* d = new student{"Omar", 456, 70};
    d->print();
    delete d;

    puts("******");
    person* e = new student("Axel", 32434, 60);
    ((student*)e)->print();
    delete e; // llama al destructor de la clase base
}
