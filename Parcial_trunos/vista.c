#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacion.h"
#include "turnos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"



int vista_mostrarMenu()
{

    int option=0;

    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
            case 1:
                opcionAlta_Turno(0);
                break;
            case 2:
                opcionAlta_Turno(1);
                break;
            case 3:
                opcionProximo();
                break;
            case 4:
                opcionListadoPendientes();

                break;
            case 5:
                opcionListadoPasados();
                break;
            case 6:

                break;



        }
    }

    return 0;
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



int opcionAlta_Turno_Regular()
{
    return 0;
}



