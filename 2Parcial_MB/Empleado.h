/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
typedef struct{
    int id;
    char name[50];
    char direccion[50];
    int horas;
    float sueldo;

}Empleado;


int empleado_compareName(void* pEmpleadoA,void* pEmpleadoB);
int empleado_compareEntero(void* EmpleadoA,void* EmpleadoB);
void empleado_print(Empleado*);
Empleado* empleado_new(void);
int empleado_setId(Empleado* , int );
int empleado_getId(Empleado* );
char* empleado_getName(Empleado* );
int empleado_SetName(Empleado* , char* );

int empleado_set_flotante(Empleado* , float );
float empleado_get_flotante(Empleado* );
void empleado_ingresoNombre(Empleado* this, int , int );
Empleado* empleado_ingreso(void);

int empleado_SetDireccion(Empleado* this, char* );
char* empleado_getDireccion(Empleado* this);
int empleado_set_horas(Empleado* this, int );
int empleado_get_horas(Empleado* this);
int empleado_set_sueldo(Empleado* this, float);
float empleado_get_sueldo(Empleado* this);

int calculoSueldo(void* EmpleadoA);
void empleado_printSueldo(Empleado* this);





#endif // _EMPLOYEE_H



