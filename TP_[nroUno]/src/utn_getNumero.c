/*
 * utn_getNumero.c
 *
 *  Created on: 12 abr 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
	{
		do{
			printf("%s", mensaje); // cualquier tipo de string en el msj
			scanf ("%d", &bufferInt);// guardamos la respuesta en el buffer
			if (bufferInt >= minimo && bufferInt <= maximo)
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
			scanf ("%f", &bufferFloat);// guardamos la respuesta en el buffer
			if (bufferFloat >= minimo && bufferFloat <= maximo)
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

void imprimirResultado (int kms ,float precio1, float formaDePago1,float formaDePago2,float formaDePago3,float formaDePago4,float precio2, float formaDePago5, float formaDePago6, float formaDePago7, float formaDePago8,  float diffDePago)
{

	if (kms >0 && precio1>0 &&formaDePago1 > 0 && formaDePago2 > 0 && formaDePago3 > 0 && formaDePago4 > 0 &&  precio2>0 && formaDePago5 > 0 && formaDePago6 > 0 && formaDePago7 > 0 && formaDePago8 > 0 && diffDePago >0){

						printf("KMs Ingresados: %d KM \n\n"
							"Precio Aerolineas: $ %.2f\n"
							"a) Precio con tarjeta de debito: $ %.2f \n"
							"b) Precio con tarjeta de credito: $ %.2f \n"
							"c) Precio pagado con bitcoin: %.2f BTC \n"
							"d) Mostrar precio unitario : $ %.2f \n\n"
							"Precio Latam: $ %.2f \n"
							"a) Precio con tarjeta de debito: $ %.2f \n"
							"b) Precio con tarjeta de credito: $ %.2f \n"
							"c) Precio pagado con bitcoin: %.2f BTC \n"
							"d) Mostrar precio unitario : $ %.2f \n\n\n"
							"La diferencia de precios es: $ %.2f", kms, precio1, formaDePago1, formaDePago2, formaDePago3, formaDePago4, precio2,formaDePago5, formaDePago6, formaDePago7, formaDePago8, diffDePago);

	}

}

