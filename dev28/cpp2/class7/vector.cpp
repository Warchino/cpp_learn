// reemplzao al printf o cout formatlib
#include <iostream>
#include <vector>

class Punto
{
    int x, y;
public:
    Punto(int x, int y)
    : x{x}, y{y}
    {}

    void show() const
    {
        std::cout << x << "," << y << std::endl;
    }
};


int main()
{
    std::vector<Punto> ps;
    ps.emplace_back(5, 8);
    ps.emplace_back(14, 2);
    ps.emplace_back(18, 20);
    
    for(auto i = ps.rbegin(); i != ps.rend(); ++i)
    {
        i->show();
    }

    return 0;
}