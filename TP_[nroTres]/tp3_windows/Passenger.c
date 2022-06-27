/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "LinkedList.h"
#include "UTN.h"
#include "parser.h"



Passenger* Passenger_new()
{
	Passenger* newPassenger = NULL;
	newPassenger = (Passenger*)malloc(sizeof(Passenger));
	if(newPassenger != NULL)
	{
		newPassenger->id = 0;
		strcpy(newPassenger->nombre," ");
		strcpy(newPassenger->apellido," ");
		newPassenger-> precio = 0;
		strcpy(newPassenger-> codigoVuelo," ");
		strcpy(newPassenger-> tipoPasajero," ");
		strcpy(newPassenger->estadoVuelo," ");
		newPassenger-> isEmpty = 1;
	}
	return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codVueloStr,char* tipoPasajeroS, char* estadoVueloStr)
{
	Passenger* newPassenger = Passenger_new ();
	if (newPassenger != NULL)
	{

		if(		Passenger_setId(newPassenger,atoi(idStr))&&
				Passenger_setNombre(newPassenger,nombreStr) &&
				Passenger_setApellido(newPassenger,apellidoStr) &&
				Passenger_setPrecio(newPassenger,atof(precioStr)) &&
				Passenger_setCodigoVuelo(newPassenger,codVueloStr) &&
 				Passenger_setTipoPasajero(newPassenger,tipoPasajeroS) &&
				Passenger_setEstadoVuelo(newPassenger,estadoVueloStr))

		{
			printf("\nPasajero en preoceso de carga.... \n");
		}
		else
		{
			free (newPassenger);
			newPassenger = NULL;
		}
	}
	return newPassenger;
}

