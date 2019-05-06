# include <stdio.h>
# include <string.h>
# include <stdlib.h>

struct Persona
{
	char nombre[32];
	char apellido[32];
	size_t anio_de_nac;
};

typedef struct
{
	char marca[16];
	char modelo[16];
	size_t anio;
} Carro;

void init(struct Persona* h, const char* n, const char* a, const size_t b)
{
	strcpy(h->nombre, n);
	strcpy(h->apellido, a);
	h->anio_de_nac = b;
}

void mostrar(const struct Persona* s)
{
	puts(s->nombre);
	puts(s->apellido);
	printf("%lu\n", s->anio_de_nac);
}
int main()
{
	struct Persona p;
	init(&p, "Omar", "Vera", 1978);
	mostrar(&p);
	struct Persona* q;
	q = (struct Persona*)malloc(sizeof(struct Persona));
	init(q, "Lady", "Gaga", 1982);
	mostrar(q);
	free(q); q = NULL;
	struct Persona f;
	init(&f, "Alan", "Walker", 1995);
	puts((const char*)&f);
	puts((char*)&f +32);
	printf("%d\n",(*((int*)((char*)&f +64))));
}
