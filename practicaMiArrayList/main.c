#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "Employee.h"
#include "ingresodatos.h"

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
    ArrayList* listaEmpleados= NULL;

    ArrayList* subempleados = NULL;

    ArrayList* listaEmpleados2 = NULL;



    int ultimoId=0;
    int ultimoId2=0;



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
        printf("7. Guardar Empleados\n");
        printf("8. Esta contenido?\n");
        printf("9. Borrar listaEmpleados\n");
        printf("10. CLONO listaEmpleados\n");
        printf("11. mostrar listaEmpleados2\n");
        printf("12. push listaEmpleados\n");
        printf("13. Salir\n");

        opcion = IngresarEntero("\nIngrese una OPCION\n", 1, 13);

        switch(opcion)
        {
            case 1:
                listaEmpleados= al_newArrayList();
                //ultimoId = parserEmployee("data.csv",listaEmpleados);
                ultimoId = dm_leerbinario(listaEmpleados);
                break;
            case 2:
                employees_print_all(listaEmpleados);
                break;
            case 3:
                //employees_sort(listaEmpleados, 1);
                al_sort(listaEmpleados,employee_compare,1);
               break;
            case 4:
                employees_add(listaEmpleados, ultimoId);
                ultimoId++;
                //
                break;
            case 5:
                 employee_delete(listaEmpleados);

               break;
            case 6:
                subempleados= al_newArrayList();
                subempleados=al_subList(listaEmpleados,50,63);
                employees_print_all(subempleados);

                break;
            case 7:
               employees_guardar_all(listaEmpleados, ultimoId);
               employees_guardar_binario(listaEmpleados, ultimoId);
                break;
            case 8:
                if(al_containsAll(listaEmpleados,subempleados)>0)
                {
                    printf("Está contenido\n");
                }
                else if (al_containsAll(listaEmpleados,subempleados)<0)
                {
                    printf("aluna lista esta vacia\n");
                }
                else
                {printf("NO Está contenido\n");}


                break;
            case 9:
                 printf("Lista len\n %d", al_len(listaEmpleados));
                if(al_deleteArrayList(listaEmpleados)==0)
                {
                    printf("Lista BORRADA\n %d", al_len(listaEmpleados));
                    listaEmpleados = NULL;
                }
                else
                {
                    printf("NO Está BORRADA\n");
                }


            break;
            case 10:



                listaEmpleados2 = al_clone(listaEmpleados);
                if(listaEmpleados2!=NULL)
                {
                     printf("Está creada la lista\n");

                }
                else
                {
                    printf("NO Está creada la lista\n");
                }

                break;
            case 11:
                 employees_print_all(listaEmpleados2);
                break;
             case 12:
                 al_push(listaEmpleados, 2, al_get(listaEmpleados, 1000));
                 // si al_get retorna NULL no hace nada
                break;
            case 13:
                seguir = 'n';
                break;
        }
    }

    return 0;
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




