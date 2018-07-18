#include "est1.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//SETER AND GETER
Est1* est1_nuevo(void)
{
    Est1* returnAux;
    returnAux =(Est1*)malloc(sizeof(Est1));
    return returnAux;

}


int est1_set_entero(Est1* this, int num)
{
    int retorno = 0;

    if(this!=NULL)
    {
        this->entero=num;
        retorno = 1;
    }

    return retorno;
}


int est1_get_entero(Est1* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->entero;
    }

    return num;
}


char* est1_get_texto(Est1* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->texto;
    }

    return texto;
}


int est1_set_texto(Est1* this, char* texto)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->texto,texto);
        retorno =1;
    }

    return retorno;
}


int est1_set_flotante(Est1* this, float flotante)
{
    int retorno =0;

    if(this!=NULL)
    {

        this->flotante=flotante;
        retorno =1;
    }

    return retorno;

}

float est1_get_flotante(Est1* this)
{

    float flotante;
    if(this!=NULL)
    {
        flotante=this->flotante;
    }

    return flotante;
}


int est1_set_largo(Est1* this,long largo)
{
    int retorno =0;

    if(this!=NULL)
    {

        this->largo=largo;
        retorno =1;
    }

    return retorno;

}

long est1_get_largo(Est1* this)
{

    long largo;
    if(this!=NULL)
    {
        largo=this->largo;
    }

    return largo;
}

//FIN SETER AND GETER


//contructor parametrizado

Est1* est1_ingresoDatos(int entero, char* texto, float flotante, long largo)
{

    Est1* nuevo;
    nuevo= est1_nuevo();

    if (nuevo!= NULL)
    {
        confirma_set(est1_set_entero(nuevo,entero));
        confirma_set(est1_set_texto(nuevo, texto));
        confirma_set(est1_set_flotante(nuevo, flotante));
        confirma_set(est1_set_largo(nuevo, largo));

    }

    return nuevo;

}

int est1_compareTexto(void* datoA,void* datoB)
{
    int retorno=0;

    Est1* aux1= (Est1*)datoA;
    Est1* aux2= (Est1*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(strcmp(est1_get_texto(aux1),est1_get_texto(aux2))>0)
        {
            retorno=1;
        }

        else if(strcmp(est1_get_texto(aux1),est1_get_texto(aux2))<0)
        {
            retorno=-1;
        }
    }

    return retorno;
}

int est1_compareEntero(void* datoA,void* datoB)
{
    int retorno=0;

    Est1* aux1= (Est1*)datoA;
    Est1* aux2= (Est1*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(est1_get_entero(aux1)>est1_get_entero(aux2))
        {
            retorno=1;

        }

        else  if(est1_get_entero(aux1)<est1_get_entero(aux2))
        {
            retorno=-1;

        }
    }

    return retorno;

}


void est1_print(Est1* this)
{
    printf("%10d\t%15s\t%15f\t%10ld\n", est1_get_entero(this), est1_get_texto(this), est1_get_flotante(this), est1_get_largo(this));

}




