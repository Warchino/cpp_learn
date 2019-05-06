# include <stdio.h>

int main()
{
	FILE* f = fopen("dias.txt", "r");
	//r de read
	if (f == NULL)
	{
		return -25;
	}
	char aux[1000];
	while(fgets(aux, 1000, f))
	{
		//fputs(aux, stdout);
		//// feof lee el archivo mas alla del final del archivo
		//if (feof(f))
		//{
			//break;
		//}
		//if(feof(f))
		//{
			//break;
		//}
		fputs(aux, stdout);
	}
	// hay 3 File*
	// el primero el stdout -> pantalla
	// el stdin -> teclado
	// stderr -> consola de error
	fclose(f);
}
