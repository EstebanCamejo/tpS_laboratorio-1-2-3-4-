/*
 * empleado.h
 *
 *  Created on: 8 may 2022
 *      Author: Usuario
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#define TAMANIO 20
#define TAMANIO 20


typedef struct {

	int id;
    char nombre[TAMANIO];
    char apellido[TAMANIO];
    float salario;
    int sector;
    int isEmpty;

}eEmpleado;

#endif /* EMPLEADO_H_ */


int inicializarIsEmpty (eEmpleado array [], int tamanio);

//int buscarEmptyLibre(espacio [], int tamanio);

int buscarEmptyLibre (eEmpleado espacio [], int tamanio, int* espacioLibre);

int ordenarEmpleados(eEmpleado array [], int tamanio);
//----------------------------------------------------------------------------------------------------------------------------
/**---------------------------------------------------------------------------------------------------------------------------
* \brief imprime los datos de un empleado
* parametro pElemento Puntero al producto que se busca imprimir
* return retorna un 0 (EXITO) y -1 (ERROR)
* pElemento es lo que envuio como parametro para imprimir
*/
int empleado_imrpimir(eEmpleado* pElemento);

/**
 * \brief imprime el array de empleados
 * \param Array array Array del empleado a ser actualizado
 * \param tamanio Limite del array del empleado
 * \return retorna un 0 (EXITO) y -1 (ERROR)
 */
int empleado_imrpimirArray (eEmpleado* array, int tamanio);

/**
 * \brief inicializa el array
 * \param array de empleados a ser actualizado
 * \param tamanio limite del array de empleado
 * \return retorna un 0 (EXITO) y -1 (ERROR)
 */
int empleado_inicializar (eEmpleado* array,int tamanio);

/**
 * \brief da de alta a un empleado en una posicion del array
 * \param array Array de empleado a ser acutualizado
 * \param tamanio limite del array de empleado
 * \param indice Posicion a ser acutualizada
 * \param ID Identificador a ser asignado al empleado
 * \return retorna un 0 (EXITO) y -1 (ERROR)
 *  DA DE ALTA AL EMPLEADO EN LA POSICION ENVIADA POR EL indice EN UNA POSICION PARTICULAR que retorna el buscarisEmpty RETORNA el ID
 */
int empleado_alta (eEmpleado* array,int tamanio, int indice, int* id);

/**
 *\brief Actualiza los datos en la posicion de Empleado del array
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param indice Posicion a ser acutualizada
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 */
int empleado_modificarMenu(eEmpleado* array,int tamanio, int indice, int tamanioVariable);

/**
 *\brief Actualiza una posicion del array
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param indice Posicion a ser acutualizada
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 *\param
 */
int empleado_bajaLogica (eEmpleado* array, int tamanio, int indice);

/**
 *\brief Busca un ID en un array y devuelve la posicion en que se encuentra
 *\param array Array de empleado
 *\param tamanio limite del array de empleado
 *\param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 */
int empelado_BuscarId (eEmpleado array [],int tamanio, int idBuscado, int* indice);

/**
 *\brief Buscar primer posicion vacia
 *\param array Array de empleado
 *\param tamanio limite del array de empleado
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 *\param retorna posicion vacia
 */
int empleado_getEmpty (eEmpleado* array,int tamanio , int* indice);

/**
 *\brief Ordenar el array de clientes por nombre
 *\param array Array de empleado
 *\param tamanio limite del array de empleado
 *\param param retorna un 0 (EXITO) y -1 (ERROR)

 */
int empleado_ordenarPorNombre (eEmpleado* array,int tamanio);

/**
 *\brief Ordenar el array de clientes por nombre y OTRO PARAMETRO
 *\brief
 *\param array Array de empleado
 *\param tamanio limite del array de empleado
 *\param param retorna un 0 (EXITO) y -1 (ERROR)

 */
int empleado_ordenarPorNombreSector (eEmpleado* array,int tamanio);

/**---------------------------------------------------------------------------------------------------------------------------------
 *\brief Actualiza los datos en la posicion del array que le solicita al usuario
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param tamanioVariable Es el tamanio designado para las variables que comprenden el array
 *\param retorna un 1 (EXITO) y -1 (ERROR)
 */
int empleado_modificar(eEmpleado* array,int tamanio, int tamanioVariable);
