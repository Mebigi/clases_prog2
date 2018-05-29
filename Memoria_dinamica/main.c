#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector; //en la pila y apunta a heap si lo construyo con malloc consecutivos
    int vec[10]; ////en la pila y apunta la pila reservo 10 * 4 bytes = 40 bytes consecutivos
    int* aux;

    //vector = malloc(sizeof(int)*10); // reservo para 10

    //realloc puede devolver =, NULL o una direccion de memoria distinta porque la sigueinte posicion de memoria esta ocupada.
    //si da nULL yo quiero preservar los valores ingresado por malloc entoences utilizo un auxiliar;

    vector = calloc(10, sizeof(int));//inicializa todo los elementos en 0 es similar a vec[10]={0};

    //vector = realloc(vector, sizeof(int)*15); // el proble es si da NULL porque no tiene espacio, entoeces es mejor en aux

    aux = realloc(vector, sizeof(int)*15);
    if (aux)
    {
     vector = aux;

         //print realloc
    for(int i=10; i<15; i++) // desde 10 poprque los otros ya los habia cargado
    {
        *(vector+i)= i+1;

    }

    for(int i=0; i<15; i++)
    {
        *(vector+i)= i+1;
         printf("%d\n", *(vector+i));

    }

    }
    //realloc por menos

     aux = realloc(vector, sizeof(int)*7); // como es menos emdevuleve la misma direccion de memoria los valores puesen seguir estando pero la memorai esta libre para otras cosas

     for(int i=0; i<15; i++)
        {

             printf("%d\n", *(vector+i));

        }




    /*for(int i=0; i<10; i++)
    {
        *(vector+i)= i+1;

    }

    for(int i=0; i<10; i++)
    {
        *(vector+i)= i+1;
         printf("%d\n", *(vector+i));

    }*/

    return 0;
}
