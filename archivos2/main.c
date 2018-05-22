#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;
} eDato;

int main()
{
    eDato d[2]={{3,'A'}, {3,'A'}};
    eDato d2[2];
    FILE* miArchivo;
    int numero=128;
    int otroNumero;

    miArchivo = fopen("numero.dat", "wb");

   //Ejemplo un un solo dato
    //fwrite(&d, sizeof(eDato), 1, miArchivo); //direccion de memoria tamaño en bytes de tipo de dato, cantidad y el archivo

    //ejemplo aaray de datos
    fwrite(d, sizeof(eDato), 2, miArchivo);

    fclose(miArchivo);



    miArchivo = fopen("numero.dat", "rb");

    fread(d2, sizeof(eDato), 2, miArchivo);

    fclose(miArchivo);

     for(int i=0; i<2; i++)
    {

     printf("%d--%c", d2[i].a, d2[i].b);
    }






}

