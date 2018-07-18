


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
 * \param nuevo Est1*
 * \return int 0 si es ok -1 si es error al_add
 *
 */
int opcionAddListado(ArrayList*, Est1*);



/** \brief
 *
 * \param this ArrayList*
 * \return int
 *
 */
int opcionDeleteDatoListado(ArrayList* );



/** \brief
 *
 * \param this ArrayList*
 * \return int
 *
 */

int opcionModificacionDatoListado(ArrayList*);

/** \brief
 *
 * \param this ArrayList*
 * \param clave int
 * \return int
 *
 */

int opcionBuscarDato(ArrayList* , int );


/** \brief
 *
 * \param this ArrayList*
 * \param orden int
 * \return void
 *
 */
void opcionOrdenarListado(ArrayList* , int );


/** \brief
 *
 * \param this ArrayList*
 * \return void
 *
 */
void est1_print_all(ArrayList*);



