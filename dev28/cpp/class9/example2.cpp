#include <cstdio>

struct X { int x; virtual ~X(){}; };
struct Y: virtual X{};
struct Z: virtual X{};
struct W final: Y, Z {};

// Con final acaba la jerarquia
// struct Aurora : W
// {
//     /* data */
// };


int main()
{
    W p;
    p.x = 45;
    printf("%d\n", p.x);
}
