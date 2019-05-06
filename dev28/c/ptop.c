# include <stdio.h>


// const char* = string
// s es un puntero a puntero
void par_impar(int n, const char** s)
{
	*s = n % 2 ? "Impar" : "Par";
}

int main()
{
	const char* x;
	par_impar(12, &x);
	puts(x);
}
