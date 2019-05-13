#include "Integer.h"

Integer::Integer(int n)
:n{n}
{

}

std::string Integer::to_string() const
{
    return std::to_string(n);
}

int Integer::compare_to(const IComparable& comparable) const
{
    auto aux = static_cast<const Integer*>(&comparable);
    return n - aux->n;
}

bool Integer::equals(const Object& o) const
{
    auto aux = static_cast<const Integer*>(&o);
    return n == aux->n;
}

