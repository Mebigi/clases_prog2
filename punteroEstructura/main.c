#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int datoInt;
    char datoChar;
}eDato;

int main()
{

   /* eDato miDato = {1,'c'};
    eDato miDato2 = {1,'A'};

    eDato lista[2];

    eDato* pDato = NULL;

    //pDato = &miDato;

    lista[0]=miDato;
    lista[1]=miDato2;

    pDato = lista;




    printf("Desde las estructura: %d -- %c\n", miDato.datoInt, miDato.datoChar );
    printf("Desde las puntero: %d -- %c\n", (* pDato).datoInt, (* pDato).datoChar );

    for(int i=0; i<2; i++)
    {
        printf("Desde las puntero array: %d -- %c\n", (* (pDato+i)).datoInt, (*(pDato+i)).datoChar );
    }

*/


    eDato miDato = {1,'c'};
    eDato* pDato = NULL;

    pDato =&miDato;

    //printf("%d", sizeoff(eDato));
    //ventaja de trabajar con punteros que cuando mueve las direcciones de memoria, muevo 4 bytesw en cada swap y no 8 (con 2 varables en este ejemplo), trabajar array distintos tipos de datos


    //operdador flecha es una astrapcion del punto y de * operdador inacceso
    printf("%d -- %c\n", pDato->datoInt, pDato->datoChar);

    return 0;
}
