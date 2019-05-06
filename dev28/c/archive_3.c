# include <stdio.h>

int main()
{
	//sprintf() imprime en un buffer
	const char* h = "Homero";
	int k = 50;
	char aux[50];
	sprintf(aux , "%s tiene %d anios", h, k);
	puts(aux);
	// sirve para enviar cadenas recientes que se almacenan en un instante
	
	// el uso mas comun que tiene sprintf es transformar de numeros a str
	// lo malo es que no es una funcion segura porque si se desborda,
	// bota un error
	char x[20];
	sprintf(x, "%d", k);
	puts(x);
}
