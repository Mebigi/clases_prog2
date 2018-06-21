#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "vistas.h"
#include "manejadorDatos.h"
#include "producto.h"



Producto* producto_nuevo(void)
{

    Producto* returnAux = NULL;
    returnAux =(Producto*)malloc(sizeof(Producto));
    return returnAux;

}


int prod_delete(Producto* this)
{
    free(this);
    return 0;
}


int prod_setCodigo(Producto* this,int codigo)
{

    int retorno =0;

    if(this!=NULL)
    {
        this->codigo=codigo;
        retorno =1;

    }

    return retorno;

}


int prod_getCodigo(Producto* this)
{

    int codigo;


    if(this!=NULL)
    {
    codigo = this->codigo;
    }

    return codigo;
}

int prod_setDesc(Producto* this,char* descripcion)
{

    int retorno =0;

    if(this!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno =1;

    }

    return retorno;

}


char* prod_getDesc(Producto* this)
{

    char* texto;


    if(this!=NULL)
    {
    texto = this->descripcion;

    }

    return texto;
}


int prod_setImporte(Producto* this,float importe)
{

    if(this!=NULL)
    {

    this->importe=importe;
    }

    return 0;

}

float prod_getImporte(Producto* this)
{
    float importe=-1;

    if(this!=NULL)
    {
        importe=this->importe;
    }

    return importe;
}

int prod_setCantidad(Producto* this,int cantidad)
{
    int retorno =0;

    if(this!=NULL)
    {

    this->cantidad=cantidad;

    retorno =cantidad;
    }

    return retorno;

}

int prod_getCantidad(Producto* this)
{

    int cantidad;


    if(this!=NULL)
    {
        cantidad=this->cantidad;
    }

    return cantidad;
;
}

int prod_setEstado(Producto* this,int estado)
{

    if(this!=NULL)
    {
    this->activo = estado;
    }
    return 0;
}

int prod_getEstado(Producto* this)
{

     if(this!=NULL)
    {
     return this->activo;
    }
    return 0;

}


Producto* prod_findById(ArrayList* Productos, int codigo)
{
    int i;
    Producto *aux;
    void* retorno=NULL;

    if (Productos!= NULL)
    {
        for(i=0;i<al_len(Productos);i++)
            {
                aux = al_get(Productos,i);
                if(codigo == aux->codigo)
                {
                    retorno = aux;
                }
            }


    }


    return retorno;
}

