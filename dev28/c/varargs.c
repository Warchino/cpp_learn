# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int sumar(size_t n, ...)
{
	va_list args;
	// Primer parametro son los argumentos
	// n no es el numero de elementos
	// es el ultimo parametro antes de los puntos
	va_start(args, n);
	int s = 0;
	for (size_t i = 0 ; i < n; i++)
	{
		s+= va_arg(args, int);
	}
	// se libera la varargs
	va_end(args);
	return s;
}

int main()
{
	int s = sumar(5, 6, 8, 4, 8, 9);
	int r = sumar(7, 1, 3, 9, 11, 14,6 ,2);
	printf("%d %d \n",s ,r);
}
