# include <stdio.h>
size_t calctam(const char* a)
{
	const char* orig = a;
	while (*a) 
	{
		printf("%s\n",a);
		a++;
	}
	return a - orig;
}

int main()
{
	const char* p = "septiembre";
	char q[] = "hello world";
	size_t tamp = calctam(p);
	printf("%lu\n", tamp);
	size_t tamq = calctam(q);
	printf("%lu\n", tamq);
}
