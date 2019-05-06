# include <stdio.h>

int main()
{
	// se llaman opaque poiter
	// porque no nos interesa como estan implementados
	// en windows hay handler
	// Es algo mas encapsulado
	FILE* f = fopen("dias.txt", "w");
	// elsegundo parametro es el modo de apertura
	// w es write y wt es 'write text'
	
	const char* dias[] = {"Lunes","Martes","Miercoles", "Jueves",
		"Viernes", "Sabado", "Domingo"};
	// f si devuelve null entonces ocurrio un error
	if (f == NULL)
		return -4;
	for (int i=0; i < 7; i++)
	{
		// Elaypuej pariente del printf
		//fprintf(f, "%s\n", dias[i]);
		fputs(dias[i], f);
		fputs("\n", f);
	}
	// Un programa escribe en el buffer de memoria para no escribir
	// con demasiados accesos al disco
	// Para ello sirve el flush para limpiar el buffer de memoria
	// Pero el buffer de memoria optimiza la cantidad de accesos
	// de escritura al disco
	
	// Por cada vez que escriba se cierre, para evitar un flush en el 
	//disco
	fclose(f);
	// fflush(f) limpia el buffer pero reduce el rendimiento pero no es
	// recomendable usar NUNCA
}
