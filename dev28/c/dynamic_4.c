# include <stdlib.h>
# include <stdio.h>

int main()
{
	int* f = (int*) malloc(3*sizeof(int));
	f[0] = 14;
	f[1] = 10;
	f[2] = 489;
	// funcion para aumentar memoria
	f =(int*)realloc(f, 6*sizeof(int));
	f[3] = 10;
	f[4] = 9;
	f[5] = 8;
	for (int* i = f; i!= f+6; i++)
	{
		printf("%d\n",*i);
	}
	free(f);
	f = NULL; // apuntar al espacio 0;
	// ambas lineas son sagradas y es buena practice hacer esto
	free(f);
}
