#include <cstdio>
#include <cstdlib>
#include <string>

struct Object
{
    virtual const std::string to_string() const = 0;
};

struct IComparable : virtual Object
{
    virtual int compare(const Object& o) const = 0;
};

class Integer : public virtual Object, public virtual IComparable
{
    int n;
    public:
    Integer(int n):n{n}{}
    const std::string to_string() const override
    {
        return std::to_string(n);
    }

    int compare(const Object& o) const override
    {
        auto num = dynamic_cast<const Integer*>(&o);
        return n - num->n;
    }

};


class String : public virtual Object, public virtual IComparable
{
    std::string str;
    public:
    String(const std::string& str):str{str}{}
    const std::string to_string() const override
    {
        return str;
    }

    int compare(const Object& o) const override
    {
        auto s = dynamic_cast<const String*>(&o);
        return str.compare(s->str);
    }
};

class node : public virtual Object
{
    Object* key = nullptr;
    Object* value = nullptr;
    node* left = nullptr;
    node* right = nullptr;
    public:
    node(Object* key, Object* value)
    :key{key}, value{value}
    {};
    const std::string to_string() const override
    {
        return std::to_string((long long) this);
    }
    
    Object* getKey()
    {
        return key;
    }
    Object* getValue()
    {
        return value;
    }
    
    node* getRight()
    {
        return right;
    }
    
    node* getLeft()
    {
        return left;
    }
};

class bst : virtual Object
{
    private:
    node* root;
    typedef void (*Function)(const Object&, const Object&);
    void add_recursive(node* bstnode, Object& key, Object& value)
    {
        if(bstnode == nullptr)
        {
            bstnode = new node{&key, &value};
            return;
        }   
        
        auto aux = dynamic_cast<const Integer*>(&value);
        int c = aux ? 
        aux->compare(*bstnode->getValue()) :  dynamic_cast<const String*>(&value)->compare(*bstnode->getValue());
        
        if (c == 0)
        {
            return;
        }

        if (c > 0)
        {
            add_recursive(bstnode->getRight(), key , value);
        }else
        {
            add_recursive(bstnode->getLeft(), key , value);
        }
    }

    public:
    bst(/* args */)
    {
        root = nullptr;
    };
    ~bst(){};
    const std::string to_string() const override
    {
        return "BST";
    }

    void add(Object* key, Object* value)
    {
        puts("Aniade!");
        add_recursive(this->root, *key, *value);
    }

    void iterate(Function)
    {
    }

};

void show_pair(const IComparable& key, const Object& value)
{
    printf("%s: %s\n", key.to_string().data(), value.to_string().data());
}

int main()
{
    bst b;
    b.add(new Integer(1), new String("uno"));
    b.add(new Integer(10), new String("diez"));
    b.add(new Integer(5), new String("cinco"));
    // b.add(new Integer(8), new String("ocho"));
    // b.add(new Integer(7), new String("siete"));
    // b.add(new Integer(2), new String("dos"));

    // b.iterate(show_pair);
    // Object* obj;
    // if (b.try_find(Integer(2), obj))
    // {
    //     puts(obj->to_string().data());
    // }
    // else
    // {
    //     puts(“Not found”);
    // }
    return 0;
}