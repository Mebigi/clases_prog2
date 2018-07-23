#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "reparto.h"
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
Reparto* rep_nuevo(void)
{
    Reparto* returnAux;
    returnAux =(Reparto*)malloc(sizeof(Reparto));
    return returnAux;

}



int rep_set_id(Reparto* this, int num)
{
    int retorno = 0;

    if(this!=NULL)
    {
        this->id=num;
        retorno = 1;
    }

    return retorno;
}


int rep_get_id(Reparto* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->id;
    }

    return num;
}


char* rep_get_producto(Reparto* this)
{
    char* producto = NULL;

    if(this!=NULL)
    {
        producto = this->producto;
    }

    return producto;
}


int rep_set_producto(Reparto* this, char* producto)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->producto,producto);
        retorno =1;
    }

    return retorno;
}


char* rep_get_direccion(Reparto* this)
{
    char* direccion = NULL;

    if(this!=NULL)
    {
        direccion = this->direccion;
    }

    return direccion;
}


int rep_set_direccion(Reparto* this, char* direccion)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno =1;
    }

    return retorno;
}


char* rep_get_localidad(Reparto* this)
{
    char* localidad = NULL;

    if(this!=NULL)
    {
        localidad = this->localidad;
    }

    return localidad;
}


int rep_set_localidad(Reparto* this, char* localidad)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno =1;
    }

    return retorno;
}

char* rep_get_recibe(Reparto* this)
{
    char* recibe = NULL;

    if(this!=NULL)
    {
        recibe = this->recibe;
    }

    return recibe;
}

char* loc_get_localidad(Localidad* this)
{
    char* localidad = NULL;

    if(this!=NULL)
    {
        localidad = this->localidad;
    }

    return localidad;
}


int rep_set_recibe(Reparto* this, char* recibe)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno =1;
    }

    return retorno;
}

int loc_set_localidad(Reparto* this, char* localidad)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno =1;
    }

    return retorno;
}

//FIN SETER AND GETER


//contructor parametrizado






Reparto* rep_SeterDatos(int id, char* producto, char* direccion, char* localidad, char* recibe)
{

    Reparto* nuevo;
    nuevo= rep_nuevo();

    if (nuevo!= NULL)
    {
        confirma_set(rep_set_id(nuevo,id));
        confirma_set(rep_set_producto(nuevo, producto));
        confirma_set(rep_set_direccion(nuevo, direccion));
        confirma_set(rep_set_localidad(nuevo, localidad));
        confirma_set(rep_set_recibe(nuevo, recibe));





    }

    return nuevo;

}

int rep_compareTexto(void* datoA,void* datoB)
{
    int retorno=0;

    Reparto* aux1= (Reparto*)datoA;
    Reparto* aux2= (Reparto*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(strcmp(rep_get_producto(aux1),rep_get_producto(aux2))>0)
        {
            retorno=1;
        }

        else if(strcmp(rep_get_producto(aux1),rep_get_producto(aux2))<0)
        {
            retorno=-1;
        }
    }

    return retorno;
}

/*
int rep_compareEntero(void* datoA,void* datoB)
{
    int retorno=0;

    Reparto* aux1= (Reparto*)datoA;
    Reparto* aux2= (Reparto*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(rep_get_cantidad(aux1)>rep_get_cantidad(aux2))
        {
            retorno=1;

        }

        else  if(rep_get_cantidad(aux1)<rep_get_cantidad(aux2))
        {
            retorno=-1;

        }
    }

    return retorno;

}
*/

void rep_print(Reparto* this)
{
    printf("%5d\t%10s\t%10s\t%10s\t%15s\n", rep_get_id(this),rep_get_producto(this),rep_get_direccion(this),rep_get_localidad(this),rep_get_recibe(this));

}





