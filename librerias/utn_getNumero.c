/*
 * utn_getNumero.c
 *
 *  Created on: 12 abr 2022
 *      Author: Usuario
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_getNumero.h"


static int esNombre (char array [], int tamanio);

static int getNombre (char pResultado [], int tamanio);

static int esFlotente(char* stringRecibido, int tamanio);

static int getFloat (float* pResultado);

static int getInt (int* pResultado);

static int esNumerica (char* cadena, int tamanio);


// recibe un espacio de memoriua y devuelve un numero entero Lee lo que el usuario entrega por teclado y valida que eso sea
// un numero llama a mygets para obtener el texto y despues lo valida con es Numero REEMPLAZA AL SCANF %d

static int getInt (int* pResultado) // numero entero
{
	int retorno = -1;
	char buffer [4096];
	fflush(stdin);

	if (pResultado != NULL){
		if (myGets (buffer, sizeof(buffer)) == 0 && (esNumerica(buffer,sizeof(buffer)))) // osea si se cumple la fx y me devuelve un verdadero
		{
			*pResultado = atoi (buffer);
			retorno = 0;
		}
	}

	return retorno;
}

//  recibe el tamanio y la cadena y nos dice  si es disponible del buffer esta ok (no lo desborda)
// lee tod0 hasta un \0 o hasta que llegue al limite

int myGets (char* cadena, int tamanio){ // NOMBRE

	int retorno = -1;
	char bufferString [4096];//**********************************************

	if (cadena != NULL && tamanio >0 ){

		fflush(stdin);
		if(fgets(bufferString,sizeof (bufferString),stdin) != NULL){

			if (bufferString [strnlen (bufferString,sizeof (bufferString) )-1] == '\n'){

				bufferString [strnlen (bufferString, sizeof (bufferString))-1] = '\0';
			}
			if (strnlen (bufferString, sizeof (bufferString)) <= tamanio){

				strncpy (cadena,bufferString, tamanio);
				retorno = 0;
			}
		}
	}

	return retorno;
}

static int esNumerica (char* cadena, int tamanio)
{
	int retorno = -1; // ERROR
	int i;
	if (cadena != NULL && tamanio > 0){

		retorno = 1; // VERDADERO
		for ( i = 0 ; i < tamanio && cadena [i] != '\0' ; i++) // el primer argumento esta vacio porque no sabemos que informacion viene en la cadena de arrays
		{
			if (i == 0 && (cadena [i] == '-' || cadena [i] == '+'))
			{
				continue;
			}
			if (cadena [i] > '9' || cadena [i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
	{
		do{
			printf("%s", mensaje); // cualquier tipo de string en el msj

			if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0 );

	}

	return retorno;
}

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
	{
		do{
			printf("%s", mensaje);// cualquier tipo de string en el msj

			if (getFloat(&bufferFloat) == 0  && bufferFloat >= minimo && bufferFloat <= maximo) // validamos el buffer
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0 );

	}

	return retorno;
}

static int getFloat (float* pResultado){

	int retorno = -1;
	char buffer [4096];
	fflush(stdin);

	if (pResultado != NULL){

			if( myGets (buffer, sizeof(buffer)) == 0 && esFlotente (buffer,sizeof(buffer))== 1 ) // osea si se cumple la fx y me devuelve un verdadero
			{
				*pResultado = atof(buffer);
				retorno = 0;
			}
		}

		return retorno;

}
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 1 (EXITO) si se obtiene un numero flotante y 0 (ERROR) si no es flotante
 *
 */
static int esFlotente(char* stringRecibido, int tamanio){ // validar flotante para pasar de char a float con aotf

	int retorno = 1;
	int i;
	int contadorPuntos = 0;


	if (stringRecibido != NULL && tamanio> 0){

		for (i=0;stringRecibido[i]!= '\0'; i++)
		{

			if (stringRecibido[i]< '0'|| stringRecibido[i]>'9')
			{
				// no estoy en el rango de numeros
				// si lo que ingresa no es un numero puede tener solo 1 punto

				if (stringRecibido[i] == '.')
				{
					contadorPuntos++;

					if(contadorPuntos>1){

					// encontre un segundo punto doy ERROR
						retorno = 0;
						break;
					}
				}
				else{
					if(i == 0){
						// hay algo que no es un punto ni un numero

						if(stringRecibido[i] != '+' &&stringRecibido[i] != '-')
						{
						// chequeo si es un caracter
							retorno = 0;
							break;
						} // if posicion 1 OK caracter
					} // IF primera posicion

				} // fin del else
			}
		} // fin del for
	}

	return retorno;
}

