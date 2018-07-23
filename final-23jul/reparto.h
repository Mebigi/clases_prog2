
typedef struct
{
int id;
char producto[50];
char direccion[50];
char localidad[50];
char recibe[50];


}Reparto;

typedef struct
{

char localidad[50];


}Localidad;



Reparto* rep_SeterDatos(int , char* , char* , char* , char*);
