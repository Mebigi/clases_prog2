#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Est1.h"
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
                Est1* aux;
                aux = (Est1*)alumno_new();
                if(fread(aux,sizeof(Est1),1,pFile))
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
        Est1* aux;
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
                aux = (Est1*)al_get(this, i);
                fwrite(aux,sizeof(Est1),1,f);
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

        Est1* aux;
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
                aux = (Est1*) malloc(sizeof(Est1));//le asigna una dire de memoria cada vez que entra al while
                r = fscanf(pFile,"%[^;];%[^;];%[^;];%[^\n]",var1,var2,var3,var4);
                if(r==4)
                {
                    //printf("Lei: %s %s\n",var1,var2);
                    alumno_setId(aux,atoi(var1));
                    alumno_SetName(aux, var2);
                    alumno_SetSexo(aux, var3);
                    alumno_set_entero(aux,atoi(var4));
                    //alumno_set_flotante(aux,atof(var4));

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
        if(this!=NULL)
        {
            Est1* aux;
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
                    aux = (Est1*)al_get(this, i);
                    fprintf(f,"%d;%s;%s;%d\n",alumno_getId(aux),alumno_getName(aux),alumno_getSexo(aux),alumno_get_entero(aux));

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

