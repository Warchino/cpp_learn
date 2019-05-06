#include <cstdio>

void c()
{


    // Busca donde se boto la excepcion en el exception handler
    // y si no hay busca en la funcion donde esta la exeption 
    // y si nohay ningun manejador entonces el programa termina

    throw 214U;
    // int* q = nullptr;
    // *q += 18;
    // int x = 6, y = 0;
    // int z = x / y;
    // Segmentation fault no se puede agarrar
    // Tampoco errores logicos 
}

void b()
{
    puts("Starting b");
    c();
    puts("Ending b");
}

void a()
{
    puts("Stating a");
    b();
    puts("Ending a");
}


int main()
{
    try
    {
        a();
        puts("Happy bye");
    }
    catch(const char* e)
    {
        printf("Error: %s\n", e);
    }
    catch(int e)
    {
        printf("codigo: %d\n", e);
    }
    puts("Bye anyway");

}