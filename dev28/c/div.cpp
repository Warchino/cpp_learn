# include <stdio.h>

int dividir(int a, int b, int* r)
{
	if ( b == 0)
	{
		return 0;
	}
	*r = a/b;
	return 1;
	
}
int main()
{
	int a = 96;
	int b = 4;
	int r ;
	if(!dividir(a, b, &r))
	{
		puts("Divide  by zero");
	}else
	{
		printf("%d\n", r);
	}
}
