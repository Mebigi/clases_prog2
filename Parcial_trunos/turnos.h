typedef struct{
 char dni[9];
 int id_turno; // orden
}Turno;


Turno* turno_nuevo(void);
int prod_delete(Turno* this);
int turno_set_id_turno(Turno* this,int);
int turno_get_id_turno(Turno* this);
int turno_setDni(Turno* ,char*);
char* turno_getDni(Turno* this);
Turno* turno_ingreso();
void turno_print(Turno*);
int compareTurno(void* ,void* );
int compareTurnoStr(void* ,void* );


