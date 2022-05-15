/*
 * empleado.c
 *
 *  Created on: 8 may 2022
 *      Author: Usuario
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_getNumero.h"
#include "empleado.h"
#define TAM 5 // tamaño de array de la estructura
#define TAMANIO 20 // TAMANIO DE LAS VARIABLES



int inicializarIsEmpty (eEmpleado array [], int tamanio) // inicializar una array de estructuira en 1 // 1 LIBRE // 0 Ocupado
	{
		 int retorno = -1;
		  int i;

		  if (array != NULL && tamanio > 0){
			  for (i = 0; i <tamanio ; i++){
				  array[i].isEmpty = 1;
			  }
			  retorno = 0;
		  }
		  return retorno;
	}

int buscarEmptyLibre(eEmpleado espacio [], int tamanio, int* espacioLibre){

	int i;
	int retorno  = -1;

	if (tamanio > 0 && espacio != NULL && espacioLibre != NULL){

		for (i = 0;i<tamanio; i++){

			if (espacio[i].isEmpty == 1){

				*espacioLibre = i;

				retorno = 0;
			}
		}
	}

	return retorno;
}

int ordenarEmpleados(eEmpleado array [], int tamanio){

	int retorno = -1;
	eEmpleado aux;
	int i;
	int j;

	if (tamanio > 0 && array != NULL){

		 for (i = 0; i < tamanio - 1; i++){

				 for (j = i + 1; j < tamanio; j++)
					{
						 if(strcmp(array[i].apellido,array[j].apellido)> 0 || (strcmp(array[i].apellido,array[j].apellido) == 0 &&
							array[i].sector >array[j].sector))
						{
						  aux = array[i];
						  array[i] = array[j];
						  array[j] = aux;
						}
					}
		   }

		 retorno = 0;
	   }
	return retorno;
}

/**---------------------------------------------------------------------------------------------------------------------------
 * \brief imprime los datos de un empleado
 * parametro pElemento Puntero al producto que se busca imprimir
 * return retorna un 0 (EXITO) y -1 (ERROR)
 * pElemento es lo que envuio como parametro para imprimir
 */
