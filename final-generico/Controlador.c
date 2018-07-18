#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "est1.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "controlador.h"
#define MIN_ENTERO 1
#define MAX_ENTERO 2000
#define MAX_TEXTO 100
#define MIN_TEXTO 3
#define MIN_FLOTANTE 0
#define MAX_FLOTANTE 999999



int opcionAlta(ArrayList* this)
{
    int retorno=-1;

    if(this!=NULL)
    {

        int entero;
        float flotante;
        char texto[MAX_TEXTO+1];
        long largo;
        retorno=0;

        Est1* nuevo;

        entero = IngresarEntero("\nIngresar entero\n", MIN_ENTERO,MAX_ENTERO);
        getString("\nIngresar texto\n",texto, MIN_TEXTO, MAX_TEXTO);
        flotante = IngresarEnteroFlotante("\nIngresar flotante\n",MIN_FLOTANTE,MAX_FLOTANTE);
        largo = Ingresarlong("\nIngresar flotante\n");

        nuevo = est1_ingresoDatos(entero,texto,flotante,largo);

        if(nuevo!= NULL)
        {
            retorno=1;
            opcionAddListado(this,nuevo);
        }
    }


    return retorno;



}


int opcionPrintListado(ArrayList* this, char* encabezado)
{
    int retorno=0;

    if (this!= NULL && !(al_isEmpty(this)))
    {
        printf("\n%s\n", encabezado);
        est1_print_all(this);
        retorno=1;
    }

    return retorno;
}



int opcionAddListado(ArrayList* this, Est1* nuevo)
{

    int retorno=-1;

    if (nuevo!=NULL && this!=NULL)
    {
        retorno=al_add(this, nuevo);
        //retorno 0 si es ok -1 si es error al_add
    }

    return retorno;

}

int opcionDeleteDatoListado(ArrayList* this)
{
    int retorno=-1;

    if (this!=NULL)
    {
        int index;
        int clave;

        retorno=0;

        Est1* returnAux = NULL;
        clave= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
        index= opcionBuscarDato(this,clave);

        if(index != -1)
        {
            returnAux= al_get(this, index);
            est1_print(returnAux);
            retorno=1;

            if(Confirmacion("Confirma quitar el elemento de la lista"))
            {
                returnAux = al_pop(this,index);
                retorno=2;

            }

        }

    }
    return retorno;

}



int opcionModificacionDatoListado(ArrayList* this)
{
    int retorno=-1;

    if (this!=NULL)
    {
        int index;
        int clave;

        retorno=0;

        Est1* returnAux = NULL;
        clave= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
        index= opcionBuscarDato(this,clave);

        if(index != -1)
        {
            returnAux= al_get(this, index);
            est1_print(returnAux);
            retorno=1;

            int entero;
            float flotante;
            char texto[MAX_TEXTO+1];
            long largo;

                entero = IngresarEntero("\nIngresar entero\n", MIN_ENTERO,MAX_ENTERO);
                getString("\nIngresar texto\n",texto, MIN_TEXTO, MAX_TEXTO);
                flotante = IngresarEnteroFlotante("\nIngresar flotante\n",MIN_FLOTANTE,MAX_FLOTANTE);
                largo = Ingresarlong("\nIngresar flotante\n");

            if(Confirmacion("Confirma modificar el elemento de la lista"))
            {

                Est1* nuevo;

                nuevo = est1_ingresoDatos(entero,texto,flotante,largo);

                if(nuevo!=NULL)
                {
                    al_set(this,index,nuevo);
                    retorno=2;
                }

            }

        }

    }
    return retorno;

}


int opcionBuscarDato(ArrayList* this, int clave)
{
    Est1* aux;
    int len;

    int index=-1;

    len=al_len(this);
    for (int i=0; i<len; i++)
    {
        aux = (Est1*)al_get(this, i);//apunta

        if (aux->entero==clave)
        {
            index=i;
            break;
        }

    }
    return index;

}


void opcionOrdenarListado(ArrayList* this, int orden)
{

    al_sort(this,est1_compareEntero,orden);
    //al_sort(this,est1_compareTexto,orden);

}



void est1_print_all(ArrayList* this)
{

    if(this != NULL)
    {
        Est1* aux;
        int len;

        len=al_len(this);

        for (int i=0; i<len; i++)
        {
            aux = (Est1*)al_get(this, i);//apunta

            est1_print(aux);
            if(i%100==0 && i>0)
            {
                printf("\n\n");
                system("pause");
            }

        }
    }

}







