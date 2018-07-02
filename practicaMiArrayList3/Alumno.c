#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"


int alumno_compareName(void* pAlumnoA,void* pAlumnoB)
{
   int retorno=0;

   Alumno* aux1= (Alumno*)pAlumnoA;
   Alumno* aux2= (Alumno*)pAlumnoB;

   if(aux1!=NULL && aux2!=NULL)
   {
   if(strcmp(alumno_getName(aux1),alumno_getName(aux2))>0)
   {
       retorno=1;
   }

   else if(strcmp(alumno_getName(aux1),alumno_getName(aux2))<0)
   {
        retorno=-1;
   }
   }

    return retorno;
}

int alumno_compareEntero(void* AlumnoA,void* AlumnoB)
{
  int retorno=0;

   Alumno* aux1= (Alumno*)AlumnoA;
   Alumno* aux2= (Alumno*)AlumnoB;


   if(aux1!=NULL && aux2!=NULL)
   {
    if(alumno_get_entero(aux1)>alumno_get_entero(aux2))
   {
       retorno=1;

   }

   else  if(alumno_get_entero(aux1)<alumno_get_entero(aux2))
   {
        retorno=-1;

   }
   }

    return retorno;

}


void alumno_print(Alumno* this)
{
      printf("%10d\t%15s\t%15s\t%15d\t\n", this->id, this->name, this->sexo, this->entero);

}

void alumnos_print_all(ArrayList* this)
{

  if(this != NULL)
 {
 Alumno* aux;
  int len;

  len=al_len(this);

  for (int i=0; i<len; i++)
  {
    aux = (Alumno*)al_get(this, i);//apunta
    alumno_print(aux);
    if(i%100==0 && i>0)
    {
        printf("\n\n");
        system("pause");
    }




  }
}

}




Alumno* alumno_new(void)
{

    Alumno* returnAux = NULL;
    returnAux =(Alumno*)malloc(sizeof(Alumno));
    return returnAux;

}



int alumno_setId(Alumno* this, int id)
{

    if(this!=NULL)
    {

    this->id=id;
    }

    return 0;

}

int alumno_getId(Alumno* this)
{

    int id;


    if(this!=NULL)
    {
        id=this->id;
    }

    return id;
}

char* alumno_getName(Alumno* this)
{

    char* texto;


    if(this!=NULL)
    {
    texto = this->name;

    }

    return texto;
}


int alumno_SetName(Alumno* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->name,texto);
        retorno =1;

    }

    return retorno;
}


char* alumno_getSexo(Alumno* this)
{

    char* texto;


    if(this!=NULL)
    {
    texto = this->sexo;

    }

    return texto;
}


int alumno_SetSexo(Alumno* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->sexo,texto);
        retorno =1;

    }

    return retorno;
}



int alumno_set_entero(Alumno* this, int entero)
{

    if(this!=NULL)
    {

    this->entero=entero;
    }

    return 0;

}

int alumno_get_entero(Alumno* this)
{

    int entero;


    if(this!=NULL)
    {
        entero=this->entero;
    }

    return entero;
}


int alumno_set_flotante(Alumno* this, float flotante)
{

    if(this!=NULL)
    {

    this->flotante=flotante;
    }

    return 0;

}

float alumno_get_flotante(Alumno* this)
{

    float flotante;


    if(this!=NULL)
    {
        flotante=this->flotante;
    }

    return flotante;
}

void alumno_ingresoNombre(Alumno* this, int min, int max)
{
    if(this!=NULL)
    {
         getStringletras("\nIngresar Nombre: ",alumno_getName(this), min, max);

            strlwr(alumno_getName(this));

            this->name[0]=toupper(this->name[0]);


    }

}


void alumno_ingresoSexo(Alumno* this, int min, int max)
{
    if(this!=NULL)
    {
         getStringletras("\nIngresar Sexo: ",alumno_getSexo(this), min, max);

            strlwr(alumno_getSexo(this));

            this->sexo[0]=toupper(this->sexo[0]);


    }

}


Alumno* alumno_ingreso(void)
{


//char name[50];
int entero;
float flotante;

 int ultimoid;
 Alumno* nuevoAlumno;


 //getStringletras("Ingresar Nombre",name,3,50);
 entero = IngresarEntero("\nIngresar Entero:",1, 10000);
 //flotante = IngresarEnteroFlotante("\nIngresar flotante:",1, 1000000);



 nuevoAlumno =alumno_new();
 ultimoid= md_leer_ultimo("ultimoNro.txt");

 if (nuevoAlumno!= NULL)
 {
    ultimoid++; // le suma antes para no repetir
    alumno_setId(nuevoAlumno,ultimoid);
    //alumno_SetName(nuevoAlumno,name);
    alumno_ingresoNombre(nuevoAlumno, 2, 50);
    alumno_ingresoSexo(nuevoAlumno, 2, 50);
    alumno_set_entero(nuevoAlumno,entero);
    //alumno_set_flotante(nuevoAlumno,flotante);

    md_guardar_ultimo("ultimoNro.txt",ultimoid);

 }

return nuevoAlumno;

}

int calculo(void* AlumnoA)
{
    Alumno* aux = NULL;

    int retorno=0;

    if (AlumnoA!=NULL)
    {
        float flotante=0;

        aux= (Alumno*)AlumnoA;
        int entero;


        entero = alumno_get_entero(aux);

        if(entero<=176 && entero>0)
        {
            flotante=(float)entero*180;
        }
        else if (entero>176 && entero<209)
        {
            flotante=(float)176*180;
            flotante+=(float)(entero-176)*270;
        }
        else if (entero>=209)
        {
            flotante=(float)176*180;
            flotante+=(float)(entero-176)*270;
            flotante+=(float)(entero-208)*360;
        }
        int retorno=1;

        alumno_set_flotante(aux,flotante);
    }

    return retorno;

}


int mayor(void* AlumnoA)
{
    Alumno* aux = NULL;

    int retorno=0;

    if (AlumnoA!=NULL)
    {
        float flotante=0;

        aux= (Alumno*)AlumnoA;
        int entero;


        entero = alumno_get_entero(aux);

        if(entero>30)
        {
           int retorno=1;

        }
    }
    return retorno;

}