int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
	{
		do{
			printf("%s", mensaje);// cualquier tipo de string en el msj
			fflush(stdin);
			scanf ("%c", &bufferChar);// guardamos la respuesta en el buffer
			if (bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
				else
				{
					printf("%s", mensajeError);
					reintentos --;
				}

			}while(reintentos >= 0 );

		}

	return retorno;
}

int calculoDescuento(float *resultadoDescuento, float precio, float descuento)
{
	int retorno = -1;

	if(resultadoDescuento != NULL && precio >0 && descuento >0){

		*resultadoDescuento = precio-(precio*descuento/100);

		retorno = 0;
	}

	return retorno;
}

int calculoInteres(float* resultadoInteres, float precio, float interes)
{

	int retorno = -1;

	if (resultadoInteres != NULL && precio>0 && interes> 0 ){

		*resultadoInteres = precio + (precio*interes/100);

		retorno = 0;
	}

	return retorno;
}

int calculoBitcoin(float* resultadoBitcoin, float precio, float bitcoin)

{
	int retorno = -1;

	if (resultadoBitcoin != NULL && precio>0 && bitcoin> 0 ){

		*resultadoBitcoin = precio / bitcoin;

		retorno = 0;
	}

	return retorno;
}

int calculoDivision(float* resultadoDivision,float operador1, float operador2){

	int retorno = -1;
	if (resultadoDivision != NULL && operador1 >0 && operador2 != 0){

		*resultadoDivision = (float) operador1 / operador2;

		retorno = 0;
	}
	return retorno;
}

int calculoDiferencia(float* resuladoDiferencia, float operador1, float operador2){
	int retorno = -1;
	float bufferFloatDiff;
	if(resuladoDiferencia != NULL && operador1 >0 && operador2 >0 ){

			if (operador1 > operador2){

				bufferFloatDiff = operador1 - operador2;
			}
			 else {

				 bufferFloatDiff = operador2 - operador1;
			 }
		*resuladoDiferencia = bufferFloatDiff;

	retorno = 0;
	}
	return retorno;
}

int inicializarArray (int array[], int tamanio)	//inicializacion EN -1
{
  int retorno = -1;
  int i;

  if (array != NULL && tamanio > 0)
    {
      for (i = 0; i <tamanio ; i++)
		{
		  array[i] = -1;
		}
      retorno = 0;
    }
  return retorno;
}

int inicializarArrayChar (char array[], int tamanio)	//inicializacion EN " "
{
  int retorno = -1;
  int i;

  if (array != NULL && tamanio > 0)
    {
      for (i = 0; i <tamanio ; i++)
		{
    	  strcpy(array[i],' ');
		}
      retorno = 0;
    }
  return retorno;
}

int inicializarArrayString (char array[][100], int tamanioFila , int tamanioColumna)
{
	int retorno = -1;
	  int i;
	  int j;

	  if (array != NULL && tamanioFila > 0 && tamanioColumna > 0)
	    {
	      for (i = 0; i <tamanioFila ; i++)
			{

	    	  for (j = 0; j <tamanioColumna ; j++){

	    		  strcpy(array[i][j]," ");
	    	  }

			}
	      retorno = 0;
	    }
	  return retorno;
}

int inicializarArrayFloat (float array[], int tamanio)	//inicializacion EN -1
{
  int retorno = -1;
  int i;

  if (array != NULL && tamanio > 0)
    {
      for (i = 0; i <tamanio ; i++)
		{
		  array[i] = -1;
		}
      retorno = 0;
    }
  return retorno;
}

///////////////////////////

