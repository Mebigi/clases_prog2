#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"



int main()
{

    ArrayList* Alumnos = al_newArrayList();
    ArrayList* Alumnos2 = al_newArrayList();



//trabajo bin
/*
    md_carga_bin("Alumnos.bat",Alumnos);
    md_carga_bin("Alumnos2.bat",Alumnos2);

     */
    //trabajo csv


     md_cargar_text(Alumnos,"Alumnos.csv");
     //md_cargar_text(Alumnos2,"Alumnos2.csv");


    //vista_mostrarMenu();
    int option=0;
    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
        case 1:
            //Alta
            opcionAlta_Alumno(Alumnos,"Alumnos.csv");
            //opcionAlta_Alumno(Alumnos,"Alumnos.bat");
            break;
        case 2:
            //LISTA
            if(Alumnos!=NULL && (al_len(Alumnos)>0))
            {
                opcionListado(Alumnos, "Lista de Alumnos");
            }
            else
            {
                printf("NO hay Alumnos\n");
            }
            break;
        case 3:
            agregar_flotante(Alumnos, Alumnos2);

            break;
        case 4:
            selec(Alumnos, Alumnos2);

            break;
        case 5:
             if(Alumnos!=NULL && (al_len(Alumnos)>0))
            {

                alumnos_sortEntero(Alumnos,1);
                opcionListado(Alumnos, "Lista de Alumnos");
            }
            else
            {
                printf("NO hay Alumnos\n");
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
