#include <stdio.h>
#include <stdlib.h>

int main()
{


    int a = -1;
    int *punteroInt;
    int **punteroPuntero;

    if(a)
    {
         printf("Hello world!\n");
    }


    int arrayInt[5]={1,3,5,6,7};
    int* p1;

    int* p2;

    p1= &arrayInt[4];

    p2= arrayInt;

    char cadena[10]= {'h','o','l','a'};

    char* puntero;

    puntero = cadena;

    printf("puntero = %s\n", cadena);

    printf("puntero = %c\n", *(puntero+2));


     printf("arrayInt[4]= %d p1 = %d p2 = %d", arrayInt[4], *p1, *p2);


    punteroInt= &a;

    punteroPuntero = &punteroInt;


    printf("entero %p -  punteor a entero %p la dm de puntero a entero %p - puntero a puntero %p - dm de punteropuntero %p", &a, punteroInt, &punteroInt, punteroPuntero, &punteroPuntero);

      printf("entero %d - valor que apunta punteor a entero %d  valor .a variable de puntero al que  punteropuntero %d", a, *punteroInt, **punteroPuntero);



    return 0;


}
