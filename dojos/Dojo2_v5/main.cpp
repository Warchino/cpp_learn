#include "Integer.h"
#include "String.h"
#include "HashMap.h"
#include <cstdio>
#include <ctime>

void show(const IHashable &h, const Object &val)
{
    printf("%s %s\n", h.to_string().data(), val.to_string().data());
}

int main()
{
    Object *obj = new Integer{5};
    Object *str = new String{"Hello World"};
    puts(str->to_string().data());
    puts(obj->to_string().data());
    delete str;
    delete obj;

    HashMap hm;
    hm.add(new Integer(10), new String("diez"));
    hm.add(new Integer(20), new String("veinte"));
    hm.add(new Integer(30), new String("treinta"));
    hm.add(new Integer(40), new String("cuarenta"));
    hm.add(new Integer(50), new String("cincuenta"));
    hm.add(new Integer(60), new String("sesenta"));
    hm.add(new Integer(70), new String("setenta"));

    hm.erase(Integer{60});
    hm.erase(Integer{10});
    hm.erase(Integer{30});
    hm.erase(Integer{50});
    hm.erase(Integer{40});
    hm.erase(Integer{40});

    HashMap hm2;
    auto t0 = clock();
    for (size_t i = 0; i < 10000'000; i++)
    {
        hm2.add(new String(std::to_string(i)), new Integer(i));
    }
    auto t1 = clock();
    //hm2.iterate(show);
    puts("************");
    puts(hm2[String("999999")].to_string().data());
    printf("the time is %lf\n", ((double)t1 - t0) / CLOCKS_PER_SEC);

    puts(hm[Integer(20)].to_string().data());

    try
    {
        puts(hm[Integer(25)].to_string().data());
    }
    catch (const std::exception &e)
    {
        puts(e.what());
    }

    puts("******");

    hm.iterate(show);
}