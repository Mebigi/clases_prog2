#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

char titulo[50];
int genero;
char duracion[4];
char descripcion[500];
int puntaje;
char linkimage[300];
int idmovie;

}eMovie;


void cargarMovie(eMovie *, int);




int IngresarEntero(char [], int, int);

/** \brief valida un numero entero ingresado se encuatre dentro de un rango
 * \param minimo valor entero
 * \param maximo valor entero
 * \return un entero validado
 *
 */

int validarEntero (int, int, int);

/**
 * \brief Solicita un número entero usuario que el mismo ingresa como un strnig
 * \param mensaje Es el mensaje a ser mostrado
 * \param el valor minimo para ese entero
  * \param el valor maximo para ese entero
 * \return El número ingresado por el usuario tipo entero
 *
 */



int validarRangoEntero (int , int , int );

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */



void getString(char [],char [], int , int );


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */



void getStringletras(char [],char [], int , int );





 /**
 * Obtiene el primer indice sin datos del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */

int obtenerEspacioLibre(eMovie *lista, int);

int esTexto(char []);

int esNumero(char []);

int Confirmacion(char []);


void getStringEntero(char [],char [], int , int );



#endif // FUNCIONES_H_INCLUDED
