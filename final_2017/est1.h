

#include "ArrayList.h"

typedef struct
{
int entero;
char texto[50];
float flotante;
long int largo;
}Est1;


/** \brief aloja memoria para estructura de Est1
 *
 * \return Est1* puntero a dir de memoria que se alojó
 */ Est1* est1_nuevo(void);



 /** \brief setea entero en la estructura
 * \param entero a setear
 * \param Est1* puntero a estructura.
 * \return entero Ok - > 1 Error -> 0
 */ int est1_set_entero(Est1*, int );



 /** \brief devuelve entero de la estructura
 *
 * \param Est1* estructura
 * \return entero Ok - > 1 Error -> 0
 */ int est1_get_entero(Est1*);

 /** \brief devuelve entero de la estructura
 * \param puntero a char
 * \param Est1* estructura
 * \return entero Ok - > 1 Error -> 0
 */ int est1_set_texto(Est1*, char* );



 /** \brief devuelve puntero char de la estructura
 *
 * \param Est1* estructura
 * \return Ok - puntero a char* - Error - NULL
 */ char* est1_get_texto(Est1*);

  /** \brief devuelve entero de la estructura
 * \param flotante
 * \param Est1* estructura
 * \return entero Ok - > 1 Error -> 0
  */ int est1_set_flotante(Est1*, float );



/** \brief devuelve flotante de la estructura
 * \param flotante
 * \param Est1* estructura
 * \return flotante
 */ float est1_get_flotante(Est1*);



 /** \brief devuelve entero de la estructura
 * \param long
 * \param Est1* estructura
 * \return entero Ok - > 1 Error -> 0
 */ int est1_set_largo(Est1*,long int);



/** \brief devuelve long de la estructura
 * \param long
 * \param Est1* estructura
 * \return long
 */ long int est1_get_largo(Est1*);




/** \brief Ingreso de datos del elementos por consola y los agregra a puntero a estructura
 *
 * \param void
 * \return Est1* puntero a estructura o Est* NULL
 *
 */
Est1* est1_IngresoDatos(void);


/** \brief Seter de elementos ingresados a una estructura
 *
 * \param entero int
 * \param texto char*
 * \param flotante float
 * \param largo int long
 * \return Est1* Est1* puntero a estructura o Est* NULL
 *
 */
Est1* est1_SetDatos(int , char* , float , long int);


int est1_compareTexto(void* ,void* );

int est1_compareEntero(void* ,void* );


void est1_print(Est1* this);



