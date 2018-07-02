#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "ingresodatos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"
#include "manejadorDatos.h"

int md_carga_bin(char nombrearchivo[], ArrayList* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        retorno =0;
        FILE* pFile=fopen(nombrearchivo,"rb");
        if(pFile != NULL)
        {
            do
            {
                Empleado* aux;
                aux = (Empleado*)empleado_new();
                if(fread(aux,sizeof(Empleado),1,pFile))
                {
                    al_add(this,aux);
                    retorno =1;
                }

            }
            while(!feof(pFile));
            fclose(pFile);
        }

    }

    return retorno;
}


int md_guardar_bin(ArrayList* this,char nombrearchivo[])
{
    int retorno=-1;

    if(this!=NULL)
    {
        Empleado* aux;
        FILE *f;
        f=fopen(nombrearchivo, "wb");
        if(f==NULL)
        {
            retorno=0;
        }
        else
        {
            int len;
            len=al_len(this);

            for (int i=0; i<len; i++)
            {
                aux = (Empleado*)al_get(this, i);
                fwrite(aux,sizeof(Empleado),1,f);
                retorno=1;

            }
            fclose(f);
        }

    }

    return retorno;

}



int md_cargar_text(ArrayList* this, char nombreArchivo[])
{

    int retorno=-1;

    if(this!=NULL)
    {

        Empleado* aux;
        FILE* pFile;

        pFile = fopen(nombreArchivo,"r");

        int r;

        char var1[50],var2[50],var3[50],var4[50];

        if(pFile == NULL)
        {
            printf("El archivo no existe");
            retorno =0;
        }
        else
        {
            do
            {
               // aux = (Empleado*) malloc(sizeof(Empleado));//le asigna una dire de memoria cada vez que entra al while
                aux =  empleado_new();
                r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
                if(r==4)
                {
                    empleado_setId(aux,atoi(var1));
                    empleado_SetName(aux, var2);
                    empleado_SetDireccion(aux, var3);
                    empleado_set_horas(aux, atoi(var4));

                    retorno =1;

                    al_add(this,(aux));


                }

            }
            while(!feof(pFile));
            fclose(pFile);

        }
    }

        return retorno;
}


int md_leer_ultimo(char nombrearchivo[])
    {
        FILE* pFile;
        pFile = fopen(nombrearchivo,"r");

        char var1[50];
        int retorno=-1;

        if(pFile == NULL)
        {
            printf("El archivo no existe");
            retorno=0;
        }

        else
        {
            fscanf(pFile,"%[^\n]",var1); // es el encabezado
            retorno= atoi(var1);
            fclose(pFile);
        }


        return retorno;
    }


int md_guardar_text(ArrayList* this, char nombrearchivo[])
    {
        int retorno=-1;
        if(this!=NULL)//chequear si esEmpty
        {
            Empleado* aux;
            FILE *f;
            f=fopen(nombrearchivo, "w");
            if(f==NULL)
            {
                retorno=0;
            }
            else
            {
                int len;
                len=al_len(this);

                for (int i=0; i<len; i++)
                {
                    aux = (Empleado*)al_get(this, i);
                    fprintf(f,"%d,%s,%s,%d,%f\n",empleado_getId(aux),empleado_getName(aux),empleado_getDireccion(aux),empleado_get_horas(aux),empleado_get_sueldo(aux));

                    retorno=1;

                }
                fclose(f);
            }


        }
        return retorno;
    }

int md_guardar_ultimo(char nombrearchivo[],int ultimoId)
    {

        FILE *f;
        int retorno=-1;

        f=fopen(nombrearchivo, "w");

        if(f==NULL)
        {
            retorno=0;
        }
        else
        {
            retorno = fprintf(f,"%d\n", ultimoId);
            fclose(f);

        }

        return retorno;

    }

