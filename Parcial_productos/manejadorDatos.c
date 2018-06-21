#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "vistas.h"
#include "manejadorDatos.h"
#include "producto.h"


int md_carga_archivo(char nombrearchivo[], ArrayList* this)
{

    int ultimoId=0;
//char encabezado[28];

    FILE* pFile=fopen("data.bat","rb");

    if(pFile != NULL)
    {

        fread(&ultimoId,sizeof(int),1,pFile);
        //printf("ultimoId %d", ultimoId);

        //fread(encabezado,sizeof(char),27,pFile);
        //printf("encabezado %s", encabezado);// es el encabezado

        do
        {

            Producto* aux;
            aux = (Producto*)producto_nuevo();

            if(fread(aux,sizeof(Producto),1,pFile))
            {
                al_add(this,aux);

            }

          } while(!feof(pFile));

        fclose(pFile);
    }

        return ultimoId;
}


void md_guardar_binario(ArrayList* this, int ultimoId)
{
  Producto* aux;

  FILE *f;

	int retorno=0;

	f=fopen("data2.bat", "wb");

	//char encabezado[28]= {"id,nombre,Apellido,isEmpty\n"};

	if(f==NULL)
	{

			retorno=1;
    }


	if(retorno ==0)
	{

        int len;

       len=al_len(this);

        //que guarde el id mas grande y un encabezado

       fwrite(&ultimoId,sizeof(int),1,f);

       //fwrite(encabezado,sizeof(char),27,f);

        for (int i=0; i<len; i++)
        {



       aux = (Producto*)al_get(this, i);

       fwrite(aux,sizeof(Producto),1,f);




     }
	}

	fclose(f);




}


