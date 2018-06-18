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
struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;


int employee_compare(void* pEmployeeA,void* pEmployeeB);
void employee_print(Employee* this);
Employee* employee_new(void);
void employee_delete(ArrayList* pArrayListEmployee);
int employee_setId(Employee* this, int id);
int employee_getId(Employee* this);
int employee_SetName(Employee* this, char* texto);


int parserEmployee(char [], ArrayList* pArrayListEmployee);

void employees_print_all(ArrayList* pArrayListEmployee);

char* employee_getName(Employee* this);

void employees_sort(ArrayList* pArrayListEmployee, int );

void employees_add(ArrayList* pArrayListEmployee, int );

void employee_set_ingresoNombre(Employee* this, int , int );

void employee_set_ingresoApellido(Employee* this, int , int );

int employees_Buscar(ArrayList* pArrayListEmployee, int );

void employees_guardar_all(ArrayList* pArrayListEmployee);

#endif // _EMPLOYEE_H



