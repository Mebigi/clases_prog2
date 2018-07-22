#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "usuario.h"
#include "temas.h"
#include "vista.h"
#include "ArrayList.h"
#include "ingresodatos.h"
#include "Controlador.h"
#include "manejadorDatos.h"


int main()
{

    ArrayList* usuarios = al_newArrayList();
     ArrayList* temas = al_newArrayList();
    ArrayList* escuchados = al_newArrayList();



     char titulo[10]="menu";
     Formato_Titulo(titulo);
     printf("%s\n", titulo);


     md_cargar_usuario(usuarios, "usuarios.dat");

     printf("%d\n",  md_cargar_tema(temas, "temas.dat"));

     printf("%d\n",  md_cargar_temaEsc(escuchados, "escuchados.dat"));


     opcionPrintListado2(escuchados, "Lista escuchados");

    int option=0;
    while(option != 6)
    {
        option=vista_opcion(MENU_PPAL, 1, 6);

        switch(option)
        {
        case 1:
            // 1. LISTAR USUARIOS

            /*

             Ordenados por Nombre
             Ordenados por Nacionalidad y Nombre

            */

           // opcionPrintListado(usuarios, "Lista ordenados por nombre");
            opcionOrdenarListado(usuarios, 1);
            opcionPrintListado(usuarios, "Lista ordenados por nombre");

            break;
        case 2:
            //2. LISTAR TEMAS
            /*

             Ordenados por Artista y Nombre del Tema


             */
            opcionOrdenarListadoTemas(temas, 1);
            opcionPrintListado2(temas, "Lista ordenados por Artista y Nombre");

            break;
        case 3:
            //4. ESCUCHAR TEMA:
            /*

            4. ESCUCHAR TEMA: El usuario que desee escuchar un tema deberá ingresar
            su Nick , su clave de acceso y elegir un tema de los disponibles.


            */

            opcionEscucharTema(temas,usuarios,escuchados);

            break;
        case 4:
            //  5. GUARDAR ESTADISTICA:
           /*


            5. GUARDAR ESTADISTICA:  Se deberá generar el archivo “estadistica.dat” en el cual se almacenara
            la información referida a las reproducciones efectuadas por cada
            Usuario, este deberá ser leído al iniciar la aplicación. 6. INFORMAR:
            1. El tema mas escuchado
            2. El tema mas escuchado según nacionalidad del usuario
            3. El autor con mas reproducciones.
            4. El autor con mas temas en el catálogo.
            opcionDeleteDatoListado(usuarios);
            */


            opcionMasEscuchados(escuchados);
            opcionMasEscuchadosAutor(escuchados);
            opcionMasEscuchadosAutor(temas);
            opcionMasEscuchadosNac(escuchados);
            break;
        case 5:
            //GUARDAR
            if(md_guardar_text(usuarios,"usuarios.csv"))
            {
                 printf("Se guardo la lista\n");
            }
            else
            {
                printf("No se guardo la lista\n");
            }
            break;
        case 6:
            break;


        }

        printf("\n\n");
        system("pause");
        system("cls");
    }


    return 0;
}
