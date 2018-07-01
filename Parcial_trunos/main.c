#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacion.h"
#include "turnos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"


int main()
{

    ArrayList* Turnos = al_newArrayList();
    ArrayList* TurnosU = al_newArrayList();
    ArrayList* TurnosA = al_newArrayList();




    //cont_inicio(Turnos, "turnos.bat");
    //cont_inicio(TurnosU, "turnosU.bat");
    //cont_inicio(TurnosA, "turnosA.bat");

    md_cargar_text(Turnos, "turnos.csv");
    md_cargar_text(TurnosU, "turnosU.csv");
    md_cargar_text(TurnosA, "turnosA.csv");

    Turno* proximo=NULL;

    //vista_mostrarMenu();
    int option=0;
    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
            case 1:
                opcionAlta_Turno(TurnosU,"turnosU.csv");
                break;
            case 2:
                opcionAlta_Turno(Turnos,"turnos.csv");
                break;
            case 3:

                proximo = opcionProximo(TurnosU, "Turnos Urgentes");
                if(add_listadoAtendidos(TurnosA,proximo)==0)
                {
                    md_guardar_text(TurnosA,"turnosA.csv");
                    md_guardar_text(TurnosU,"turnosU.csv");

                }
                else
                 {

                 printf("NO hay pacientes URGENTES para atender\n");

                 proximo = opcionProximo(Turnos, "Turnos Regulares");
                if(add_listadoAtendidos(TurnosA,proximo)==0)
                {
                    md_guardar_text(TurnosA,"turnosA.csv");
                    md_guardar_text(Turnos,"turnos.csv");

                }
                else
                {
                    printf("NO hay pacientes para atender\n");
                     }
                }


                break;
            case 4:
                if(TurnosU!=NULL)
                {
                 opcionListado(TurnosU, "Lista de Turnos Urgentes");
                }
                if(Turnos!=NULL)
                {
                 opcionListado(Turnos, "Lista de Turnos Regulares");
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
