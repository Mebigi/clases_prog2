#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
   int retorno=1;

   if(pEmployeeA!=NULL && pEmployeeA!=NULL)
   {
    if(strcmp(employee_getName(pEmployeeA),employee_getName(pEmployeeB)))
   {
       retorno=0;

   }
   }else
   {
        printf("NULL");
   }


    //definir criterio
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

  }

}


void employees_sort(ArrayList* pArrayListEmployee, int orden)
{

  al_sort(pArrayListEmployee,employee_compare,orden);

}





Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}

char* employee_getName(Employee* this)
{

    char* texto;

    texto = (char*) malloc(sizeof(char));


    if(this!=NULL)
    {
        strcpy(this->name,texto);

    }

    return texto;
}

