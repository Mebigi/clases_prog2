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

LogEntry* loge_nuevo(void)
{
    LogEntry* returnAux;
    returnAux =(LogEntry*)malloc(sizeof(LogEntry));
    return returnAux;

}


int loge_set_serviceId(LogEntry* this, int num)
{
    int retorno = 0;

    if(this!=NULL)
    {
        this->serviceId=num;
        retorno = 1;
    }

    return retorno;
}


int loge_set_gravedad(LogEntry* this, int num)
{
    int retorno = 0;

    if(this!=NULL)
    {
        this->gravedad=num;
        retorno = 1;
    }

    return retorno;
}


int loge_get_serviceId(LogEntry* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->serviceId;
    }

    return num;
}


int loge_get_gravedad(LogEntry* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->gravedad;
    }

    return num;
}

char* loge_get_date(LogEntry* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->date;
    }

    return texto;
}

char* loge_get_time(LogEntry* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->time;
    }

    return texto;
}

char* loge_get_msg(LogEntry* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->msg;
    }

    return texto;
}


int loge_set_msg(LogEntry* this, char* texto)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->msg,texto);
        retorno =1;
    }

    return retorno;
}

int loge_set_date(LogEntry* this, char* texto)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->date,texto);
        retorno =1;
    }

    return retorno;
}

int loge_set_time(LogEntry* this, char* texto)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->time,texto);
        retorno =1;
    }

    return retorno;
}



LogEntry* loge_SetDatos(char* date, char* time, int serviceId, int gravedad, char* msg  )
{

    LogEntry* nuevo;
    nuevo= loge_nuevo();

    if (nuevo!= NULL)
    {
        confirma_set(loge_set_date(nuevo,date));
        confirma_set(loge_set_time(nuevo, time));
        confirma_set(loge_set_serviceId(nuevo, serviceId));
        confirma_set(loge_set_gravedad(nuevo, gravedad));
        confirma_set(loge_set_msg(nuevo, msg));

    }

    return nuevo;

}


void loge_print(LogEntry* this)
{
    printf("%10s\t%15s\t%15d\t%10d\t%15s\n", loge_get_date(this),loge_get_time(this),loge_get_serviceId(this),loge_get_gravedad(this),loge_get_msg(this));

}
