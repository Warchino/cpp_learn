# include <stdio.h>

void contar(int n)
{
	printf("%d\n", n);
	contar(n+1);
}

int main()
{
	contar(0);
}
