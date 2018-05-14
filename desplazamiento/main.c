#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numero;
    int* punteroEntero;

    numero=33;
    punteroEntero=&numero;

     printf("\nvalor punteroEntero: %d", punteroEntero);//direccion de memoria de la variable numero
     //ARITMETICA DE PUNTEROS me puedo mover en memoria
     printf("\nvalor punteroEntero+1: %d", punteroEntero+1);//suma 4 si fuera tipo char le suma 1
     printf("\nvalor punteroEntero+1: %d", punteroEntero+2);

    printf("\nvalor punteroEntero+1: %d", punteroEntero+3);
    printf("\nvalor punteroEntero+0: %d", punteroEntero+0);

    printf("\nvalor punteroEntero-1: %d", punteroEntero-1);

    punteroEntero=punteroEntero+1;
    printf("\nvalor punteroEntero: %d", punteroEntero);

    //0x26
    //0x30 3
    //0x38 9
    //0x425
    //int vector[3];  printf("\n%d", vector[0]);//puntero
    // printf("\n%d", vector[1]);//puntero en 1

    /*
    printf("\nvalor punteroEntero antes de asignar: %p", punteroEntero);// ajo con esto porque tira cualquier cosa antes de asignar
    printf("\nvalor punteroEntero  antes de asignar: con & %p", &punteroEntero);

   // hay que estandarizar el puntero cuando lo definimos cuando no lo asignamos directamnte
   int * Puntero = NULL;


    numero=10;
    punteroEntero=&numero;
    //un putero ocupa 4 bytes simpre es el tamaño del  entero
    //
    sizeof(punteroEntero);

    printf("\nvalor punteroEntero: %d",  sizeof(punteroEntero));

    printf("\nvalor punteroEntero: %p", punteroEntero);
    printf("\nvalor punteroEntero: con & %p", &punteroEntero);
    printf("\nvalor punteroEntero: * %p", *punteroEntero);


    printf("\nvalor punteroEntero: %d", punteroEntero);//direccion de memoria del que contiene puntero
    printf("\nvalor punteroEntero: & %d", &punteroEntero);//direccion de memoria del puntero
    printf("\nvalor punteroEntero: * %d", *punteroEntero);//el valor que apunta al puntero


    //como saber si un puntero no tiene asignado un valor No ESTA NULL

    // != NULL

    if( Puntero != NULL)
    {
         printf("\nvalor punteroEntero: * %d", *Puntero);
    }
    else{

        printf("\nEs nulo");// siempre hay que verificar nulidad cuando pasamos a una funcion
    }

    //printf("Hello world!\n");
    */
    return 0;

}
//\\PC1119342\Users\capacita_mecon\Desktop
