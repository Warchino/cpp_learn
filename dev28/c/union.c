# include <string.h>
# include <stdio.h>

typedef union
{
	char str[32];
	int num;
	double dbl;
} item;

int main()
{
	item x;
	strcpy(x.str, "hola");
	puts(x.str);
	x.num = 0x00616263;
	printf("%x\n", x.num);
	//x.double = 4.453;
	puts(x.str);
}
