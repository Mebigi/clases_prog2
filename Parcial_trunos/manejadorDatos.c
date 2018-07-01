#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacion.h"
#include "turnos.h"
#include "ArrayList.h"
#include "Vista.h"
#include "controlador.h"

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
                Turno* aux;
                aux = (Turno*)turno_nuevo();
                if(fread(aux,sizeof(Turno),1,pFile))
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
        Turno* aux;
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
                aux = (Turno*)al_get(this, i);
                fwrite(aux,sizeof(Turno),1,f);
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

        Turno* aux;
        FILE* pFile;

        pFile = fopen(nombreArchivo,"r");

        int r;

        char var1[50],var2[50];


        if(pFile == NULL)
        {
            printf("El archivo no existe");
            retorno =0;
        }
        else
        {
            do
            {
                aux = (Turno*) malloc(sizeof(Turno));//le asigna una dire de memoria cada vez que entra al while
                r = fscanf(pFile,"%[^,],%[^\n]\n",var1,var2);
                if(r==2)
                {
                    //printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);
                    strncpy((aux)->dni,var1,sizeof((aux)->dni));
                    (aux)->id_turno = atoi(var2);
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


int md_leer_turno(char nombrearchivo[])
    {
        FILE* pFile;
        pFile = fopen(nombrearchivo,"r");
        int r;
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
            Turno* aux;
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
                    aux = (Turno*)al_get(this, i);
                    fprintf(f,"%s,%d\n", aux->dni, aux->id_turno);
                    printf("%s,%d\n", aux->dni, aux->id_turno);
                    retorno=1;

                }
                fclose(f);
            }


        }
        return retorno;
    }

    int md_guardar_turno(char nombrearchivo[],int ultimoId)
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



