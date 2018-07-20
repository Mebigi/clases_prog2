#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
#include "vista.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include "Controlador.h"
#include "manejadorDatos.h"


int main()
{

    ArrayList* Estructura1 = al_newArrayList();
    ArrayList* log = al_newArrayList();

    ArrayList* services = al_newArrayList();



     char titulo[10]="menu";
     Formato_Titulo(titulo);
     printf("%s\n", titulo);


     md_cargar_text(Estructura1,"Estructura1.csv");
     md_cargar_LogEntry(log,"log.txt");
     md_cargar_Service(services,"services.txt");

    int option=0;
    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
        case 1:
            //LISTA
            //opcionPrintListado(Estructura1, "Lista");
            opcionPrintListadoLogEntry(log,"lista Log");
            //opcionPrintListadoService(services,"Lista Services");
            //opcionGravedad3(log, services);
           // opcionGravedadmayor7(log, services);
            opcionGravedad4a7(log, services);
            opcionMasfallos(log);




            break;
        case 2:
            //ALTA
            opcionAlta(Estructura1);

            break;
        case 3:
            //BAJA
            opcionDeleteDatoListado(Estructura1);

            break;
        case 4:
            //MODIFICACION
            opcionModificacionDatoListado(Estructura1);

            break;
        case 5:
            //GUARDAR
            if(md_guardar_text(Estructura1,"Estructura1.csv"))
            {
                 printf("Se guardo la lista\n");
            }
            else
            {
                printf("No se guardo la lista\n");
            }
            break;
        case 6:
            break;


        }

        printf("\n\n");
        system("pause");
        system("cls");
    }


    return 0;
}
