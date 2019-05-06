#include <cstdio>
#include <string>

struct Object
{
    virtual const std::string to_string() const = 0;
};

struct IComparable : virtual Object
{
    virtual int compare(const Object*, const Object*) const = 0;
};

class Integer : public virtual Object
{
    int n;
    public:
    Integer(int n):n{n}{}
    const std::string to_string() const override
    {
        return std::to_string(n);
    }

};


class String : public virtual Object
{
    std::string str;
    public:
    String(const std::string str):str{str}{}
    const std::string to_string() const override
    {
        return str;
    }
};

class node : virtual Object
{
    Object* key = nullptr;
    Object* value = nullptr;
    Object* left = nullptr;
    Object* right = nullptr;
    public:
    node(Object* key, Object* value)
    :key{key}, value{value}
    {};
    const std::string to_string() const override
    {
        return "Node";
    }
    
    Object* getKey()
    {
        return key;
    }
    Object* getValue()
    {
        return value;
    }
    
};

class bst : virtual Object, virtual IComparable
{
    private:
    node* root;
    typedef void (*Function)(const Object&, const Object&);
    void add_recursive(node* bstnode, Object* key, Object* value)
    {
        if(root == nullptr)
        {
            root = new node{key, value};
            return;
        }
        int c = compare(key, bstnode->getKey());
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
        add_recursive(this->root, key, value);
    }

    void iterate(Function)
    {
    }

    int compare(const Object*, const Object*) const override
    {
        return 0;
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
    b.add(new Integer(8), new String("ocho"));
    b.add(new Integer(7), new String("siete"));
    b.add(new Integer(2), new String("dos"));

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