#include <unordered_map>
#include <iostream>
#include <string>

struct carid
{
    std::string s;
    int id;
};

struct caridhash
{
    // Se implementa el functor
    size_t operator()(const carid& a) const
    {
        std::hash<std::string> h;
        return h(a.s) + a.id;
    }
};
struct caridequal
{
    bool operator()(const carid& a, const carid& b) const
    {
        // return a.s == b.s && b.id == b.id;
        return std::tie(a.s, a.id) == std::tie(b.s,b.id);
    }
};


int main(int argc, const char** argv)
{
    // para la tabla hash es necesario implementar el operador igual
    std::unordered_map<carid, std::string, caridhash, caridequal> crs;
    crs[{"123ABC", 1}] = "Tyrion Vadin";
    crs[{"214RMM", 1}] = "Eotron Rogue";
    crs[{"197ADN", 1}] = "Mon Warrior";

    for(auto& e : crs)
    {
        std::cout << e.first.s << " " << e.second << std::endl;
    }


    return 0;
}

