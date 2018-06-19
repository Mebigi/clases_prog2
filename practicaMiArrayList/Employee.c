#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "ingresodatos.h"
#include <ctype.h>


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
   int retorno=0;

   Employee* aux1= (Employee*)pEmployeeA;
   Employee* aux2= (Employee*)pEmployeeB;

   if(aux1!=NULL && aux2!=NULL)
   {
   if(strcmp(employee_getName(aux1),employee_getName(aux2))>0)
   {
       retorno=1;
   }

   }else if(strcmp(employee_getName(aux1),employee_getName(aux2))<0)
   {
        retorno=-1;
   }

    return retorno;
}


void employee_print(Employee* this)
{
      printf("%10d\t%15s\t%15s\t%15d\t\n", this->id, this->name, this->lastName, this->isEmpty );

}

void employees_print_all(ArrayList* pArrayListEmployee)
{
  Employee* aux;
  int len;

  len=al_len(pArrayListEmployee);

  for (int i=0; i<len; i++)
  {
    aux = (Employee*)al_get(pArrayListEmployee, i);//apunta
    employee_print(aux);
    if(i%100==0 && i>0)
    {
        printf("\n\n");
        system("pause");
    }

  }

}


void employees_sort(ArrayList* pArrayListEmployee, int orden)
{

  al_sort(pArrayListEmployee,employee_compare,orden);

}


void employees_add(ArrayList* pArrayListEmployee, int ultimoId)
{


 Employee* NuevoEmpleado = employee_new();

 if(NuevoEmpleado !=NULL)
 {

    employee_set_ingresoNombre(NuevoEmpleado,3,25);
    employee_set_ingresoApellido(NuevoEmpleado,3,25);
    employee_setId(NuevoEmpleado, ultimoId+1);

     NuevoEmpleado->isEmpty=1;


     al_add(pArrayListEmployee,NuevoEmpleado);


 }


}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;
    returnAux =(Employee*)malloc(sizeof(Employee));
    return returnAux;

}

void employee_delete(ArrayList* pArrayListEmployee)
{
   //employees_print_all(listaEmpleados);
   int index;
   int id;

   id= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
   index= employees_Buscar(pArrayListEmployee ,id);
   al_remove(pArrayListEmployee,index);

}


int employees_Buscar(ArrayList* pArrayListEmployee, int id)
{
  Employee* aux;
  int len;

  int index=-1;
  len=al_len(pArrayListEmployee);
  for (int i=0; i<len; i++)
  {
    aux = (Employee*)al_get(pArrayListEmployee, i);//apunta

    if (aux->id==id)
    {
        index=i;
        break;
    }


  }
  return index;

}

int employee_setId(Employee* this, int id)
{

    if(this!=NULL)
    {

    this->id=id;
    }

    return 0;

}

int employee_getId(Employee* this)
{

    int id;


    if(this!=NULL)
    {
        id=this->id;
    }

    return id;
}

char* employee_getName(Employee* this)
{

    char* texto;


    if(this!=NULL)
    {
    texto = this->name;

    }

    return texto;
}


int employee_SetName(Employee* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->name,texto);
        retorno =1;

    }

    return retorno;
}

void employee_set_ingresoNombre(Employee* this, int min, int max)
{
    if(this!=NULL)
    {
         getStringletras("\nIngresar Nombre: ",this->name, min, max);

            strlwr(this->name);

            this->name[0]=toupper(this->name[0]);


    }

}


void employee_set_ingresoApellido(Employee* this, int min, int max)
{

    if(this!=NULL)
    {


    getStringletras("\nIngresar Apellido: ",this->lastName, min, max);

    strlwr(this->lastName);

    this->lastName[0]=toupper(this->lastName[0]);
    }

}


void employees_guardar_all(ArrayList* pArrayListEmployee)
{
  Employee* aux;

  FILE *f;

	int retorno=0;

	f=fopen("data2.csv", "w");

	if(f==NULL)
	{

			retorno=1;
    }


	if(retorno ==0)
	{

        int len;

       len=al_len(pArrayListEmployee);

        //que guarde el id mas grande y un encabezado

        for (int i=0; i<len; i++)
        {

       aux = (Employee*)al_get(pArrayListEmployee, i);

       fprintf(f,"%d,%s,%s,%d\n", aux->id, aux->name, aux->lastName, aux->isEmpty );


     }
	}

	fclose(f);




}

