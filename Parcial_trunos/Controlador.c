#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacion.h"
#include "turnos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"


ArrayList* Turnos;
int ultimoId =0;

void cont_inicio()
{

     Turnos = al_newArrayList();

     int ultimoId =0;

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

      vista_mostrarMenu();

}


int opcionAlta_Turno(int tipo)
{

 //0 urgente
 int estado=1; // 0 finalizado
 char dni[9];
 int id_turno; // orden

 id_turno=ultimoId+1;
 getStringEntero("ingresar DNI",dni, 7, 8);

 Turno* nuevoTurno;

 nuevoTurno= turno_nuevo();

 if (nuevoTurno!= NULL)
 {

    turno_set_tipo_tramite(nuevoTurno,tipo);
    turno_setEstado(nuevoTurno,estado);
    turno_set_id_turno(nuevoTurno,id_turno);
    turno_setDni(nuevoTurno,dni);

    al_add(Turnos,nuevoTurno);

 }

    return 0;
}


void turno_print(Turno* this)
{
      printf("%10d\t%15s\t%15d\t%15d\t\n", this->id_turno, this->dni, this->tipo_tramite, this->estado );

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
int opcionListadoPendientes()
{

    turnos_print_all(Turnos);
    return 0;
}

int opcionListadoPasados()
{
    return 0;
}


int opcionProximo()
{

   Turno* proximo;

   al_sort(Turnos,turno_compare,0);
   turnos_print_all(Turnos);

   printf("\nEl Proximo turno es:\n");

   proximo = al_get(Turnos,0);

   turno_print(proximo);


    return 0;
}

