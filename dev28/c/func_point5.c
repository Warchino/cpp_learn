# include <stdio.h>
# include <stdlib.h>

int c(const void* a, const void* b)
{
	const int* p = (const int*) a;
	const int* q = (const int*) b;
	return *q - *p;
}

int main()
{
	int p[] = {48, 25, 14, 2, 30, 80, 26, 5};
	qsort(p, 8, sizeof(int), c);
	for(int i = 0; i < 8; i++)
	{
		printf("%d\n", p[i]);
	}
}
