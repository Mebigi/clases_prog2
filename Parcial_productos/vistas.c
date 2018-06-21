
int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 5)
    {
        vista_opcion(MENU_PPAL,2,5);


        switch(option)
        {
            case 1:
                opcionListado();
                break;
            case 2:
                opcionAlta();
                break;
            case 3:
                opcionBaja();
                break;
            case 4:
                opcionModificacion();
                break;

        }
    }

    return 0;
}

int Confirmacion(char mensaje[])
{
     char confirma;
     int retorno=0;

      printf("\n.....................................................");


     printf("\n%s s/n: ", mensaje);



     confirma= getche();
     confirma= tolower(confirma);


     if(confirma == 's')
     {
         retorno=1;

     }

     return retorno;

}


int vista_opcion(char mensaje[], int min, int max)
{
    char entero[6];
    int numero;
    int numerovalidado=0;

    do
    {
    printf("%s", mensaje);
    fflush(stdin);
    gets(entero);

    numero = validarEntero(entero, min, max, 6);//

    numerovalidado = validarRangoEntero(numero, min, max);


    }while(numerovalidado==0);



    return numero;
}
