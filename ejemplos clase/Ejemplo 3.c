#include<stdio.h>

main()
{
	int x, *p;
	p=&x;

		
	printf("Ingrese un numero: ");
	scanf("%d", p);
	printf("\nEl numero fue: %d->desde la variable\n", x);
	printf("El numero fue: %d->desde el puntero p\n", *p);	
	getch();
	printf("Declaro otro puntero apuntando al anterior:\n");
	int *q;
	q=p;
	printf("El numero fue: %d->desde el puntero q\n", *q);	
	getch();
	printf("Le asigno un nuevo valor al puntero q: ");
	scanf("%d", q);
	
	printf("\nEl numero fue: %d->desde la variable\n", x);
	printf("El numero fue: %d->desde el puntero p\n", *p);
	printf("El numero fue: %d->desde el puntero q\n", *q);	
	
	printf("Las direcciones de memoria: %d--%d--%d", &x, p, q);
}
