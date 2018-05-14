#include<stdio.h>

typedef struct 
{
	char nombre[20];
	int nota;
} eAlumno;


main()
{
	eAlumno alu[5], *p, aux;
	int i, j;
	p=&alu;
	
	for(i=0; i<5; i++)
	{
		printf("Ingrese nombre: ");
		fflush(stdin);
		gets((p+i)->nombre);
		printf("Ingrese nota: ");
		scanf("%d", &(p+i)->nota);	
	}

	for(i=0; i<5; i++)
	{
		printf("\n%s con nota: %d", (p+i)->nombre, (p+i)->nota);
	}
	printf("\nO de esta forma:\n");
	for(i=0; i<5; i++)
	{
		printf("\n%s con nota: %d", (*(p+i)).nombre, (*(p+i)).nota);
	}
	getch();
	system("cls");
	printf("\nOrdenamos:\n");
	
	for(i=0;i<5-1;i++)
	    for(j=i+1;j<5; j++)
	       if((p+i)->nota > (p+j)->nota)
	       {
		   	   aux=*(p+i);
		   	   *(p+i)=*(p+j);
		   	   *(p+j)=aux;
		   }
		   
    for(i=0; i<5; i++)
	{
		printf("\n%s con nota: %d", (p+i)->nombre, (p+i)->nota);
	}	 
}
