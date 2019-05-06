# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct declsllitem
{
	int value;
	struct declsllitem* next;
} sllitem;

typedef struct
{
	sllitem* first;
	sllitem* last;
} sll;

void sll_init(sll* p)
{
	p->first = p ->last = NULL;
}

void sll_add(sll* p, int n)
{
	sllitem* ni = (sllitem*)malloc(sizeof(sllitem));
	ni->value = n;
	ni->next = NULL;
	if (p->first == NULL)
	{
		p->first = p->last = ni;
		return ;
	}
	p->last->next = ni;
	p->last = ni;
	
}

void sll_release(sll* p)
{
	sllitem* aux = p->first;
	while(aux)
	{
		//free(aux);
		//aux = aux->next;
		//malo porque elimina el punto sin saber su siguiente direccion
		sllitem* next = aux->next;
		free(aux);
		aux = next;
	}
}

void sll_print(const sll* p)
{
	sllitem* aux = p->first;
	while(aux)
	{
		printf("%d\n",aux->value);
		aux = aux->next;
	}
}

int main()
{
	sll x;
	sll_init(&x);
	sll_add(&x, 14);
	sll_add(&x, 24);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_add(&x, 48);
	sll_print(&x);
	sll_release(&x);
}



































































































































































































