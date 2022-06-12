/*
 * estructura.h
 *
 *  Created on: 12 may 2022
 *      Author: Usuario
 */


#ifndef ESTRUCTURA_H_
#define ESTRUCTURA_H_

#define TAM 3
#define LENNAME 51
#define LENCODE 10

typedef struct {

	int id;
    char name[LENNAME];
    char lastname[LENNAME];
    float price;
    char flycode[LENCODE] ; // ID
    int typePassenger;
    int statusFly;
    int isEmpty;

}ePassenger;

typedef struct {

	int statusFly;
	char statusDescription [25];

}eStatusFly;

typedef struct {

	int typePassenger;
	char typedescription[25];

}etypePassenger; /// OKOKOKOKOKKOK




#endif /* ESTRUCTURA_H_ */


int initPassengers (ePassenger* array, int tamanio);


int buscarEmptyLibre(ePassenger espacio [], int tamanio, int* espacioLibre);

//int inicializarId(ePassenger array[], int tamanio);





/**
 * \brief da de alta a un empleado en una posicion del array
 * \param array Array de empleado a ser acutualizado
 * \param tamanio limite del array de empleado
 * \param indice Posicion a ser acutualizada
 * \param ID Identificador a ser asignado al empleado
 * \return retorna un 0 (EXITO) y -1 (ERROR)
 *  DA DE ALTA AL EMPLEADO EN LA POSICION ENVIADA POR EL indice EN UNA POSICION PARTICULAR que retorna el buscarisEmpty RETORNA el ID
 */

//estatica
int addPassengers (ePassenger array[],int tamanio, int indice, int* id);

//int imprimirUnEmpleadoConId(ePassenger array[], int tamanio);
int printPassenger(ePassenger array[], int tamanio);

void passengerPrint(ePassenger empleado);

int findPassengerById(ePassenger array[], int tamanio,int id,int *indice);
/**
 *\brief Actualiza los datos en la posicion de Empleado del array
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param indice Posicion a ser acutualizada
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 */
void passenger_modificarMenu(ePassenger* bufferEmpleado,int tamanio);

int removePassenger (ePassenger* bufferEmpleado);

int sortPassengers (ePassenger* array,int tamanio);
