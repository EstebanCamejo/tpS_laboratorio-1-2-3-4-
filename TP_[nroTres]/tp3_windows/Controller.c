#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "UTN.h"
#include "Controller.h"



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
	FILE* pFile = NULL;
	int retorno = 0;

	if (pArrayListPassenger != NULL && path != NULL)
	{
		printf("\n\n**Cargar los datos de los pasajeros desde el archivo (BIN).**\n");
		//pFile = fopen (path, "a+b");
		pFile = fopen(path,"rb");
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
int controller_addPassenger(char* path,LinkedList* pArrayListPassenger)
{
	Passenger* newPassenger = Passenger_new ();
	int retorno = 0;
	int id;
	char nombre[15];
	char apellido[15];
	float precio;
	char codigoVuelo[8];
	int tipoPasajeroint;
	char tipoPasajero[15];
	int estadoVueloInt;
	char estadoVuelo [15];
	int tamanio;
	if (pArrayListPassenger != NULL)
	{
		tamanio = ll_len(pArrayListPassenger);
		if (tamanio  == 0)
		{
			FILE* pFile;
			pFile = fopen(path,"r");
			id = controller_getMaximoId(pFile)+1;
			fclose(pFile);
		}
		else
		{
			id = controller_SiguienteId(pArrayListPassenger);
			id ++;
		}

		printf("\n ****************************** ALTA DE PASAJEROS ************************************ \n\n");

		if(
			utn_getNombre(nombre,50,"\nIngrese el nombre. \n","\nError. \n", 3) == 0 &&
			utn_getNombre(apellido,50,"\nIngrese el pellido. \n","\nError. \n", 3) == 0 &&
			getNumeroFlotante(&precio,"\ningrese el precio del vuelo.","\nError. \n",1.0,500000.0,3) == 0 &&
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
			newPassenger = Passenger_newParametrosAlta(id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
				if(newPassenger != NULL)
				{
					if (ll_add(pArrayListPassenger,newPassenger) == 0)
					{
						//controller_GuardarSiguienteID(id);
						printf("\nPasajero cargado con exito! \n");
						retorno = 1;
					}
					else
					{
						printf("\nERROR DE CARGA \n");
					}
				}
				else
				{
					free (newPassenger);
					newPassenger = NULL;
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
	char nombre[15];
	char apellido[15];
	float precio;
	int tipoPasajeroint;
	char tipoPasajero[15];
	char codigoVuelo[8];
	int estadoVueloInt;
	char estadoVuelo [15];
	int option;
	int indicePax;
	int reintentos = 3;
	Passenger* editPassenger;

	printf("\n 				              **MODIFICACION PASAJEROS** \n");
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
	if (pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("\n\nPor favor, ingrese el numero de ID del pax que desea modificar.");
		scanf("%d",&id);
		while(Passenger_BuscarPaxId(pArrayListPassenger,id) == 0 || reintentos == 0)
		{
			printf("\n\ERROR. \nPor favor, ingrese el **numero de ID** del pax que desea modificar.");
			scanf("%d",&id);
			reintentos--;
		}

		indicePax = Passenger_BuscarPaxId (pArrayListPassenger,id);
		editPassenger = ll_get(pArrayListPassenger,indicePax);//

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
			    					"5) Modificar Tipo de Pasajero.\n"
									"6) Modificar Estado de Vuelo. \n", "\nError. \n"
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
	Passenger* removePassenger;
	int id;
	int reintentos = 3;
	int retorno = 0;
	int indicePax;
	int option;

	system("cls");
	printf("\n 				              **REMOVER PASAJEROS** \n");
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
	if (pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("\n\nPor favor, ingrese el numero de ID del pax que desea REMOVER.");
		scanf("%d",&id);
		while(Passenger_BuscarPaxId(pArrayListPassenger,id) == 0 || reintentos == 0)
		{
			printf("\n\ERROR. \nPor favor, ingrese el **Numero de ID** del pax que desea *REMOVER*.");
			scanf("%d",&id);
			reintentos--;
		}
		indicePax = Passenger_BuscarPaxId (pArrayListPassenger,id);
		removePassenger = ll_get(pArrayListPassenger,indicePax);
		if(indicePax == -1)
		{
			printf("\n\ERROR. \n **Numero de ID inexistente**");
		}
		else
		{
			printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO	AEREO	TIPO PASAJERO 		ESTADO");
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
			controller_printPassenger(removePassenger);
		}
		if(utn_getNumero(&option,"\n\nPor favor ingrese una opcion correcta: \n\n"
					    					"1) REMOVER EL PASAJERO. \n"
					    			 		"2) SALIR. \n", "\nError. \n"
											,1,2,3)==0){
						switch (option){

						case 1:
								if(ll_remove(pArrayListPassenger,indicePax) != 0)
								{
									printf("\nEl pasajero se removio correctamente!");
								}
								retorno = 1;
							break;

						case 2:  printf("\nNo se realizaron cambios en la lista!");

							break;
						}
		}
		else
		{
			printf("\ERROR al remover el pasajero!");
		}
	}

	return retorno;
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
		printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO	AEREO	TIPO PASAJERO 		ESTADO");
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

		for (int i = 0;i<tamanio;i++)
		{
			pAuxPassenger = (Passenger*)ll_get(pArrayListPassenger,i);
			if(pAuxPassenger != NULL)
			{
				controller_printPassenger(pAuxPassenger);
			}
		}

		printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
		retorno = 1;
	}
    return retorno;
}

static int controller_printPassenger (Passenger* pPassenger)
{
	int retorno = 0;
	int id;
	char nombre[15];
	char apellido[15];
	float precio;
	char codigoVuelo[8];
	char tipoPasajero[15];
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
	//	printf	("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO	AEREO	TIPO PASAJERO 		ESTADO");
		printf("\n%d	 	%-10s         %-10s           %.2f         %-10s             %-10s                %-10s \n",
					id,     nombre,       apellido,      precio,     codigoVuelo,     tipoPasajero,       estadoVuelo);
		retorno = 1;
	}
	return retorno;
}






//////////////////////////////////

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path ,LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int id;
	char nombre[15];
	char apellido[15];
	float precio;
	char tipoPasajero[15];
	char codigoVuelo[8];
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


int controller_SiguienteId(LinkedList* pArrayListPassenger) // v2
{
	int sigId;
	Passenger* pAuxPassenger = NULL;
	int id;
	if(pArrayListPassenger != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListPassenger) ; i++)
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			Passenger_getId(pAuxPassenger, &id);
			if(id > sigId || i == 0)
			{
				sigId = id;
			}
		}

	}
	return sigId;
}

int controller_getMaximoId (FILE* pFile)
{
	Passenger* pAuxPassenger = NULL;
	int maxmoId = 0;
	int cant = 0;
	char buffer1[50], buffer2[50], buffer3[50], buffer4[50], buffer5[8], buffer6[50], buffer7[50];
//	pFile = fopen("data.csv","r");
	if(pFile == NULL)
	{
		printf("Error al escanear el archivo.");
		system("pause");
		exit (EXIT_FAILURE);
	}
	else
	{
		printf("\n** CARGA DE ARCHIVO EN PROCESO **\n");
	// LECTURA FANTASMA - 1    -2  -3    -4   -5   -6     -7
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7);
		while(!feof(pFile))
		{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7);
			if(cant<7)
			{
				break;
			}
			pAuxPassenger = Passenger_newParametros(buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7);
			if(pAuxPassenger!=NULL)
			{
				maxmoId++;
			}
		}
	}
	//fclose(pFile);
	return maxmoId;
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
	int retorno = 0;
	int criterio;
	int opcion;
	LinkedList* sortClone;
	if (pArrayListPassenger != NULL)
	{
		sortClone = ll_clone(pArrayListPassenger);

		if(utn_getNumero(&opcion,"\n\nPor favor ingrese que tipo de ordenamiento desea aplicar: \n\n"
											"1) Ordenar por ID. \n"
											"2) Ordenar por Nombre. \n"
					    			 		"3) Ordenar por Apellido. \n"
											"4) Ordenar por precio. \n"
											"5) Ordenar por codigo de vuelo. \n"
											"6) Ordenar por tipo pasajero. \n"
											"7) Ordenar por estado de vuelo. \n"
					    					, "\nError. \n"
											,1,6,3)==0 && utn_getNumero(&criterio,
								 "\n\nPor favor ingrese que tipo de criterio desea aplicar: \n\n"
											"0) Ordenamiento descendente. \n"
											"1) Ordenamiento ascendente. \n"
											,"\nError. \n",0,1,3) == 0) {
			switch (opcion){

								case 1: ll_sort(sortClone,Passenger_OrdenamientoID,criterio);
										printf("\n\nOrdenamineto en proceso...");
										controller_ListPassenger(sortClone);
									break;
								case 2: ll_sort(sortClone,Passenger_OrdenamientoNombre,criterio);
										printf("\n\nOrdenamineto en proceso...");
										controller_ListPassenger(sortClone);
									break;
								case 3:	ll_sort(sortClone,Passenger_OrdenamientoApellido,criterio);
										printf("\n\nOrdenamineto en proceso...");
										controller_ListPassenger(sortClone);
									break;
								case 4:	ll_sort(sortClone,Passenger_OrdenamientoPrecio,criterio);
										printf("\n\nOrdenamineto en proceso...");
										controller_ListPassenger(sortClone);
									break;
								case 5:	ll_sort(sortClone,Passenger_OrdenamientoCodigoVuelo,criterio);
										printf("\n\nOrdenamineto en proceso...");
										controller_ListPassenger(sortClone);
									break;
								case 6:	ll_sort(sortClone,Passenger_OrdenamientoTipodePax,criterio);
										printf("\n\nOrdenamineto en proceso...");
										controller_ListPassenger(sortClone);
									break;
								case 7:	ll_sort(sortClone,Passenger_OrdenamientoEstadoVuelo,criterio);
										printf("\n\nOrdenamineto en proceso...");
										controller_ListPassenger(sortClone);
									break;

								}
					ll_deleteLinkedList(sortClone);
					retorno = 1;
		}
		else{
			printf("\nERROR al realizar el ordenamiento.");
		}
	}

    return retorno;
}
