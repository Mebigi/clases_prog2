#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "temas.h"
#include "usuario.h"
#include "escuchados.h"


int esc_set_pais(Escuchados* this, char* pais)
{
    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->pais,pais);
        retorno =1;
    }

    return retorno;
}



char* esc_get_pais(Escuchados* this)
{
    char* texto = NULL;

    if(this!=NULL)
    {
        texto = this->pais;
    }

    return texto;
}


Escuchados* esc_SeterDatos(int idTema, char* nombreTema,char* artista, char* pais)
{

    Escuchados* nuevo;
    nuevo= tem_nuevo();

    if (nuevo!= NULL)
    {
        confirma_set(tem_set_idTema(nuevo,idTema));
        confirma_set(tem_set_nombreTema(nuevo, nombreTema));
        confirma_set(tem_set_artista(nuevo, artista));
        confirma_set(esc_set_pais(nuevo, pais));


    }

    return nuevo;

}




