typedef struct{
 char dni[9];
 int id_turno; // orden
}Turno;


Turno* turno_nuevo(void);
int prod_delete(Turno* this);

int turno_set_id_turno(Turno* this,int id);
int turno_get_id_turno(Turno* this);
int turno_setDni(Turno* this,char* dni);
char* turno_getDni(Turno* this);


void turno_print(Turno*);


