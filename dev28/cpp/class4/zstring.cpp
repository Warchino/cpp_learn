#include <cstdio>
#include <cstring>
#include <cstdlib>

constexpr size_t MAX = 16;

class ztring
{
    char* chars;
    // SSO: small string optimization
    char szo[MAX];
    size_t len;
    public:
    ztring(const char* s = "")
    :len{strlen(s)}
    {
        set_string(s);
    }
    const char* data() const
    {
        return len < MAX ? szo : chars;
    }
    ~ztring()
    {
        if (len >= MAX)
        {
            free(chars);
        }
    }
    ztring(const ztring& s)
    :len{s.len}
    {
        set_string(s.data());
    }

    ztring& operator=(const ztring& src)
    {
        if (this != &src)
        {
            return *this;
        }
        this->~ztring();
        len = src.len;
        set_string(src.data());
        return *this;
    }

    ztring operator+(const ztring& s) const
    {
        auto nlen = len + s.len;
        ztring ns;
        ns.len = nlen;
        if (nlen >= MAX)
        {
            ns.chars = (char*) malloc(nlen+1);
        }
        char* str = nlen < MAX ? ns.szo : ns.chars;
        memcpy(str, data(), len);
        memcpy(str + len, s.data(), s.len+1);
        return ns;

    }

    ztring& operator+=(const ztring& src)
    {
        auto nlen = len + src.len;
        if (len >= MAX)
        {
            chars = (char*) realloc(chars, nlen+1);
            memcpy(chars + len, src.data(), src.len+1);
            len = nlen;
            return *this;
        }

        if (nlen >= MAX)
        {
            chars = (char*) malloc(nlen+1);
            memcpy(chars, data(), len);
            memcpy(chars + len, src.data(), src.len+1);
            len = nlen;
            return *this;
        }
        memcpy(szo + len, src.data(), src.len+1);
        len = nlen;
        return *this;
    }

    bool operator==(const ztring& s) const
    {
        if (this == &s)
        {
            return true;
        }
        if (len != s.len)
        {
            return false;
        }
        return memcmp(data(), s.data(), len) == 0;
    }

    bool operator>(const ztring& s) const
    {
        size_t auxLen = len > s.len ? len : s.len;
        return memcmp(data(), s.data(), auxLen) > 0;
    }

    bool operator<(const ztring& s) const
    {
        size_t auxLen = len > s.len ? len : s.len;
        return memcmp(data(), s.data(), auxLen) < 0;
    }

    bool operator!=(const ztring& s) const
    {
        return !(*this == s);
    }

    bool operator>=(const ztring& s) const
    {
        size_t auxLen = len > s.len ? len : s.len;
        return memcmp(data(), s.data(), auxLen) >= 0;
    }

    bool operator<=(const ztring& s) const
    {
        size_t auxLen = len > s.len ? len : s.len;
        return memcmp(data(), s.data(), auxLen) <= 0;
    }

    ztring& trim()
    {
        size_t left = 0;
        while (this->data()[left] == ' ')
        {
            left++;
        }
        
        size_t right = len-1;
        while (this->data()[right] == ' ' || right == 0)
        {
            right--;
        }
        size_t nlen = right - left + 1;
        if (len == nlen)
        {

            return *this;
        }
        

        if (nlen >= MAX)
        {
            char* aux = (char*) malloc(len+1);
            memcpy(aux, chars, len + 1);
            chars = (char*) realloc(chars, nlen+1);
            memcpy(chars, aux + left, nlen);
            free(aux);
            len = nlen;
            chars[nlen] = '\0';
            return *this;
        }
        const char* aux = this->data();
        memcpy(szo, aux + left, nlen);
        if (len >= MAX)
        {
            free(chars);
        }
        len = nlen;
        szo[nlen] = '\0';
        return *this;
    }

    private:
    void set_string(const char* s)
    {
        if (len >= MAX)
        {
            chars = (char*) malloc(len+1);
            memcpy(chars, s, len+1);
        }else
        {
            memcpy(szo, s, len+1);
        }
    }

};

int main()
{
    // ztring s = "Hola";
    // puts(s.data());
    // ztring r = "Antonio Jose de Sucre";
    // puts(r.data());

    // auto p = r;
    // puts(p.data());
    // auto x = s;
    // puts(x.data());
    // p = "Segmentation";
    // puts(p.data());
    // // si explicit ztring(const char* s)
    // // entonces la {linea algo} no funciona porque no encuentra el compilador un constrcutor 
    // // de esa forma

    // ztring h = "hello";
    // ztring w = "world";
    // auto hw = h + " " + w;
    // puts(hw.data());

    // auto hw2 = hw + " of C++ segmentation fault";
    // puts(hw2.data());

    // ztring b = "today";
    // b += "is";
    // b += "Tuesday, April 24";
    
    // puts((b += "2019").data());


    ztring z = "               Hello World magic world of narnia   ";

    puts(z.trim().data());
    printf("Length -> %lu\n", strlen(z.data()));

    ztring a{"ab"};
    ztring b{"aBC"};

    puts("---------comparators---------");
    puts(">=");
    puts(a >= b ? "true" : "false");
    puts(strcmp(a.data(), b.data()) >= 0 ? "true" : "false");
    puts(">");
    puts(a > b ? "true" : "false");
    puts(strcmp(a.data(), b.data()) > 0 ? "true" : "false");
    puts("<=");
    puts(a <= b ? "true" : "false");
    puts(strcmp(a.data(), b.data()) <= 0 ? "true" : "false");
    puts("<");
    puts(a < b ? "true" : "false");
    puts(strcmp(a.data(), b.data()) < 0 ? "true" : "false");
    puts("==");
    puts(a == b ? "true" : "false");
    puts(strcmp(a.data(), b.data()) == 0 ? "true" : "false");
    puts("!=");
    puts(a != b ? "true" : "false");
    puts(strcmp(a.data(), b.data()) != 0 ? "true" : "false");
    // operator==
    // operator!=
    // operator>=
    // operator>
    // operator<=
    // operator<
    // trim();
// es posible usar strcmp
    return 0;
}