/*
 * estructura.c
 *
 *  Created on: 12 may 2022
 *      Author: Usuario
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "UTN.h"
#include "estructura.h"



int initPassengers (ePassenger* array, int tamanio)
{
		 int retorno = -1;
		 int i;

		  if(array != NULL && tamanio > 0)
		  {
			  for (i = 0; i <tamanio ; i++)
			  {
				  array[i].isEmpty = 1;
			  }
			  retorno = 0;
		  }
		  return retorno;
	}

//busca lufgar libre
int buscarEmptyLibre(ePassenger espacio[], int tamanio, int* espacioLibre)
{

	int i;
	int retorno  = -1;

	if (tamanio > 0 && espacio != NULL && espacioLibre != NULL){

		for (i = 0;i<tamanio; i++)
		{
			if (espacio[i].isEmpty == 1)
			{

				*espacioLibre = i;

				retorno = 0;
			}
		}
	}

	return retorno;
}
//inicializa id
/*
int inicializarId(ePassenger array[], int tamanio) // inicializar una array de estructuira en 1 // 1 LIBRE // 0 Ocupado
{
	 int retorno = -1;
	  int i;

	  if(array != NULL && tamanio > 0)
	  {
		  for (i = 0; i <tamanio ; i++)
		  {
			  array[i].id = i;
		  }
		  retorno = 0;
	  }
	  return retorno;
}
*/
//funcion alta
int addPassengers (ePassenger* array,int tamanio, int indice, int* id)
{
	int retorno = -1;

	ePassenger bufferPassenger;
	if (array != NULL && tamanio >0 && indice >=0 && id != NULL)
	{
		if (
			utn_getNombre(bufferPassenger.name,LENNAME,"\nIngrese el nombre. \n","\nError. \n", 3) == 0 &&
			utn_getNombre(bufferPassenger.lastname,LENNAME,"\nIngrese el pellido. \n","\nError. \n", 3) == 0 &&
			getNumeroFlotante(&bufferPassenger.price,"\ningrese el precio del vuelo.","\nError. \n",1.0,500000.0,3)==0 &&
			utn_getNumero(&bufferPassenger.typePassenger, "\nIngrese el tipo de pax: \n 1. Adulto. "
					"(entre 18 y 65 a�os). \n 2. Menor de edad (hasta 17 a�os). \n 3. Tercer edad. "
					"(mayor de 65 a�os).\n 4. Embarazada. \n 5. Pasajero con discapacidad. \n\n","\nError. \n",1,5,3) == 0 &&
			getAlfanumerico(bufferPassenger.flycode,"\nIngrese el codigo aereo.\n","\nError. \n", LENCODE,3) == 0 &&
			utn_getNumero(&bufferPassenger.statusFly,"\nIngrese el estado del vuelo.\n \n 1. Activo. \n 2. Demorado.\n 3. Cancelado.","\nError. \n",1, 3,3) == 0)

		{

			bufferPassenger.id = *id;
			bufferPassenger.isEmpty = 0;
			array[indice] = bufferPassenger;
			*id = *id + 1 ;

		}

			retorno = 0;
		}


	return retorno;
}

//valido que el id es valido
 int findPassengerById (ePassenger array[], int tamanio,int id,int *indice)
{
	int retorno = -1;

	if (array != NULL && tamanio >0 && indice != NULL)
	{
			for(int i= 0; i<tamanio;i++)
			{
				if(array[i].isEmpty==0 && id==array[i].id)
				{
					*indice=i;
					retorno=0;
					break;
				}
		}

	}

	return retorno;
}

int printPassenger(ePassenger array[], int tamanio)
{
	int retorno = -1;
	if (array != NULL && tamanio >0)
	{

		printf("\n 				  **LISTADO EMPLEADOS** \n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO		TIPO PASAJERO 		ESTADO");
		for (int i = 0;i<tamanio;i++)
		{
			if(array[i].isEmpty == 0)
			{

				passengerPrint (array[i]);
			}
		}

		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		retorno = 0;
	}
	return retorno;
}


void passengerPrint(ePassenger passenger) // imprimir empleado 73
{
	 //printPassenger(ePassenger array[], int tamanio, int* pResultado)
	etypePassenger type [5] = {{1,"Adulto"},{2,"Menor"},{3,"Tercer edad"},{4,"Embarazada"},{5,"discapacitado"}};
	eStatusFly status [3] = {{1,"activo"},{2,"demorado"},{3,"cancelado"}};
	int i ;
	int j ;

		for ( i = 0; i<5; i++){

			if (passenger.typePassenger == type [i].typePassenger){

				break;
			}
		}

		for ( j = 0; j < 3; j++){

			if (passenger.statusFly == status [j].statusFly){

				break;
			}
		}

		printf("\n%d	 	%s		 %s     		  %.2f	  	 %s    	 %s  		 %s \n",
			passenger.id, passenger.name, passenger.lastname, passenger.price, passenger.flycode,
			type[i].typedescription,status [j].statusFly);

}





//------------------------------------------------------------------

/**
 *\brief Actualiza los datos en la posicion de Empleado del array
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param indice Posicion a ser acutualizada
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 */

