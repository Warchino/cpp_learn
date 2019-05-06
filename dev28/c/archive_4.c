# include <stdio.h>

void imprimir_item(const int c, const char* d, double p, FILE* f)
{
	fprintf(f, "%5d %-16s %8.2f %8.2f\n", c, d, p, p*c);
}

void imprimir(const int* cs, const char** ds, const double* ps,
				size_t n, FILE* f)
{
	for(size_t i = 0; i < n; i++)
	{
		imprimir_item(cs[i], ds[i], ps[i], f);
	}
}

int main()
{
	int cantidades[] = {10, 8, 4};
	const char* descripciones[] = {"Pantalones", "Camisas", "Zapatos"};
	double precios[] = {80, 90, 9000};
	FILE* f = fopen("factura.txt", "w");
	imprimir(cantidades, descripciones, precios, 3, f);
	imprimir(cantidades, descripciones, precios, 3, stdout);
	fclose(f);
}
