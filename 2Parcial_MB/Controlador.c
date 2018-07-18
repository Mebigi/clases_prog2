#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"




int opcionListado(ArrayList* this, char* encabezado)
{
    if (this!= NULL)
    {

    printf("\n%s\n", encabezado);
    empleados_print_all(this);
    }

    return 0;
}

int opcionListadoSueldo(ArrayList* this, char* encabezado)
{
    if (this!= NULL)
    {
    printf("\n%s\n", encabezado);
    empleados_print_all_sueldo(this);
    }

    return 0;
}


int add_listadoEmpleados2(ArrayList* this, Empleado* empleado)
{

 int retorno=-1;
 if (empleado!=NULL && this!=NULL)
 {

  retorno=al_add(this, empleado);
  //retorno 0 si es ok -1 si es error al_add

 }

 return retorno;

}

void empleado_delete(ArrayList* this)
{
   //empleados_print_all(listaEmpleados);
   int index;
   int id;
   Empleado* returnAux = NULL;

   id= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
   index= empleados_Buscar(this ,id);
   returnAux = al_pop(this,index);

   empleado_print(returnAux);


}


int empleados_Buscar(ArrayList* this, int id)
{
  Empleado* aux;
  int len;

  int index=-1;
  len=al_len(this);
  for (int i=0; i<len; i++)
  {
    aux = (Empleado*)al_get(this, i);//apunta


    if (aux->id==id)
    {
        index=i;
        break;
    }


  }
  return index;

}


void empleados_sort(ArrayList* this, int orden)
{

  al_sort(this,empleado_compareName,orden);

}



void est1_print_all(ArrayList* this)
{

  if(this != NULL)
 {
  Est1* aux;
  int len;

  len=al_len(this);

  for (int i=0; i<len; i++)
  {
    aux = (Est1*)al_get(this, i);//apunta

    empleado_print(aux);
    if(i%100==0 && i>0)
    {
        printf("\n\n");
        system("pause");
    }

  }
}

}





