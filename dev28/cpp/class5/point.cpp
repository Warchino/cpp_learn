#include <cstdio>
#include <cstdlib>

class point
{
    int x;
    int y;
    public:
        point(int x = 0, int y = 0)
        :x{x}, y{y}
        {
        }

        void print() const
        {
            printf("(%d,%d)\n", x, y);
        }

        ~point()
        {
            puts("Bye");
        }
        void set_values(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

};

int main()
{
    point p{6,8};
    p.print();
    // auto* q = (point*) malloc(sizeof(point)); // no llama al constructor por lo que no sirve
    point* q = new point(6, 9); // Pide en el HEAP pero es mas lento
    // new desventajas
    // no se puede hacer como aritmetica de punteros
    // tampoco realloc

    q->print();
    // free(q);
    delete q;

    point* ps = new point[3];
    // operador new[]
    // std::bad_alloc es porque no encuentra espacio en memoria
    ps[0].set_values(9,5);
    ps[1].set_values(2,1);
    ps[2].set_values(0,4);
    for (size_t i = 0; i < 3; i++)
    {
        ps[i].print();
    }
    // delete[]
    delete[] ps;
}


// POD: Plain Old Data
// Tipo primitivo
// array de pods
// structs de pods
// union de pods
// para todo esto se puede usar malloc realloc free