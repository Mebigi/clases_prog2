#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAM_M 10




void cargarMovie(EMovie *lista)
{
    int index;

    index = obtenerEspacioLibre(lista);

    if (index!= -1)
    {

        getString("TITULO:",(lista+index)->titulo, 3,19);
        (lista+index)->duracion=IngresarEntero("DURACION en minutos:", 15, 300);
        getString("Ingrese Descripcion:",(lista+index)->descripcion, 10, 49);
        (lista+index)->duracion=IngresarEntero("Puntaje:", 1, 10);
        getString("URL imagen:",(lista+index)->linkimage, 3, 49);
        (lista+index)->idmovie = index+1;

    }
}

int agregarPelicula(EMovie *x)
{
    int retorno=-1;
	FILE *f;

   /* f = fopen("listamovie.dat", "rb");

    fread(x,sizeof(EMovie),TAM_M,f);

    fclose(f);
*/

    f = fopen("listamovie.dat","wb");
    if(f == NULL)
		{
			retorno=1;
		}

	fwrite(x,sizeof(EMovie),TAM_M,f);

	fclose(f);

	return retorno;
}


int obtenerEspacioLibre(EMovie *lista)
{
    int index = -1;

    for(int i=0; i<TAM_M; i++)
    {
        if((lista+i)->idmovie==0 && lista != NULL)
        {
            index=i;
            break;
        }
    }

    return index;
}


int IngresarEntero(char mensaje[], int min, int max)
{
    int entero;
    puts(mensaje);
    fflush(stdin);
    scanf("%d",&entero);
    entero = validarEntero(entero, min, max);

    return entero;
}




int validarEntero (int dato, int min, int max)
{
    while(dato < min || dato > max)
    {

        fflush(stdin);
        printf("Dato no v%clido reingresar: ", 160);
        scanf("%d", &dato);

    }

    return dato;

}

void getString(char mensaje[],char input[], int min, int max)
{
    int len;
    int valido=0;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);

    len = strlen(input);
    if(len < min || len > max)
    {
        printf("Error,");
    }
    else
    {
       valido =1 ;

    }
    }
    while(valido ==0);

}


void getStringletras(char mensaje[],char input[], int min, int max)
{
        int estex=0;
        do
        {
        getString(mensaje, input, min,max);

        estex = esTexto(input);

        if (estex == 0)
        {
            printf("Error, ingresar %cnicamente letras", 163);
        }

        }
        while (estex == 0);
}


void getStringEntero(char mensaje[],char input[], int min, int max)
{
        int esnum=0;
        do
        {
        getString(mensaje, input, min,max);

        esnum = esNumero(input);

        if (esnum == 0)
        {
            printf("Error, ingresar %cnicamente n%cmeros", 163, 163);
        }

        }
        while (esnum == 0);
}

int esTexto(char texto[])
{
    int estexto = 0;

    int len = strlen(texto);

    for (int i=0; i<len; i++)
    {
        if (isalpha(texto[i]) || isspace(texto[i]))
        {
            estexto = 1;
        }
        else
        {

            estexto = 0;
            break;

        }

    }

    return estexto;

}




int esNumero(char numero[])
{

    int esnum = 0;

    int len = strlen(numero);

    for (int i=0; i<len; i++)
    {
        if (isdigit(numero[i]))
        {
            esnum = 1;
        }
        else
        {

            esnum = 0;
            break;

        }

    }

    return esnum;

}

int Confirmacion(char mensaje[])
{
     char confirma;
     int retorno=0;

      printf("\n.....................................................");

     printf("\n%s s/n: ", mensaje);

     confirma= getche();
     confirma= tolower(confirma);

     if(confirma == 's')
     {
         retorno=1;

     }

     return retorno;

}

