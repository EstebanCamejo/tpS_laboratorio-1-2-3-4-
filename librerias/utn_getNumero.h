/*
 * utn_getNumero.h
 *
 *  Created on: 12 abr 2022
 *      Author: Usuario
 */
#ifndef UTN_GETNUMERO_H_
#define UTN_GETNUMERO_H_


//


int myGets (char* cadena, int tamanio);



int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);//menu OK

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);





int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int calculoDescuento(float* resultadoDescuento, float precio, float descuento);

int calculoInteres(float* resultadoInteres, float precio, float interes);

int calculoBitcoin(float* resultadoBitcoin, float precio, float bitcoin);

int calculoDivision(float* resultadoDivision,float operador1, float operador2);

int calculoDiferencia(float* resuladoDiferencia, float operador1, float operador2);




int inicializarArray (int array[], int tamanio);	//OK a -1

int inicializarArrayChar (char array[], int tamanio);

int inicializarArrayString (char array [][100], int tamanioFila , int tamanioColumna);/// en el segundo [] se inicializa pasandole el tamanio del string REVISAR

int inicializarArrayFloat (float array[], int tamanio);



int maximoArray (int array[], int tam, int* maximo); //FALTA

int minimoArray (int array[], int tam, int* minimo); //FALTA


// ordenamiento
int ordenamientoArrayEfectivoDecendente(int array[], int tamanio); //EFECTIVA

int ordenamientoArrayEfectivoAscendente(int array[], int tamanio); //EFECTIVA


int ordenamientoArrayAscendente (int array[], int tamanio); // NO efectiva 2 for

int ordenamientoArrayDecendente (int array[], int tamanio); // NO efectiva 2 for

void insertionAscendente(int array[],int tamanio);

void insertionDecendente(int array[],int tamanio);


int mostrarArrayDecendente (int array[], int tamanio);

int mostrarArrayAscendente (int array[], int tamanio);

int promedioArray (int array[], int tamanio , float* pResultadoPromedio);


//
int buscarLibre(char espacio[], int tamanio, int* lugar);



int utn_getNombre(char array [], int tamanio, char* mensaje, char* mensajeError, int reintentos );



#endif /* UTN_GETNUMERO_H_ */
