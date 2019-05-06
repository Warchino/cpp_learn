# include <stdlib.h>
# include <string.h>
# include <stdio.h>


typedef struct
{
	char* marca;
	// menor rendimiento porque no se declara ya cuanto se necesita
	//porque se pide al sistema
	char* modelo;
	size_t anio;
} Carro;

char* clone_str(const char* s)
{
	size_t len = strlen(s);
	char* cc = (char*) malloc(len+1);
	memcpy(cc, s, len+1);
	return cc;
}

void carro_init(Carro* d, const char* marca, const char* modelo, size_t anio)
{
	d->marca = clone_str(marca);
	d->modelo = clone_str(modelo);
	d->anio = anio;
}

void carro_print(const Carro* z)
{
	puts(z->marca);
	puts(z->modelo);
	printf("%lu\n", z->anio);
}

void carro_release(Carro* c)
{
	free(c->marca);
	free(c->modelo);
	c->marca = c->modelo = NULL;
	c->anio = 0;
}

int main()
{
	//Carro c;
	//carro_init(&c, "VM", "Peta", 1967);
	//carro_print(&c);
	//carro_release(&c);
	Carro* cs = (Carro *)malloc(sizeof(Carro)*3);
	carro_init(cs, "VM", "Peta", 1967);
	carro_init(cs+1, "Peugeout", "Z60", 2001);
	carro_init(&cs[2], "Lamborgini", "Gallardp", 2007);
	for(Carro* i=cs; i!= cs+3; i++)
	{
		carro_print(i);
	}
	for(Carro* i=cs; i!= cs+3; i++)
	{
		carro_release(i);
	}
	free(cs);
}
