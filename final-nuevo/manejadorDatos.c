#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
#include "producto.h"
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



int md_cargar_Deposito(ArrayList* this, char nombreArchivo[])
{

    int retorno=0;

    if(this!=NULL)
    {

        Producto* aux;
        FILE* pFile;

        pFile = fopen(nombreArchivo,"r");

        int r;

        char var1[50],var2[50],var3[50];

        if(pFile == NULL)
        {
            printf("El archivo no existe");

        }
        else
        {

               //encabezado
               r = fscanf(pFile,"%[^,],%[^,],%[^\n]",var1,var2,var3);

            do
            {
               // aux = (Est1*) malloc(sizeof(Est1));//le asigna una dire de memoria cada vez que entra al while
                aux =  prod_nuevo();

                r = fscanf(pFile,"%[^,],%[^,],%[^\n]",var1,var2,var3);



                if(r==3)
                {


                   aux = prod_SeterDatos((atoi(var1)),var2,(atoi(var3)));

                   //printf("%s,%s,%s\n",var1,var2,var3);


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


int md_guardar_Deposito(ArrayList* this, char nombrearchivo[])
    {
        int retorno=-1;
        if(this!=NULL && !(al_isEmpty(this)))
        {
            Producto* aux;
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

                fprintf(f,"id,descrpcion,cantidad\n");

                for (int i=0; i<len; i++)
                {
                    aux = (Producto*)al_get(this, i);

                    fprintf(f,"%d,%s,%d\n",prod_get_id(aux),prod_get_descripcion(aux),prod_get_cantidad(aux));

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

