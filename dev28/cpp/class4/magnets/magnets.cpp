#include <cmath>
#include <cstdio>

class Magnets
{
public:
    static double doubles(int maxk, int maxn);
};

double Magnets::doubles(int maxk, int maxn)
{
    double result = 0;
    for (int k = 1; k <= maxk; k++)
    {
        for (int n = 1; n <= maxn; n++)
        {
            result += 1 / (k*pow(n+1, 2*k));
        }
    }
    return result;
}

int main()
{
    printf("magnet->%f\n",Magnets::doubles(1, 10));
    return 0;
}