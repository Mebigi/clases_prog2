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
#define MIN_ENTERO 1
#define MAX_ENTERO 2000
#define MAX_TEXTO 100
#define MIN_TEXTO 3
#define MIN_FLOTANTE 0
#define MAX_FLOTANTE 999999

/////////////ABM///////////////////////////

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




////////////////FUNCIONES PARTICULARES/////////////////////////

int opcionGravedad3(ArrayList* this, ArrayList* this2)
{
    int index=0;


    if(this!=NULL && this2!=NULL && !(al_isEmpty(this)) && !(al_isEmpty(this2)) )
    {

    LogEntry* aux;
    Service* aux2;

    ArrayList* log3 = al_newArrayList();
    ArrayList* service3 = al_newArrayList();

    int len;


    len=al_len(this);


    for (int i=0; i<len; i++)
    {
        aux = (LogEntry*)al_get(this, i);//apunta

        if (aux->gravedad==3 && aux->serviceId!=45)
        {
            al_add(log3,aux);
            index++;

            for (int j=0; j<len; j++)
            {
                aux2 = (Service*)al_get(this2, j);

                if(aux->serviceId == aux2->id)
                {
                     al_add(service3,aux2);
                     break;
                }
            }



        }

    }


    md_guardar_w_e(log3,service3,"warnings.txt");

    }

    return index;

}


int opcionGravedad4a7(ArrayList* this, ArrayList* this2)
{
    LogEntry* aux;
    Service* aux2;

    int len;
    int len2;

    int contador=0;

    len=al_len(this);
    len2=al_len(this2);

    if(this!=NULL && this2!=NULL && !(al_isEmpty(this)) && !(al_isEmpty(this2)) )
    {

        printf("\nFecha                \tHora\tNombre servicio\tMensaje de error\tGravedad\n");

        for (int i=0; i<len; i++)
        {
            aux = (LogEntry*)al_get(this, i);//apunta



            if ((aux->gravedad<=7) && (aux->gravedad>4))
            {
                printf("%10s\t%10s\t", loge_get_date(aux),loge_get_time(aux));
                contador++;

                for (int j=0; j<len2; j++)
                {
                    aux2 = (Service*)al_get(this2, j);

                    if(aux->serviceId == aux2->id)
                    {
                        printf("%10s\t%10s\t%10d\t\n", serv_get_name(aux2),loge_get_msg(aux),loge_get_gravedad(aux));
                        break;
                    }


                }

            }

        }


    }



    return contador;
}




int opcionGravedadmayor7(ArrayList* this, ArrayList* this2)
{
    LogEntry* aux;
    Service* aux2;

    ArrayList* log7 = al_newArrayList();
    ArrayList* service7 = al_newArrayList();

    int len;

    int index=0;

    len=al_len(this);
    for (int i=0; i<len; i++)
    {
        aux = (LogEntry*)al_get(this, i);//apunta

        if (aux->gravedad>7)
        {
            al_add(log7,aux);
            index++;

            for (int j=0; j<len; j++)
            {
                aux2 = (Service*)al_get(this2, j);

                if(aux->serviceId == aux2->id)
                {
                     al_add(service7,aux2);
                     break;
                }
            }



        }

    }


    md_guardar_w_e(log7,service7,"errors.txt");

    return index;

}





void opcionOrdenarListado(ArrayList* this, int orden)
{

    al_sort(this,est1_compareEntero,orden);
    //al_sort(this,est1_compareTexto,orden);

}



int opcionMasfallos(ArrayList* this)
{

int index=0;

if(this!= NULL && !(al_isEmpty(this)))
{
    int index=1;

    ArrayList* this2;
    this2 = al_clone(this);

    LogEntry* aux;
    LogEntry* aux2;

    int mayor=0;
    int idMayor;
    int cont=0;


   for(int j=0;j<al_len(this);j++)
    {
        cont=0; //se reinicia en cada loop

        aux = al_get(this, j);

        for(int i=al_len(this2)-1;i>=0;i--)
        {
            aux2 = al_get(this2, i);

            if(aux->serviceId==aux2->serviceId)
            {
                cont++;
                al_remove(this2, i);

            }
        }


    if(cont > mayor)
    {
        mayor = cont;
        idMayor = loge_get_serviceId(aux);

    }

    }

    printf("ID %d cantidad %d\n", idMayor, mayor);

}

return index;

}



