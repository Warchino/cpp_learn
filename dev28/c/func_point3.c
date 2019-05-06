# include <stdio.h>
# include <stdlib.h>

void mostrar_avance(int n)
{
	printf("%d\n", n);
}

void flash(void (*func)(int))
{
	for(size_t i = 0; i < 100; i++)
	{
		for(int j = 0; j < 10000000; j++)
		{
			void* p = malloc(10000000);
			free(p);
		}
		func(i);
	}
}

int main()
{
	flash(mostrar_avance);
}
