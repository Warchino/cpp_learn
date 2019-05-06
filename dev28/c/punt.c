# include <stdio.h>

void g()
{
	int* p = (int*) 0xDEADBEEF;
	printf("%p\n",p);
	printf("%d\n",*p);
}
int main()
{
	puts("Hola");
	g();
	return 0;
}
