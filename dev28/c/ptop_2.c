int main()
{
	int** lista = (int**)malloc(2*sizeof(int*));
	lista[0] = (int*) malloc(2*sizeof(int))
	lista[1] = (int*) malloc(3*sizeof(int))
	lista[0][0] = 6;
	lista[0][1] = 8;
	lista[1][0] = 4;
	lista[1][1] = 10;
	lista[1][2] = 20;
	free(lista[0]);
	free(lista[1]);
	free(lista);
}
