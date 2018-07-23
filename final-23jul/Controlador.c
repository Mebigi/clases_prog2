#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "est1.h"
#include "Reparto.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include "Controlador.h"
#include "manejadorDatos.h"
#define MIN_ENTERO 1
#define MAX_ENTERO 2000
#define MAX_TEXTO 100
#define MIN_TEXTO 3
#define MIN_FLOTANTE 0
#define MAX_FLOTANTE 999999



int opcionAlta(ArrayList* this)
{
    int retorno=-1;

    if(this!=NULL)
    {

        Est1* nuevo;

        nuevo= est1_IngresoDatos();

        if(nuevo!= NULL)

        {
            retorno=1;
            opcionAddListado(this,nuevo);
        }
    }


    return retorno;



}


int opcionPrintListado(ArrayList* this, char* encabezado)
{
    int retorno=0;

    if (this!= NULL && !(al_isEmpty(this)))
    {
        printf("\n%s\n", encabezado);
        est1_print_all(this);
        retorno=1;
    }

    return retorno;
}



int opcionAddListado(ArrayList* this, Est1* nuevo)
{

    int retorno=-1;

    if (nuevo!=NULL && this!=NULL)
    {
        retorno=al_add(this, nuevo);
        //retorno 0 si es ok -1 si es error al_add
    }

    return retorno;

}

int opcionDeleteDatoListado(ArrayList* this)
{
    int retorno=-1;

    if (this!=NULL)
    {
        int index;
        int clave;

        retorno=0;

        Est1* returnAux = NULL;
        clave= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
        index= opcionBuscarDato(this,clave);

        if(index != -1)
        {
            returnAux= al_get(this, index);
            est1_print(returnAux);
            retorno=1;

            if(Confirmacion("Confirma quitar el elemento de la lista"))
            {
                returnAux = al_pop(this,index);
                retorno=2;

            }

        }

    }
    return retorno;

}



int opcionModificacionDatoListado(ArrayList* this)
{
    int retorno=-1;

    if (this!=NULL)
    {
        int index;
        int clave;

        retorno=0;

        Est1* returnAux = NULL;
        clave= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
        index= opcionBuscarDato(this,clave);

        if(index != -1)
        {
            returnAux= al_get(this, index);

            est1_print(returnAux);

            retorno=1;

            Est1* modificado;

            modificado = est1_IngresoDatos();

            if(modificado!= NULL)
            {
                if(Confirmacion("Confirma modificar el elemento de la lista"))
                {
                    al_set(this,index,modificado);
                    retorno=2;
                }

            }



        }
    }
        return retorno;

}


int opcionBuscarDato(ArrayList* this, int clave)
{
    Est1* aux;
    int len;

    int index=-1;

    len=al_len(this);
    for (int i=0; i<len; i++)
    {
        aux = (Est1*)al_get(this, i);//apunta

        if (aux->entero==clave)
        {
            index=i;
            break;
        }

    }
    return index;

}


void opcionOrdenarListado(ArrayList* this, int orden)
{

    al_sort(this,est1_compareEntero,orden);
    //al_sort(this,est1_compareTexto,orden);

}



void est1_print_all(ArrayList* this)
{

    if(this != NULL)
    {
        Est1* aux;
        int len;

        len=al_len(this);

        for (int i=0; i<len; i++)
        {
            aux = (Est1*)al_get(this, i);//apunta

            est1_print(aux);
            if(i%100==0 && i>0)
            {
                printf("\n\n");
                system("pause");
            }

        }
    }

}


int opcionMoverEntregas(ArrayList* this, ArrayList* this2)
{

    int retorno=0;
    if(this!=NULL && this2!=NULL)
    {

    int origen;
    int Destino;
    int id;
    int index;

    retorno=1;

    //this 0
    //this2 1
    origen = IngresarEntero("\n\nIngrese El Entrega de Origen 0/1", 0, 1);
    Destino = IngresarEntero("\n\nIngrese El Entrega de Destino  0/1", 0, 1);



    if(origen==0 && Destino==1)
    {

        if(!(al_isEmpty(this)))
        {
        id = IngresarEntero("\n\nIngrese El Codigo del Reparto", 1, 100000);
        index = opcionBuscarReparto(this, id);

        if(index!=-1)
        {
            al_add(this2, al_pop(this, index));
            md_guardar_Entrega(this2, "Dep1.csv");
            md_guardar_Entrega(this, "Dep0.csv");

        }
        else
        {
             printf("Reparto no encontrado");
        }
        }
        else
        {
             printf("Entrega origen vacio");
        }

    }
    else if(origen==1 && Destino==0)
    {
        if(!(al_isEmpty(this2)))
        {
        id = IngresarEntero("\n\nIngrese El Codigo del Reparto", 1, 100000);
        index = opcionBuscarReparto(this2, id);

        if(index!=-1)
        {
            al_add(this2, al_pop(this, index));
            md_guardar_Entrega(this2, "Dep1.csv");
            md_guardar_Entrega(this, "Dep0.csv");

        }
        else
        {
             printf("Reparto no encontrado");
        }
        }
        else
        {
             printf("Entrega origen vacio");
        }
    }
    else
    {
        printf("Operacion invalida");


    }
    }
    return retorno;
}



int opcionBuscarReparto(ArrayList* this, int clave)
{
    Reparto* aux;
    int len;
    int index=-1;
    len=al_len(this);

    for (int i=0; i<len; i++)
    {
        aux = (Reparto*)al_get(this, i);//apunta

        if (aux->id==clave)
        {
            index=i;
            break;
        }
    }

    return index;

}







