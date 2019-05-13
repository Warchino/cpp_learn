#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object
{
    public:
    virtual std::string to_string() const = 0;
    virtual bool equals(const Object& stc) const = 0;
    virtual ~Object();
};

#endif // !OBJECT_H
