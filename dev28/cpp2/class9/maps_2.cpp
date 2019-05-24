#include <map>
#include <iostream>

struct ci
{
    size_t number;
    std::string city;

};

struct ciless
{
    // es mucho mejor sobrecargar el operador parentesis
    // porque asi se puede sustituir a un puntero a funcion
    bool operator()(const ci& a, const ci& b) const
    {
        if (a.number < b.number)
        {
            return true;
        }
        
        if (b.number < a.number)
        {
            return false;
        }

        return a.city < b.city;
        
    }
};

bool cilessfunc(const ci& a, const ci& b)
{
    // Tie devuelve un tupla de referencias
    // Tiene variois tipos en la tupla
    return std::tie(a.city, a.number) < std::tie(b.city, b.number);
}

int main()
{
    std::map<ci, std::string, ciless> ps;
    ps[{3456789, "pts"}] = "armin van burren";
    ps[{6815426, "scr"}] = "david ghetta";
    ps[{1234567, "lpz"}] = "avicii";
    ps[{6942174, "cba"}] = "tiesto";

    for (auto& e : ps)
    { 
        std::cout << e.first.number << " " << e.second << std::endl;
    }
    std::map<ci, std::string, bool (*)(const ci&, const ci&)> qs{cilessfunc};
    qs[{3456789, "pts"}] = "armin van burren";
    qs[{6815426, "scr"}] = "david ghetta";
    qs[{1234567, "lpz"}] = "avicii";
    qs[{6942174, "cba"}] = "tiesto";
    for (auto& e : qs)
    { 
        std::cout << e.first.number << " " << e.second << std::endl;
    }
    

}
