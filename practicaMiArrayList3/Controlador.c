#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"


int opcionAlta_Alumno(ArrayList* this, char nombrearchivo[])
{

 int retorno=-1;
 if(this!=NULL)
 {
    Alumno* nuevoAlumno;
    nuevoAlumno = alumno_ingreso();

    if(al_add(this,nuevoAlumno)==0) //0=es ok
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
    alumnos_print_all(this);
    }

    return 0;
}




int add_listadoEmpleados2(ArrayList* this, Alumno* empleado)
{

 int retorno=-1;

 if (empleado!=NULL && this!=NULL)
 {

  retorno=al_add(this, empleado);
  //retorno 0 si es ok -1 si es error al_add

 }

 return retorno;

}

void alumno_delete(ArrayList* this)
{
   //alumnos_print_all(listaEmpleados);
   int index;
   int id;
   Alumno* returnAux = NULL;

   id= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
   index= alumnos_Buscar(this ,id);
   returnAux = al_pop(this,index);

   alumno_print(returnAux);


}


int alumnos_Buscar(ArrayList* this, int id)
{
  Alumno* aux;
  int len;

  int index=-1;
  len=al_len(this);
  for (int i=0; i<len; i++)
  {
    aux = (Alumno*)al_get(this, i);//apunta


    if (aux->id==id)
    {
        index=i;
        break;
    }


  }
  return index;

}


void alumnos_sort(ArrayList* this, int orden)
{

  al_sort(this,alumno_compareName,orden);

}

void alumnos_sortEntero(ArrayList* this, int orden)
{

  al_sort(this,alumno_compareEntero,orden);

}

int agregar_flotante(ArrayList* this, ArrayList* this2)
{

    int returnAux = -1;

    int tam;

    if (this !=NULL && this!=NULL )
    {
        this2= al_clone(this);

        if(al_nueva(this2,calculo)!=0)
            {

                printf("Ocurrio un error al agregar los datos\n");

            }
        else{
                 md_guardar_text(this, "empleados2.cvs");

            }

        }
}

int selec(ArrayList* this, ArrayList* this2)
{

    int returnAux = -1;

    int tam;

    if (this !=NULL && this!=NULL )
    {
        this2= al_clone(this);

        if(al_nueva(this2,mayor)!=0)
            {

                printf("Ocurrio un error al agregar los datos\n");

            }
        else{
                 md_guardar_text(this2, "salida.csv");
                 printf("se creo el archivo de salida\n");


            }

        }
}






