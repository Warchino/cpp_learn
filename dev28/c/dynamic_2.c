# include <stdio.h>
# include <stdlib.h>

int main()
{
	for(int i = 0; i <= 100000000; i++)
	{
		char* r = (char*)malloc(100);
		if(i % 1000000 == 0)
		{
			printf("%d\n", i / 1000000);
		}
		free(r);
	}
}
