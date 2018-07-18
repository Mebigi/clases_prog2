

#include "ArrayList.h"

typedef struct
{
int entero;
char texto[50];
float flotante;
long largo;
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
 */ int est1_set_largo(Est1*,long);



/** \brief devuelve long de la estructura
 * \param long
 * \param Est1* estructura
 * \return long
 */ long est1_get_largo(Est1*);


Est1* est1_ingresoDatos(int , char* , float , long );


int est1_compareTexto(void* ,void* );

int est1_compareEntero(void* ,void* );


void est1_print(Est1* this);



