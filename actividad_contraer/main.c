#include <stdio.h>
#include <stdlib.h>

int contraer (int* array, int tam, int index);

int main()
{

    int* vector;
    int tam_n;

    vector = malloc(sizeof(int)*10);

    for(int i=0; i<10; i++)
    {
          *(vector+i)= i+1;
    }

    for(int i=0; i<10; i++)
    {

         printf("%d\n", *(vector+i));

    }




    tam_n = contraer(vector, 10, 5);



     printf("CONTRAIDO \n");

     for(int i=0; i<tam_n; i++)
    {

         printf("%d\n", *(vector+i));

    }


    return 0;
}

int contraer (int* array, int tam, int index)
{
    int retorno=0;

    for(int i=index; i<tam-1; i++)
    {
            *(array+i)=*(array+(i+1));


            }

    array = realloc(array, sizeof(int)* (tam-1));

     if(array!= NULL)
     {
         retorno=tam-1;
     }


    return retorno;

}
