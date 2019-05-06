# include <stdio.h>

_Bool verify_if_even(int n)
{
	return n % 2 == 0;
}

_Bool great_than_20(int n)
{
	return n > 20;
}

void print_if(const int* p, size_t n, _Bool (*func) (int))
{
	// Cualquier elemento que evalua a una funcion y devuelve un booleano
	// predicado
	for(size_t i = 0; i < n; i++)
	{
		if(func(p[i]))
		{
			printf("%d\n", p[i]);
		}
		puts("-------");
	}
}

int main()
{
	int x[] = {6, 25, 48, 72, 12 ,20, 4};
	//print_if(x, 7, verify_if_even);
	print_if(x, 7, great_than_20);
}
