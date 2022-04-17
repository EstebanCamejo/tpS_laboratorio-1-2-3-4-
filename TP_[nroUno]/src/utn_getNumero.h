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
//Esta función la uso para llamar al menú.
//Al ser una función del tipo INT lo que hago es usarla pidiéndole un valor de retorno de “0” para confirmar que la operación fue exitosa y  un valor de  -“1” para informar que hubo un error.
//Le envío la dirección de una variable del tipo INT para que me escriba el resultado que voy a buscar. Después de eso le envío un mensaje dentro de una variable del tipo char que es la que utilizo para comunicarme con el usuario. Separado de esta envío de la misma forma un mensaje de error que será utilizado en el caso que sea necesario.
//Ademas envían dos variables del tipo int donde se encuentran los valores del mínimo y el máximo estableciendo el rango en el que la función va a validar los resultados.
//Por ultimo se envia el valor de la cantidad de reintentos posibles para que el usuario complete la acción.
//Si la función tiene éxito (ósea devuelve un 0) ingresa a la siguiente sección del código. (Switch)
//Después vuelvo a utilizar esta misma función para validar los datos del case 1

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
//Al ser una función del tipo INT lo que hago es usarla pidiéndole un valor de retorno de 0 para confirmar que la operación fue exitosa
//y  un valor de  “-1 “ para informar que hubo un error.
//La utilizo para validar y obtener resultados de datos del tipo flotante.
//Le envío la dirección de una variable del tipo INT para que me escriba el resultado que voy a buscar.
//Después de eso le envío un mensaje dentro de una variable del tipo char que es la que utilizo para comunicarme con el usuario.
//Separado de esta envío de la misma forma un mensaje de error que será utilizado en el caso que sea necesario.
//Además envían dos variables del tipo int donde se encuentran los valores del mínimo y
//el máximo estableciendo el rango en el que la función va a validar los resultados.
//Por último se envia el valor de la cantidad de reintentos posibles para que el usuario complete la acción.

int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);


int calculoDescuento(float* resultadoDescuento, float precio, float descuento);
//Al ser una función del tipo INT lo que hago es usarla pidiéndole un valor de retorno de 0 para confirmar que la operación fue exitosa
//y  un valor de  “-1 “ para informar que hubo un error.
//Le envío la dirección de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Después de eso le envío dos variables del tipo FLOAT  que contienen la información para realizar el cálculo.
//En este caso es un descuento que se resta del resultado final le envío el precio total y el tipo de descuento a aplicar.

int calculoInteres(float* resultadoInteres, float precio, float interes);
//Al ser una función del tipo INT lo que hago es usarla pidiéndole un valor de retorno de 0 para confirmar que la operación fue exitosa
//y  un valor de  “-1 “ para informar que hubo un error.
//Le envío la dirección de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Después de eso le envío dos variables del tipo FLOAT  que contienen la información para realizar el cálculo.
//En este caso es para aplicar un  interés que se suma al resultado final, asique envío el precio total
//y el tipo de interés que debo aplicar.

int calculoBitcoin(float* resultadoBitcoin, float precio, float bitcoin);
//Al ser una función del tipo INT lo que hago es usarla pidiéndole un valor de retorno de 0 para confirmar que la operación fue exitosa
//y  un valor de  “-1 “ para informar que hubo un error.
//Le envío la dirección de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Después de eso le envío dos variables del tipo FLOAT  que contienen la información para realizar el cálculo.
//En este caso como es para aplicar el tipo de cambio de una moneda le envío el precio total en pesos
//y lo divido por el valor de cambio equivalente en pesos de la moneda en cuestión.

int calculoDivision(float* resultadoDivision,float operador1, float operador2);
//Al ser una función del tipo INT lo que hago es usarla pidiéndole un valor de retorno de 0 para confirmar que la operación fue exitosa y
//un valor de  “-1 “ para informar que hubo un error.
//Le envío la dirección de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Después de eso le envío dos variables del tipo FLOAT  que contienen la información para realizar el cálculo.
//Y luego realizo  la división.

int calculoDiferencia(float* resuladoDiferencia, float operador1, float operador2);
//Al ser una función del tipo INT lo que hago es usarla pidiéndole un valor de retorno de 0 para confirmar que la operación fue exitosa
//y  un valor de  “-1 “ para informar que hubo un error.
//Le envío la dirección de una variable del tipo FLOAT para que me escriba el resultado que voy a buscar.
//Después de eso le envío dos variables del tipo FLOAT  que contienen la información para realizar el cálculo.
//Y luego realizo la resta

void imprimirResultado (int kms ,float precio1, float formaDePago1,float formaDePago2,float formaDePago3,float formaDePago4,float precio2, float formaDePago5, float formaDePago6, float formaDePago7, float formaDePago8,  float diffDePago);
//Al ser una variable del tipo VOID no retorna un tipo de resultado que valide la acción.
//En este caso la utilice para poder mostrar al usuario los resultados de cada una de las operaciones que realizo en cada uno de los casos
//donde ingreso la información solicitada.
//Le envié toda la información de cada una de las variables  utilizadas según el tipo ,
//previamente escaneadas en cada paso para que cuando se imprima quede tal y como se solicita en el enunciado del trabajo practico.

#endif /* UTN_GETNUMERO_H_ */
