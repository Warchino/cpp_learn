# include <stdio.h>

void copiar(char* container, const char* array)
{
	//size_t n = 0;
	//while (array[n] != '\0') 
	//{
		//container[n] = array[n];
		//n++;
	//}
	//container[n] = '\0';
	char* orig = container;
	while(*array)
	{
		*orig++ = *array++;
	}
	*orig = 0;
}

void concatenar(char* container, const char* array)
{
	size_t n = 0;
	while (container[n] != '\0') n++;
	size_t a = 0;
	while(array[a] != '\0')
	{
		container[n+a] = array[a];
		a++;
	}
	container[n+a] = '\0';
	//size_t len = clactam (container);
	//copiar(dst+len, src);
	//return dst;
}
int main()
{
	const char* w = "Today is";
	const char* y = "Thursday...";
	char aux[100];
	copiar(aux, w);
	puts(aux);
	concatenar(aux, y);
	puts(aux);
	return 0;
}
