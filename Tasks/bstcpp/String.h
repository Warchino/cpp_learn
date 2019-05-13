#ifndef STRING_H
#define STRING_H

#include "IComparable.h"
#include <string>

class String : public IComparable
{
    std::string s;
    public:
    String(const std::string&);
    std::string to_string() const;
    int compare_to(const IComparable&) const;
    bool equals(const Object&) const;
};

#endif // !STRING_H
