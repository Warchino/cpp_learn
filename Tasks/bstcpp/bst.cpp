#include "bst.h"
#include <cstdio>

bst::bst()
:root{nullptr}
{}


void add_recursive(node*& bst_node, IComparable*& key, Object*& value)
{
    if(bst_node == nullptr)
    {
        bst_node = new node{};
        bst_node->key = key;
        bst_node->value = value;
        return;
    }
    int c = bst_node->key->compare_to(*key);
    if(c == 0)
        return;
    if(c>0)
        add_recursive(bst_node->right, key, value);
    else
        add_recursive(bst_node->left, key, value);
}

void bst::add(IComparable* key, Object* value)
{
    add_recursive(root, key, value);
}

void iterate_recursive(node* bst_node, void (*func)(const IComparable&, const Object&))
{
    if ( bst_node == nullptr)
    {
        return;
    }
    iterate_recursive(bst_node->left, func);
    func(*(bst_node->key), *(bst_node->value));
    iterate_recursive(bst_node->right, func);
}


void bst::iterate(void (*func)(const IComparable&, const Object&)) const
{
    iterate_recursive(root, func);
}

bool find_iterate(const node* bst_node, const IComparable& key, const Object& value)
{
    if(bst_node == nullptr)
    {
        return false;
    }
    int c = bst_node->key->compare_to(key);
    if(c == 0)
    {
        return bst_node->value->equals(value);
    }
    if(c>0)
        return find_iterate(bst_node->right, key, value);
    else
        return find_iterate(bst_node->left, key, value);
}


bool bst::try_find(const IComparable& key, const Object& value) const
{
    return find_iterate(root, key, value);
}



void release(node* bst_node)
{
    if (bst_node == nullptr)
    {
        return;
    }

    release(bst_node->left);
    release(bst_node->right);
    delete bst_node->key;
    delete bst_node->value;
    delete bst_node;
}



bst::~bst()
{
    release(root);
}
