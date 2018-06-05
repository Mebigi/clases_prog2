#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/

int IngresarEntero(char [], int, int);
int validarEntero (int , int , int );
int main()
{
    ArrayList* listaEmpleados;


    listaEmpleados= al_newArrayList();

    ArrayList* subempleados;

    subempleados= al_newArrayList();



     char seguir='s';
     int opcion;


    while(seguir=='s')
    {
        printf("1. Parse del archivo data.csv\n");
        printf("2. Listar Empleados\n");
        printf("3. Ordenar por nombre\n");
        printf("4. Agregar un elemento\n");
        printf("5. Elimina un elemento\n");
        printf("6. Listar Empleados (Desde/Hasta)\n");
        printf("7. Salir\n");

        opcion = IngresarEntero("\nIngrese una OPCION", 1, 5);

        switch(opcion)
        {
            case 1:
                parserEmployee("data.csv",listaEmpleados);
                break;
            case 2:
                employees_print_all(listaEmpleados);
                break;
            case 3:
                employees_sort(listaEmpleados, 1);
               break;
            case 4:
                break;
            case 5:
               break;
            case 6:
                break;
            case 7:
                seguir = 'n';
                break;
        }
    }

    return 0;
}


int IngresarEntero(char mensaje[], int min, int max)
{
    int entero;
    puts(mensaje);
    fflush(stdin);
    scanf("%d",&entero);
    entero = validarEntero(entero, min, max);

    return entero;
}
int validarEntero (int dato, int min, int max)
{
    while(dato < min || dato > max)
    {

        fflush(stdin);
        printf("Dato no v%clido reingresar: ", 160);
        scanf("%d", &dato);

    }

    return dato;

}









   /*
   subempleados = al_newArrayList();

   printf("LISTA\n");

    for (int i=0; i<al_len(listaEmpleados); i++)
    {

    aux = (Employee*)al_get(listaEmpleados, i);//apunta


    printf("%d\t%s\t%s\t%d\t\n", aux->id, aux->name, aux->lastName, aux->isEmpty );

    }

    al_sort(listaEmpleados,employee_compare,1);//0 descendente
   printf("LISTA ORDENADA\n");
     for (int i=0; i<al_len(listaEmpleados); i++)
    {

    aux = (Employee*)al_get(listaEmpleados, i);//apunta


    printf("%d\t%s\t%s\t%d\t\n", aux->id, aux->name, aux->lastName, aux->isEmpty );

    }

     printf("Elementos: %d", al_len(listaEmpleados));



     subempleados = al_subList(listaEmpleados,1,100);

  for (int i=0; i<al_len(subempleados); i++)
    {

    aux = (Employee*)al_get(subempleados, i);//apunta


    printf("%d\t%s\t%s\t%d\t\n", aux->id, aux->name, aux->lastName, aux->isEmpty );

    }

*/




