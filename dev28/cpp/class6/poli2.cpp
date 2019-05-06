 #include <cstdio>

struct Animal
{
    virtual ~Animal(){};
    virtual void comunicarse() const = 0;
    // si se iguala a 0 entonces es un metodo abstracto;
    // pero se llaman metodos virtuales puros
    // Por lo que hace que toda la clase es abstracta
};

struct Felino: Animal
{
    protected:
    Felino(){};
};

struct Perro: Animal
{
    void comunicarse() const override
    {
        puts("Woof Woof");
    }
};

struct Vaca: Animal
{
    void comunicarse() const override
    {
        puts("Muuuuuhhh");
    }
};

struct Gato:Felino
{
    /* data */
};


void hacerAlgo(const Animal& a)
{
    a.comunicarse();
}

int main()
{
    Perro p;
    Vaca v;
    // Animal a;
    hacerAlgo(p);
    hacerAlgo(v);
}


// Las clases ABC
// Abstract Base Class
// las cuales solo tienen firmas
// menos el destructor