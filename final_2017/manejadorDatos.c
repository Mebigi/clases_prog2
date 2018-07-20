#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
#include "loge.h"
#include "service.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include "Controlador.h"
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
                aux = (Est1*)est1_nuevo();
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

    if(this!=NULL && !(al_isEmpty(this)))
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
               // aux = (Est1*) malloc(sizeof(Est1));//le asigna una dire de memoria cada vez que entra al while
                aux =  est1_nuevo();
                r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
                if(r==4)
                {

                   //printf("%s,%s,%s,%s\n",var1,var2,var3,var4);
                   aux = est1_SetDatos(atoi(var1), var2, atof(var3), atol(var4));


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


int md_cargar_Service(ArrayList* this, char nombreArchivo[])
{

    int retorno=-1;

    if(this!=NULL)
    {
        Service* aux;
        FILE* pFile;

        pFile = fopen(nombreArchivo,"r");

        int r;

        char var1[50],var2[50],var3[50];

        if(pFile == NULL)
        {
            printf("El archivo no existe");
            retorno =0;
        }
        else
        {
            do
            {
               // aux = (Est1*) malloc(sizeof(Est1));//le asigna una dire de memoria cada vez que entra al while
                aux =  serv_nuevo();

                r = fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3);

                if(r==3)
                {

                   //printf("%s,%s,%s,%s\n",var1,var2,var3,var4);
                   aux = serv_SetDatos(atoi(var1), var2, var3);


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


int md_cargar_LogEntry(ArrayList* this, char nombreArchivo[])
{

    int retorno=-1;

    if(this!=NULL)
    {
        LogEntry* aux;
        FILE* pFile;

        pFile = fopen(nombreArchivo,"r");

        int r;

        char var1[50],var2[50],var3[50],var4[50],var5[50];

        if(pFile == NULL)
        {
            printf("El archivo no existe");
            retorno =0;
        }
        else
        {
            do
            {
               // aux = (Est1*) malloc(sizeof(Est1));//le asigna una dire de memoria cada vez que entra al while
                aux =  loge_nuevo();
                r = fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",var1,var2,var3,var4,var5);
                if(r==5)
                {

                   //printf("%s,%s,%s,%s\n",var1,var2,var3,var4);
                   aux = loge_SetDatos(var1, var2, atoi(var3), atoi(var4), var5);


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
        if(this!=NULL && !(al_isEmpty(this)))
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
                    fprintf(f,"%d,%s,%f,%ld\n",est1_get_entero(aux),est1_get_texto(aux),est1_get_flotante(aux),est1_get_largo(aux));

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



int md_guardar_w_e(ArrayList* this,ArrayList* this2, char nombrearchivo[])
    {
        int retorno=-1;
        if(this!=NULL && !(al_isEmpty(this)))
        {
            LogEntry* aux;
            Service* aux2;

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
                    aux = (LogEntry*)al_get(this, i);
                    aux2 = (Service*)al_get(this2, i);

                    fprintf(f,"%s,%s,%s,%s,%s\n",loge_get_date(aux),loge_get_time(aux),serv_get_name(aux2),loge_get_msg(aux),serv_get_email(aux2));

                    retorno=1;

                }
                fclose(f);
            }


        }
        return retorno;
    }




