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
		strcpy(newPassenger-> codigoVuelo, " ");
		strcpy(newPassenger-> tipoPasajero, " ");
		strcpy(newPassenger->estadoVuelo, " ");
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
	if(this != NULL && nombre!= NULL && strlen(nombre)>0 && strlen(nombre)<50)
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
	if(this != NULL &&  apellido != NULL && strlen(apellido)>0 && strlen(apellido)<50)
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
	if(this != NULL &&  codigoVuelo != NULL && strlen(codigoVuelo)== 7)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	if(this != NULL &&  codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;
	if(this != NULL && tipoPasajero != NULL && strlen(tipoPasajero) > 0 && strlen(tipoPasajero)<=15)
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
	if(this != NULL && estadoVuelo != NULL && strlen(estadoVuelo) > 0 && strlen(estadoVuelo)<=15)
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
	int retorno = 0;
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
