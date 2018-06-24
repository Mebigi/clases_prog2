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




void turno_print(Turno* this)
{
      printf("%10s\t%10d\n", turno_getDni(this), turno_get_id_turno(this));
}





