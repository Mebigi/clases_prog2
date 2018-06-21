#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "vistas.h"
#include "manejadorDatos.h"
#include "producto.h"


void cont_inicio()
{
     ArrayList* Productos;

     Productos = al_newArrayList();

     int ultimoId =0;

     if(Productos!=NULL)
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


      //vista_mostrarMenu();

}

