#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE* miArchivo;
    int numero;
    int lista[5]=

    for {
        ingreso numero;
    }

    while(!feof(miArchivo)){
        fread(&numero,sizeof(int),1,miArchivo);
    }

    FILE* miArchivo;
    int numero=64;
    miArchivo=fopen("prueba1.txt","w");

    fwrite(&numero,sizeof(int),1,miArchivo);

    fclose(miArchivo);

    fread(&numero,sizeof(int),1,miArchivo);
    fclose(miArchivo);

    printf("numero %d", numero);
    printf("Hello world!\n");

    return 0;
}
