#include <stdio.h>
#include <stdlib.h>

char* traerGenero(int numero, char* genero);

char* getDynamicString();


int main()
{
    char genero[10];
    char* nombre;

    traerGenero(1, genero);

    printf("%s\n", genero);


    nombre=getDynamicString("Ingresar nombre");

     return 0;
}
char* traerGenero(int numero, char* genero)
{
        switch (numero)
                {
                case 1:
                    strcpy(genero, "Terror");
                    break;
                case 2:
                    strcpy(genero, "Comedia");
                    break;
                case 3:
                    strcpy(genero, "Drama");
                    break;
                case 4:
                    strcpy(genero, "Accion");
                    break;
                case 5:
                    strcpy(genero, "Otros");
                    break;
                }

//Terror-1 , Comedia-2, Drama-3, Accion-4, Otros-5


    return genero;
}
//Construir una función llamada "getDynamicString" que permita al usuario ingresar un texto
//y devuelva un puntero a un espacio de memoria donde esta almacenado el texto ingresado.
 //Se requiere el uso de memoria dinámica.


char* getDynamicString(char* mensaje)
{
    char * texto;

    int len;

    printf("%s\n", mensaje);

    texto = (char*)malloc(sizeof(char)*30);

    fflush(stdin);
    scanf("%s", texto);

    len=strlen(texto);

    texto = (char*)realloc(texto, sizeof(char)*(len+1));


    return texto;


}