int empleado_imrpimir(eEmpleado* pElemento){ // recibe la direccion de memoria del cliente// empleado
	int retorno = -1;
	if (pElemento != NULL && pElemento -> isEmpty == 0){

		printf(" ID: %d - %s - %s - %.2f -%d",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->salario,pElemento->sector);
		//      id  nombre apellido salario sector
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief imprime el array de empleados
 * \param Array array Array del empleado a ser actualizado
 * \param tamanio Limite del array del empleado
 * \return retorna un 0 (EXITO) y -1 (ERROR)
 */

int empleado_imrpimirArray (eEmpleado* array, int tamanio){

	int retorno = -1;
	if (array != NULL && tamanio >0){

		for (int i = 0;i<tamanio;i++){

			empleado_imrpimir (&array [i]);

			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief inicializa el array
 * \param array de empleados a ser actualizado
 * \param tamanio limite del array de empleado
 * \return retorna un 0 (EXITO) y -1 (ERROR)
 */
int empleado_inicializar (eEmpleado* array,int tamanio){

	int retorno = -1;

	if (array != NULL && tamanio >0){

		for (int i = 0;i<tamanio;i++){

			array [i].isEmpty = 1;

			retorno = 0;
		}

	}
	return retorno;
}
/**
 * \brief da de alta a un empleado en una posicion del array
 * \param array Array de empleado a ser acutualizado
 * \param tamanio limite del array de empleado
 * \param indice Posicion a ser acutualizada
 * \param ID Identificador a ser asignado al empleado
 * \return retorna un 0 (EXITO) y -1 (ERROR)
 *  DA DE ALTA AL EMPLEADO EN LA POSICION ENVIADA POR EL indice EN UNA POSICION PARTICULAR que retorna el buscarisEmpty RETORNA el ID
 */
int empleado_alta (eEmpleado* array,int tamanio, int indice, int* id){

	int retorno = -1;
	eEmpleado bufferEmpleado;
	if (array != NULL && tamanio >0 && indice < tamanio && indice >=0 && id != NULL)
	{
		if (
			utn_getNombre(bufferEmpleado.nombre,TAMANIO,"\nNombre? \n","\nError \n", 2) == 0 &&
			utn_getNombre(bufferEmpleado.apellido,TAMANIO,"\nApellido? \n","\nError \n", 2) == 0 &&
			utn_getNumeroFloat(&bufferEmpleado.salario,"\Salario? \n","\nError \n",0.0,10000.1, 2) == 0 &&
			utn_getNumero(&bufferEmpleado.sector, "\nIngrese el sector\n","\nError \n",1,5,2) == 0
		)
		{
			bufferEmpleado.id = *id;
			bufferEmpleado.isEmpty = 0;
			array [indice] = bufferEmpleado;
			*id = *id + 1 ;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 *\brief Actualiza los datos en la posicion de Empleado del array
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param indice Posicion a ser acutualizada
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 */
int empleado_modificarMenu(eEmpleado* array,int tamanio, int indice, int tamanioVariable){ // PULIR CON UN SUB MENU SWITCH // EPDIR EL ID para enviar a la fx

	int retorno = -1;
	eEmpleado bufferEmpleado;
	int opcion;

	if (array != NULL && tamanio >0 && indice < tamanio && array [indice].isEmpty == 0){

				do{
						if (utn_getNumero(&opcion,"Por favor ingrese el numero de la opcion que "
														"desea modificar: \n"
														"1) Nombre \n"
														"2) Apellido\n"
														"3) Salario\n"
														"4) Sector\n"
														"5) SALIR \n",
														"ERROR opcion incorrecta \n",1,5,4) == 0){

							switch (opcion){

								case 1 :

									utn_getNombre(bufferEmpleado.nombre,tamanioVariable,"\nNombre? \n","\nError \n", 2);

									break;

								case 2 :

									utn_getNombre(bufferEmpleado.apellido,tamanioVariable,"\nApellido? \n","\nError \n", 2);

									break;
								case 3 :

									utn_getNumeroFloat(&bufferEmpleado.salario,"\Salario? \n","\nError \n",0,11, 2);

									break;
								case 4 :

									utn_getNumero(&bufferEmpleado.sector, "\nIngrese el sector\n","\nError \n",1,5,2);

									break;
								}

						}

						}while(opcion != 5);


				if (opcion == 5)
				{

					bufferEmpleado.id = array [indice].id;
					bufferEmpleado.isEmpty = 0;
					array [indice] = bufferEmpleado;

					retorno = 0;
				}

	}
	return retorno;
}

/**
 *\brief Actualiza una posicion del array
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param indice Posicion a ser acutualizada
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 *\param
 */
int empleado_bajaLogica (eEmpleado* array, int tamanio, int indice){

	int retorno = -1;

	if (array != NULL && tamanio > 0 && indice > tamanio && indice >= 0 && array [indice].isEmpty == 0){

			array [indice].isEmpty = 1;

			retorno = 0;
		}

	return retorno;
}
/**
 *\brief Busca un ID en un array y devuelve la posicion en que se encuentra
 *\param array Array de empleado
 *\param tamanio limite del array de empleado
 *\param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 */
int empelado_BuscarId (eEmpleado array [],int tamanio, int idBuscado, int* indice){ // busca ID y devuelve el indice

	int retorno = -1;

	if (array != NULL && tamanio >0 && idBuscado >= 0){

		for (int i = 0;i<tamanio;i++){

			if(array [i].id == idBuscado){

				*indice = i;

				retorno = 0;

				break;
			}
		}

	}
	return retorno;
}

/**
 *\brief Buscar primer posicion vacia
 *\param array Array de empleado
 *\param tamanio limite del array de empleado
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 *\param retorna posicion vacia
 */
int empleado_getEmpty (eEmpleado* array,int tamanio , int* indice){ // Busca un lugar isEmpti y devuelve el indice(la posision)

	int retorno = -1;

	if (array != NULL && tamanio >0){

		for (int i = 0;i<tamanio;i++)
			{
				if(array [i].isEmpty == 1)
				{
					*indice = i;
					retorno = 0;
					break;
				}
		}
	}
	return retorno;
}
/**
 *\brief Ordenar el array de clientes por nombre
 *\param array Array de empleado
 *\param tamanio limite del array de empleado
 *\param param retorna un 0 (EXITO) y -1 (ERROR)

 */
int empleado_ordenarPorNombre (eEmpleado* array,int tamanio){

	int retorno = -1;
	int flagSwap;
	int i;
	eEmpleado bufferSwap;


	if (array != NULL && tamanio >0){

			do {
				  flagSwap = 0;

				  for (i = 0 ; i< tamanio - 1; i++)
				  {
					if (array[i].isEmpty == 1 || array[i + 1].isEmpty == 1 ){

							continue;
					}
					if(strncmp(array[i].nombre, array[i + 1].nombre,TAM) > 0)

						/*  en esta parte va lo que queremos ordenar array[i].loQueQueresQrdenar*/
						{
							flagSwap = 1;
							bufferSwap = array[i];
							array[i] = array[i + 1];
							array[i + 1] = bufferSwap;

						} // FIN DEL IF
				  }// FIN DEL FOR

				  tamanio --;

			}while (flagSwap);

			retorno = 0;
	}

	return retorno;
}
/**
 *\brief Ordenar el array de clientes por nombre y OTRO PARAMETRO
 *\brief
 *\param array Array de empleado
 *\param tamanio limite del array de empleado
 *\param param retorna un 0 (EXITO) y -1 (ERROR)

 */
int empleado_ordenarPorNombreSector (eEmpleado* array,int tamanio){

	int retorno = -1;
	int flagSwap;
	int i;
	eEmpleado bufferSwap;


	if (array != NULL && tamanio >0){

			do {
				  flagSwap = 0;

				  for (i = 0 ; i< tamanio - 1 ; i++)
				  {
						if (array[i].isEmpty == 1 || array[i + 1].isEmpty == 1 ){

								continue;
						}
						if(strncmp(array[i].nombre, array[i + 1].nombre,TAM) > 0)

							/*  en esta parte va lo que queremos ordenar array[i].loQueQueresQrdenar*/
							{
								flagSwap = 1;
								bufferSwap = array[i];
								array[i] = array[i + 1];
								array[i + 1] = bufferSwap;

							} // FIN DEL IF
						else if(strncmp(array[i].nombre, array[i + 1].nombre,TAM) == 0 &&  array[i].sector > array[i + 1].sector)
							{	// COMPARACION DE STRING 									Comparacion de CHAR
									flagSwap = 1;
									bufferSwap = array[i];
									array[i] = array[i + 1];
									array[i + 1] = bufferSwap;
								}
				  }// FIN DEL FOR

				  tamanio --;

			}while (flagSwap);

			retorno = 0;
	}

	return retorno;
}

/**---------------------------------------------------------------------------------------------------------------------------------
 *\brief Actualiza los datos en la posicion del array que le solicita al usuario
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param tamanioVariable Es el tamanio designado para las variables que comprenden el array
 *\param retorna un 1 (EXITO) y -1 (ERROR)
 */
int empleado_modificar(eEmpleado* array,int tamanio, int tamanioVariable){ // PULIR CON UN SUB MENU SWITCH // EPDIR EL ID para enviar a la fx

	int retorno = -1;
	eEmpleado bufferEmpleado;
	int opcion;
	int idAux;
	int indiceAux;
	if (array != NULL && tamanio >0 ){


					if(utn_getNumero(&idAux,"Por favor ingrese el numedo de ID que desea modificar\n","ERROR",0,tamanio,3) == 0)
					{

						if(empelado_BuscarId (array, tamanio, idAux, &indiceAux) == 0)

						{
							if (empleado_modificarMenu(array,tamanio, indiceAux,tamanioVariable) == 0){


								retorno = 1;
							}

						}

					}

	}
	return retorno;
}





