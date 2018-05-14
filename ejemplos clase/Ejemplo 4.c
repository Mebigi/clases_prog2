#include<stdio.h>

main()
{
	int *p, x;
	x=5;
	p=&x;
	printf("Desplazamiento a partir del puntero:\n");
	printf("Direccion de memoria de p: %d\n", p);
	printf("Direccion de memoria de p+1: %d\n", p+1);
	printf("Direccion de memoria de p+2: %d\n", p+2);
	printf("Direccion de memoria de p+3: %d\n", p+3);
	printf("Direccion de memoria de p-1: %d\n", p-1);
	getch();
	printf("Desplazamiento del puntero:\n");
	printf("Direccion de memoria de p: %d\n", p);
	p=p+1;
	printf("Direccion de memoria de p luego del desplazamiento: %d\n", p);	
	
	
}