//-------------------------------------------------------------------------------------

void passenger_modificarMenu(ePassenger* bufferPassenger,int tamanio)
{ // PULIR CON UN SUB MENU SWITCH // EPDIR EL ID para enviar a la fx


	int opcion;



				do{
						if (utn_getNumero(&opcion,"Por favor ingrese el numero de la opcion que "
														"desea modificar: \n"
														"1) Nombre. \n"
														"2) Apellido.\n"
														"3) Precio del vuelo.\n"
														"4) Tipo de pasajero.\n"
														"5) Codigo de vuelo.\n"
														"6) Estado de vuelo.\n"
														"7) SALIR. \n",
														"ERROR opcion incorrecta \n",1,7,4) == 0)
						{

							switch (opcion)
							{

								case 1 :

									if(utn_getNombre(bufferPassenger->name,LENNAME,"\nIngrese el nombre.\n","\nError.\n", 3) ==  0)
									{
										printf("modificacion ok.");
									}

									break;

								case 2 :

									if(utn_getNombre(bufferPassenger->lastname,LENNAME,"\nIngrese el pellido. \n","\nError. \n", 3) == 0)
									{
										printf("modificacion ok.");
									}

									break;

								case 3 :

									if(getNumeroFlotante(&bufferPassenger->price,"\ningrese el precio del vuelo.","\nError. \n",
											1.0,500000.0,3)==0)
									{
										printf("modificacion ok.");
									}
									break;

								case 4 :

									if(utn_getNumero(&bufferPassenger->typePassenger, "\nIngrese el tipo de pax: \n 1. Adulto. "
											"(entre 18 y 65 a�os). \n 2. Menor de edad (hasta 17 a�os). \n 3. Tercer edad. "
											"(mayor de 65 a�os).\n 4. Embarazada. \n 5. Pasajero con discapacidad. \n\n","\nError. \n",
											1,5,3) == 0)
									{
										printf("modificacion ok.");
									}

									break;

								case 5 :

									if(getAlfanumerico(bufferPassenger->flycode,"\nIngrese el codigo aereo.\n","\nError. \n",
											LENCODE,3) == 0)
									{
										printf("modificacion ok.");
									}

									break;


								case 6 :

									if (utn_getNumero(&bufferPassenger->statusFly,
									"\nIngrese el estado del vuelo.\n \n 1. Activo. \n 2. Demorado.\n 3. Cancelado.","\nError \n",
									1,3,3) == 0)

										{
												printf("modificacion ok");
										}
								} // FIN DEL SWITCH

						} // FIN DEL MENU

						}while(opcion != 7);

}

/**
 *\brief Actualiza una posicion del array
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param indice Posicion a ser acutualizada
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 *\param
 */
// ---------------------------------------------------------------------------------------------

int removePassenger (ePassenger* bufferEmpleado)
{
	int retorno = -1;

	if (bufferEmpleado != NULL && bufferEmpleado->isEmpty == 0){

		bufferEmpleado ->isEmpty = 1;

			retorno = 0;
		}

	return retorno;
}

/*
 *\brief Ordenar el array de clientes por nombre y OTRO PARAMETRO
 *\brief
 *\param array Array de empleado
 *\param tamanio limite del array de empleado
 *\param param retorna un 0 (EXITO) y -1 (ERROR)

 */

// ---------------------------------------------------------------------------------------------


int sortPassengers (ePassenger* array, int tamanio)
{
	int retorno = -1;
	int flagSwap;
	int i;
	int order;
	int orderTipo;
	ePassenger bufferSwap;

	if (array != NULL && tamanio >0){


		if (utn_getNumero (&order, "Por favor ingrese que tipo de ordenamiento desea. \n .Ingrese: \n 1 Descendente \n 0 Ascendente .","\nERROR\n",0,1,3) == 0)
		{
			do {
				  flagSwap = 0;

				  for (i = 0 ; i< tamanio - 1; i++)
				  {
						if (array[i].isEmpty == 1 || array[i + 1].isEmpty == 1){
								continue;
						}

						if (order == 1){

								orderTipo = (strncmp(array[i].lastname, array[i + 1].lastname,TAM) < 0); // ascendente
							}
						else if(order == 0){

								orderTipo = (strncmp(array[i].lastname, array[i + 1].lastname,TAM) > 0); // des
							}
							//  en esta parte va lo que queremos ordenar array[i].loQueQueresQrdenar
							if ((orderTipo) == 1)
							{
								flagSwap = 1;
								bufferSwap = array[i];
								array[i] = array[i + 1];
								array[i + 1] = bufferSwap;

							} // FIN DEL IF
							else if (strncmp(array[i].lastname, array[i + 1].lastname,TAM) == 0  //Comparacion de CHAR
							&& array[i].typePassenger > array[i + 1].typePassenger) // COMPARACION DE STRING
							{
									flagSwap = 1;
									bufferSwap = array[i];
									array[i] = array[i + 1];
									array[i + 1] = bufferSwap;
							}

				  }// FIN DEL FOR

				  tamanio --;

			}while (flagSwap);
		}
			retorno = 0;
	}

	return retorno;
}


