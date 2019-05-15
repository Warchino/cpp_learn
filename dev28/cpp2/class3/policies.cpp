#include <cstdio>

struct Animal
{
    virtual ~Animal(){}
    virtual void hablar() const = 0;
};

struct vaca : Animal
{
    void hablar() const override
    {
        puts("muuuuuu");
    }
};

struct perro : Animal
{
    void hablar() const override
    {
        puts("Woof");
    }
};

void f(const Animal& a)
{
    a.hablar();
}

int main()
{
    perro p;
    vaca v;
    f(p);
    f(v);

    return 0;
}

/**
 * Policies una forma de evitar el polimorfismo
 * se evita herencia, pero se realiza en tiempo de compilacion
 * Si es necesario agregar nuevos animales el problema esta en aumentar
 * los tipos
 */

