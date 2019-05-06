# include <stdio.h>
# include <stdarg.h>
# include <string.h>

void myprintf(const char* s, ...)
{
	va_list args;
	va_start(args, s);
	while(*s)
	{
		switch(*s)
		{
			case 'I':
				printf("%d\n", va_arg(args, int));
				break;
			case 'S':
				puts(va_arg(args, const char*));
				break;
		}
		s++;
	}
	puts("");
	va_end(args);
}

int main()
{
	int p = 4;
	int q = 6;
	const char* n = "Juan";
	myprintf("ISIS", p,n,q,"hola");
}
