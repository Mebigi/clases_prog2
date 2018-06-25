#include <stdio.h>
#include <stdlib.h>
void funcion1(char *);
void funcion2(char *);
void funcionDelegado(void(*funcion)(char*));
int main()
{

    //funcion1();
    void (*F1)(char*); //indica puntero a funcion
    F1 = funcion1;

    F1("Mercedes"); //llamo a f1

    funcionDelegado(funcion1);
    funcionDelegado(funcion2);


    return 0;
}
void funcion1(char * txt)
{
    printf("Bienvenida %s\n", txt);
}
void funcion2(char * txt)
{
    printf("Despedida %s\n", txt);
}
void funcionDelegado(void(*funcion)(char*))
{
    funcion("Lucia, ");
}
