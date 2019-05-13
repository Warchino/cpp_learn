#include <cstdio>


template <int N>
void star()
{
    for (size_t i = 0; i < N; i++)
    {
        printf("*");
    }
    puts("");
    
}


int main()
{
    // para calculos muit complejos cuando queremos que el compilador lo haga
    // porque muchos calculos se pueden realizar en tiempo de compilacion
    // int long char
    star<6>();
    star<8>();
    star<4>();
    // constexpr lo hace en tiempo de compilacin
    // const lo hace en tiempo de ejecucion.
    constexpr int p = 11;
    star<p>();
}