#include <cstdio>

void modify(int* num)
{
    auto lambda = [num]() { *num = 5; };
    lambda();
}

int main()
{
    int b = 2;
    int *a = &b;
    modify(&b);

    printf("numero->%d\n", b);
    return 0;
}