int maximoArray (int array[], int tamanio ,int* maximo) // FALTA REVISAR
{
	int	retorno = -1;
	int	flag = 0;

 if (array != NULL && tamanio>0 && maximo != NULL){

	 for  (int i = 0; i < tamanio; i++ ){

		 if (flag == 0 || array [i] > *maximo){// ver el puntero en esta linea

		 *maximo = array [i]; // es igual a la linea 218

		 flag =1;

		 }
	 }
	 retorno =0;
 }
 return retorno;
}

int minimoArray (int array[], int tamanio, int* minimo) //FALTA REVISAR
{
	int	retorno = -1;
	int	flag = 0;

 if (array != NULL && tamanio>0 && minimo != NULL){

	 for  (int i = 0; i < tamanio; i++ ){

		 if (flag == 0 || array [i] < *minimo){ // ver el puntero en esta linea

		 *minimo = array [i]; // es igual a la linea 218

		 flag =1;

		 }
	 }
	 retorno =0;
 }
 return retorno;
}

///////////////////////////

int ordenamientoArrayEfectivoDecendente(int array[], int tamanio)

{
	int flaggSwap;
	int i;
	int contador = 0;
	int retorno = -1;
	int aux;
	int nuevoLimite;

	 if (array != NULL && tamanio >= 0)
	 {
		 nuevoLimite = tamanio - 1;

		 do{
			 flaggSwap = 0;
			 for (i = 0; i < nuevoLimite; i++)
			 {
				 contador++;
				 if (array[i] < array[i+1])
					{
					 flaggSwap = 1;
					  aux = array[i];
					  array[i] = array[i +1];
					  array[i+1] = aux;
					}

				 nuevoLimite--;
			 }

		 }while (flaggSwap);

		 retorno = 0;
	   }

	return retorno;


}

int ordenamientoArrayEfectivoAscendente(int array[], int tamanio)

{
	int flaggSwap;
	int i;
	int contador = 0;
	int retorno = -1;
	int aux;
	int nuevoLimite;

	 if (array != NULL && tamanio >= 0)
	 {
		 nuevoLimite = tamanio - 1;

		 do{
			 flaggSwap = 0;
			 for (i = 0; i < nuevoLimite; i++)
			 {
				 contador++;
				 if (array[i] > array[i+1])
					{
					 flaggSwap = 1;
					  aux = array[i];
					  array[i] = array[i +1];
					  array[i+1] = aux;
					}

				 nuevoLimite--;
			 }

		 }while (flaggSwap);

		 retorno = 0;
	   }

	return retorno;


}

