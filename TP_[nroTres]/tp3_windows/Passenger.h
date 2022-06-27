/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[15];;
	char codigoVuelo[8];
	char estadoVuelo[15];
	int isEmpty;

}Passenger;

/* brief Passenger_new
 * Funcion constructor creaa  espacio en memoria para guardar un nuevo pasajero.
 * Retorna el espacio/pasajero vacio
 *
 * */
Passenger* Passenger_new();

/* brief Passenger_newParametros
 * La funcion carga el espacio en memoria con los datos que le llegan por parametro
 * param idStr cadena de caracteres, contiene la informacion del ID
 * param nombreStr cadena de caracteres,contiene la informacion del nombre
 * param apellidoStr cadena de caracteres, contiene la informacion del apellido
 * param precioStr cadena de caracteres, contiene la informacion del percio
 * param codVueloStr cadena de caracteres, contiene la informacion del codigo de vuelo
 * param tipoPasajeroS cadena de caracteres , contiene la informacion del tipo de pax
 * param estadoVueloStr cadena de caracteres, contiene la informacion del estado de vuelo
 * retorna el pasajero con los datos cargados
 * */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codVueloStr,
								   char* tipoPasajeroS, char* estadoVueloStr);
/* brief Passenger_newParametrosAlta
 * La funcion carga el espacio en memoria con los datos que le llegan por parametro
 * param idStr tipo de dato entero,contiene la informacion del ID
 * param nombreStr cadena de caracteres,contiene la informacion del nombre
 * param apellidoStr cadena de caracteres, contiene la informacion del apellido
 * param precioStr tipo de dato flotante,contiene la informacion del percio
 * param codVueloStr cadena de caracteres, tipo de dato codigo de vuelo
 * param tipoPasajeroS cadena de caracteres , tipo de dato tipo de pax
 * param estadoVueloStr cadena de caracteres, tipo de dato estado de vuelo
 * retorna el pasajero con los datos cargados
 * */
Passenger* Passenger_newParametrosAlta(int idStr,char* nombreStr,char* apellidoStr,float precioStr,char* codVueloStr,
		char* tipoPasajeroS, char* estadoVueloStr);

/* brief Passenger_delete
 * Libera la memoria ocupada por un pax
 *
 * */
void Passenger_delete();

/* brief Passenger_setId
 * carga el ID del pax
 * param this puntero al listado de pasajeros
 * param id dato a cargar
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 * */
int Passenger_setId(Passenger* this,int id);

/* brief Passenger_getId
 * obtiene el ID del pax
 * param this puntero al listado de pasajeros
 * param id dato a obtener
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 */
int Passenger_getId(Passenger* this,int* id);

/* brief Passenger_setNombre
 * carga el nombre del pax
 * param this puntero al listado de pasajeros
 * param nombre dato a cargar
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 * */
int Passenger_setNombre(Passenger* this,char* nombre);

/* brief Passenger_getNombre
 * obtiene el nombre del pax
 * param this puntero al listado de pasajeros
 * param nombre dato a obtener
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 */
int Passenger_getNombre(Passenger* this,char* nombre);


/* brief Passenger_setApellido
 * carga el apellido del pax
 * param this puntero al listado de pasajeros
 * param apellido dato a cargar
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 * */
int Passenger_setApellido(Passenger* this,char* apellido);

/* brief Passenger_getApellido
 * obtiene el apellido del pax
 * param this puntero al listado de pasajeros
 * param apellido dato a obtener
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/* brief Passenger_setCodigoVuelo
 * carga el codigode vuelo del pax
 * param this puntero al listado de pasajeros
 * param codigode vuelo dato a cargar
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 * */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/* brief Passenger_getCodigoVuelo
 * obtiene el codigo de vuelo
 * param this puntero al listado de pasajeros
 * param codigovuelo dato a obtener
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/* brief Passenger_setTipoPasajero
 * carga el tipo de pasajero de vuelo del pax
 * param this puntero al listado de pasajeros
 * param tipo de pasajero de vuelo dato a cargar
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 * */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

/* brief Passenger_getTipoPasajero
 * obtiene el tipo de pasajero
 * param this puntero al listado de pasajeros
 * param tipopasajero dato a obtener
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/* brief Passenger_setPrecio
 * carga el precio del vuelo
 * param this puntero al listado de pasajeros
 * param precio del vuelo dato a cargar
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 * */

int Passenger_setPrecio(Passenger* this,float precio);

/* brief Passenger_getPrecio
 * obtiene el precio del vuelo
 * param this puntero al listado de pasajeros
 * param precio dato a obtener
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/* brief Passenger_setEstadoVuelo
 * carga el Estado del vuelo
 * param this puntero al listado de pasajeros
 * param estadoVuelo dato a cargar
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 * */
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);

/* brief Passenger_getEstadoVuelo
 * obtiene el estado del vuelo
 * param this puntero al listado de pasajeros
 * param estadoVuelo dato a obtener
 * retorna un verdadero (1) si funciona o en caso contrario un falso (0).
 */
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

/* brief Passenger_BuscarPaxId
 * verifica que el ID ingresado se encuentra en el listado
 * param pArrayListPassenger puntero a el listado de paxs
 * param ID dato a verificar
 *retorna indice del pax si funciona o en caso contrario un -1
 * */
int Passenger_BuscarPaxId (LinkedList* pArrayListPassenger, int id);

/* brief Passenger_OrdenamientoID
 *
 *.
 * */
int Passenger_OrdenamientoID (void* idUno,void* idDos);

/* brief Passenger_OrdenamientoNombre
 *
 *
 * */
int Passenger_OrdenamientoNombre(void* nombreUno,void* nombreDos);

/* brief Passenger_OrdenamientoApellido
 *
 *
 * */
int Passenger_OrdenamientoApellido(void* ApellidoUno,void* ApellidoDos);

/* brief Passenger_OrdenamientoPrecio
 *
 *
 * */
int Passenger_OrdenamientoPrecio (void* precioUno,void* precioDos);

/* brief Passenger_OrdenamientoCodigoVuelo
 *
 *
 * */
int Passenger_OrdenamientoCodigoVuelo (void* codigoUno,void* codigoDos);

/* brief Passenger_OrdenamientoTipodePax
 *
 *
 * */
int Passenger_OrdenamientoTipodePax (void* tipoUno,void* tipoDos);

/* brief Passenger_OrdenamientoEstadoVuelo
 *
 *
 * */
int Passenger_OrdenamientoEstadoVuelo (void* estadoUno,void* estadoDos);
#endif /* PASSENGER_H_ */
