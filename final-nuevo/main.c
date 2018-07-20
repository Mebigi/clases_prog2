#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
#include "producto.h"
#include "vista.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include "Controlador.h"
#include "manejadorDatos.h"


int main()
{

    ArrayList* Estructura1 = al_newArrayList();

     ArrayList* Deposito0 = al_newArrayList();
     ArrayList* Deposito1 = al_newArrayList();



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
            //CARGAR DEPOSITOS

            if(md_cargar_Deposito(Deposito0,"dep0.csv"))
            {
                printf("- Se genero la lista de Deposito 0 \n");
            }
            else
            {
                printf("- No se genero la lista de Deposito 0\n");
            }

            if(md_cargar_Deposito(Deposito1,"dep1.csv"))
            {
                printf("- Se genero la lista de Deposito 1 \n");
            }
            else
            {
                printf("- No se genero la lista de Deposito 1\n");
            }
            break;
        case 2:
            //LISTADO DEPOSITOS
            printf("Lista de Deposito 0\n");
            Producto_print_all(Deposito0);

            printf("Lista de Deposito 1\n");
            Producto_print_all(Deposito1);

            break;
        case 3:
            //Mover Depositos
            opcionMoverDepositos(Deposito0,Deposito1);

            break;
        case 4:
            //Descontar prodcutos
            opcionDescontarProductos(Deposito0,Deposito1);

            break;
        case 5:
            opcionAgregarProductos(Deposito0,Deposito1);

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
