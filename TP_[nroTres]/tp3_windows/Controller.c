#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "UTN.h"
#include "Controller.h"


/*
static int controller_printPassenger (Passenger* pPassenger);

static int controller_ListPassengerStatic(LinkedList* pArrayListPassenger);
static int controller_getMaximoId(LinkedList* pArrayListPassenger);
static int controller_ValidarId (LinkedList* pArrayListPassenger, int id);
*/
static int controller_printPassenger (Passenger* pPassenger);
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno = 0;

	if (pArrayListPassenger != NULL && path != NULL)
	{
		printf("\n\n**Cargar los datos de los pasajeros desde el archivo (TXT).**\n");
		pFile = fopen (path, "r");
		if (pFile == NULL)
		{
			printf("\nERROR al abrir el archivo.\n");
		}
		else
		{
			if (parser_PassengerFromText(pFile, pArrayListPassenger))
			{
				printf("\nEl archivo (TXT) fue cargado exitosamente.\n");
				retorno = 1;
			}
		}
	}
	fclose(pFile);
	return retorno;
}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno = 0;

	if (pArrayListPassenger != NULL && path != NULL)
	{
		printf("\n\n**Cargar los datos de los pasajeros desde el archivo (BIN).**\n");
		pFile = fopen (path, "rb");
		if (pFile == NULL)
		{
			printf("\nERROR al abrir el archivo.\n");
		}
		else
		{
			if (parser_PassengerFromBinary(pFile,pArrayListPassenger))
			{
				printf("\nEl archivo (TXT) fue cargado exitosamente.\n");
				retorno = 1;
			}
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger*  newPassenger;
	int retorno = 0;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajeroint;
	char tipoPasajero[15];
	char codigoVuelo[7];
	int estadoVueloInt;
	char estadoVuelo [15];

	if (pArrayListPassenger != NULL && newPassenger != NULL)
	{
		newPassenger = Passenger_new ();
		id = controller_SiguienteId(pArrayListPassenger);

		printf("\n ****************************** ALTA DE PASAJEROS ************************************ \n\n");

		if(
			utn_getNombre(nombre,50,"\nIngrese el nombre. \n","\nError. \n", 3) == 0 &&
			utn_getNombre(apellido,50,"\nIngrese el pellido. \n","\nError. \n", 3) == 0 &&
			getNumeroFlotante(&precio,"\ningrese el precio del vuelo.","\nError. \n",1.0,500000.0,3)==0 &&
			getAlfanumerico(codigoVuelo,"\nIngrese los 7 digitos del codigo aereo.\n","\nError. \n",7,3) == 0 &&
			utn_getNumero(&tipoPasajeroint, "\nIngrese el tipo de pax: \n 1. FirstClass. \n 2. ExecutiveClass.\n"
											" 3. EconomyClass.\n","\nError. \n",1,3,3) == 0 &&
			utn_getNumero(&estadoVueloInt,"\nIngrese el estado del vuelo.\n "
			"1. Aterrizado. \n 2. En Horario.\n 3. Demorado.\n 4. En vuelo.\n","\nError. \n",1,4,3) == 0)
		{
			switch(tipoPasajeroint)
			{
				case 1 :
					strcpy(tipoPasajero,"FirstClass");
					break;
				case 2 :
					strcpy(tipoPasajero,"ExecutiveClass");
					break;
				case 3 :
					strcpy(tipoPasajero,"EconomyClass");
					break;
			}

			switch(estadoVueloInt)
			{
				case 1 :
					strcpy(estadoVuelo,"Aterrizado");
					break;
				case 2 :
					strcpy(estadoVuelo,"En Horario");
					break;
				case 3 :
					strcpy(estadoVuelo,"Demorado");
					break;
				case 4 :
					strcpy(estadoVuelo,"En vuelo");
					break;
			}

			if(newPassenger != NULL)
			{
				if(Passenger_setId(newPassenger,id)&&
				Passenger_setNombre(newPassenger,nombre) &&
				Passenger_setApellido(newPassenger,apellido) &&
				Passenger_setPrecio(newPassenger,precio) &&
				Passenger_setCodigoVuelo(newPassenger,codigoVuelo)&&
				Passenger_setTipoPasajero(newPassenger,tipoPasajero) &&
				Passenger_setEstadoVuelo(newPassenger,estadoVuelo))
				{
					controller_GuardarSiguienteID(id);
					ll_add(pArrayListPassenger, newPassenger);
					printf("\nPasajero cargado con exito! \n");
					retorno = 1;
				}
				else
				{
					free (newPassenger);
					newPassenger = NULL;
				}

			}
		}

	}
	else
	{
		printf("**ERROR NO SE ENCUENTRA ESPACIO DISPONIBLE PARA REALIZAR LA CARGA**");
	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajeroint;
	char tipoPasajero[15];
	char codigoVuelo[7];
	int estadoVueloInt;
	char estadoVuelo [15];
	int option;
	int indicePax;
	int reintentos = 3;
	Passenger* editPassenger;

	system("cls");
	printf("\n 				              **MODIFICACION PASAJEROS** \n");
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
	if (pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("\n\nPor favor, ingrese el numero de ID del pax que desea modificar.");
		scanf("%d",&id);
		while(controller_ValidarId(pArrayListPassenger,id) == 0 || reintentos == 0)
		{
			printf("\n\ERROR. \nPor favor, ingrese el **numero de ID** del pax que desea modificar.");
			scanf("%d",&id);
			reintentos --;
		}

		indicePax = Passenger_BuscarPaxId (pArrayListPassenger,id);
		editPassenger = ll_get(pArrayListPassenger,indicePax);

		if(indicePax == -1)
		{
			printf("\n\ERROR. \n **Numero de ID inexistente**");
		}
		else
		{
			printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO	AEREO	TIPO PASAJERO 		ESTADO");
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
			controller_printPassenger(editPassenger);

			if(utn_getNumero(&option,"\n\nPor favor ingrese una opcion correcta: \n\n"
			    					"1) Modificar Nombre. \n"
			    			 		"2) Modificar Apellido. \n"
			    					"3) Modificar Precio. \n"
			    					"4) Modificar Codigo Aereo.\n"
			    					"5) Modificar Estado de Vuelo\n"
									"6) Modificar Tipo de Pasajero. \n", "\nError. \n"
									,1,6,3)==0){

				switch (option){



				case 1:

						if(utn_getNombre(nombre,50,"\nIngrese el nombre. \n","\nError. \n", 3) == 0)
						{
							Passenger_setNombre(editPassenger,nombre);
							printf("\nModificacion exitosa!");
						}

					break;

				case 2:
						if(utn_getNombre(apellido,50,"\nIngrese el pellido. \n","\nError. \n", 3) == 0)
						{
							Passenger_setApellido(editPassenger,apellido);
							printf("\nModificacion exitosa!");
						}

					break;

				case 3:
						if(getNumeroFlotante(&precio,"\ningrese el precio del vuelo.","\nError. \n",1.0,500000.0,3)==0)
						{
							Passenger_setPrecio(editPassenger,precio);
							printf("\nModificacion exitosa!");
						}

					break;

				case 4:
						if(getAlfanumerico(codigoVuelo,"\nIngrese los 7 digitos del codigo aereo.\n","\nError. \n",7,3) == 0)
						{
							Passenger_setCodigoVuelo(editPassenger,codigoVuelo);
							printf("\nModificacion exitosa!");
						}

					break;

				case 5:
						if(utn_getNumero(&tipoPasajeroint, "\nIngrese el tipo de pax: \n 1. FirstClass. \n 2. ExecutiveClass.\n"
								" 3. EconomyClass.\n","\nError. \n",1,3,3) == 0)
						{
							switch(tipoPasajeroint)
							{
								case 1 :
									strcpy(tipoPasajero,"FirstClass");
									break;
								case 2 :
									strcpy(tipoPasajero,"ExecutiveClass");
									break;
								case 3 :
									strcpy(tipoPasajero,"EconomyClass");
									break;
							}
							Passenger_setTipoPasajero(editPassenger,tipoPasajero);
							printf("\nModificacion exitosa!");
						}

					break;

				case 6:
						if(utn_getNumero(&estadoVueloInt,"\nIngrese el estado del vuelo.\n "
								"1. Aterrizado. \n 2. En Horario.\n 3. Demorado.\n 4. En vuelo.\n","\nError. \n",1,4,3) == 0)
						{
							switch(estadoVueloInt)
							{
								case 1 :
									strcpy(estadoVuelo,"Aterrizado");
									break;
								case 2 :
									strcpy(estadoVuelo,"En Horario");
									break;
								case 3 :
									strcpy(estadoVuelo,"Demorado");
									break;
								case 4 :
									strcpy(estadoVuelo,"En vuelo");
									break;

							}
							Passenger_setEstadoVuelo(editPassenger,estadoVuelo);
							printf("\nModificacion exitosa!");
						}

					break;

					retorno = 1;

				}
			}
			else
			{
				printf("\nERROR! La modificacion ha sido cancelada.");
			}

		}

	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path ch
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	/*
	 * pide id a eliminar
	 * uscar el indice donde esta el id
	 * con **ll_get** (linkendlist) obtener el puntero de ese indice
	 * confirmar la baja / employe_delete ---- ll_remove (linkendlist);
	 *
	 * */
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger*  pAuxPassenger = NULL;
	int retorno = 0;
	int tamanio;

	if (pArrayListPassenger != NULL){

		tamanio = ll_len(pArrayListPassenger);

		printf("\n 				              **LISTADO PASAJEROS** \n");
		printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO	AEREO	TIPO PASAJERO 		ESTADO");
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

		for (int i = 0;i<tamanio;i++)
		{

			pAuxPassenger = ll_get(pArrayListPassenger,i); //???
			controller_printPassenger(pAuxPassenger);

		}

		printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
		retorno = 1;
	}
    return retorno;
}
/*
static int controller_ListPassengerStatic(LinkedList* pArrayListPassenger)
{
	Passenger*  pAuxPassenger = NULL;
	int retorno = 0;
	int tamanio;

	if (pArrayListPassenger != NULL){

		tamanio = ll_len(pArrayListPassenger);

		printf("\n 				              **LISTADO PASAJEROS** \n");
		printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO	AEREO	TIPO PASAJERO 		ESTADO");
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

		for (int i = 0;i<tamanio;i++)
		{

			pAuxPassenger = ll_get(pArrayListPassenger,i); //???
			controller_printPassenger(pAuxPassenger);

		}

		printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
		retorno = 1;
	}
    return retorno;
}
*/
static int controller_printPassenger (Passenger* pPassenger)
{
	int retorno = 0;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[15];
	char codigoVuelo[7];
	char estadoVuelo [15];

	if (pPassenger != NULL &&
		Passenger_getId(pPassenger,&id) &&
		Passenger_getNombre(pPassenger,nombre)&&
		Passenger_getApellido(pPassenger,apellido)&&
		Passenger_getPrecio(pPassenger,&precio)&&
		Passenger_getCodigoVuelo(pPassenger,codigoVuelo)&&
		Passenger_getTipoPasajero(pPassenger,tipoPasajero)&&
		Passenger_getEstadoVuelo(pPassenger,estadoVuelo))
	{
		printf("\n%d	 	%-10s		 %-10s     		  %.2f	  	 %-15s    	 %-15s  		 %-15s \n",
		id, nombre, apellido, precio,codigoVuelo,tipoPasajero,estadoVuelo);
		retorno = 1;
	}
	return retorno;
}




/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{


	/*
	 * employee_showlistEmployee	 ----> Recorre hasta el ll_len
	 * 								 ----> obtiene el indice ll_get
	 * 	 							 ----> muestra 1 empleado
     * 	 							 ----> FIN
     *
	 * */

	/*

	int allOK = 0;
	int criterio;
	LinkedList* sort;

	if (pArrayListPassenger != NULL)
	{
		sort = ll_clone(pArrayListPassenger);
		if(utn_getNumero(&criterio,"\n\nPor favor ingrese que tipo de criterio desea aplicar: \n\n"
					    					"1) Ordenar Nombre. \n"
					    			 		"2) Modificar Apellido. \n"
					    					, "\nError. \n"
											,0,1,3)==0){

						switch (criterio){


	}
	*/
    return 1;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[15];
	char codigoVuelo[7];
	char estadoVuelo [15];
	Passenger*  pAuxPassenger;
	FILE* pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			system("pause");
			exit (EXIT_FAILURE);
		}
		for (int i = 0; i< ll_len(pArrayListPassenger);i++ )
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			if (pAuxPassenger != NULL &&
				Passenger_getId(pAuxPassenger,&id) &&
				Passenger_getNombre(pAuxPassenger,nombre)&&
				Passenger_getApellido(pAuxPassenger,apellido)&&
				Passenger_getPrecio(pAuxPassenger,&precio)&&
				Passenger_getCodigoVuelo(pAuxPassenger,codigoVuelo)&&
				Passenger_getTipoPasajero(pAuxPassenger,tipoPasajero)&&
				Passenger_getEstadoVuelo(pAuxPassenger,estadoVuelo))
			{
				fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
				retorno = 1;
			}
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	Passenger*  pAuxPassenger;
	FILE* pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			system("pause");
			exit (EXIT_FAILURE);
		}
		for (int i = 0; i< ll_len(pArrayListPassenger);i++ )
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			if (pAuxPassenger != NULL)
			{
				fwrite(pAuxPassenger, sizeof(Passenger),1,pFile);
				retorno = 1;
			}
		}
	}
	fclose(pFile);
    return retorno;
}
/*
static int controller_idSubSiguiente (LinkedList* pArrayListPassenger)
{
	Passenger*  pAuxPassenger;
	int id;
	int siguienteId;
	int tamanio;
	if (pArrayListPassenger != NULL)
	{
		tamanio = ll_len(pArrayListPassenger);
		for(int i = 0;i<tamanio; i++)
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			Passenger_getId(pAuxPassenger,&id);
			if(id > siguienteId || i == 0)
			{
				siguienteId = id;
			}
		}
	}
	return siguienteId;
}
*/
int controller_GuardarSiguienteID(int id)
{
	int retorno = 0;
	FILE* pFile = fopen("siguienteID.txt","r+");
	if(pFile == NULL)
	{
		pFile = fopen("siguienteID.txt","w");
	}

	fprintf(pFile,"%d",id);
	fclose(pFile);
	retorno = 1;

	return retorno;
}
int controller_SiguienteId(LinkedList* pArrayListPassenger)
{
	int cont = controller_getMaximoId(pArrayListPassenger);
	cont++;
	return cont;
}

int controller_getMaximoId(LinkedList* pArrayListPassenger)
{
	Passenger*  pAuxPassenger;
	int retorno = 0;
	int maximoId = 0;
	int tamanio;

	if(pArrayListPassenger != NULL)
	{
		tamanio = ll_len(pArrayListPassenger);
		for(int i = 0; i<tamanio ; i++)
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);

			if(i == 0 || pAuxPassenger->id > maximoId)
			{
				maximoId = pAuxPassenger->id;
			}

			retorno = maximoId ;
		}
	}
	return retorno;
}

int controller_ValidarId (LinkedList* pArrayListPassenger, int id)
{
	int idBuscar;
	int tamanio;
	int retorno = 0;
	Passenger*  auxPassenger;
	if (pArrayListPassenger != NULL && id >= 0)
	{
		tamanio = ll_len(pArrayListPassenger);
		for(int i = 0 ; i < tamanio ; i++)
		{
			auxPassenger = ll_get(pArrayListPassenger,i);
			if(auxPassenger != NULL)
			{
				Passenger_getId(auxPassenger,&idBuscar);
				if(id == idBuscar)
				{
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}
