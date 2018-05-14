#include<stdio.h>

main()
{
	char palabras[5][20], *p;
	p=palabras;
	
	for(int i=0; i<5; i++)
	{
		printf("Ingrese una palabra: ");
		fflush(stdin);
		gets(p+i*20);
	}
	getch();
	
	for(int i=0; i<5; i++)
	{
		printf("\n%s", p+i*20); 
	}
	
}
