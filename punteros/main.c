#include <stdio.h>
#include <stdlib.h>

//puntero: es una variable que guarda una direccion de memoria en principio de otra variable
//como se delcara un puntero: tipo de dato * nombre del puntero
// char* caracter;
// por el momento vamos a declarar otra varible para que provea una direccion de memoria una variable escalar.
//mas adelante pedremos al S.O. una direccion de memoria

void swap(int* a, int* b);

int main()
{

    char* caracter;
    char aux='7';
    caracter=&aux;



    // 0x27 0x30 <- caracter
    //-
    //-0x30 7 <- aux



    printf("%c\n", aux); //=>7
    printf("%d\n", &aux); //direccion de memoria de aux con & =>0x30
    printf("%d\n", caracter); //=> 30
    printf("%d\n", *caracter);// operador de inacceso * => 7
    printf("%d\n", &caracter);// direccion de memoria del puntero=> 27
    printf("%p\n", &caracter);// direccion de memoria del puntero en hexadecimal => 0x27
    //un array es un puntero porque la variable del array le pasa una direccion de memoria

    int x=9; //0x42
    int y=2; //0x46
    swap(&x, &y);

    return 0;
}
void swap(int* a, int* b)// a= 0x46 b=0x42
{
    int aux;
    aux = *a; // aux= 9
    *a=*b; // y=2 X=2
    *b=aux; //y=9

}
