#include <stdio.h>
#include <stdlib.h>


int main()
{

    //crear array enteros de 10 elementos
    //crear funcion CargarArray(int *, int)
    //mostrarArray(int *, int)
    //for para cargar y mostrar demostrar la null
    //ojo con scanf


    int *punteroEntero;
    int arrayEnteros[4];
    //punteroEntero=&arrayEnteros; //es redundante!
    punteroEntero=arrayEnteros; //es redundante!   p=&x[0]; //

    printf("arrayEnteros[0]? %d\n", &arrayEnteros[0]);
    printf("arrayEnteros? %d\n", punteroEntero);

    arrayEnteros[0]=155;
    arrayEnteros[1]=511;
    arrayEnteros[2]=177;
    arrayEnteros[3]=666;

    int *punteroEntero2;
    int arrayEnteros2[10];

    punteroEntero2=arrayEnteros2;



printf("Muestro desde punteros\n");
for (int i=0; i<4; i++)
{
       printf("arrayEnteros? %d\n", *(punteroEntero+i));//forma correcta
}
for (int i=0; i<4; i++)
{
       printf("arrayEnteros? %d\n", (punteroEntero+i));
}
for (int i=0; i<4; i++)
{
       printf("arrayEnteros? %d\n", (*punteroEntero+i));//primero accede al valor y luego suma i
}


    return 0;
}