ArrayList* opcionLocalidades(ArrayList* this)
{


ArrayList* localidades=NULL;

if(this!= NULL && !(al_isEmpty(this)))
{
    ArrayList* this2;
    this2 = al_clone(this);

    Reparto* aux;
    Reparto* aux2;
    localidades= al_newArrayList();
    Localidad* loc;

    //int mayor=0;
    //int idMayor;
    int cont=0;





   for(int j=0;j<al_len(this);j++)
    {
        cont=0; //se reinicia en cada loop

        aux = al_get(this, j);

        for(int i=al_len(this2)-1;i>=0;i--)
        {
            aux2 = al_get(this2, i);

             if(strcmp(aux->localidad,aux2->localidad)==0 && cont==0)
            {
                cont=1;
                al_add(localidades, rep_get_localidad(aux2));
                al_remove(this2, i);
                //printf("%s\n", rep_get_localidad(aux2));

            }

             if(strcmp(aux->localidad,aux2->localidad)==0 && cont==1)
            {
                cont=1;
                al_remove(this2, i);

            }



        }


    }


}

return localidades;

}


char* combo_loc(ArrayList* localidades)
{

    char* localidad=NULL;

    localidad = (char*)malloc(51);

    char ingresada[50];

    Localidad* aux;

    Reparto_print_loc(localidades);

    getString("\nIngresar Localidad\n",ingresada, MIN_TEXTO, MAX_TEXTO);


    for(int i=0;i<al_len(localidades);i++)
    {
    aux = al_get(localidades, i);


    if(strcmp((char*)aux->localidad,ingresada)==0)
    { printf("%s\n", aux->localidad);
    printf("%s\n", ingresada);
        strcpy(localidad,ingresada);


        break;
    }

    }
    return localidad;

}


int loc_compare(void* datoA, char* datoB)
{
    int retorno=0;

    Reparto* aux1= (Reparto*)datoA;





    if(aux1!=NULL && datoB!=NULL)
    {
        if(strcmp(rep_get_localidad(aux1),datoB)==0)
        {
            printf("agrego");
            retorno=1;



        }
    }

    return retorno;
}






int reparto_localidad(ArrayList* this, char* loc)//this entrega0 this23 entreda1
{

        int retorno=0;

        if(this!=NULL && loc!=NULL)
        {

        ArrayList* localidadfiltrada;


        //veridicar !NULL

        localidadfiltrada = al_nueva(this,loc_compare,loc);


         if(localidadfiltrada!= NULL)
            {

                md_guardar_Entrega(localidadfiltrada, "localidad.csv");

            }
        else{



                 printf("Ocurrio un error al agregar los datos\n");


            }


        }



return retorno;

}




/*
int opcionDescontarRepartos(ArrayList* this, ArrayList* this2)
{
    int retorno=0;

    Reparto* aux;

    if(this!=NULL && this2!=NULL)
    {

        retorno=1;
        int id;
        int cantidad;
        int descontar;
        int index=-1;

        id = IngresarEntero("\n\nIngrese El Codigo del Reparto", 1, 100000);

        index = opcionBuscarReparto(this, id);

        if(index==-1)
        {
            index = opcionBuscarReparto(this2, id);
            if(index==-1)
            {
               printf("El repcutos no se encuantra en ningun deposito");
            }
            else
            {
            descontar = IngresarEntero("\n\nIngrese Cantidad a descontar", 1, 100000);

            aux = al_get(this2, index);

            cantidad = rep_get_cantidad(aux);

            if((cantidad-descontar)>=0)
            {
                 confirma_set(rep_set_cantidad(aux, (cantidad-descontar)));
                 md_guardar_Entrega(this2, "Dep1.csv");
            }
            else
            {
                 printf("La cantidad de Reparto a descontar supera al stock actual");


            }

            }

        }
        else
        {

            descontar = IngresarEntero("\n\nIngrese Cantidad a descontar", 1, 100000);

            aux = al_get(this, index);

            cantidad = rep_get_cantidad(aux);

            if((cantidad-descontar)>=0)
            {

                confirma_set(rep_set_cantidad(aux, (cantidad-descontar)));

                 md_guardar_Entrega(this, "Dep0.csv");


            }
            else
            {
                 printf("La cantidad de Reparto a descontar supera al stock actual");


            }


        }


    }


    return retorno;
}



int opcionAgregarRepartos(ArrayList* this, ArrayList* this2)
{
    int retorno=0;

    Reparto* aux;

    if(this!=NULL && this2!=NULL)
    {

        retorno=1;
        int id;
        int cantidad;
        int agregar;
        int index=-1;

        id = IngresarEntero("\n\nIngrese El Codigo del Reparto", 1, 100000);

        index = opcionBuscarReparto(this, id);

        if(index==-1)
        {
            index = opcionBuscarReparto(this2, id);
            if(index==-1)
            {
               printf("El repcutos no se encuantra en ningun deposito");
            }
            else
            {
            agregar = IngresarEntero("\n\nIngrese Cantidad a Agregar", 1, 100000);

            aux = al_get(this2, index);

            cantidad = rep_get_cantidad(aux);


             confirma_set(rep_set_cantidad(aux, (cantidad+agregar)));
             md_guardar_Entrega(this2, "Dep1.csv");


            }

        }
        else
        {

            agregar = IngresarEntero("\n\nIngrese Cantidad a agregar", 1, 100000);

            aux = al_get(this, index);

            cantidad = rep_get_cantidad(aux);

            confirma_set(rep_set_cantidad(aux, (cantidad+agregar)));

            md_guardar_Entrega(this, "Dep0.csv");


        }


    }


    return retorno;
}
*/
