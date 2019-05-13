#ifndef INTEGER_H
#define INTEGER_H

#include "IComparable.h"

class Integer : public IComparable
{
    int n;
    public:
    Integer(int);
    std::string to_string() const;
    int compare_to(const IComparable&) const;
    bool equals(const Object&) const;
};


#endif // !INTEGER_H