Passenger* Passenger_newParametrosAlta(int idStr,char* nombreStr,char* apellidoStr,float precioStr,char* codVueloStr,char* tipoPasajeroS, char* estadoVueloStr)
{
	Passenger* newPassenger = Passenger_new ();
//	printf("%s Precarga",apellidoStr);
	if (newPassenger != NULL)
	{
		if(		Passenger_setId(newPassenger,idStr)&&
				Passenger_setNombre(newPassenger,nombreStr) &&
				Passenger_setApellido(newPassenger,apellidoStr) &&
				Passenger_setPrecio(newPassenger,precioStr) &&
				Passenger_setCodigoVuelo(newPassenger,codVueloStr) &&
 				Passenger_setTipoPasajero(newPassenger,tipoPasajeroS) &&
				Passenger_setEstadoVuelo(newPassenger,estadoVueloStr))

		{
			printf("\nPasajero cargado con exito! \n");
		}
		else
		{
			free (newPassenger);
			newPassenger = NULL;
		}
	}
	return newPassenger;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->id = id;

		retorno = 1;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre!= NULL ) // && strlen(nombre)>0 && strlen(nombre)<=15
	{
		strcpy(this->nombre,nombre);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	if(this != NULL &&  nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = 0;
	if(this != NULL &&  apellido != NULL ) // && strlen(apellido)>0 && strlen(apellido)<=15
	{
		strcpy(this->apellido,apellido);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this, char* apellido)
{
	int retorno = 0;
	if(this != NULL &&  apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	if(this != NULL &&  codigoVuelo != NULL ) // && strlen(codigoVuelo)== 7
	{
		strncpy(this->codigoVuelo,codigoVuelo,8);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	if(this != NULL &&  codigoVuelo != NULL)
	{
		strncpy(codigoVuelo,this->codigoVuelo,8);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;
	if(this != NULL && tipoPasajero != NULL ) // && strlen(tipoPasajero) > 0 && strlen(tipoPasajero)<=15
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;
	if(this != NULL &&  tipoPasajero != NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = 0;
	if(this != NULL &&  precio > 0 && precio<=1000000)
	{
		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = 0;
	if(this != NULL &&  precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = 0;
	if(this != NULL && estadoVuelo != NULL ) // && strlen(estadoVuelo) > 0 && strlen(estadoVuelo)<=15
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = 0;
	if(this != NULL &&  estadoVuelo != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_BuscarPaxId (LinkedList* pArrayListPassenger, int id)
{
	int tamanio;
	int retorno = -1;
	int idAux;
	Passenger* auxPassenger;

		if (pArrayListPassenger != NULL && id >= 0)
		{
			tamanio = ll_len(pArrayListPassenger);
			for(int i = 0 ; i < tamanio ; i++)
			{
				auxPassenger = ll_get(pArrayListPassenger,i);
				if (auxPassenger != NULL)
				{
					Passenger_getId (auxPassenger,&idAux);
					if(id == idAux)
					{
						retorno = i;
						break;
					}
				}
			}
		}
	return retorno;
}

int Passenger_OrdenamientoID (void* idUno,void* idDos)
{
	Passenger* pax1 = NULL;
	Passenger* pax2 = NULL;

	int idPaxUno;
	int idPaxDos;
	int retorno;

	pax1 = (Passenger*) idUno;
	pax2 = (Passenger*) idDos;

	if(idUno != NULL && idDos != NULL)
	{
		if(Passenger_getId(pax1,&idPaxUno) && Passenger_getId(pax2, &idPaxDos))
		{
			if(idPaxUno > idPaxDos)
			{
				retorno = 1;
			}
			else if(idPaxUno < idPaxDos)
			{
				retorno = -1;
			}
		}
	}
		return retorno;
}
int Passenger_OrdenamientoNombre(void* nombreUno,void* nombreDos)
{
	int retorno;
	Passenger* pax1 = NULL;
	Passenger* pax2 = NULL;

	char nombre1[50];
	char nombre2[50];

	pax1 = (Passenger*) nombreUno;
	pax2 = (Passenger*) nombreDos;


	if(nombreUno != NULL && nombreDos != NULL)
	{
		if(Passenger_getNombre(pax1, nombre1)&& Passenger_getNombre(pax2, nombre2))
		{
			if(strcmp(nombre1, nombre2) > 0)
			{
				retorno = 1;
			}
			else if(strcmp(nombre1, nombre2)< 0)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
int Passenger_OrdenamientoApellido(void* ApellidoUno,void* ApellidoDos)
{
	int retorno;
	Passenger* pax1 = NULL;
	Passenger* pax2 = NULL;

	char apellido1[50];
	char apellido2[50];

	pax1 = (Passenger*) ApellidoUno;
	pax2 = (Passenger*) ApellidoDos;


	if(ApellidoUno != NULL && ApellidoDos != NULL)
	{
		if(Passenger_getApellido(pax1, apellido1)&& Passenger_getApellido(pax2, apellido2))
		{
			if(strcmp(apellido1, apellido2) > 0)
			{
				retorno = 1;
			}
			else if(strcmp(apellido1, apellido2)< 0)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
int Passenger_OrdenamientoPrecio (void* precioUno,void* precioDos)
{
	Passenger* pax1 = NULL;
	Passenger* pax2 = NULL;

	float precioPaxUno;
	float precioPaxDos;
	int retorno;

	pax1 = (Passenger*) precioUno;
	pax2 = (Passenger*) precioDos;

	if(precioUno != NULL && precioDos != NULL)
	{
		if(Passenger_getPrecio(pax1,&precioPaxUno) && Passenger_getPrecio(pax2, &precioPaxDos))
		{
			if(precioPaxUno > precioPaxDos)
			{
				retorno = 1;
			}
			else if(precioPaxUno < precioPaxDos)
			{
				retorno = -1;
			}
		}
	}
		return retorno;
}
int Passenger_OrdenamientoCodigoVuelo (void* codigoUno,void* codigoDos)
{
	int retorno;
	Passenger* pax1 = NULL;
	Passenger* pax2 = NULL;

	char codigo1[50];
	char codigo2[50];

	pax1 = (Passenger*) codigoUno;
	pax2 = (Passenger*) codigoDos;


	if(codigoUno != NULL && codigoDos != NULL)
	{
		if(Passenger_getCodigoVuelo(pax1, codigo1) && Passenger_getCodigoVuelo(pax2, codigo2))
		{
			if(strcmp(codigo1, codigo2) > 0)
			{
				retorno = 1;
			}
			else if(strcmp(codigo1, codigo2)< 0)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
int Passenger_OrdenamientoTipodePax (void* tipoUno,void* tipoDos)
{
	int retorno;
	Passenger* pax1 = NULL;
	Passenger* pax2 = NULL;

	char tipo1[50];
	char tipo2[50];

	pax1 = (Passenger*) tipoUno;
	pax2 = (Passenger*) tipoDos;


	if(tipoUno != NULL && tipoDos != NULL)
	{
		if(Passenger_getCodigoVuelo(pax1, tipo1) && Passenger_getCodigoVuelo(pax2, tipo2))
		{
			if(strcmp(tipo1, tipo2) > 0)
			{
				retorno = 1;
			}
			else if(strcmp(tipo1, tipo2)< 0)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
int Passenger_OrdenamientoEstadoVuelo (void* estadoUno,void* estadoDos)
{
	int retorno;
	Passenger* pax1 = NULL;
	Passenger* pax2 = NULL;

	char esteado1[50];
	char esteado2[50];

	pax1 = (Passenger*) estadoUno;
	pax2 = (Passenger*) estadoDos;


	if(estadoUno != NULL && estadoDos != NULL)
	{
		if(Passenger_getCodigoVuelo(pax1, esteado1) && Passenger_getCodigoVuelo(pax2, esteado2))
		{
			if(strcmp(esteado1, esteado2) > 0)
			{
				retorno = 1;
			}
			else if(strcmp(esteado1, esteado2)< 0)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}
