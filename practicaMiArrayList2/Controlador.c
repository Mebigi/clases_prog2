#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"


int opcionAlta_Employee(ArrayList* this, char nombrearchivo[])
{

 int retorno=-1;
 if(this!=NULL)
 {
    Employee* nuevoEmployee;
    nuevoEmployee = employee_ingreso();

    if(al_add(this,nuevoEmployee)==0) //0=es ok
    {
        md_guardar_text(this,nombrearchivo);
        //md_guardar_bin(this,nombrearchivo);

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
    employees_print_all(this);
    }

    return 0;
}




int add_listadoEmpleados2(ArrayList* this, Employee* empleado)
{

 int retorno=-1;

 if (empleado!=NULL && this!=NULL)
 {

  retorno=al_add(this, empleado);
  //retorno 0 si es ok -1 si es error al_add

 }

 return retorno;

}

void employee_delete(ArrayList* this)
{
   //employees_print_all(listaEmpleados);
   int index;
   int id;
   Employee* returnAux = NULL;

   id= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
   index= employees_Buscar(this ,id);
   returnAux = al_pop(this,index);

   employee_print(returnAux);


}


int employees_Buscar(ArrayList* this, int id)
{
  Employee* aux;
  int len;

  int index=-1;
  len=al_len(this);
  for (int i=0; i<len; i++)
  {
    aux = (Employee*)al_get(this, i);//apunta


    if (aux->id==id)
    {
        index=i;
        break;
    }


  }
  return index;

}


void employees_sort(ArrayList* this, int orden)
{

  al_sort(this,employee_compareName,orden);

}

void employees_sortEntero(ArrayList* this, int orden)
{

  al_sort(this,employee_compareEntero,orden);

}

/*void agregar_flotante(ArrayList* this)
{
al_nueva(this,calculo,Employee)

}*/



