#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacion.h"
#include "turnos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"


ArrayList* Turnos;
ArrayList* TurnosU;
ArrayList* TurnosA;
ArrayList* TurnosUA;

int nroturno=0;

void cont_inicio()
{

     Turnos = al_newArrayList();
     TurnosU = al_newArrayList();
     TurnosUA = al_newArrayList();
     TurnosA = al_newArrayList();
     vista_mostrarMenu();



     /*if(Turnos!=NULL)
     {
         ultimoId = md_carga_archivo("data.dat", Productos);

         if(ultimoId)
         {
             printf("Se cargaron los Datos a la lista");
         }
         else
         {
             printf("No Se cargaron los Datos a la lista");
         }
     }
     else
     {
          printf("No Se creo el ArrayList Productos");
     }
*/



}

void opcionAlta_TurnoUrgente(void)
{
    opcionAlta_Turno(TurnosU);

}

void opcionAlta_TurnoNormal(void)
{
    opcionAlta_Turno(Turnos);
}

int opcionAlta_Turno(ArrayList* this)
{
 char dni[9];

 Turno* nuevoTurno;


 getStringEntero("Ingresar DNI",dni, 7, 8);

 nuevoTurno = turno_nuevo();

 if (nuevoTurno!= NULL)
 {
    nroturno++;
    turno_set_id_turno(nuevoTurno,nroturno);
    turno_setDni(nuevoTurno,dni);
    al_add(this,nuevoTurno);

 }
    return 0;
}

int opcionListadoPendientes()
{
    printf("\nTurnos Urgentes:\n");
    turnos_print_all(TurnosU);
    printf("\nTurnos Normales:\n");
    turnos_print_all(Turnos);
    return 0;
}

int opcionListadoAtendidos()
{

    printf("\nTurnos Normales:\n");
    turnos_print_all(TurnosA);
     printf("\nTurnos Urgentes:\n");
    turnos_print_all(TurnosUA);
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


int opcionProximo()
{

   Turno* proximoU;

   turnos_print_all(TurnosU);
   turnos_print_all(Turnos);

   printf("\nEl Proximo turno es:\n");

   proximoU = al_get(TurnosU,0);

   if(proximoU!=NULL)
   {
       turno_print(proximoU);
       al_add(TurnosUA,proximoU);
       al_pop(TurnosU,0);

   }
   else{
    Turno* proximo;
    proximo = al_get(Turnos,0);
    if(proximo!=NULL)
       {
           turno_print(proximo);
           al_add(TurnosA,proximo);
           al_pop(Turnos,0);



       }
       else {

        printf("No hay turnos pendientes\n");

       }

   }

    return 0;
}

