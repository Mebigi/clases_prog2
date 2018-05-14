#include<stdio.h>

main()
{
	int *p, x[4];
	p=&x;//o p=&x[0];
	
	printf("Cuanto vale x[0]? %d\n", &x[0]);
	printf("Cuanto vale p? %d\n", p);
	getch();
	printf("Cargo el vector...\n");
	x[0]=15;
	x[1]=5;
	x[2]=17;
	x[3]=26;
	
	printf("Muestro desde el puntero: \n");
	for(int i=0; i<4; i++)
	{
		printf("%d-", *(p+i));
	}
	getch();
	printf("\nIngresando valores desde el puntero: \n");
	
	for(int i=0; i<4; i++)
	{
		printf("Ingrese un valor: ");
		scanf("%d", p+i);
	}
	
	printf("\nMuestro desde el puntero: \n");
	for(int i=0; i<4; i++)
	{
		printf("%d-", *(p+i));
	}
	getch();
	
	printf("\nMuestro desde el vector: \n");
	for(int i=0; i<4; i++)
	{
		printf("%d-", x[i]);
	}
		

	
	
}
