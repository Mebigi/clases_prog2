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
    char sexo[50];
    int entero;
    float flotante;


}Alumno;


int alumno_compareName(void* pAlumnoA,void* pAlumnoB);
int alumno_compareEntero(void* AlumnoA,void* AlumnoB);
void alumno_print(Alumno*);
Alumno* alumno_new(void);
int alumno_setId(Alumno* , int );
int alumno_getId(Alumno* );
char* alumno_getName(Alumno* );
int alumno_SetName(Alumno* , char* );
int alumno_set_entero(Alumno* , int );
int alumno_get_entero(Alumno* );
int alumno_set_flotante(Alumno* , float );
float alumno_get_flotante(Alumno* );
void alumno_ingresoNombre(Alumno* this, int , int );
void alumno_ingresoEntero(Alumno* this, int , int );
void alumno_ingresoFlotante(Alumno* this, int , int );
Alumno* alumno_ingreso(void);
int calculo(void* AlumnoA);
int mayor(void* AlumnoA);


#endif // _EMPLOYEE_H



