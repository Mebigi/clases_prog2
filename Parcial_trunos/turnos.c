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

Turno* turno_ingreso(void)
{

 char dni[9];
 int ultimoturno;
 Turno* nuevoTurno;

 getStringEntero("Ingresar DNI",dni, 7, 9);
 nuevoTurno = turno_nuevo();
 ultimoturno= md_leer_turno("ultimoNro.txt");

 if (nuevoTurno!= NULL)
 {
    ultimoturno++; // le suma antes para no repetir
    turno_set_id_turno(nuevoTurno,ultimoturno);
    turno_setDni(nuevoTurno,dni);
    md_guardar_turno("ultimoNro.txt",ultimoturno);

 }

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


int compareTurno(void* turnoA,void* turnoB)
{
  int retorno=0;

   Turno* aux1= (Turno*)turnoA;
   Turno* aux2= (Turno*)turnoB;

//long int axulong1=0;
//long int axulong2=0;

int axulong1=0;
int axulong2=0;

   if(aux1!=NULL && aux2!=NULL)
   {
  axulong1=atol(turno_getDni(aux1));
  //printf("axulong1 %ld\n",axulong1);
  axulong2=atol(turno_getDni(aux2));
  //printf("axulong2 %ld\n",axulong2);

   if(axulong1>axulong2)
   {
       retorno=1;
       // printf("axulong1 %ld es mayor a axulong1 %ld\n",axulong1, axulong2);
   }

   else if(axulong1<axulong2)
   {
        retorno=-1;
        //printf("axulong1 %ld es NO mayor a axulong1 %ld\n",axulong1, axulong2);
   }
   }

    return retorno;

}

int compareTurnoStr(void* turnoA,void* turnoB)
{
  int retorno=0;

   Turno* aux1= (Turno*)turnoA;
   Turno* aux2= (Turno*)turnoB;



   if(aux1!=NULL && aux2!=NULL)
   {
   if(strcmp(turno_getDni(aux1),turno_getDni(aux2))>0)
   {
       retorno=1;
   }

   else if(strcmp(turno_getDni(aux1),turno_getDni(aux2))<0)
   {
        retorno=-1;
   }
   }

    return retorno;


}





