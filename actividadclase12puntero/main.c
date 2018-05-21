#include <stdio.h>
#include <stdlib.h>
#define TAM 10


void MostrarArray1(int [], int);
void MostrarArray2(int [], int);
void MostrarArray3(int *, int);
int MostrarArray4(int *, int);

int main()
{
    int vector[]={9,1,2,7,4}; // se esta declarando un puntero a una direccion de memoria el SO reserva un espacio de memoria 5 X sice-off
    //int vector[]; esto esta mal necesito decirle cuantos elementos debo reservar
    //int* punteroArray = NULL;




   // MostrarArray1(vector, 5);
    //MostrarArray2(vector, 5);
   // MostrarArray3(vector, 5);

   if(MostrarArray4(vector, 5))
   {
        printf("\nMensaje Array nulo\n");
   }



    return 0;
}

void MostrarArray1(int lista[], int tam)
{
    int i;


         printf("\nMostrar Array Notacion Array\n");
         for (i=0 ; i<tam ; i++)
    {
        printf("%d, ", lista[i]);

    }


}


void MostrarArray2(int lista[], int tam)
{
    int i;

         printf("\nMostrar Array Notacion puntero\n");
         for (i=0 ; i<tam ; i++)
    {
        printf("%d, ",*(lista+i));

    }


}

void MostrarArray3(int * Array, int tam)
{
    int i;

    printf("\nMostrar Array Notacion Array\n");
    for (i=0 ; i<tam ; i++)
    {
        printf("%d, ", Array[i]);

    }


}
//puntero puede venir nulo o una direccion inaccesible esta ocupada por SO.

int MostrarArray4(int * Array, int tam)
{
    int i;
    int retorno=-1;//es verdadero

    if(Array != NULL)
    {
        retorno=0;// cero siempre es falso
        printf("\nMostrar Array Notacion Puntero\n");
        for (i=0 ; i<tam ; i++)
        {
            printf("%d, ",*(Array+i));

        }
    }
    return retorno;
}

