#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM_M 10

int main()
{


    eMovie listamovie[TAM_M]={0};


    char seguir='s';
    int opcion;

    while(seguir=='s')
    {
        printf("1- Agregar pel%ccula\n", 161);
        printf("2- Borrar pel%ccula\n");
        printf("3- Modificar pel%ccula\n");
        printf("4- Generar p%cgina web\n\n", 160);
        printf("5- Salir\n");



        opcion = IngresarEntero("\nIngrese una OPCION", 1, 5);

        switch(opcion)
        {
        case 1:
            cargarMovie(listamovie, TAM_M);
            break;
        case 2:

         /*   printf("Ingresar el DNI de la Persona: \n");
            dni= IngresarDNI();


            index = buscarPorDni(listadoPersonas, TAM, dni);

            if (index != -1)
            {
                printf("Se borr%c el registro con DNI Nro: %ld", 162, dni);
                listadoPersonas[index].dni = 0;//
                listadoPersonas[index].estado = 0;//
            }
            else
            {
                printf("Persona no encontrada");

            }*/

            break;
        case 3:

            //imprimirListadoPersonas(listadoPersonas, TAM);
            //CrearArchivoListadoPersonas(listadoPersonas, TAM);

            break;
        case 4:
            //GraficoListadoPersonas(listadoPersonas, TAM);
            break;
        case 5:
            seguir = 'n';
            break;
        }


        printf("\n\n");
        system("pause");
        system("cls");

    }



    return 0;
}
