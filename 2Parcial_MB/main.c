#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"



int main()
{

    ArrayList* Empleados = al_newArrayList();
    ArrayList* Empleados2 = al_newArrayList();
    ArrayList* Empleados3 = al_newArrayList();

     md_cargar_text(Empleados,"dataSueldo.csv");
     //md_cargar_text(Empleados2,"empleados2.csv");

     char titulo[10]="menu";
     Formato_Titulo(titulo);
     printf("%s\n", titulo);

    int option=0;
    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
        case 1:
            opcionListado(Empleados, "Lista de Empleados");
            break;
        case 2:
                Empleados2 = al_clone(Empleados);
                empleados_sort(Empleados2,1);
                opcionListado(Empleados2, "Lista de Empleados ORDENADA");
                if(Empleados2!=NULL)
                {
                     printf("Está creada la lista\n");

                }
                else
                {
                    printf("NO Está creada la lista\n");
                }

            break;
        case 3:
            Empleados3 = al_clone(Empleados);
            if(al_len(Empleados3) == al_map(Empleados3,calculoSueldo))
            {
                  printf("Todos los sueldos pudieron ser calculados\n");
            }
            else
            {
                  printf("Ver lista hubo sueldos sin calcular\n");

            }
            opcionListadoSueldo(Empleados3, "Lista de Empleados mas sueldo");

            break;
        case 4:
            if(md_guardar_text(Empleados3,"sueldo.csv"))
            {
                 printf("Se guardo la lista\n");
            }
            else
            {
                printf("No se guardo la lista\n");
            }
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
