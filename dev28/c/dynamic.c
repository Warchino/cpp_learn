# include <stdio.h>
# include <stdlib.h>

void imprimir(int* s, size_t n)
{
	for(size_t i = 0; i < n; i++)
		printf("%d\n", s[i]);
}


int main()
{
	int* p = (int*)malloc(5 * sizeof(int));
	if (p == NULL)
	{
		puts("OOPS");
		exit(-4);
	}
	p[0] = 8;
	p[1] = 25;
	p[2] = 4;
	p[3] = 0;
	p[4] = 40;
	imprimir(p, 5);
	free(p);
	p = NULL;
	int g[] = {1, 8 ,5};
	imprimir(g, 3);
}
