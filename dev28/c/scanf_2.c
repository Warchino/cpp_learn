# include <stdio.h>

int main()
{
	puts("Ingresa tu nombre completo");
	char nombre[200];
	//scanf("%s", nombre);
	// gets(nombre) significa peligro porque si se sobrepasa puede 
	//acceder a espacios de memoria que no le corresponden
	fgets(nombre, 200, stdin);
	puts(nombre);
	//el scanf solo saca palabras pero separa con espacios enters en su codigo
	puts("***");
}
