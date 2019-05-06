# include <stdio.h>

int sum(int a, int b)
{
	return a+b;
}

int max(int x, int y)
{
	return x > y? x : y;
}

int main()
{
	int (*ptr) (int, int);
	ptr = sum;
	printf("%d\n", ptr(18, 45));
	ptr = max;
	printf("%d\n", ptr(100, 200));
}
