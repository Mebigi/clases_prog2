#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "escuchados.h"

#include "usuario.h"
#include "temas.h"
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
            char encabezado[200];
            fread(encabezado,sizeof(200),1,pFile);

            do
            {
                Usuario* aux;
                aux = (Usuario*)us_nuevo();
                if(fread(aux,sizeof(Usuario),1,pFile))
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
        Usuario* aux;
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
                aux = (Usuario*)al_get(this, i);
                fwrite(aux,sizeof(Usuario),1,f);
                retorno=1;

            }
            fclose(f);
        }

    }

    return retorno;

}



int md_cargar_usuario(ArrayList* this, char nombreArchivo[])
{

    int retorno=-1;

    if(this!=NULL)
    {



        Usuario* aux;
        FILE* pFile;

        pFile = fopen(nombreArchivo,"r");

        int r;

        char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];

        if(pFile == NULL)
        {
            printf("El archivo no existe");
            retorno =0;
        }
        else
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);
            do
            {
               // aux = (Usuario*) malloc(sizeof(Usuario));//le asigna una dire de memoria cada vez que entra al while
                aux =  us_nuevo();
                r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);
                if(r==7)
                {

                   //printf("%s,%s,%s,%s\n",var1,var2,var3,var4);
                   aux = us_SeterDatos(atoi(var1),var2,var3,var4,var5,var6,var7);


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


int md_cargar_tema(ArrayList* this, char nombreArchivo[])
{

    int retorno=-1;

    if(this!=NULL)
    {



        Tema* aux;
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


            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
            do
            {
               // aux = (Tema*) malloc(sizeof(Tema));//le asigna una dire de memoria cada vez que entra al while
                aux =  us_nuevo();
                r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
                if(r==3)
                {

                   //printf("%s,%s,%s\n",var1,var2,var3);
                   aux = tem_SeterDatos(atoi(var1),var2,var3);


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



int md_cargar_temaEsc(ArrayList* this, char nombreArchivo[])
{

    int retorno=-1;

    if(this!=NULL)
    {



        Escuchados* aux;
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


            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            do
            {
               aux = (Escuchados*) malloc(sizeof(Escuchados));//le asigna una dire de memoria cada vez que entra al while


                r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
                if(r==4)
                {
               // printf("%s,%s,%s,%s\n",var1,var2,var3,var4);
                   aux = esc_SeterDatos(atoi(var1),var2,var3,var4);



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
            Usuario* aux;
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
                    aux = (Usuario*)al_get(this, i);
                    fprintf(f,"%d,%s,%s,%s,%s,%s,%s\n",us_get_idUsuario(aux),us_get_nombreUsuario(aux),us_get_email(aux),us_get_sexo(aux),us_get_pais(aux),us_get_password(aux),us_get_ip_address(aux));

                    retorno=1;

                }
                fclose(f);
            }


        }
        return retorno;
    }



int md_guardar_temas(ArrayList* this, char nombrearchivo[])
    {
        int retorno=-1;
        if(this!=NULL && !(al_isEmpty(this)))
        {
            Tema* aux;
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

                fprintf(f,"id,nombre,artista\n");

                for (int i=0; i<len; i++)
                {
                    aux = (Tema*)al_get(this, i);
                    fprintf(f,"%d,%s,%s\n",tem_get_idTema(aux),tem_get_nombreTema(aux),tem_get_artista(aux));

                    retorno=1;

                }
                fclose(f);
            }


        }
        return retorno;
    }



int md_guardar_temasEsc(ArrayList* this, char nombrearchivo[])
    {
        int retorno=-1;
        if(this!=NULL && !(al_isEmpty(this)))
        {
            Escuchados* aux;
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

                fprintf(f,"id,nombre,artista,pais\n");

                for (int i=0; i<len; i++)
                {
                    aux = (Escuchados*)al_get(this, i);
                    fprintf(f,"%d,%s,%s,%s\n",tem_get_idTema(aux),tem_get_nombreTema(aux),tem_get_artista(aux),esc_get_pais(aux));


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

