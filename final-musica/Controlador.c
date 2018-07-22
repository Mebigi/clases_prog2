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

        Usuario* nuevo;

        nuevo= us_IngresoDatos();

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
        us_print_all(this);
        retorno=1;
    }

    return retorno;
}


int opcionPrintListado2(ArrayList* this, char* encabezado)
{
    int retorno=0;

    if (this!= NULL && !(al_isEmpty(this)))
    {
        printf("\n%s\n", encabezado);
        tem_print_all(this);
        retorno=1;
    }

    return retorno;
}



int opcionAddListado(ArrayList* this, Usuario* nuevo)
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

        Usuario* returnAux = NULL;
        clave= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
        index= opcionBuscarDato(this,clave);

        if(index != -1)
        {
            returnAux= al_get(this, index);
            us_print(returnAux);
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

        Usuario* returnAux = NULL;
        clave= IngresarEntero("\n\nIngrese El ID que desea eliminar", 1, 100000);
        index= opcionBuscarDato(this,clave);

        if(index != -1)
        {
            returnAux= al_get(this, index);

            us_print(returnAux);

            retorno=1;

            Usuario* modificado;

            modificado = us_IngresoDatos();

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
    Usuario* aux;
    int len;

    int index=-1;

    len=al_len(this);
    for (int i=0; i<len; i++)
    {
        aux = (Usuario*)al_get(this, i);//apunta

        if (aux->idUsuario==clave)
        {
            index=i;
            break;
        }

    }
    return index;

}

int opcionBuscarTema(ArrayList* this, int clave)
{
    Tema* aux;
    int len;

    int index=-1;

    len=al_len(this);
    for (int i=0; i<len; i++)
    {
        aux = (Usuario*)al_get(this, i);//apunta

        if (aux->idTema==clave)
        {
            index=i;
            break;
        }

    }
    return index;

}


void opcionOrdenarListado(ArrayList* this, int orden)
{
    //al_sort(this,us_compareEntero,orden);
    //al_sort(this,us_compareTexto,orden);
    al_sort(this,us_comparePais,orden);
    //

}


void opcionOrdenarListadoTemas(ArrayList* this, int orden)
{
    //al_sort(this,us_compareEntero,orden);
    //al_sort(this,us_compareTexto,orden);
    al_sort(this,tem_compareTemas,orden);
    //

}

void us_print_all(ArrayList* this)
{

    if(this != NULL)
    {
        Usuario* aux;
        int len;

        len=al_len(this);

        for (int i=0; i<len; i++)
        {
            aux = (Usuario*)al_get(this, i);//apunta

            us_print(aux);
            if(i%100==0 && i>0)
            {
                printf("\n\n");
                system("pause");
            }

        }
    }

}



void tem_print_all(ArrayList* this)
{

    if(this != NULL)
    {
        Tema* aux;
        int len;

        len=al_len(this);

        for (int i=0; i<len; i++)
        {
            aux = (Tema*)al_get(this, i);//apunta

            tem_print(aux);
            if(i%100==0 && i>0)
            {
                printf("\n\n");
                system("pause");
            }

        }
    }

}

int opcionEscucharTema(ArrayList* temas, ArrayList* usuarios, ArrayList* escuchados)
{
    int retorno=0;
     if(temas != NULL && usuarios != NULL && escuchados != NULL)
    {
        retorno=1;

        int index;
        int indext;
        int idUsuario;
        char password[50];
        int idTema;
        int pais[50];

        Usuario* returnAux = NULL;
        Tema* returnAuxTema = NULL;
        Escuchados* returnAuxEsc = NULL;

        returnAuxEsc = (Escuchados*) malloc(sizeof(Escuchados));

        idUsuario= IngresarEntero("\n\nIngrese El ID Usuario", 1, 100000);

        index= opcionBuscarDato(usuarios,idUsuario);

        if(index != -1)
        {
            returnAux= al_get(usuarios, index);


            getString("\nIngresar passwoird\n",password, MIN_TEXTO, MAX_TEXTO);


            if(strcmp(password,returnAux->password)==0)
            {

             idTema= IngresarEntero("\n\nIngrese El ID tema", 1, 100000);

             indext= opcionBuscarTema(temas,idTema);



             if(indext!=-1)
             {
             returnAuxTema= al_get(temas, indext);



            returnAuxEsc->idTema = returnAuxTema->idTema;

             strcpy(returnAuxEsc->nombreTema,returnAuxTema->nombreTema);
             strcpy(returnAuxEsc->artista,returnAuxTema->artista);
             strcpy(returnAuxEsc->pais,returnAux->pais);

             printf("pais %s", returnAuxEsc->pais);


             al_add(escuchados, returnAuxEsc);



             md_guardar_temasEsc(escuchados,"escuchados.dat");




             retorno=1;

             }
             else{

                printf("tema inexistente\n");

             }






            }




         }
         else
         {
             printf("usuario inexistente\n");
         }
}
return retorno;
}



int opcionMasEscuchados(ArrayList* this)
{

int index=0;

if(this!= NULL && !(al_isEmpty(this)))
{
    int index=1;

    ArrayList* this2;
    this2 = al_clone(this);

    Tema* aux;
    Tema* aux2;

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

            if(aux->idTema==aux2->idTema)
            {
                cont++;
                al_remove(this2, i);

            }
        }


    if(cont > mayor)
    {
        mayor = cont;
        idMayor = tem_get_idTema(aux);

    }

    }

    printf("ID %d cantidad %d\n", idMayor, mayor);

}

return index;

}


int opcionMasEscuchadosAutor(ArrayList* this)
{

int index=0;

if(this!= NULL && !(al_isEmpty(this)))
{
    int index=1;

    ArrayList* this2;
    this2 = al_clone(this);

    Tema* aux;
    Tema* aux2;

    int mayor=0;
    int cont=0;
    char artista[50];


   for(int j=0;j<al_len(this);j++)
    {
        cont=0; //se reinicia en cada loop

        aux = al_get(this, j);

        for(int i=al_len(this2)-1;i>=0;i--)
        {
            aux2 = al_get(this2, i);

            if(strcmp(aux->artista,aux2->artista)==0)
            {
                cont++;
                al_remove(this2, i);

            }
        }


    if(cont > mayor)
    {
        mayor = cont;

        strcpy(artista,tem_get_artista(aux));


    }

    }

    printf("Artista %s cantidad %d\n", artista, mayor);

}

return index;

}



int opcionMasEscuchadosNac(ArrayList* this)
{

int index=0;

if(this!= NULL && !(al_isEmpty(this)))
{
    int index=1;

    ArrayList* this2;
    this2 = al_clone(this);

    Escuchados* aux;
    Escuchados* aux2;

    int mayor=0;
    int cont=0;
    char pais[50];


   for(int j=0;j<al_len(this);j++)
    {
        cont=0; //se reinicia en cada loop

        aux = al_get(this, j);

        for(int i=al_len(this2)-1;i>=0;i--)
        {
            aux2 = al_get(this2, i);

            if(strcmp(aux->pais,aux2->pais)==0)
            {
                cont++;
                al_remove(this2, i);

            }
        }


    if(cont > mayor)
    {
        mayor = cont;

        strcpy(pais,esc_get_pais(aux));



    }

    }

    printf("Pais %s cantidad %d\n", pais, mayor);

}

return index;

}

