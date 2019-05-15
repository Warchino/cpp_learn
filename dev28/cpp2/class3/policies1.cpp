#include <cstdio>

template <typename HablarPolicy>
struct Animal
{
    HablarPolicy hp;
    void hablar() const
    {
        hp.hablar();
    }
};

struct hablar_perro
{
    void hablar() const
    {
        puts("woof");
    }
};

struct hablar_vaca
{
    void hablar() const
    {
        puts("muuuuu");
    }
};
using perro = Animal<hablar_perro>;
using vaca = Animal<hablar_vaca>;

// template <typename A>
// void f(const A& a)
// {
//     a.hablar();
// };

// Recibe un animal con su respectivo typename
template <typename HP>
void f(const Animal<HP>& a)
{
    a.hablar();
}


int main()
{
    f(perro{});
    f(vaca{});

    return 0;
}
