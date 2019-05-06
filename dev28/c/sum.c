 # include <stdio.h>
 
int sum (int , int);			//prototype
int sum3 (int , int, int);		//prototype

int main()
{
	int m = 5;
	int n = 2;
	int p = 8;
	int r1 = sum(m, n);
	int r2 = sum3(m, n, p);
	printf("%d\n", r1);
	printf("%d\n", r2);
	return 0;
}

int sum(int a, int b)
{
	return a + b;
}

int sum3(int a, int b, int c)
{
	return a + b + c;
}
