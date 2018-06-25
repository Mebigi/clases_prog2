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
    char aux;
    int* mipunteroAEntero;
    char* caracter;
    char* otroPuntero;
    int a =9;
    int b= 2;
    int* pa =&a;
    int* pb=&b;

     printf("\n%d - %d", *pa, *pb);


    caracter=&aux;
    otroPuntero=caracter;
    printf("\nvalor otroPuntero: %d", otroPuntero);
    aux='7';
    *otroPuntero='e';
    printf("\nvalor aux: %d", aux);
    printf("\nvalor aux: %d", &aux);
    printf("\nvalor aux: %c", aux);
    printf("\nvalor otroPuntero: %d", otroPuntero);




    datos = swap(datos);

    printf("\n%d - %d", datos.uno, datos.dos);

    swap2(pa, pb);

    printf("\n%d - %d", *pa, *pb);


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
