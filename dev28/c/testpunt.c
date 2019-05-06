# include <stdio.h>

int main()
{
	int a = 1;
	int* q = &a;
	printf("%p\n",q);
	(*q)++;
	//printf("%d\n",*q);
	printf("%d\n",a);
	
	return 0;
}
