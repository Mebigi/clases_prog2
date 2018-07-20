#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
#include "loge.h"
#include "service.h"
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

     int cont_gravedad3=0;
     int cont_gravedad47=0;
     int cont_gravedad7=0;



    int option=0;
    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
        case 1:
            //LEER LOG

            /*
            Deberá parsear el archivo log.txt y services.txt cargando
            un array dinámico con las entidades “LogEntry” y otro array
            con las entidades “Service” descriptas a continuación.
            */

            if(md_cargar_LogEntry(log,"log.txt"))
            {
                printf("- Se genero la lista de entidades LogEntry\n");
            }
            else
            {
                printf("- No se genero la lista de entidades LogEntry\n");
            }



            if(md_cargar_Service(services,"services.txt"))
            {
                printf("- Se genero la lista de entidades Services\n");
            }
            else
            {
                printf("- No se genero la lista de entidades Services\n");
            }

            break;

        case 2:
            //PROCESAR INFOMACION

            //opcionPrintListadoLogEntry(log,"listado Log");

            /*
            a) Si la gravedad es 3, se deberán copiar los mensajes en el
            archivo warnings.txt,para cualquier servicio menos el de ID 45.

            */

            cont_gravedad3 = opcionGravedad3(log, services);

            if(cont_gravedad3>0)
            {
                printf("- Gravedad 3 = Se ha generado el archivo warning\n");
            }
             else{

                 printf("- No existen datos Gravedad 3\n");

            }

            /*
            b)
            Si la gravedad tiene un valor entre 4 y 7 (inclusive)
            se imprimirán por pantalla con el siguiente formato :
            Fecha Hora Nombre servicio Mensaje de error Gravedad

            */

            printf("- Listado gravedad 4 - 7\n");

            cont_gravedad47 = opcionGravedad4a7(log, services);

            if(cont_gravedad47<0)
           {

                 printf("- No existen datos Gravedad entre 4 y 7\n");

            }

            /*
            c)

            Si la gravedad es mayor a 7, se copiarán los
            mensajes en el archivo errors.txt.

            */

            cont_gravedad7= opcionGravedadmayor7(log, services);

            if(cont_gravedad7>0)
            {
                 printf("- Gravedad > 7 = Se ha generado el archivo errors.txt\n");
            }
            else{

                 printf("- No existen datos Gravedad mayor 7\n");
            }



            break;
        case 3:
            //MOSTRAR ESTADISTICAS

            /*
            Deberá indicar el servicio que más fallos tiene y la cantidad de fallos para los
                siguientes valores de gravedad:
                • Menores a 3
                • 3
                • 4 y 7 (inclusive)
                • Mayores a 7
            */

            opcionMasfallos(log);

            printf("*  <3: \n");
            printf("*   3: %d\n", cont_gravedad3);
            printf("* 4-3: %d\n", cont_gravedad47);
            printf("*  >7: %d\n", cont_gravedad7);



            break;
       }

        printf("\n\n");
        system("pause");
        system("cls");
    }


    return 0;
}
