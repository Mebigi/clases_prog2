#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"



int parserEmployee(char nombreArchivo[], ArrayList* pArrayListEmployee)
{

    Employee* aux;

    FILE* pFile;

    pFile = fopen(nombreArchivo,"r");

    int r;
    int i=0;
    char var1[50],var3[50],var2[50],var4[50];
    int ultimoId=0;

    if(pFile == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }

    do
    {

    if(i==0)
    {

    fscanf(pFile,"%d", &ultimoId);
    printf("%d\n", ultimoId);
    i++;

    }
    else if(i==1)
    {
      fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4); // es el encabezado
      i++;
    }
    else if(i>1)
    {



    aux = (Employee*) malloc(sizeof(Employee));//le asigna una dire de memoria cada vez que entra al while

        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            //printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);

            (aux)->id = atoi(var1);
            strncpy((aux)->name,var2,sizeof((aux)->name));
            strncpy((aux)->lastName,var3,sizeof((aux)->lastName));

            if(strcmp(var4,"true"))
            {
                (aux)->isEmpty = 1;
            }
            else
            {
                (aux)->isEmpty = 0;

            }

            al_add(pArrayListEmployee, (aux));

            i++;

        }

    }
      }
    while(!feof(pFile));



    fclose(pFile);
    //exit(EXIT_SUCCESS);



    return ultimoId;
}


int dm_leerbinario(ArrayList* pArrayListEmployee)
{


   int ultimoId=0;
   char encabezado[28];



    FILE* pFile=fopen("data.bat","rb");

    if(pFile == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }


     fread(&ultimoId,sizeof(int),1,pFile);
     //printf("ultimoId %d", ultimoId);

     fread(encabezado,sizeof(char),27,pFile);
     //printf("encabezado %s", encabezado);// es el encabezado

    do
    {

            Employee* aux = employee_new();

            if(fread(aux,sizeof(Employee),1,pFile))
            {
            al_add(pArrayListEmployee,aux);

            }



            //employee_print(aux);


    }while(!feof(pFile));

        fclose(pFile);

        return ultimoId;
}


void employees_guardar_binario(ArrayList* pArrayListEmployee, int ultimoId)
{
  Employee* aux;

  FILE *f;

	int retorno=0;

	f=fopen("data.bat", "wb");

	char encabezado[28]= {"id,nombre,Apellido,isEmpty\n"};

	if(f==NULL)
	{

			retorno=1;
    }


	if(retorno ==0)
	{

        int len;

       len=al_len(pArrayListEmployee);

        //que guarde el id mas grande y un encabezado

       fwrite(&ultimoId,sizeof(int),1,f);

       fwrite(encabezado,sizeof(char),27,f);

        for (int i=0; i<len; i++)
        {



       aux = (Employee*)al_get(pArrayListEmployee, i);

       fwrite(aux,sizeof(Employee),1,f);




     }
	}

	fclose(f);




}

