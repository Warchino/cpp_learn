#ifndef BST_H
#define BST_H

#include "IComparable.h"
#include "Object.h"

struct node
{
    node* left = nullptr;
    node* right = nullptr;
    IComparable* key = nullptr;
    Object* value = nullptr;
};

class bst
{
    node* root;
    public:
    bst();
    ~bst();
    void add(IComparable*, Object*);
    void iterate(void (*func)(const IComparable&, const Object&)) const;
    bool try_find(const IComparable&, const Object&) const;
};

#endif // !BST_H
