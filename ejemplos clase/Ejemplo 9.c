#include<stdio.h>

typedef struct 
{
	char nombre[20];
	int nota;
} eAlumno;


main()
{
	eAlumno alu1, *p;
	p=&alu1;
	
	printf("Ingrese nombre: ");
	fflush(stdin);
	gets(p->nombre);
	printf("Ingrese nota: ");
	scanf("%d", &p->nota);
	
	printf("El alumno es: %s con nota: %d", p->nombre, p->nota);
}
