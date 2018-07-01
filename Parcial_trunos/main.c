#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacion.h"
#include "turnos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"


int main()
{

    ArrayList* Turnos = al_newArrayList();
    ArrayList* TurnosU = al_newArrayList();
    ArrayList* TurnosA = al_newArrayList();


//trabajo bin

    md_carga_bin("turnos.bat",Turnos);
    md_carga_bin("turnosU.bat",TurnosU);
    md_carga_bin("turnosA.bat",TurnosA);

    //trabajo csv

    /*
     md_cargar_text(Turnos, "turnos.csv");
     md_cargar_text(TurnosU, "turnosU.csv");
     md_cargar_text(TurnosA, "turnosA.csv");
     */

    Turno* proximo=NULL;

    //vista_mostrarMenu();
    int option=0;
    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
        case 1:
            //opcionAlta_Turno(TurnosU,"turnosU.csv");
            opcionAlta_Turno(TurnosU,"turnosU.bat");
            break;
        case 2:
            //opcionAlta_Turno(Turnos,"turnos.csv");
            opcionAlta_Turno(Turnos,"turnos.bat");
            break;
        case 3:
            proximo = opcionProximo(TurnosU, "Turnos Urgentes");
            if(add_listadoAtendidos(TurnosA,proximo)==0)
            {
                /*
                md_guardar_text(TurnosA,"turnosA.csv");
                md_guardar_text(TurnosU,"turnosU.csv");
                */
                md_guardar_bin(TurnosA,"turnosA.bat");
                md_guardar_bin(TurnosU,"turnosU.bat");

            }
            else
            {

                printf("NO hay pacientes URGENTES para atender\n");
                proximo = opcionProximo(Turnos, "Turnos Regulares");
                if(add_listadoAtendidos(TurnosA,proximo)==0)
                {
                    /*
                    md_guardar_text(TurnosA,"turnosA.csv");
                    md_guardar_text(Turnos,"turnos.csv");
                    */
                    md_guardar_bin(TurnosA,"turnosA.bat");
                    md_guardar_bin(Turnos,"turnos.bat");


                }
                else
                {
                    printf("NO hay pacientes para atender\n");
                }
            }


            break;
        case 4:
            if(TurnosU!=NULL && (al_len(TurnosU)>0))
            {
                opcionListado(TurnosU, "Lista de Turnos Urgentes");
            }
            if(Turnos!=NULL && (al_len(Turnos)>0))
            {
                opcionListado(Turnos, "Lista de Turnos Regulares");
            }
            if(al_len(TurnosU)==0 && al_len(Turnos)==0)
            {
                printf("NO hay Pacientes\n");
            }

            break;
        case 5:

            if(TurnosA!=NULL)
            {
                opcionListado_sort(TurnosA, "Lista de Turnos Atendidos");
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
