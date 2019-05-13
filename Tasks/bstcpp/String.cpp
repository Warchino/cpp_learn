#include "String.h"
#include <iostream>

String::String(const std::string& src)
:s{src}
{
    
}

std::string String::to_string() const
{
    return s;
}

int String::compare_to(const IComparable& src) const
{
    auto aux = static_cast<const String*>(&src);
    return s.compare(aux->s);
}

bool String::equals(const Object& o) const
{
    auto aux = static_cast<const String&>(o);
    return s.compare(aux.s) == 0;
}

