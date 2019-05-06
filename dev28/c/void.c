# include <stdio.h>
# include <stdlib.h>

typedef struct
{
	void** elems;
	size_t n;
} ptramylist;

void pal_init(ptramylist* p)
{
	p->elems = malloc(0);
	p->n=0;
}

void pal_add(ptramylist* p, void* e)
{
	p->elems =(void**) realloc(p->elems, (p->n+1)*sizeof(void*));
	p->elems[p->n++] = e;
}

void pal_release(ptramylist* p)
{
	free(p->elems);
	p->elems = NULL;
	p->n = 0;
}

int main()
{
	//int a = 10;
	//void* p = &a;
	//printf("%p\n", p);
	//printf("%d\n", *p);
	//no se puede porque se deshabilita la aritmetica de punteros
	
	int a = 8, b = 5, c = 25;
	ptramylist p;
	pal_init(&p);
	// se puede copiar los datos en vez de solo enviar la direccion de memoria
	pal_add(&p, &a);
	pal_add(&p, &b);
	pal_add(&p, &c);
	size_t n = p.n;
	for(size_t i = 0; i < n; i++)
	{
		printf("%d\n",*((int*)p.elems[i]));
		//el programador es el que le da el sentido al void* la unica desventaja
	}
	ptramylist q;
	pal_init(&q);
	pal_add(&q, "Hello");
	pal_add(&q, "world");
	for(size_t i = 0; i < q.n; i++)
	{
		puts((char*)q.elems[i]);
	}
	//el free se hace a cada elemento como un for
	pal_release(&p);
	pal_release(&q);
}
