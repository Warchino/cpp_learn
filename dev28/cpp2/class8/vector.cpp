#include <cstdio>
#include <vector>
#include <iostream>

struct Shape
{
    virtual ~Shape()
    {
        puts("No me quiero ir");
    }

    virtual double get_area() const = 0;
};

struct Circle : Shape
{
    double r;
public:
    Circle(double r) : r{r} {}
    double get_area() const override
    {
        return 3.14159 * r * r;
    }
};

struct Square : Shape
{
    double side;
public:
    Square(double side) : side{side}
    {}
    double get_area() const override
    {
        return side * side;
    }
};

int main()
{
    std::vector<Shape*> fs;
    fs.push_back(new Circle{4});
    fs.push_back(new Circle{8});
    fs.push_back(new Square{10});
    // IMprime cero porque todo se guarda como shape
    for(auto& f : fs)
    {
        std::cout << f->get_area() << std::endl;
    }

    for(auto& f : fs)
    {
        delete f;
    }
}