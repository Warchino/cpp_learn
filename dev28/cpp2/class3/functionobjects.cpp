#include <cstdio>

struct P
{
    void operator()(int a, int b) const
    {
        printf("%d\n", a+b);
    }
};


int main()
{
    P p;
    p(10,15);
}


// Funtion Object
// Es un objeto que se comporta como una funcion
// Sirve cuando se tiene un objecto en el que se necesita procesar ciertos
// metodos y atributos los cuales se enceuntran almacenados y cambian en el tiempo