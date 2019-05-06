#include <cstdio>
#include <string>
#include <stdexcept>

struct Ex
{
    int code;
    std::string msg;

    ~Ex()
    {
        puts("Exception bye");
    }

};

class Ex2 : public std::exception
{
    int code;
    std::string msg;
    public:
    Ex2(int c, const std::string& m)
    :code{c}, msg{m}
    {}
    const char* what() const noexcept override
    {
        return msg.data();
    }

};

void s()
{
    puts("A");
    throw Ex2{14, "File not found"};
    puts("B");
}

void z()
{
        s();
}

int main()
{
    try
    {
        z();
    }
    // siempre enviar referencias constantes
    catch(const std::exception& e)
    {
        puts(e.what());
    }
    
}

// std::exception es la base de las exepciones