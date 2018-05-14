#include<stdio.h>

void modificaEntero(int*);

main()
{
	int entero=4;
	printf("El entero antes de ser pasado como parametro de la funcion: %d", entero);
	modificaEntero(&entero);
	getche();
	printf("El entero despues de ser pasado como parametro de la funcion: %d", entero);
}

void modificaEntero(int *miEntero)
{
	*miEntero=*miEntero+5;
}
