namespace fj
{
    struct item
    {
        int value;
        int* next;
    };
    struct ill
    {
        item* first;
        item* last;
    };

    void init(ill& x)
    {
        x.first = x.last = nullptr;
    }

    void add(ill& x, int p)
    {

    }

    void iterate(const ill& x, void (*p)(int))
    {

    }

    void release(ill& x)
    {
        z
    }
}
