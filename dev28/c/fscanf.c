# include <stdio.h>
# include <stdlib.h>

typedef struct
{
	int x;
	int y;
} punto;

void imprimir_punto(const punto* q)
{
	printf("(%d,%d)\n", q->x, q->y);
}

int main()
{
	FILE* f = fopen("puntos.txt", "r");
	if (!f) return -16;
	punto p;
	// Devuelve el numero de datos capturados
	while(fscanf(f, "%d:%d", &p.x, &p.y) == 2)
	{
		imprimir_punto(&p);
	}
	fclose(f);
}
