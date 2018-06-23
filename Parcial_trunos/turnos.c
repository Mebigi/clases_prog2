#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacion.h"
#include "turnos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"




Turno* turno_nuevo(void)
{
    Turno* nuevoTurno = NULL;
    nuevoTurno =(Turno*)malloc(sizeof(Turno));

    return nuevoTurno;
}


int prod_delete(Turno* this)
{
    free(this);
    return 0;
}


//int tipo_tramite; //0 urgente
 //int estado; // 0 finalizado
 //char dni9;
 //int id_turno; // orden

int turno_set_tipo_tramite(Turno* this,int tipo)
{
    int retorno =0;
    if(this!=NULL)
    {
        this->tipo_tramite=tipo;
        retorno =1;

    }

    return retorno;

}

int turno_get_tipo_tramite(Turno* this)
{
    int tipo=-1;

    if(this!=NULL)
    {
        tipo=this->tipo_tramite;


    }
    return tipo;
}

int turno_set_id_turno(Turno* this,int id)
{
    int retorno =0;
    if(this!=NULL)
    {
        this->id_turno=id;
        retorno =1;

    }

    return retorno;

}


int turno_get_id_turno(Turno* this)
{
    int id=-1;

    if(this!=NULL)
    {
        id=this->id_turno;


    }
    return id;
}

int turno_setDni(Turno* this,char* dni)
{

    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->dni,dni);
        retorno =1;

    }

    return retorno;

}


char* turno_getDni(Turno* this)
{

    char* texto;


    if(this!=NULL)
    {
    texto = this->dni;

    }

    return texto;
}



int turno_setEstado(Turno* this,int estado)
{
    int retorno =0;

    if(this!=NULL)
    {
    this->estado = estado;
     int retorno =1;
    }
    return retorno;
}

int turno_getEstado(Turno* this)
{

     if(this!=NULL)
    {
     return this->estado;
    }

    return 0;

}


int turno_compare(void* turnoA,void* turnoB)
{
   int retorno=0;

   Turno* aux1= (Turno*)turnoA;
   Turno* aux2= (Turno*)turnoA;

   if(aux1!=NULL && aux2!=NULL)
   {
   if(turno_get_tipo_tramite(aux1) > turno_get_tipo_tramite(aux2))
   {
       retorno=1;


   }

   }else if(turno_get_tipo_tramite(aux1)< turno_get_tipo_tramite(aux2))
   {
        retorno=-1;
   }

    return retorno;
}

