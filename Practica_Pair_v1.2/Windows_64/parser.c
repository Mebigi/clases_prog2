#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{

 Employee* aux;
 int r;

 int i=0;

 if(pFile == NULL)
 {
 printf("El archivo no existe");
 exit(EXIT_FAILURE);
 }
 do
 {

   aux = (Employee*)al_get(pArrayListEmployee, i);
   i++;

   //r = fscanf(pFile,"%d,%s,%s,%d\n",aux->id,aux->name,aux->lastName,aux->isEmpty);
   if(r==4){
   printf("Lei %d %s %s %d\n",aux->id,aux->name,aux->lastName,aux->isEmpty);
    }
     else
     break;
     }while(!feof(pFile));
     fclose(pFile);
     exit(EXIT_SUCCESS);



    return 0;
}
