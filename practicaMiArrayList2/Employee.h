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
    int entero;
    float flotante;
}Employee;


int employee_compareName(void* pEmployeeA,void* pEmployeeB);
int employee_compareEntero(void* EmployeeA,void* EmployeeB);
void employee_print(Employee*);
Employee* employee_new(void);
int employee_setId(Employee* , int );
int employee_getId(Employee* );
char* employee_getName(Employee* );
int employee_SetName(Employee* , char* );
int employee_set_entero(Employee* , int );
int employee_get_entero(Employee* );
int employee_set_flotante(Employee* , float );
float employee_get_flotante(Employee* );
void employee_ingresoNombre(Employee* this, int , int );
void employee_ingresoEntero(Employee* this, int , int );
void employee_ingresoFlotante(Employee* this, int , int );
Employee* employee_ingreso(void);
Employee* calculo(void* EmployeeA);


#endif // _EMPLOYEE_H



