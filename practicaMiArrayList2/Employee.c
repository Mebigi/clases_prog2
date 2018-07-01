#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"


int employee_compareName(void* pEmployeeA,void* pEmployeeB)
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

   else if(strcmp(employee_getName(aux1),employee_getName(aux2))<0)
   {
        retorno=-1;
   }
   }

    return retorno;
}

int employee_compareEntero(void* EmployeeA,void* EmployeeB)
{
  int retorno=0;

   Employee* aux1= (Employee*)EmployeeA;
   Employee* aux2= (Employee*)EmployeeB;


   if(aux1!=NULL && aux2!=NULL)
   {
    if(employee_get_entero(aux1)>employee_get_entero(aux2))
   {
       retorno=1;

   }

   else  if(employee_get_entero(aux1)<employee_get_entero(aux2))
   {
        retorno=-1;

   }
   }

    return retorno;

}


void employee_print(Employee* this)
{
      printf("%10d\t%15s\t%15d\t%15f\t\n", this->id, this->name, this->entero, this->flotante);

}

void employees_print_all(ArrayList* this)
{

  if(this != NULL)
 {
 Employee* aux;
  int len;

  len=al_len(this);

  for (int i=0; i<len; i++)
  {
    aux = (Employee*)al_get(this, i);//apunta
    employee_print(aux);
    if(i%100==0 && i>0)
    {
        printf("\n\n");
        system("pause");
    }




  }
}

}




Employee* employee_new(void)
{

    Employee* returnAux = NULL;
    returnAux =(Employee*)malloc(sizeof(Employee));
    return returnAux;

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


int employee_set_entero(Employee* this, int entero)
{

    if(this!=NULL)
    {

    this->entero=entero;
    }

    return 0;

}

int employee_get_entero(Employee* this)
{

    int entero;


    if(this!=NULL)
    {
        entero=this->entero;
    }

    return entero;
}


int employee_set_flotante(Employee* this, float flotante)
{

    if(this!=NULL)
    {

    this->flotante=flotante;
    }

    return 0;

}

float employee_get_flotante(Employee* this)
{

    float flotante;


    if(this!=NULL)
    {
        flotante=this->flotante;
    }

    return flotante;
}

void employee_ingresoNombre(Employee* this, int min, int max)
{
    if(this!=NULL)
    {
         getStringletras("\nIngresar Nombre: ",employee_getName(this), min, max);

            strlwr(employee_getName(this));

            this->name[0]=toupper(this->name[0]);


    }

}

Employee* employee_ingreso(void)
{


//char name[50];
int entero;
float flotante;

 int ultimoid;
 Employee* nuevoEmployee;


 //getStringletras("Ingresar Nombre",name,3,50);
 entero = IngresarEntero("\nIngresar Entero:",1, 10000);
 flotante = IngresarEnteroFlotante("\nIngresar flotante:",1, 1000000);



 nuevoEmployee =employee_new();
 ultimoid= md_leer_ultimo("ultimoNro.txt");

 if (nuevoEmployee!= NULL)
 {
    ultimoid++; // le suma antes para no repetir
    employee_setId(nuevoEmployee,ultimoid);
    //employee_SetName(nuevoEmployee,name);
    employee_ingresoNombre(nuevoEmployee, 2, 50);
    employee_set_entero(nuevoEmployee,entero);
    employee_set_flotante(nuevoEmployee,flotante);

    md_guardar_ultimo("ultimoNro.txt",ultimoid);

 }

return nuevoEmployee;

}

Employee* calculo(void* EmployeeA)
{


   Employee* aux= NULL;

   if (EmployeeA!=NULL)
   {
    float flotante=0;
    aux= (Employee*)EmployeeA;
    int entero;


   entero = employee_get_entero(aux);

    if(entero<=176 && entero>0)
    {
      flotante=(float)entero*180;
    }
    else if (entero>176 && entero<209)
    {
       flotante=(float)entero*180;
       flotante*=(float)(entero-176)*270;
    }
    else if (entero>=209)
    {
       flotante=(float)entero*180;
       flotante*=(float)(entero-176)*270;
       flotante*=(float)(entero-208)*270;
    }

    employee_set_flotante(aux,flotante);


   }




    return aux;

}



