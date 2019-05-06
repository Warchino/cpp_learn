# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct
{
	char** items;
	size_t n;
} strarrlist;

typedef strarrlist sal;

void sal_init(sal* s)
{
	//valido pero no tanto
	//s->items = NULL;
	//s->n =0;
	s->items = (char**)malloc(0);
	s->n =0;
}

char* clone_str(const char* s)
{
	size_t len = strlen(s);
	char* r = (char*) malloc(len+1);
	memcpy(r, s, len+1);
	return r;
}

void sal_add(sal* ss, const char* s)
{
	char* cc = clone_str(s);
	ss->items = (char**) realloc(ss->items, sizeof(char*)*(ss->n+1));
	ss->items[ss->n++] = cc;
}

void sal_print(const sal* ss)
{
	for(size_t i = 0; i < ss->n; i++)
	{
		puts(ss->items[i]);
	}
}

//void sal_remove(const sal* ss)
//{
	//ss->items = (char**) realloc(ss->items, sizeof(char*)*(ss->n-1));
//}

void sal_release(sal* s)
{
	for(size_t i = 0; i< s->n; i++)
	{
		free(s-> items[i]);
	}
	free(s->items);
	s->items == NULL;
	s->n = 0;
}

int main()
{
	sal x;
	sal_init(&x);
	sal_add(&x,"Pepe");
	sal_add(&x,"Loca");
	sal_add(&x,"123");
	
	
	sal_print(&x);
	sal_release(&x);
	
	sal_init(&x);
	sal_add(&x,"Roooo");
	sal_print(&x);
	
}
