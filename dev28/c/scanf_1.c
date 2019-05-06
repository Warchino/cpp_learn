# include <stdio.h>

int main()
{
	puts("Ingrese tres numeros separadois por :");
	int a = 0, b = 0, c = 0;
	//Es una forma de parsear con un cierto formato pero al primer error sale
	scanf("%d:%d:%d", &a, &b, &c);
	printf("%d\n", a+b+c);
}
