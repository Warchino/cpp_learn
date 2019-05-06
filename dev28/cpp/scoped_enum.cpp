#include <cstdio>

enum class Priority
{
    RED, BLUE, BLACK
};
enum class Color
{
    RED, GREEN, BLACK
};

int main()
{
    Priority p = Priority::RED;
    Color c = Color::RED;
    if (c == Color::RED)
    {
        puts("Hola\n");
    }
    
}