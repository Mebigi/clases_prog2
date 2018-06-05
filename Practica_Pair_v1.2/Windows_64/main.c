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


int main()
{
    ArrayList* listaEmpleados;
    ArrayList* subempleados;

    Employee* aux;

    FILE* pFile;

    listaEmpleados = al_newArrayList();

    subempleados = al_newArrayList();

    pFile = fopen("data.csv","r");

    parserEmployee(pFile,listaEmpleados);


   /* printf("LISTA\n");

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

     */

     subempleados = al_subList(listaEmpleados,1,100);

  for (int i=0; i<al_len(subempleados); i++)
    {

    aux = (Employee*)al_get(subempleados, i);//apunta


    printf("%d\t%s\t%s\t%d\t\n", aux->id, aux->name, aux->lastName, aux->isEmpty );

    }



    return 0;
}


