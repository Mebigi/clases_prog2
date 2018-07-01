#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacion.h"
#include "turnos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"




int opcionAlta_Turno(ArrayList* this, char nombrearchivo[])
{

 int retorno=-1;
 if(this!=NULL)
 {
    Turno* nuevoTurno;
    nuevoTurno = turno_ingreso();

    if(al_add(this,nuevoTurno)==0) //0=es ok
    {
        md_guardar_text(this,nombrearchivo);
        retorno =1;

    }

 }

     return retorno;
}

int opcionListado(ArrayList* this, char* encabezado)
{
    if (this!= NULL)
    {

    printf("\n%s\n", encabezado);
    turnos_print_all(this);
    }

    return 0;
}

int opcionListado_sort(ArrayList* this, char* encabezado)
{

    printf("\n%s\n", encabezado);
    al_sort(this,compareTurno,0); //descendente

    turnos_print_all(this);

    return 0;
}


void turnos_print_all(ArrayList* this)
{
  Turno* aux;
  int len;

  len=al_len(this);

  for (int i=0; i<len; i++)
  {
    aux = (Turno*)al_get(this, i);//apunta
    turno_print(aux);

  }
}


Turno* opcionProximo(ArrayList* this, char encabezado[])
{
  Turno* proximo = NULL;

   if(this!=NULL)
   {

       printf("\n%s\n", encabezado);
       proximo =(Turno*)al_get(this,0);

       if (proximo!=NULL)
       {

       turno_print(proximo);

       if(Confirmacion("Confirma la atencion s/n?"))
       {
        proximo = (Turno*)al_pop(this,0);
       }

       }
       else
       {
            printf("\\n");

       }



   }
   return proximo;

}

int add_listadoAtendidos(ArrayList* this, Turno* atendido)
{

 int retorno=-1;

 if (atendido!=NULL && this!=NULL)
 {

  retorno=al_add(this, atendido);
  //retorno 0 si es ok -1 si es error al_add

 }

 return retorno;

}

