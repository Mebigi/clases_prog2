#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void CargarArray(int *, int);
void MostrarArray(int *, int);
void OrdenarArray(int *, int );

int main()
{
    int Array[TAM];
    int* punteroArray = NULL;
    printf("\nel valor puntero %p:", punteroArray);

    punteroArray=Array;// no uso & en este caso porque como es un array el nombre ya indica una direccion de memoria

    CargarArray(punteroArray, TAM);
    OrdenarArray(punteroArray, TAM);
    MostrarArray(punteroArray, TAM);




    printf("Hello world!\n");
    return 0;
}

void CargarArray(int *punteroArray, int tam)
{
    if(punteroArray != NULL)
    {
        for(int i=0; i<tam; i++)
    {
        //printf("\ningresar un Numero");
        //scanf("%d", punteroArray+i);

        *(punteroArray+i)=10+i;
    }


    }

}
void MostrarArray(int *punteroArray, int tam)
{
    int i;

    if(punteroArray != NULL)
    {
        printf("\nel valor ingresado fue\n");
         for (i=0 ; i<tam ; i++)
    {
        printf("%d, ",*(punteroArray+i));

    }

    }

}
void OrdenarArray(int *punteroArray, int tam)
{
    if(punteroArray != NULL)
    {
        int aux;

        printf("\nOrdenado:\n");

        for (int i=0 ; i<tam-1 ; i++)
        {
            for (int j=1 ; j<tam ; j++)
            {
                if(*(punteroArray+i)<*(punteroArray+j))
                {
                    aux= *(punteroArray+i);
                    *(punteroArray+i)=*(punteroArray+j);
                    *(punteroArray+j)=aux;
                }

            }
        }


    }

}
