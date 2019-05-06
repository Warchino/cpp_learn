# include <stdio.h>

typedef enum
{
	ALTA = 10,
	MEDIA = 36,
	BAJA = 80
} prioridad;

//typedef enum
//{
	//BAJA,NORMAL,ALTA
//} estatura;
//Su vivencia no es local sino es global
	
int main()
{
	prioridad p;
	p = MEDIA;
	printf("%d\n", p);
	p++;
	printf("%d\n", p);
	if (p == MEDIA)
	{
		puts("Media");
	} else if (p == ALTA)
	{
		puts("ALTA");
	}
}
