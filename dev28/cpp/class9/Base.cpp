#include <string>

class Base
{
    public:
    virtual ~Base(){}
    virtual std::string to_string() const = 0;
};

class IComparable : public virtual Base
{
    public:
    virtual int compare_to(const Base& b) const = 0;
};

class Integer : public virtual Base, public virtual IComparable
{
    int n;
    public:
        Integer(int n):n{n}{}
        std::string to_string() const
        {
            return std::to_string(n);
        }
        int compare_to(const Base& b) const override
        {
            // al usar herencia virtual se deshabilita el static_cast
            // auto& e = static_cast<const Integer&>(b);
            auto& e = dynamic_cast<const Integer&>(b);
            return n- e.n;
        }
};

class A : public virtual Base
{
    public:
    std::string to_string() const override
    {
        return "A";
    }
};

class B : public virtual Base
{
    // implementacion ambigua
    // public:
    // std::string to_string() const override
    // {
    //     return "B";
    // }
};

class C : public A, public B
{

};

int main()
{
    // Base* b = new Integer{18};
    // IComparable* c = new Integer{20};
    // puts(b->to_string().data());
    // printf("%d\n", c->compare_to(*b));
    // delete c;
    // delete b;

    A* a = new C();
    B* b = new C();
    puts(a->to_string().data());
    puts(b->to_string().data());
    delete a;
    delete b;
}

// Problema del triangulo

// Herencia virtual es que discrimina metodos repetidos y quita la ambiguedad