# include <stdio.h>

int main()
{
	//scanf lee del teclado
	//fscanf lee de un archivo
	//sscanf lee de un buffer
	puts("Ingresa dos numeros");
	int a = 0, b = 0;
	size_t x = scanf("%d %d", &a, &b);
	//deberia de devolver 2 porque reconoce 2 valores
	printf("%lu\n", x);
	printf("La suma es %d", a+b);
}
