#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "UTN.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char buffer1[50], buffer2[50], buffer3[50], buffer4[50], buffer5[8], buffer6[50], buffer7[50];
	Passenger* pAuxPassenger;
	int cant;

	if (pFile == NULL)
	{
		printf("Error al escanear el archivo.");
		retorno = 0;
		system("pause");
		exit (EXIT_FAILURE);
	}
	else
	{
		printf("\n** CARGA DE ARCHIVO EN PROCESO **\n");
	}
// LECTURA FANTASMA - 1    -2  -3    -4   -5   -6     -7
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
			buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7);

	while(!feof(pFile))
	{
		cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7);
		if (cant < 7)
		{
			printf("Error al leer el archivo.");
			break;
		}
		pAuxPassenger = Passenger_newParametros(buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7);

		if(pAuxPassenger != NULL)
		{
			ll_add(pArrayListPassenger,pAuxPassenger);
			printf("\nPasajero cargado con exito! \n");
			//free(pAuxPassenger);
			retorno = 1;
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pAuxPassenger;
	int retorno;
	int cantidad;

	if(pFile != NULL && pArrayListPassenger != NULL )
	{
		while(!feof(pFile))
		{
			pAuxPassenger = Passenger_new();
			cantidad = fread(pAuxPassenger,sizeof(Passenger),1,pFile);

			if(pAuxPassenger != NULL && cantidad == 1)
			{
				ll_add(pArrayListPassenger,pAuxPassenger);
				retorno = 1;
			}
			else{

				retorno = 0;
			}

		}
	}
	return retorno;
}

