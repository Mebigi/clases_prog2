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
Usuario* us_nuevo(void)
{
    Usuario* returnAux;
    returnAux =(Usuario*)malloc(sizeof(Usuario));
    return returnAux;

}


int us_set_idUsuario(Usuario* this, int num)
{
    int retorno = 0;

    if(this!=NULL)
    {
        this->idUsuario=num;
        retorno = 1;
    }

    return retorno;
}


int us_get_idUsuario(Usuario* this)
{

    int num;
    if(this!=NULL)
    {
        num=this->idUsuario;
    }

    return num;
}


char* us_get_nombreUsuario(Usuario* this)
{
    char* nombreUsuario = NULL;

    if(this!=NULL)
    {
        nombreUsuario = this->nombreUsuario;
    }

    return nombreUsuario;
}


int us_set_nombreUsuario(Usuario* this, char* nombreUsuario)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->nombreUsuario,nombreUsuario);
        retorno =1;
    }

    return retorno;
}


char* us_get_email(Usuario* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->email;
    }

    return texto;
}


int us_set_email(Usuario* this, char* email)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->email,email);
        retorno =1;
    }

    return retorno;
}



char* us_get_sexo(Usuario* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->sexo;
    }

    return texto;
}


int us_set_sexo(Usuario* this, char* sexo)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->sexo,sexo);
        retorno =1;
    }

    return retorno;
}



char* us_get_pais(Usuario* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->pais;
    }

    return texto;
}


int us_set_pais(Usuario* this, char* pais)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->pais,pais);
        retorno =1;
    }

    return retorno;
}



char* us_get_password(Usuario* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->password;
    }

    return texto;
}


int us_set_password(Usuario* this, char* password)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->password,password);
        retorno =1;
    }

    return retorno;
}



char* us_get_ip_address(Usuario* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->ip_address;
    }

    return texto;
}


int us_set_ip_address(Usuario* this, char* ip_address)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->ip_address,ip_address);
        retorno =1;
    }

    return retorno;
}



Usuario* us_SeterDatos(int idUsuario, char* nombreUsuario,char* email,char* sexo,char* pais,char* password,char* ip_address)
{

    Usuario* nuevo;
    nuevo= us_nuevo();

    if (nuevo!= NULL)
    {
        confirma_set(us_set_idUsuario(nuevo,idUsuario));
        confirma_set(us_set_nombreUsuario(nuevo, nombreUsuario));
          confirma_set(us_set_sexo(nuevo, sexo));
        confirma_set(us_set_email(nuevo, email));
         confirma_set(us_set_pais(nuevo, pais));
         confirma_set(us_set_password(nuevo, password));
          confirma_set(us_set_ip_address(nuevo, ip_address));


    }

    return nuevo;

}

Usuario* us_IngresoDatos(void)
{

        int idUsuario;
        char nombreUsuario[MAX_TEXTO+1];
        char email[MAX_TEXTO+1];
        char sexo[MAX_TEXTO+1];
        char pais[MAX_TEXTO+1];
        char password[MAX_TEXTO+1];
        char ip_address[MAX_TEXTO+1];

        Usuario* nuevo;

        idUsuario = IngresarEntero("\nIngresar idUsuario\n", MIN_ENTERO,MAX_ENTERO);
         getString("\nIngresar nombre\n",nombreUsuario, MIN_TEXTO, MAX_TEXTO);
        getString("\nIngresar email\n",email, MIN_TEXTO, MAX_TEXTO);
         getString("\nIngresar sexo\n",sexo, MIN_TEXTO, MAX_TEXTO);
          getString("\nIngresar pais\n",pais, MIN_TEXTO, MAX_TEXTO);
           getString("\nIngresar password\n",password, MIN_TEXTO, MAX_TEXTO);
            getString("\nIngresar ip_address\n",ip_address, MIN_TEXTO, MAX_TEXTO);


        nuevo = us_SeterDatos(idUsuario,nombreUsuario,email,sexo,pais,password,ip_address);

        return nuevo;

}





int us_compareTexto(void* datoA,void* datoB)
{
    int retorno=0;

    Usuario* aux1= (Usuario*)datoA;
    Usuario* aux2= (Usuario*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(strcmp(us_get_nombreUsuario(aux1),us_get_nombreUsuario(aux2))>0)
        {
            retorno=1;
        }

        else if(strcmp(us_get_nombreUsuario(aux1),us_get_nombreUsuario(aux2))<0)
        {
            retorno=-1;
        }
    }

    return retorno;
}


int us_comparePais(void* datoA,void* datoB)
{
    int retorno=0;

    Usuario* aux1= (Usuario*)datoA;
    Usuario* aux2= (Usuario*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(strcmp(us_get_pais(aux1),us_get_pais(aux2))>0)
        {
            retorno=1;
        }

        else if(strcmp(us_get_pais(aux1),us_get_pais(aux2))<0)
        {
            retorno=-1;
        }
        else{

             if(strcmp(us_get_nombreUsuario(aux1),us_get_nombreUsuario(aux2))>0)
            {
            retorno=1;
            }

            else if(strcmp(us_get_nombreUsuario(aux1),us_get_nombreUsuario(aux2))<0)
            {
            retorno=-1;
            }

        }

    }

    return retorno;
}



int us_compareEntero(void* datoA,void* datoB)
{
    int retorno=0;

    Usuario* aux1= (Usuario*)datoA;
    Usuario* aux2= (Usuario*)datoB;

    if(aux1!=NULL && aux2!=NULL)
    {
        if(us_get_idUsuario(aux1)>us_get_idUsuario(aux2))
        {
            retorno=1;

        }

        else  if(us_get_idUsuario(aux1)<us_get_idUsuario(aux2))
        {
            retorno=-1;

        }
    }

    return retorno;

}


void us_print(Usuario* this)
{
    printf("%d\t%15s\t%5s\t%5s\t%10s\t%10s\t%10s\n",us_get_idUsuario(this),us_get_nombreUsuario(this),us_get_email(this),us_get_sexo(this),us_get_pais(this),us_get_password(this),us_get_ip_address(this));

}




