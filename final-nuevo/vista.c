#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
#include "producto.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include "Controlador.h"
#include "manejadorDatos.h"





int vista_mostrarMenu()
{

    /*int option=0;

    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
            case 1:
                opcionAlta_Turno(TurnosU);
                break;
            case 2:
                opcionAlta_Turno(Turnos);
                break;
            case 3:

                add_listadoAtendidos(TurnosA, opcionProximo());

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

                if(TurnosU!=NULL)
                {
                 opcionListadoAtendidos(TurnosU, "Lista de Turnos Urgentes Atendidos");
                }
                if(Turnos!=NULL)
                {
                 opcionListadoAtendidos(Turnos, "Lista de Turnos Regulares Atendidos");
                }
                break;
            case 6:

                break;



        }
    }

   */ return 0;
}

int vista_opcion(char mensaje[], int min, int max)
{
    char entero[6];
    int numero;
    int numerovalidado=0;

    do
    {
    printf("%s", mensaje);
    fflush(stdin);
    gets(entero);

    numero = validarEntero(entero, min, max, 6);//

    numerovalidado = validarRangoEntero(numero, min, max);


    }while(numerovalidado==0);



    return numero;
}




void Producto_print_all(ArrayList* this)
{

    if(this != NULL)
    {
        Producto* aux;
        int len;

        len=al_len(this);

        for (int i=0; i<len; i++)
        {
            aux = (Producto*)al_get(this, i);//apunta

            prod_print(aux);
            if(i%100==0 && i>0)
            {
                printf("\n\n");
                system("pause");
            }

        }
    }

}
