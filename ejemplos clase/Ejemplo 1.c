#include<stdio.h>

main()
{
	char x, *punt;//Declaracion del puntero
	punt=&x;//Asignamos al puntero la direccion de memoria de la variable x
		
	printf("Ingrese un caracter: ");
	*punt=getche();//Guardo el caracter ingresado el la posicion apuntada
	printf("\nEl caracter fue: %c->desde la variable\n", x);
	printf("El caracter fue: %c->desde el puntero\n", *punt);	
}
