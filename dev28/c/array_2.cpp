# include <stdio.h>

void mostrar(const int* a, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("%d\n", *a++);
	}
}

void fib(int* a, size_t n)
{
	if (n > 0) a[0] = 1;
	if (n > 1) a[1] = 1;
	for (size_t i = 2; i < n; i++)
	{
		a[i] = a[i-1] + a[i-2];
	}
}

int main()
{
	int p[10];
	fib(p, 10);
	mostrar(p, 10);
}
