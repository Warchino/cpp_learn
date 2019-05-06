#include <cstdio>
#include <string>

class Object
{
    public:
    virtual std::string to_string() const
    {
        return std::to_string((long long) this);
    }
    
    virtual bool equals(const Object& obj) const
    {
        return this == &obj;
    }

    virtual ~Object() {}
};

class Integer: public Object
{
    int n;
    public:
        Integer(int n): n{n} {};
        bool equals(const Object& src) const override
        {
            // return n == ((const Integer&)src).n;
            // static_cast<> en tiempo de compilacion castea
            return n == static_cast<const Integer&>(src).n;
        }
        std::string to_string() const override
        {
            return std::to_string(n);
        }
        int get() const
        {
            return n;
        }
};

class String: public Object
{
    std::string str;
    public:
        String(const std::string& str)
        :str{str}
        {}
        std::string to_string() const override
        {
            return str;
        }
        bool equals(const Object& src) const override
        {
            return str == static_cast<const String&>(src).str;
        }
};

class Stack : public Object
{
    Object** items;
    size_t n;
    public:
        Stack()
        :items{static_cast<Object**>(malloc(0))},
        n{0}
        {
        }

        ~Stack()
        {
            for (size_t i = 0; i < n; i++)
            {
                delete items[i];
            }
            free(items);
        }
        bool is_empty() const
        {
            return n == 0;
        }

        void push(Object* obj)
        {
            items = static_cast<Object**>(realloc(items, sizeof(obj)*(n+1)));
            items[n++] = obj;
        }

        Object* pop()
        {
            return items[--n];
        }

        std::string to_string() const override
        {
            std::string s;
            for (int i = (int)n-1; i >= 0; i--)
            {
                s += items[i]->to_string();
                s += "\n";
            }
            return s;
        }
};


int main()
{
    Stack s;
    s.push(new Integer{125});
    s.push(new Integer{214});
    s.push(new String{"Hola"});
    puts(s.to_string().data());
    int sum = 0;
    while (!s.is_empty())
    {
        auto e = s.pop(); // e es Object*
        printf("num->%d\n", ((Integer*)e)->get());
        // dynamic cast <tipo de dato al que quieren castear>
        // por lo menos tiene que tener un metodo virtual
        // si es hijo castear, si no es hijo entonces retorna null
        auto f = dynamic_cast<Integer*>(e);
        sum += f ? f->get() : 0;
        delete e;
    }
    printf("la suma es->%d\n", sum);
    
    // printf("%s\n", s.to_string().data());
}