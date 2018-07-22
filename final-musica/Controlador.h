
typedef struct
{
    int idUsuario;
    char nombreUsuario[50];
    char email[50];
    char sexo[50];
    char pais[50];
    char password[50];
    char ip_address[50];

}Usuario;



/** \brief Dar de alta un elemento de la lista
 *
 * \param this ArrayList*
 * \return int -1 arraylist NULL - 0 elemento arraylist  NULL - 1 es ok agrego el elemento
 *
 */
int opcionAlta(ArrayList*);


/** \brief Imprime un listado con un titulo encabezado
 *
 * \param this ArrayList*
 * \param encabezado char*
 * \return int 0: ArrayList* NULL y/o vacio - 1: ArrayList* no NULL, no vacio
 *
 */
int opcionPrintListado(ArrayList*, char*);



/** \brief agrega un elemento al Listado
 * \param this ArrayList*
 * \param nuevo Usuario*
 * \return int 0 si es ok -1 si es error al_add
 *
 */
int opcionAddListado(ArrayList*, Usuario*);



/** \brief borra un elemento de la lista
 *
 * \param this ArrayList*
 * \return int -1: ArrayList NULL 0: ArrayList no NULL 1: NO confirma 2: Cofirma borrrar el elemento
 *
 */
int opcionDeleteDatoListado(ArrayList* );



/** \brief Modifica un elemento de la  Lista
 *
 * \param this ArrayList*
 * \return int -1: ArrayList NULL 0: ArrayList no NULL 1: NO confirma la modificacion 2: Cofirma modificacion del elemento
 *
 */

int opcionModificacionDatoListado(ArrayList*);

/** \brief Busca en un campo de un elemento de la lista y devuelve el indice
 *
 * \param this ArrayList*
 * \param clave int
 * \return int en indice o -1 si no lo encuentra
 *
 */

int opcionBuscarDato(ArrayList* , int );


/** \brief Ordena un Listado
 *
 * \param this ArrayList*
 * \param orden int orden desdendente 1 ascendente 0
 * \return void
 *
 */
void opcionOrdenarListado(ArrayList* , int );


/** \brief muestra en pantalla todos los campos de los elementos de la lista
 *
 * \param this ArrayList*
 * \return void
 *
 */
void us_print_all(ArrayList*);



