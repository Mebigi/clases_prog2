#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE* pArchivo;//abrir usar y cerrarlo siempre!!!//estructura file se crea un puntero que representa el archivo

/*
    pArchivo= fopen("C:\\TEST1\\archivo.txt","w");
    //abrir archvio recibe dos punteros a char 1 cadena 1 directorio o path del archivo
    //segundo string el modo w escribir rb // a append
    // si no lo puede abrir si no tiene permisos por ejemplo devulve un NULL

    if(pArchivo !=NULL)
    {
        fprintf(pArchivo, "Hola a todos!!!");
        fclose(pArchivo);
        printf("Guardado!\n");
    }
    else{printf("NO Guardado!\n");
    }
*/

    pArchivo= fopen("archivo.txt","r");

    char cadena[50];

     if(pArchivo !=NULL)
    {
        while(!feof(pArchivo))//mietra no sea el final del archivo voy a leer y mostrar
        {fgets(cadena,50, pArchivo);
        puts(cadena);//ojo que agrega el \n

        }

        fclose(pArchivo);
    }


    printf("Hello world!\n");
    return 0;
}
//archivos que se pueden generar de texto y binarios jashon xml
//parecido es un binario

//hacer un funcion que escriba en archivo de texto los datos de cada persona del array.
