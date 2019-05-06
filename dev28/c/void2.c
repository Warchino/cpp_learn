# include <stdio.h>
# include <stdlib.h>
# include <string.h>


//version mas ineficiente porque crea y destruye las copias
typedef struct
{
	void** elems;
	size_t n;
	size_t elemsize;
} ptramylist2;

void pal2_init(ptramylist2* p, size_t size)
{
	p->elems = malloc(0);
	p->n=0;
	p->elemsize = size;
}

void pal2_add(ptramylist2* p, void* e)
{
	void* ce = malloc(p->elemsize);
	memcpy(ce, e, p->elemsize);
	p->elems = (void**) realloc(p->elems, (p->n+1)*sizeof(void*));
	p->elems[p->n++] = ce;
}

void pal2_release(ptramylist2* p)
{
	for(size_t i = 0; i < p->n; i++)
	{
		free(p->elems[i]);
		//p->elems[i] = NULL;
	}
	free(p->elems);
	p->n = 0;
	p->elemsize = 0;
}

int main()
{
	ptramylist2 f;
	pal2_init(&f, sizeof(int));
	int aux = 8;
	pal2_add(&f, &aux);
	aux = 5;
	pal2_add(&f, &aux);
	aux = 40;
	pal2_add(&f, &aux);
	for (size_t i = 0; i < f.n; i++)
	{
		printf("%d\n", *((int*)f.elems[i]));
	}
	pal2_release(&f);
	for (size_t i = 0; i < f.n; i++)
	{
		printf("%d\n", *((int*)f.elems[i]));
	}
}
