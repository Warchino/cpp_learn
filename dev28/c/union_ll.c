# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum
{
	LL_STR,
	LL_INT
} ll_type;

typedef struct
{
	ll_type type;
	union
	{
		char* str;
		int num;
	} item;
} value;

typedef struct PITEM
{
	value val;
	struct PITEM* next;
} item;

typedef struct
{
	item* first;
	item* last;
} ll;

void ll_init(ll* x)
{
	x->first = x->last = NULL;
}
void ll_add(ll* x, item*p)
{
	if (x->first == NULL)
	{
		x-> first= x->last = p;
		return ;
	}
	x->last->next=p;
	x->last=p;
}

void ll_add_int(ll*x, int n)
{
	item* ni = (item*) malloc(sizeof(item));
	ni->next = NULL;
	ni->val.type = LL_INT;
	ni->val.item.num = n;
	ll_add(x, ni);
}

void ll_add_str(ll*x, const char* s)
{
	item* ni = (item*) malloc(sizeof(item));
	ni->next = NULL;
	ni->val.type = LL_STR;
	size_t len = strlen(s);
	char* aux = (char*) malloc(len+1);
	memcpy(aux, s, len+1);
	ni->val.item.str = aux;
	ll_add(x, ni);
}

void ll_print(const ll* x)
{
	item* aux = x->first;
	while(aux)
	{
		switch (aux->val.type)
		{
			case LL_INT:
				printf("%d\n", aux->val.item.num);
				break;
			case LL_STR:
				puts(aux->val.item.str);
				break;
		}
		aux = aux->next;
	}
}

void ll_release(ll* x)
{
	item* aux = x->first;
	while(aux)
	{
		item* next = aux->next;
		if (aux->val.type == LL_STR)
		{
			free(aux->val.item.str);
		}
		free(aux);
		aux = next;
	}
}

int main()
{
	ll z; ll_init(&z);
	ll_add_int(&z, 18);
	ll_add_int(&z, 45);
	ll_add_str(&z, "hola");
	ll_add_str(&z, "mundo");
	ll_print(&z);
	ll_release(&z);
	ll_print(&z);
}
