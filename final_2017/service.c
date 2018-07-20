#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
#include "loge.h"
#include "service.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include "Controlador.h"
#include "manejadorDatos.h"
#define MIN_ENTERO 1
#define MAX_ENTERO 2000
#define MAX_TEXTO 100
#define MIN_TEXTO 3
#define MIN_FLOTANTE 0
#define MAX_FLOTANTE 999999


Service* serv_nuevo(void)
{
    Service* returnAux;
    returnAux =(Service*)malloc(sizeof(Service));
    return returnAux;

}


int serv_set_id(Service* this, int num)
{
    int retorno = 0;

    if(this!=NULL)
    {
        this->id=num;
        retorno = 1;
    }

    return retorno;
}



int serv_get_id(Service* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->id;
    }

    return num;
}


char* serv_get_name(Service* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->name;
    }

    return texto;
}

char* serv_get_email(Service* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->email;
    }

    return texto;
}


int serv_set_email(Service* this, char* texto)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->email,texto);
        retorno =1;
    }

    return retorno;
}



Service* serv_SetDatos(int id, char* name, char* email)
{

    Service* nuevo;
    nuevo= serv_nuevo();

    if (nuevo!= NULL)
    {
        confirma_set(serv_set_id(nuevo,id));
        confirma_set(serv_set_name(nuevo, name));
        confirma_set(serv_set_email(nuevo, email));

    }

    return nuevo;

}


void serv_print(Service* this)
{
    printf("%10d\t%15s\t%15s\n", serv_get_id(this),serv_get_name(this),serv_get_email(this));

}

