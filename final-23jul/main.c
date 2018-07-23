#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
#include "reparto.h"
#include "vista.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include "Controlador.h"
#include "manejadorDatos.h"


int main()
{

    ArrayList* Estructura1 = al_newArrayList();

     ArrayList* Entrega0 = al_newArrayList();


     ArrayList* Entrega1;



     char titulo[10]="menu";
     Formato_Titulo(titulo);
     printf("%s\n", titulo);


     md_cargar_text(Estructura1,"Estructura1.csv");

    int option=0;
    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
        case 1:
            //CARGAR Entrega

            if(md_cargar_Entrega(Entrega0,"entrega.csv.csv"))
            {
                printf("- Se genero la lista de Entrega 0 \n");
            }
            else
            {
                printf("- No se genero la lista de Entrega 0\n");
            }


            break;
        case 2:
            //LISTADO Entrega
            printf("Lista de Entrega 0\n");
            Reparto_print_all(Entrega0);



            break;
        case 3:
            //
            Entrega1 = opcionLocalidades(Entrega0);
            Reparto_print_loc(Entrega1);



            break;
        case 4:

           Entrega1 = opcionLocalidades(Entrega0);

           // Reparto_print_loc(Entrega1);



            char* loc;

            loc = combo_loc(Entrega1);

            //printf("%s", loc);


            reparto_localidad(Entrega0,loc);


            break;
        case 5:
            //opcionAgregarRepartos(Entrega0,Entrega1);

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
