#include <cstdio>
#include <vector>
#include <iostream>
#include <memory>

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
    std::vector<std::unique_ptr<Shape> > fs;
    fs.emplace_back(new Circle{4});
    fs.emplace_back(new Circle{8});
    fs.emplace_back(new Square{10});
    fs.push_back(std::unique_ptr<Shape>(new Circle{9}));
    fs.push_back(std::make_unique<Square>(20));
    // IMprime cero porque todo se guarda como shape
    // El puntero es unico
    // auto& p = fs[0];
    // std::cout << p->get_area() << std::endl;
    auto p = std::move(fs[0]);
    std::cout << p->get_area() << std::endl;
    for(auto& f : fs)
    {
        std::cout << f->get_area() << std::endl;
    }

}