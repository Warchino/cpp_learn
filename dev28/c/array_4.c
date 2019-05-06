# include <stdio.h>

int comparar(const char* array, const char* string)
{
	
	//while(*array || *string)
	//{
		//if(*array++ != *string++)
		//{
			//return *array - *string;
		//} 
		//if(*array == 0) break;
	//}
	for (; ; array++, string++)
	{
		if(*array != *string)
		{
			return *array - *string;
		}
		if (*array == 0) break;
	}
	return 0;
}

int main()
{
	const char* j = "avion";
	int cmp = comparar(j, "avion");
	printf("%d\n", cmp);
	return 0;
}
