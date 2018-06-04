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
    ArrayList* listaEmpleados2;

    Employee* miEmpleado;

    Employee* miEmpleado2;

    Employee* aux;

    FILE* pFile;

    pFile = fopen("data.csv","r");

    miEmpleado = (Employee*) malloc(sizeof(Employee));

    miEmpleado2 = (Employee*) malloc(sizeof(Employee));

    listaEmpleados2 = al_newArrayList();


    //parserEmployee(pFile,listaEmpleados2);




    miEmpleado->id=7;
    strcpy(miEmpleado->name, "Juan");
    miEmpleado->isEmpty=1;
    strcpy(miEmpleado->lastName, "Gomez");


    miEmpleado2->id=2;
    strcpy(miEmpleado2->name, "Maria");
    miEmpleado2->isEmpty=1;
    strcpy(miEmpleado2->lastName, "Bigi");



   listaEmpleados = al_newArrayList();//Allocate


    al_add(listaEmpleados, miEmpleado);
    al_add(listaEmpleados, miEmpleado2);

    for (int i=0; i<al_len(listaEmpleados); i++)
    {

    aux = (Employee*)al_get(listaEmpleados, i);//apunta

    printf("Elementos: %d--%s\n", aux->id, aux->name);

    }

    al_sort(listaEmpleados,employee_compare,1);//0 descendente

     for (int i=0; i<al_len(listaEmpleados); i++)
    {

    aux = (Employee*)al_get(listaEmpleados, i);//apunta

    printf("Elementos: %d--%s\n", aux->id, aux->name);

    }

     printf("Elementos: %d", al_len(listaEmpleados));




    return 0;
}


