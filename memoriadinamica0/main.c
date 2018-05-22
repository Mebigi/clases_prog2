#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* y;

    //va a la pila
    //int x;
    //y=&x

    //va a heap/monton
     y = (int*) malloc(sizeof(int)); //bueca una direccion de memoria libre para ese tipo de dato lo casteo a puntero entero porque malloc te devulve void

    *y=9;

    printf("%d", y);

    printf("Hello world!\n");
    return 0;
}
