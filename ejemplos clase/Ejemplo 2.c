#include<stdio.h>

int main()
{
    int x, *p;
    
    x = 10;
    
    
    p = &x;
    
    printf("\nMuestro la direccion de memoria de x: ");
    getch();
    
    printf(" %d \n\n", &x);
   	getch();
    
    printf("Muestro la direccion de memoria donde apunta el puntero p: ");
    getch();
    
    printf("%d \n\n", p);
    getch();
    
    printf("Muestro el contenido de x: ");  
    getch();
    
    printf("%d \n\n", x);
    getch();
    
    
    printf("Muestro el contenido de la variable apuntada por p: "); 
    getch();
    
    printf("%d \n\n", *p);
    getch();
    
    
    printf("Muestro la direccion de memoria de p: ");     
    getch();
    
    printf("%d \n\n", &p); 
    getch();
    
     printf("Escribo 15 en la variable apuntada por el puntero   *p = 15; \n\n ");  
     *p = 15;   
    getch();
    
    printf("Ahora el valor de x es: ");
    getch();
    printf("%d \n\n", x);
    getch();
    
   
    system("pause");
    
    
    return 0;
}
    
    
