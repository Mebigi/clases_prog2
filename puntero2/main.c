#include <stdio.h>
#include <stdlib.h>
typedef struct{
int uno;
int dos;
}eDato;

eDato swap(eDato);

void swap2(int* a, int* b);

int main()
{
    eDato datos;
    datos.uno = 1;
    datos.dos = 2;
    char letra;
    int* mipunteroAEntero;
    char* otroPunteroaChar;
    char* punteroaChar;

    punteroaChar=&letra;
    otroPunteroaChar=punteroaChar;
    printf("\nvalor otroPuntero: %d", otroPunteroaChar);
    printf("\nvalor otroPuntero: %p", otroPunteroaChar);
    letra='7';
    *punteroaChar='e';
    printf("\nvalor aux: %d", letra);
    printf("\nvalor aux: %d", &letra);
    printf("\nvalor aux: %c", letra);
    printf("\nvalor de puntero %d en hex:%p", letra,&letra);
    printf("\nvalor de puntero %d en hex:%p", punteroaChar,punteroaChar);
    printf("\nvalor de puntero %c", punteroaChar);
    printf("\nvalor de puntero %d en hex:%p", &punteroaChar, &punteroaChar);





    datos = swap(datos);

    printf("\n%d - %d", datos.uno, datos.dos);


    return 0;
}
eDato swap(eDato dato)
{
    int aux;
    aux=dato.dos;
    dato.dos=dato.uno;
    dato.uno=aux;

    return dato;

}

void swap2(int* a, int* b)// a= 0x46 b=0x42
{
    int aux;
    aux = *a; // aux= 9
    *a=*b; // y=2 X=2
    *b=aux; //y=9

}

//puntero: es una variable que guarda una direccion de memoria en principio de otra variable
