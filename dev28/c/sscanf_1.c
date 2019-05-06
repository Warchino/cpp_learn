# include <stdio.h>

int main()
{
	const char* buffer = "10:20:30";
	int a = 0, b  = 0, c = 0;
	// el sscanf lee un bloque de memoria o un buffer
	//sirve para recoger un cierto de datos con un cierto formato 
	sscanf(buffer, "%d:%d:%d", &a, &b, &c);
	// se utiliza harto para convertir cadenas a numeros
	printf("%d\n", a+b+c);
	const char* pi = "3.1415";
	double pid;
	sscanf(pi, "%lf", &pid);
	printf("%g\n", pid*2);
}
