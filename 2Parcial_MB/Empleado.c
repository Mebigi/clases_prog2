#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"


int empleado_compareName(void* pEmpleadoA,void* pEmpleadoB)
{
   int retorno=0;

   Empleado* aux1= (Empleado*)pEmpleadoA;
   Empleado* aux2= (Empleado*)pEmpleadoB;

   if(aux1!=NULL && aux2!=NULL)
   {
   if(strcmp(empleado_getName(aux1),empleado_getName(aux2))>0)
   {
       retorno=1;
   }

   else if(strcmp(empleado_getName(aux1),empleado_getName(aux2))<0)
   {
        retorno=-1;
   }
   }

    return retorno;
}




void empleado_print(Empleado* this)
{

      printf("%10d\t%15s\t%15s\t%10d\n", empleado_getId(this), empleado_getName(this), empleado_getDireccion(this), empleado_get_horas(this));

    //printf("%10d\t%15s\t%15s%\t%10d\t%10f\n", empleado_getId(this), empleado_getName(this), empleado_getDireccion(this), empleado_get_horas(this), empleado_get_sueldo(this));


}

void empleado_printSueldo(Empleado* this)
{

     // printf("%10d\t%15s\t%15s%\t%10d\n", empleado_getId(this), empleado_getName(this), empleado_getDireccion(this), empleado_get_horas(this));

    printf("%10d\t%10s\t%10s\t%10d\t%10.2f\n", empleado_getId(this), empleado_getName(this), empleado_getDireccion(this), empleado_get_horas(this), empleado_get_sueldo(this));


}


void empleados_print_all_sueldo(ArrayList* this)
{

  if(this != NULL)
 {
 Empleado* aux;
  int len;

  len=al_len(this);

  for (int i=0; i<len; i++)
  {
    aux = (Empleado*)al_get(this, i);//apunta

    empleado_printSueldo(aux);
    if(i%100==0 && i>0)
    {
        printf("\n\n");
        system("pause");
    }




  }
}

}

void empleados_print_all(ArrayList* this)
{

  if(this != NULL)
 {
 Empleado* aux;
  int len;

  len=al_len(this);

  for (int i=0; i<len; i++)
  {
    aux = (Empleado*)al_get(this, i);//apunta

    empleado_print(aux);
    if(i%100==0 && i>0)
    {
        printf("\n\n");
        system("pause");
    }




  }
}

}




Empleado* empleado_new(void)
{

    Empleado* returnAux = NULL;
    returnAux =(Empleado*)malloc(sizeof(Empleado));
    return returnAux;

}



int empleado_setId(Empleado* this, int id)
{

    if(this!=NULL)
    {

    this->id=id;
    }

    return 0;

}

int empleado_getId(Empleado* this)
{

    int id;


    if(this!=NULL)
    {
        id=this->id;
    }

    return id;
}

char* empleado_getName(Empleado* this)
{

    char* texto;


    if(this!=NULL)
    {
    texto = this->name;

    }

    return texto;
}


int empleado_SetName(Empleado* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->name,texto);
        retorno =1;

    }

    return retorno;
}

char* empleado_getDireccion(Empleado* this)
{

    char* texto;


    if(this!=NULL)
    {
    texto = this->direccion;

    }

    return texto;
}


int empleado_SetDireccion(Empleado* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->direccion,texto);
        retorno =1;

    }

    return retorno;
}



void empleado_ingresoNombre(Empleado* this, int min, int max)
{
    if(this!=NULL)
    {
         getStringletras("\nIngresar Nombre: ",empleado_getName(this), min, max);

            strlwr(empleado_getName(this));

            this->name[0]=toupper(this->name[0]);


    }

}

int empleado_set_horas(Empleado* this, int horas)
{

    if(this!=NULL)
    {

    this->horas=horas;
    }

    return 0;

}

int empleado_get_horas(Empleado* this)
{

    int horas;


    if(this!=NULL)
    {
        horas=this->horas;
    }

    return horas;
}


int empleado_set_sueldo(Empleado* this, float sueldo)
{

    if(this!=NULL)
    {

    this->sueldo=sueldo;
    }

    return 0;

}

float empleado_get_sueldo(Empleado* this)
{

    float sueldo;


    if(this!=NULL)
    {
        sueldo=this->sueldo;
    }

    return sueldo;
}



int calculoSueldo(void* EmpleadoA)
{
    Empleado* aux = NULL;

    int retorno=0;

    if (EmpleadoA!=NULL)
    {
        float sueldo=0;

        aux= (Empleado*)EmpleadoA;

        int horas;

        horas = empleado_get_horas(aux);

        if(horas<=120 && horas>0)
        {
            sueldo=(float)horas*180;
        }
        else if (horas>120 && horas<160)
        {
            sueldo=(float)120*180;
            sueldo+=(float)(horas-120)*240;
        }
        else if (horas>=160)
        {
            sueldo=(float)120*180;
            sueldo+=(float)(horas-120)*240;
            sueldo+=(float)(horas-160)*350;
        }
        retorno=1;

        empleado_set_sueldo(aux,sueldo);
    }

    return retorno;

}


