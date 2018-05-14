#include <stdio.h>
#include <conio.h>

main()
{
        	 int vec[5],i,*p,j,aux;
        	 p=&vec;
        	 //cargar
        	 for(i=0; i<5;i++)
        	   {
        	   	   printf("Ingrese un numero: ");
        	   	   scanf("%d",p+i);
		       }
		       
			// ordenar
			
			  for(i=0;i<5-1;i++)
			     for(j=i+1;j<5; j++)
			       if(*(p+i) > *(p+j))
			           {
			           	   aux=*(p+i);
			           	   *(p+i)=*(p+j);
			           	   *(p+j)=aux;
					   }	         
			     
			//mostrar
			for(i=0;i<5; i++)
			   {
			   	   printf("%d - ",*(p+i));
			   }
}

