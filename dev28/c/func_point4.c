//funciones genericas
# include <stdio.h>
void sumar(int a, int b, void* c)
{
	printf("%d\n", (a+b));
	puts((const char*) c);
}

void restar(int a, int b, void* c)
{
	printf("%d\n", (a-b));
	void (*proc)() = (void (*)())c;
	proc();
}

void diga_fin()
{
	puts("-Fin-");
}

void hacer_algo(void (*p)(int, int, void*), int a, int b, void* c)
{
	puts("Hola");
	p(a,b,c);
	puts("Chau");
}

int main()
{
	hacer_algo(sumar, 4, 5,"****");
	hacer_algo(restar, 14, 6, diga_fin);
}
