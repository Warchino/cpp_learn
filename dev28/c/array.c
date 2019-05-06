# include <stdio.h>

void mostrar(int* a, size_t n)
{
	//el array funciona como puntero, comunmente mandan como puntero
	//lo malo es que no se sabe si a es array o puntero a entero
	for (size_t i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
	puts("xxx");
}

int main()
{
	int b[] = {6, 8, 4};
	//for (int i = 0; i < 3; i++)
	//{
		//printf("%d\n", b[i]);
	//}
	int c[5];
	c[0] = 8;
	c[1] = 9;
	c[2] = 10;
	c[3] = 11;
	c[4] = 12;
	//mostrar(c, 5);
	//mostrar(b, 3);
	int d[] = {2, 8, 8, 5};
	d[4] = 14;
	d[5] = 42; 
	//prohibido porque puede sobreescribir espacios de memoria
	int* e = d;
	mostrar(d ,6);
	printf("%p\n", *e);
	e++;
	printf("%p\n", *e);
	e++;
	printf("%p\n", *e);
	e++;
	printf("%p\n", *e);
	printf("%d\n", *(--e));
	e = d;
	printf("%d\n", e[3]);
	//e[3] == *(e+3) el compilador lo reconoce asi
	printf("%d\n", 3[e]);
	return 0;
}
