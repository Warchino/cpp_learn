# include <stdio.h>

int main()
{
	char h[] = { 'h', 'o', 'l', 'a', '\0'};
	//char h[] = "hola";
	char j[] = "mundo";
	const char* f = "miercoles";
	puts(h);
	puts(j);
	puts(f);
	j[0] = 'c';
	puts(j);
	f[2] = 'e';
	puts(f);
}
