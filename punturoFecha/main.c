#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int datoInt;
    char datoChar;
}eDato;

int main()
{

    eDato miDato = {1,'c'};
    eDato miDato2 = {1,'A'};
    eDato* pDato = NULL;

    eDato lista[2];



    //pDato = &miDato;

    lista[0]=miDato;
    lista[1]=miDato2;

    pDato = lista;



    for(int i=0; i<2; i++)
    {
        printf("Desde las puntero array: %d -- %c\n", (pDato+i)->datoInt, (pDato+i)->datoChar );
    }


    return 0;

    //TP2 pasar a puntero. en cada funcion
}
