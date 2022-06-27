/*
 *  brief controller_loadFromText
 *  Carga de paxs al listado desde un archivo csv
 *  param pArrayListPassenger puntero a el listado de paxs
 *  param path nombre del archivo
 * 	retorna un verdadero si funciona o en caso contrario un falso (0).
 * */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
/*
 *  brief controller_loadFromBinary
 *  Carga de paxs al listado desde un archivo binario
 *  param pArrayListPassenger puntero a el listado de paxs
 *  param path nombre del archivo
 * 	retorna un verdadero si funciona o en caso contrario un falso (0).
 * */

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
/*
 *  brief controller_addPassenger
 *  Alta de paxs
 *  param pArrayListPassenger puntero a el listado de paxs
 *  param path nombre del archivo
 * retorna un verdadero si funciona o en caso contrario un falso (0).
 * */

int controller_addPassenger(char* path,LinkedList* pArrayListPassenger);

/*
 *  brief controller_editPassenger
 *  Modifica datos de los pasajeros en lista
 *  param pArrayListPassenger puntero a el listado de paxs
 *  param path nombre del archivo
 *  retorna un verdadero si funciona o en caso contrario un falso (0).
 * */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief controller_removePassenger
 * Remueve del listado el pasajero indicado por id
 *  Baja de pasajero
 * \param pArrayListPassenger puntero a el listado de paxs
 * \retorna un verdadero si funciona o en caso contrario un falso (0).
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/* brief controller_ListPassenger
 * Lista el total de pasajeros
 * param pArrayListPassenger puntero a el listado de paxs
 * retorna un verdadero si funciona o en caso contrario un falso (0).
 * */

int controller_ListPassenger(LinkedList* pArrayListPassenger);


/*
 * brief controller_sortPassenger
 * Ordena a los pasajeros segun criterio
 * param pArrayListPassenger puntero a el listado de paxs
 *  retorna un verdadero si funciona o en caso contrario un falso (0).
 * */

int controller_sortPassenger(LinkedList* pArrayListPassenger);
/*
 * brief controller_saveAsText
 * Esta funcion abre un archivo para escritura
 * Carga los datos de los paxs en un nuevo archivo
 * param path nombre del archivo
 * param pArrayListPassenger puntero a el listado de paxs
 * retorna un verdadero si funciona o en caso contrario un falso (0).
 *
 * */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/*
 * brief controller_saveAsBinary
 * Esta funcion abre un archivo para escritura en modo binario
 * Cargha los datos de los paxs en un nuevo archivo BIN
 * param path nombre del archivo
 * param pArrayListPassenger puntero a el listado de paxs
 * retorna un verdadero si funciona o en caso contrario un falso (0).
 * */

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/*
 * Brief controller_SiguienteId
 * Esta funcion nos retorna el valor del siguiente id a ser asignado a un nuevo alta.
 * param pArrayListPassenger puntero a el listado de paxs
 * */
int controller_SiguienteId(LinkedList* pArrayListPassenger);
/*
 * brief controller_getMaximoId
 * la funcion lee el archivo para contar la cantidad de lineas(paxs) que contiene.
 * los suma con un contador dentro de un while y retorna el vvalor del maximo ID existente
 * param pArrayListPassenger puntero a el listado de paxs
 * param pFile direccion de memoria del archivo
 *
 * */
int controller_getMaximoId(FILE* pFile);

