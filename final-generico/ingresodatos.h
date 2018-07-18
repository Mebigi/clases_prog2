#ifndef INGRESODATOS_H_INCLUDED
#define INGRESODATOS_H_INCLUDED

/** \brief lee un nuemro ingresado (long sin puntos) en una cadena de carceres de longitud 9 y
 * llama la funcion validar si es un numero lo coniverte a long entero
 * \param cadena de caracteres mensaje para el ingreso
 * \return un long entrero
 *
 */

long int Ingresarlong(char []);

/** \brief valida un numero long entero ingresado se encuentre dentro de un rango
 * \param minimo valor entero
 * \param maximo valor entero
 * \return un long entero validado
 *
 */

long int esNumerolong(char [], int);



/**
 * \brief Solicita un número al usuario que el mismo ingresa como un strnig
 * \param mensaje Es el mensaje a ser mostrado
 * \param el valor minimo para ese flotante
  * \param el valor maximo para ese flotante
 * \return El número ingresado por el usuario tipo flotante natural
 *
 */


float IngresarEnteroFlotante(char [], int , int );

/**
 * \brief Valida strnig que posea solo numeros en un rago flotante
 * \param mensaje Es el mensaje a ser mostrado
 * \param el valor minimo para ese flotante
  * \param el valor maximo para ese flotante
 * \return El número ingresado por el usuario tipo flotante natural
 *
 */

float validarEnteroFlotante(char [], int , int , int );

/**
 * \brief Valida flotante entero ingresado este comprendido en un rango
  * \param el valor flotante
 * \param el valor minimo para ese flotante
  * \param el valor maximo para ese flotante
 * \return El número ingresado por el usuario tipo flotante
 *
 */
int  RangoValidoFlotante(float , int , int );

/**
 * \brief Solicita un número entero usuario que el mismo ingresa como un strnig
 * \param mensaje Es el mensaje a ser mostrado
 * \param el valor minimo para ese entero
  * \param el valor maximo para ese entero
 * \return El número ingresado por el usuario tipo entero
 *
 */

int IngresarEntero(char [], int , int );

/**
* \brief valida un strnig solo numeros
* \param el cadena caracteres
* \param el valor minimo para ese entero
* \param el valor maximo para ese entero
* \return El número ingresado por el usuario tipo entero
*
*/
float validarEntero(char [], int , int , int );

/** \brief valida el rango min y max que debe estar un entero
 *
 * \param entero a validar
 * \param  minimo valor
 * \param maximo valor
  * \return entero valor 1 cuando es ok y 0 - error
 *
 */


int validarRangoEntero (int , int , int );

/** \brief lee un string ingresado y valida cantidad de caracteres, imprime un mensaje segun el dato a ingresar
 *
 * \param cadena de caracteres mensaje
 * \param cadena de caracteres ingresado
 * \param entero cantidad de caracteres min
 * \param entero cantidad de caracteres max
 * \return void
 *
 */

void getString(char [],char [], int , int );


/** \brief lee un string ingresado y valida cantidad de caracteres y que sean solo letras, imprime un mensaje segun el dato a ingresar
 *
 * \param cadena de caracteres mensaje
 * \param cadena de caracteres ingresado
 * \param entero cantidad de caracteres min
 * \param entero cantidad de caracteres max
 * \return void
 *
 */


void getStringletras(char [],char [], int , int );

/** \brief valida String soo letras
 *
 * \param cadena de caracteres
 * \return entero 0 error (si posse algun caracter distinta alfa o espacio) 1 es ok
 *
 */

int esTexto(char []);

/** \brief valida String solo de numeros
 *
 * \param cadena de caracteres
 * \return entero 0 error (si posse algun caracter distinta digito) 1 es ok
 *
 */

int esNumero(char []);


/** \brief lee confirmacion donde pide ingresar s/n
 *
 * \param cadena de caracteres - mensaje segun tipo confirmacion
 * \return entero 1 si confirma 0 si cancela la opercacion
 *
 */


int Confirmacion(char []);

/** \brief lee un string ingresado y valida cantidad de caracteres y que sean solo numeros, imprime un mensaje segun el dato a ingresar
 *
 * \param cadena de caracteres mensaje
 * \param cadena de caracteres ingresado
 * \param entero cantidad de caracteres min
 * \param entero cantidad de caracteres max
 * \return void
 *
 */


void getStringEntero(char [],char [], int , int );



/** \brief imprime un error si no logra confirmar la carga de datos
 *
 * \param entero valor 0 si no confirma, 1 en caso contrario
 * \return void
 *
 */

void confirma_set(int);

/** \brief imprime un error si no logra confirmar leer de datos
 *
 * \param entero valor -1 si no confirma, >-1 en caso contrario
 * \return void
 *
 */
void confirma_getNum(int);

/** \brief imprime un error si no logra confirmar leer de datos
 *
 * \param char* valor NULL si no confirma, string en caso contrario
 * \return void
 *
 */
void confirma_getText(char*);

/** \brief da formato a un string tipo "Titulo"
 *
 * \param puntero a char
 * \return puntero a char
 *
 */
char* Formato_Titulo(char* );




#endif
