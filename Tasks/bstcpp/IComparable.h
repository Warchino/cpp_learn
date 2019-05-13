#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H

#include "Object.h"

class IComparable : public Object
{
    public:
    virtual int compare_to(const IComparable&) const = 0;
};

#endif // !ICOMPARABLE_H
