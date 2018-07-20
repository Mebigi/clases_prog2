#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "producto.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include "manejadorDatos.h"
#define MIN_ENTERO 1
#define MAX_ENTERO 2000
#define MAX_TEXTO 100
#define MIN_TEXTO 3
#define MIN_FLOTANTE 0
#define MAX_FLOTANTE 999999

//SETER AND GETER
Producto* prod_nuevo(void)
{
    Producto* returnAux;
    returnAux =(Producto*)malloc(sizeof(Producto));
    return returnAux;

}


int prod_set_cantidad(Producto* this, int num)
{
    int retorno = 0;

    if(this!=NULL)
    {
        this->cantidad=num;
        retorno = 1;
    }

    return retorno;
}


int prod_get_cantidad(Producto* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->cantidad;
    }

    return num;
}


int prod_set_id(Producto* this, int num)
{
    int retorno = 0;

    if(this!=NULL)
    {
        this->id=num;
        retorno = 1;
    }

    return retorno;
}


int prod_get_id(Producto* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->id;
    }

    return num;
}


char* prod_get_descripcion(Producto* this)
{
    char* descripcion = NULL;

    if(this!=NULL)
    {
        descripcion = this->descripcion;
    }

    return descripcion;
}


int prod_set_descripcion(Producto* this, char* descripcion)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno =1;
    }

    return retorno;
}

//FIN SETER AND GETER


//contructor parametrizado



Producto* prod_IngresoDatos(void)
{

        int cantidad;
        int id;
        char descripcion[MAX_TEXTO+1];



        Producto* nuevo;

        id = IngresarEntero("\nIngresar id\n", MIN_ENTERO,MAX_ENTERO);
        cantidad = IngresarEntero("\nIngresar cantidad\n", MIN_ENTERO,MAX_ENTERO);
        getString("\nIngresar descripcion\n",descripcion, MIN_TEXTO, MAX_TEXTO);


        nuevo = prod_SeterDatos(id,descripcion,cantidad);

        return nuevo;

}



Producto* prod_SeterDatos( int id, char* descripcion, int cantidad)
{

    Producto* nuevo;
    nuevo= prod_nuevo();

    if (nuevo!= NULL)
    {
        confirma_set(prod_set_id(nuevo,id));
        confirma_set(prod_set_descripcion(nuevo, descripcion));
        confirma_set(prod_set_cantidad(nuevo,cantidad));


    }

    return nuevo;

}

int prod_compareTexto(void* datoA,void* datoB)
{
    int retorno=0;

    Producto* aux1= (Producto*)datoA;
    Producto* aux2= (Producto*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(strcmp(prod_get_descripcion(aux1),prod_get_descripcion(aux2))>0)
        {
            retorno=1;
        }

        else if(strcmp(prod_get_descripcion(aux1),prod_get_descripcion(aux2))<0)
        {
            retorno=-1;
        }
    }

    return retorno;
}

int prod_compareEntero(void* datoA,void* datoB)
{
    int retorno=0;

    Producto* aux1= (Producto*)datoA;
    Producto* aux2= (Producto*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(prod_get_cantidad(aux1)>prod_get_cantidad(aux2))
        {
            retorno=1;

        }

        else  if(prod_get_cantidad(aux1)<prod_get_cantidad(aux2))
        {
            retorno=-1;

        }
    }

    return retorno;

}


void prod_print(Producto* this)
{
    printf("%10d\t%15s\t%10d\n", prod_get_id(this), prod_get_descripcion(this),  prod_get_cantidad(this));

}





