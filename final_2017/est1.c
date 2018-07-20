#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
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

//SETER AND GETER
Est1* est1_nuevo(void)
{
    Est1* returnAux;
    returnAux =(Est1*)malloc(sizeof(Est1));
    return returnAux;

}

LogEntry* loge_nuevo(void)
{
    LogEntry* returnAux;
    returnAux =(LogEntry*)malloc(sizeof(LogEntry));
    return returnAux;

}


Service* serv_nuevo(void)
{
    Service* returnAux;
    returnAux =(Service*)malloc(sizeof(Service));
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


int loge_get_serviceId(LogEntry* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->serviceId;
    }

    return num;
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



int loge_get_gravedad(LogEntry* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->gravedad;
    }

    return num;
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


int serv_set_name(Service* this, char* texto)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->name,texto);
        retorno =1;
    }

    return retorno;
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


int est1_set_largo(Est1* this,long int largo)
{
    int retorno =0;

    if(this!=NULL)
    {

        this->largo=largo;
        retorno =1;
    }

    return retorno;

}

long int est1_get_largo(Est1* this)
{

    long int largo;
    if(this!=NULL)
    {
        largo=this->largo;
    }

    return largo;
}

//FIN SETER AND GETER


//contructor parametrizado



Est1* est1_IngresoDatos(void)
{

        int entero;
        float flotante;
        char texto[MAX_TEXTO+1];
        long int largo;


        Est1* nuevo;

        entero = IngresarEntero("\nIngresar entero\n", MIN_ENTERO,MAX_ENTERO);
        getString("\nIngresar texto\n",texto, MIN_TEXTO, MAX_TEXTO);
        flotante = IngresarEnteroFlotante("\nIngresar flotante\n",MIN_FLOTANTE,MAX_FLOTANTE);
        largo = Ingresarlong("\nIngresar LONG dni\n");

        nuevo = est1_SetDatos(entero,texto,flotante,largo);

        return nuevo;

}



Est1* est1_SetDatos(int entero, char* texto, float flotante, long int largo)
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



void serv_print(Service* this)
{
    printf("%10d\t%15s\t%15s\n", serv_get_id(this),serv_get_name(this),serv_get_email(this));

}

void loge_print(LogEntry* this)
{
    printf("%10s\t%15s\t%15d\t%10d\t%15s\n", loge_get_date(this),loge_get_time(this),loge_get_serviceId(this),loge_get_gravedad(this),loge_get_msg(this));

}





