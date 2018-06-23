typedef struct{
 int tipo_tramite; //0 urgente
 int estado; // 0 finalizado
 char dni[9];
 int id_turno; // orden
}Turno;


Turno* turno_nuevo(void);
int prod_delete(Turno* this);
int turno_set_tipo_tramite(Turno* this,int tipo);
int turno_get_tipo_tramite(Turno* this);
int turno_set_id_turno(Turno* this,int id);
int turno_get_id_turno(Turno* this);
int turno_setDni(Turno* this,char* dni);
char* turno_getDni(Turno* this);
int turno_setEstado(Turno* this,int estado);
int turno_getEstado(Turno* this);
int turno_compare(void*,void*);
