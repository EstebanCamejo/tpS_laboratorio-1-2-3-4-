/*
 * utn_getNumero.c
 *
 *  Created on: 12 abr 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>

int utnTP1calculo (char* pResultado, float operador1, float operador2, float operador3)
			{

				char resultado;
				int retorno = -1;

				float tarjetaDebitoOP2;// a) Tarjeta de débito (descuento 10%)
				float tarjetaCreditoOP2;// b) Tarjeta de crédito (interés 25%)
				float btcOP2;// c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
				float precioKmOP2;

				float tarjetaDebitoOP1;// a) Tarjeta de débito (descuento 10%)
				float tarjetaCreditoOP1;// b) Tarjeta de crédito (interés 25%)
				float btcOP1;// c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
				float precioKmOP1;// d) Mostrar precio por km (precio unitario)

				float diffAerolineas;// e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

											// latam     Aerolines       KMs
				if (pResultado != NULL && operador1 >= 0, operador2 >= 0 , operador3 > 0 )
				{	// Aerolineas
					tarjetaDebitoOP1 = operador1 * 0.9;
					tarjetaCreditoOP1 = operador1 * 1.25;
					btcOP1 = operador1/4606954.55;
					precioKmOP1 = operador1/ operador3;
					// Latam
					tarjetaDebitoOP2 = operador2 * 0.9;
					tarjetaCreditoOP2 = operador2 * 1.25;
					btcOP2 = operador2/4606954.55;
					precioKmOP2 = operador2/ operador3;
					 if (operador1 > operador2){
						 diffAerolineas = operador1 - operador2;					 }
					 else {
						 diffAerolineas = operador2 - operador1;
					 }
					resultado = pintf(
								 "KMs Ingresados: %f KM \n\nPrecio Aerolineas: $ %f\n a) Precio con tarjeta de debito: $ %f \n b) Precio con tarjeta de credito: $ %f \n c) Precio pagado con bitcoin: %f BTC \n d) Mostrar precio unitario : $ %f \n\nPrecio Latam: $ %f \n a) Precio con tarjeta de debito: $ %f \n b) Precio con tarjeta de credito: $ %f \n c) Precio pagado con bitcoin: %f BTC \n d) Mostrar precio unitario : $ %f \n\nLa diferencia de precios es: $ %f",
								 operador3, operador2,tarjetaDebitoOP2,tarjetaCreditoOP2,precioKmOP2,operador1,tarjetaDebitoOP1,tarjetaCreditoOP1,precioKmOP1,diffAerolineas
						 	 	 );
					*pResultado = resultado;
					retorno = 0;
				} // final del IF

				return retorno;
			} // final de la fx




int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
	{
		do{
			printf("%s", mensaje);// cualquier tipo de string en el msj
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

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
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
