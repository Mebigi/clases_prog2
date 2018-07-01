#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"



int main()
{

    ArrayList* Empleados = al_newArrayList();
    //ArrayList* Empleados2 = al_newArrayList();



//trabajo bin
/*
    md_carga_bin("empleados.bat",Empleados);
    md_carga_bin("empleados2.bat",Empleados2);

     */
    //trabajo csv


     md_cargar_text(Empleados,"data_p2.csv");
     //md_cargar_text(Empleados2,"empleados2.csv");


    //vista_mostrarMenu();
    int option=0;
    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
        case 1:
            //Alta
            opcionAlta_Employee(Empleados,"data_p2.csv");
            //opcionAlta_Employee(Empleados,"empleados.bat");
            break;
        case 2:
            //LISTA
            if(Empleados!=NULL && (al_len(Empleados)>0))
            {
                opcionListado(Empleados, "Lista de Empleados");
            }
            else
            {
                printf("NO hay Empleados\n");
            }
            break;
        case 3:

            break;
        case 4:


            break;
        case 5:



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
