/*	Cargar un vector de 20 elementos usando punteros. Una vez terminada la carga y por medio de un menú de opciones realizar lo siguiente:
a-	Ingresar un número y mostrar en que posición dentro del vector se encuentra
b-	Ingresar la posición del vector y mostrar el número que se encuentra en esa posición
Si la posición es incorrecta o el número no se encuentra se debe mostrar un mensaje de error.
Ambos puntos deben ser hechos por medio de punteros.*/

#include <stdio.h>
#include <conio.h>

int main()
        {
        	 int vec[5],i,*p,j,aux;
        	 p=&vec;
        	 //cargar
        	 for(i=0; i<5;i++)
        	   {
        	   	   printf("Ingrese un numero: ");
        	   	   scanf("%d",p+i);
		       }
		       
		       
		      printf("Ingrese posici%cn:",164);
		      scanf("%d",&aux);
		      
		      for(i=0;i<5;i++)
		        {
		        	if(i==aux)
		        	  {
					  
		        	  printf("%d",*(p+i)); 
		        	 
		              }
		        	
				}
				if(i==5)
				printf("no se encuentra esa posici%cn",164);
				getch();
			  
			  
		      
		       
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
			   	   printf(" \n %d - ",*(p+i));
			   }
			getch();
		}


