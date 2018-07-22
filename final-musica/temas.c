#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "usuario.h"
#include "temas.h"
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
Tema* tem_nuevo(void)
{
    Tema* returnAux;
    returnAux =(Tema*)malloc(sizeof(Tema));
    return returnAux;

}


int tem_set_idTema(Tema* this, int num)
{
    int retorno = 0;

    if(this!=NULL)
    {
        this->idTema=num;
        retorno = 1;
    }

    return retorno;
}


int tem_get_idTema(Tema* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->idTema;
    }

    return num;
}


char* tem_get_nombreTema(Tema* this)
{
    char* nombreTema = NULL;

    if(this!=NULL)
    {
        nombreTema = this->nombreTema;
    }

    return nombreTema;
}


int tem_set_nombreTema(Tema* this, char* nombreTema)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->nombreTema,nombreTema);
        retorno =1;
    }

    return retorno;
}

char* tem_get_artista(Tema* this)
{
    char* artista = NULL;

    if(this!=NULL)
    {
        artista = this->artista;
    }

    return artista;
}


int tem_set_artista(Tema* this, char* artista)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->artista,artista);
        retorno =1;
    }

    return retorno;
}



Tema* tem_SeterDatos(int idTema, char* nombreTema,char* artista)
{

    Tema* nuevo;
    nuevo= tem_nuevo();

    if (nuevo!= NULL)
    {
        confirma_set(tem_set_idTema(nuevo,idTema));
        confirma_set(tem_set_nombreTema(nuevo, nombreTema));
        confirma_set(tem_set_artista(nuevo, artista));


    }

    return nuevo;

}




int tem_compareTemas(void* datoA,void* datoB)
{
    int retorno=0;

    Tema* aux1= (Tema*)datoA;
    Tema* aux2= (Tema*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(strcmp(tem_get_artista(aux1),tem_get_artista(aux2))>0)
        {
            retorno=1;
        }

        else if(strcmp(tem_get_artista(aux1),tem_get_artista(aux2))<0)
        {
            retorno=-1;
        }
        else{

             if(strcmp(tem_get_nombreTema(aux1),tem_get_nombreTema(aux2))>0)
            {
            retorno=1;
            }

            else if(strcmp(tem_get_nombreTema(aux1),tem_get_nombreTema(aux2))<0)
            {
            retorno=-1;
            }

        }

    }

    return retorno;
}




void tem_print(Tema* this)
{
    printf("%d\t%30s\t%30s\n",tem_get_idTema(this),tem_get_nombreTema(this),tem_get_artista(this));

}





