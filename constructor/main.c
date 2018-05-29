#include <stdio.h>
#include <stdlib.h>

//Constructor es el quwe reserva un es´pacio en memoeria y devuelve una direccion de memeoria

typedef struct
{
    int id;
    char nombre;
    float sueldo;

}eEmpleado;

eEmpleado* new_eEmpleado(); //constructor por defectos solo se limita a devolver un espacio en memoria o NULL
eEmpleado* new_eEmpleado_parametros(int, char*, float);

int main()
{
    eEmpleado* miEmpleado;
    eEmpleado* otro_eEmpleado;

    printf("%p\n", miEmpleado);
    miEmpleado = new_empleado();
    printf("%p\n", miEmpleado);
    miEmpleado->id = 99;

    printf("%d\n", miEmpleado->id);

    otro_eEmpleado= new_eEmpleado_parametros(14, "pedro", 2500);

    //if(otroEmpleado!=NULL)
    {
        //usar set
    }

    return 0;
}

eEmpleado* new_eEmpleado()
{
    eEmpleado* mi_eEmpleado;

    mi_eEmpleado= (eEmpleado*) malloc(sizeof(eEmpleado));

    return mi_eEmpleado;

}

eEmpleado* new_eEmpleado_parametros(int id, char* nombre, float sueldo)
{
    eEmpleado* miEmpleado;

    miEmpleado = new_eEmpleado();

    if(miEmpleado!=NULL)
    {
        miEmpleado->id=id;
        miEmpleado->sueldo=sueldo;
        strcpy(miEmpleado->nombre, nombre);
    }

     return miEmpleado;
}
