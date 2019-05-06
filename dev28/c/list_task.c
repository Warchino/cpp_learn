# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct decldllitem
{
	struct decldllitem* back;
	struct decldllitem* next;
} dllitem;

typedef struct
{
	dllitem* first;
	dllitem* last;
} dll;

void dll_init(dll* p)
{
	p->first = p ->last = NULL;
}

void dll_pushback(dll* q, const char* s)
{
	int len = strlen(s);
	dllitem* ni = (dllitem*)malloc(sizeof(dllitem) + len + 1);
	ni->back = q->last;
	ni->next = NULL;
	memcpy(ni+sizeof(dllitem), s, len + 1);
	if (q->first == NULL)
	{
		ni->back = NULL;
		q->first = q->last = ni;
		return ;
	}
	q->last->next = ni;
	q->last = ni;
}

void dll_pushfront(dll* q, const char* s)
{
	int len = strlen(s);
	dllitem* ni = (dllitem*)malloc(sizeof(dllitem) + len + 1);
	ni->back = NULL;
	ni->next = q->first;
	memcpy(ni+sizeof(dllitem), s, len + 1);
	if (q->first == NULL)
	{
		ni->next = NULL;
		q->first = q->last = ni;
		return ;
	}
	q->first->back = ni;
	q->first = ni;
}

void dll_print_forward(const dll* p)
{
	dllitem* aux = p->first;
	while(aux)
	{
		puts(((char*)(aux+sizeof(dllitem))));
		aux = aux->next;
	}
}
void dll_print_backward(const dll* p)
{
	dllitem* aux = p->last;
	while(aux)
	{
		puts(((char*)(aux+sizeof(dllitem))));
		aux = aux->back;
	}
}
void dll_release(dll* p)
{
	dllitem* aux = p->first;
	while(aux)
	{
		dllitem* next = aux->next;
		free(aux);
		aux = next;
	}
}

int main()
{
	dll p;
	dll_init(&p);
	dll_pushback(&p, "hola");
	dll_pushback(&p, "amigos");
	dll_pushback(&p, "c++");
	dll_pushfront(&p, "fundacion");
	dll_print_forward(&p);
	dll_print_backward(&p);
	dll_release(&p);
}
