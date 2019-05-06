# include <stdio.h>

void g()
{
	int r = 801425;
	printf("%d\f", r);
}

void h()
{
	int m;
	printf("%d\f", m);
}

int main()
{
	g();
	h();
	return 0;
}
