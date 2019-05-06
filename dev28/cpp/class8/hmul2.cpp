#include <string>

class Base1
{
private:
    int n;
public:
    Base1(int n):n{n}
    {
    }

    int get_n() const
    {
        return n;
    }
    ~Base1(){};
};

class Base2
{
private:
    std::string str;
public:
    Base2(const std::string& str):str{str}
    {}
    const std::string& get_str() const
    {
        return str;
    }
    ~Base2(){};
};

class Derived : private Base1, private Base2
{
    public:
        Derived(int id, const std::string& name)
        :Base1{id}, Base2{name}
        {
        }
        ~Derived(){}

    void print() const
    {
        printf("%d, %s\n", get_n(), get_str().data());
    }
};

int main()
{
    Derived d{12352534,"Miguel Garcia"};
    // puts(d.get_str().data());
    d.print();
}
