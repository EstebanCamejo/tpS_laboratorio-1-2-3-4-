/*
 * utn_getNumero.h
 *
 *  Created on: 12 abr 2022
 *      Author: Usuario
 */
#ifndef UTN_GETNUMERO_H_
#define UTN_GETNUMERO_H_

//
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);//menu OK
//Esta funci�n la uso para llamar al men�.
//Al ser una funci�n del tipo INT lo que hago es usarla pidi�ndole un valor de retorno de �0� para confirmar que la operaci�n fue exitosa y  un valor de  -�1� para informar que hubo un error.
//Le env�o la direcci�n de una variable del tipo INT para que me escriba el resultado que voy a buscar. Despu�s de eso le env�o un mensaje dentro de una variable del tipo char que es la que utilizo para comunicarme con el usuario. Separado de esta env�o de la misma forma un mensaje de error que ser� utilizado en el caso que sea necesario.
//Ademas env�an dos variables del tipo int donde se encuentran los valores del m�nimo y el m�ximo estableciendo el rango en el que la funci�n va a validar los resultados.
//Por ultimo se envia el valor de la cantidad de reintentos posibles para que el usuario complete la acci�n.
//Si la funci�n tiene �xito (�sea devuelve un 0) ingresa a la siguiente secci�n del c�digo. (Switch)
//Despu�s vuelvo a utilizar esta misma funci�n para validar los datos del case 1

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
//Al ser una funci�n del tipo INT lo que hago es usarla pidi�ndole un valor de retorno de 0 para confirmar que la operaci�n fue exitosa
//y  un valor de  �-1 � para informar que hubo un error.
//La utilizo para validar y obtener resultados de datos del tipo flotante.
//Le env�o la direcci�n de una variable del tipo INT para que me escriba el resultado que voy a buscar.
//Despu�s de eso le env�o un mensaje dentro de una variable del tipo char que es la que utilizo para comunicarme con el usuario.
//Separado de esta env�o de la misma forma un mensaje de error que ser� utilizado en el caso que sea necesario.
//Adem�s env�an dos variables del tipo int donde se encuentran los valores del m�nimo y
//el m�ximo estableciendo el rango en el que la funci�n va a validar los resultados.
//Por �ltimo se envia el valor de la cantidad de reintentos posibles para que el usuario complete la acci�n.

int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);


int calculoDescuento(float* resultadoDescuento, float precio, float descuento);
//Al ser una funci�n del tipo INT lo que hago es usarla pidi�ndole un valor de retorno de 0 para confirmar que la operaci�n fue exitosa
//y  un valor de  �-1 � para informar que hubo un error.
//Le env�o la direcci�n de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Despu�s de eso le env�o dos variables del tipo FLOAT  que contienen la informaci�n para realizar el c�lculo.
//En este caso es un descuento que se resta del resultado final le env�o el precio total y el tipo de descuento a aplicar.

int calculoInteres(float* resultadoInteres, float precio, float interes);
//Al ser una funci�n del tipo INT lo que hago es usarla pidi�ndole un valor de retorno de 0 para confirmar que la operaci�n fue exitosa
//y  un valor de  �-1 � para informar que hubo un error.
//Le env�o la direcci�n de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Despu�s de eso le env�o dos variables del tipo FLOAT  que contienen la informaci�n para realizar el c�lculo.
//En este caso es para aplicar un  inter�s que se suma al resultado final, asique env�o el precio total
//y el tipo de inter�s que debo aplicar.

int calculoBitcoin(float* resultadoBitcoin, float precio, float bitcoin);
//Al ser una funci�n del tipo INT lo que hago es usarla pidi�ndole un valor de retorno de 0 para confirmar que la operaci�n fue exitosa
//y  un valor de  �-1 � para informar que hubo un error.
//Le env�o la direcci�n de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Despu�s de eso le env�o dos variables del tipo FLOAT  que contienen la informaci�n para realizar el c�lculo.
//En este caso como es para aplicar el tipo de cambio de una moneda le env�o el precio total en pesos
//y lo divido por el valor de cambio equivalente en pesos de la moneda en cuesti�n.

int calculoDivision(float* resultadoDivision,float operador1, float operador2);
//Al ser una funci�n del tipo INT lo que hago es usarla pidi�ndole un valor de retorno de 0 para confirmar que la operaci�n fue exitosa y
//un valor de  �-1 � para informar que hubo un error.
//Le env�o la direcci�n de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Despu�s de eso le env�o dos variables del tipo FLOAT  que contienen la informaci�n para realizar el c�lculo.
//Y luego realizo  la divisi�n.

int calculoDiferencia(float* resuladoDiferencia, float operador1, float operador2);
//Al ser una funci�n del tipo INT lo que hago es usarla pidi�ndole un valor de retorno de 0 para confirmar que la operaci�n fue exitosa
//y  un valor de  �-1 � para informar que hubo un error.
//Le env�o la direcci�n de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Despu�s de eso le env�o dos variables del tipo FLOAT  que contienen la informaci�n para realizar el c�lculo.
//Y luego realizo la resta

void imprimirResultado (int kms ,float precio1, float formaDePago1,float formaDePago2,float formaDePago3,float formaDePago4,float precio2, float formaDePago5, float formaDePago6, float formaDePago7, float formaDePago8,  float diffDePago);
//Al ser una variable del tipo VOID no retorna un tipo de resultado que valide la acci�n.
//En este caso la utilice para poder mostrar al usuario los resultados de cada una de las operaciones que realizo en cada uno de los casos
//donde ingreso la informaci�n solicitada.
//Le envi� toda la informaci�n de cada una de las variables  utilizadas seg�n el tipo ,
//previamente escaneadas en cada paso para que cuando se imprima quede tal y como se solicita en el enunciado del trabajo practico.

#endif /* UTN_GETNUMERO_H_ */
