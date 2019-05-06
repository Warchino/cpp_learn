# include <stdio.h>

int main()
{
	int i=0;
	EVAL:
		if (i == 10)
			goto FIN;
		printf("%d\n", i);
		i++;
		goto EVAL;
	FIN:
		puts("Bye");
	return 0;
}
