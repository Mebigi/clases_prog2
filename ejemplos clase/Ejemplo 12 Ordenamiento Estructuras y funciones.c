#include<stdio.h>
#define TAM 5
typedef struct 
{
	char nombre[20];
	int nota;
} eAlumno;

void cargarArray(eAlumno*);
void mostrarArray(eAlumno*);
void ordenarArray(eAlumno*);

main()
{
	eAlumno alu[TAM], *p, aux;
	int i, j;
	p=&alu;
	
	
	cargarArray(p);
	mostrarArray(p);

	

	
	getch();
	system("cls");
	printf("\nOrdenamos:\n");
	
	ordenarArray(p);
	mostrarArray(p);
   	 
}


void cargarArray(eAlumno* sender)
{
	int i;
	for(i=0; i<TAM; i++)
	{
		printf("Ingrese nombre: ");
		fflush(stdin);
		gets((sender+i)->nombre);
		printf("Ingrese nota: ");
		scanf("%d", &(sender+i)->nota);	
	}	
}
void mostrarArray(eAlumno* sender)
{
	int i;
	for(i=0; i<5; i++)
	{
		printf("\n%s con nota: %d", (sender+i)->nombre, (sender+i)->nota);
	}
	
	/*printf("\nO de esta forma:\n");
	for(i=0; i<5; i++)
	{
		printf("\n%s con nota: %d", (*(p+i)).nombre, (*(p+i)).nota);
	}*/
}
void ordenarArray(eAlumno* sender)
{
	int i,j;
	eAlumno aux;
	for(i=0;i<TAM-1;i++)
	    for(j=i+1;j<TAM; j++)
	       if((sender+i)->nota > (sender+j)->nota)
	       {
		   	   aux=*(sender+i);
		   	   *(sender+i)=*(sender+j);
		   	   *(sender+j)=aux;
		   }
		   
}