int ordenamientoArrayAscendente (int array[], int tamanio)// forma NO efectiva
{
	int retorno = -1;
	int aux;
	int i;
	int j;
	int contador = 0;

	 if (array != NULL && tamanio >= 0){

		 for (i = 0; i < tamanio - 1; i++)
		   {
			 for (j = i + 1; j < tamanio; j++)
				{
				 	 contador++;

				 	 if (array[i] > array[j])
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

int ordenamientoArrayDecendente (int array[], int tamanio)// forma NO efectiva
{
	int retorno = -1;
	int aux;
	int i;
	int j;
	int contador = 0;

	 if (array != NULL && tamanio >= 0 )
	 {
		 for (i = 0; i < tamanio - 1; i++)
		   {
			 for (j = i + 1; j < tamanio; j++)
				{
				 	 contador++;

				 	 if (array[i] < array[j])
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

void insertionAscendente(int array[],int tamanio) // ordenamiento efectivo por insercion MENOR A MAYOR
{
	int i,j;
	int temp;

	for(i=1;i<tamanio;i++){

		temp = array[i];
		j=i-1;

	while(temp<array[j] && j>=0) // temp<array[j] o temp>array[j]
	{
		array[j+1] = array[j];
		j--;}

		array[j+1]=temp; // inserción
	}
}

void insertionDecendente(int array[],int tamanio) // ordenamiento efectivo por insercion MAYOR A MENOR
{
	int i,j;
	int temp;

	for(i=1;i<tamanio;i++){

		temp = array[i];
		j=i-1;

	while(temp>array[j] && j>=0) // temp<array[j] o temp>array[j]
	{
		array[j+1] = array[j];
		j--;}

		array[j+1]=temp; // inserción
	}
}

int mostrarArrayAscendente (int array[], int tamanio)
{
int	retorno = -1;

if (array != NULL && tamanio >= 0){

	for (int i = 0; i < tamanio; i++)
		{
			printf ("\norden en posicion ascendente: posicion %d, elemento %d", i,

					array [i]);
		}
	retorno = 0;
}
return retorno;
}

int mostrarArrayDecendente (int array[], int tamanio)
{
int	retorno = -1;

if (array != NULL && tamanio >= 0){

	for (int i = 0; i < tamanio; i++)
	{

		 printf ("\norden en posicion descendente: posicion %d, elemento %d", i,

		  array [i]);
	}

	  retorno = 0;
}
return retorno;
}

int promedioArray (int array[], int tamanio , float* pResultadoPromedio)
{
	int retorno = -1;
    int i;
    int acumArray = 0;

    if (array != NULL && tamanio >0 && pResultadoPromedio != NULL ){

        for (i= 0; i< tamanio ; i++){

        acumArray+= array [i];
        }

        *pResultadoPromedio = (float) acumArray/ tamanio;
    }
     retorno = 0;

    return retorno;
}

int buscarLibre(char espacio[], int tamanio, int* lugar) // Busca un lugar en -1 DEVUELVE la posicion
{

	int retorno = -1;

		if (espacio != NULL && tamanio>0 && lugar != NULL){
			for(int i= 0; i<tamanio;i++){

					if (espacio[i]==-1)
						{
							*lugar = i;
							retorno = 0;
							break;
						}
		}

	}
	return retorno;
}

/**
 * \brief Solicita una palabra al usuario, luego de verificarlo devuelve el resultado
 * \param array Es el puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje que pide el dato
 * \param mensajeError Es el mensaje de Error
 * \param minimo Es el numero maximo aceptado
 * \param maximo Es el minimo minimo aceptado
 * \return Retorna 0 si fue EXITOSA  o -1 en caso de ERROR
 *
 */
int utn_getNombre(char array [], int tamanio, char* mensaje, char* mensajeError, int reintentos )
{
	int retorno = -1;
	char buffer [tamanio];

	if (array != NULL && tamanio >0 &&  mensaje != NULL &&  mensajeError != NULL && reintentos>= 0){

		do{
				printf ("%s", mensaje);
				if (getNombre (buffer, tamanio) == 0){

					retorno = 0;
					strcpy(array,buffer);
					break;

					}
				else{
					printf ("%s", mensajeError);
					reintentos --;
				}

			}while(reintentos >= 0);

	}

	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es de caracteres
 *\param array Array de  a ser validado
 *\param tamanio limite del array
 * \return Retorna 1 (EXITO) si son todos son caracteres , 0 en el caso de ERROR y -1 si no se cumple la funcion
 */
static int esNombre (char array [], int tamanio)
{
	int retorno = -1;
	int i;

	if (array != NULL && tamanio > 0){

		for (i = 0; i < tamanio && array [i] != 0; i++){

			array [i] = tolower(array [i]); // pasa el array a minusculas

			retorno = 1;

			if (array [i] < 'a' || array [i] > 'z'){

				retorno = 0; // ERROR
				break;
			} // FIN DEL IF
		} // FIN DEL FOR
	} // FIN VALIDACION

	return retorno;
}

/**
 * \brief  Obtiene un array de caracteres validado
 *\param array Array de  a ser validado
 *\param tamanio limite del array
 * \return Retorna 0 (EXITO) si logro convertirlo a caracteres y -1 (ERROR)
 */

static int getNombre (char pResultado [], int tamanio)
{
	int retorno = -1;
	char buffer [tamanio];

	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0 && esNombre(buffer,sizeof(buffer))>0) // osea si se cumple la fx y me devuelve un verdadero
			{
				strcpy(pResultado,buffer);
				retorno = 0;
			}
	return retorno;
}
