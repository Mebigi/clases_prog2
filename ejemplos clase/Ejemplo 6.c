#include<stdio.h>

main()
{
	char palabra[20]="mi palabra", *p;
	p=palabra;
	
	puts(p);
	getch();
	printf("\nRecorro cada letra de la palabra:\n");
	for(int i=0; i<20; i++)
	{
		if(*(p+i)!='\0')
			printf("%c\n", *(p+i));
	}
	getch();
	
}
