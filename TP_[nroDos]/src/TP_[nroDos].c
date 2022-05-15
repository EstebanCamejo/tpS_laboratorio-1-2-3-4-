/*
 ============================================================================
 Name        : TP_[nroDos].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "estructura.h"
#include "UTN.h"

#define TAM 3
#define LENNAME 51
#define LENCODE 10

int main(void) {
	setbuf(stdout, NULL);


	ePassenger aPassenger [TAM];

	int option;
	int id = 1;
	int espacioLibre;
	int flagAlta = 0;
	int auxId;
	int auxIndice;

	if (initPassengers (aPassenger, TAM) == 0){
		 // ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
		//número de Id. El resto de los campos se le pedirá al usuario.
		do {
			if(utn_getNumero(&option,"\n\n \t *** INGRESO DE PASAJEROS *** \n\nPor favor ingrese una opcion: \n\n"

				"1) Altas. \n"
		 		"2) Modificar.\n"
				"3) Baja.\n"
				"4) informar.\n"
				"5) SALIR. \n",
				"ERROR opcion incorrecta \n",1,5,3)==0){

					switch (option)
					{
					case 1: // ALTA
						if ( buscarEmptyLibre(aPassenger, TAM, & espacioLibre) == 0 &&
						addPassengers (aPassenger,TAM,espacioLibre, &id) == 0)
						{
							printf("Carga realizada con EXITO");
							flagAlta = 1;
						}
						else
						{
							printf("ERROR");
						}

						break;
					case 2: // MODIFICAR

						if( flagAlta == 1 && printPassenger(aPassenger, TAM) == 0 &&
							utn_getNumero(&auxId,"\nIngrese el id del pasajero que desea modificar.\n",
							"\nError \n",1,5,2) == 0  && findPassengerById(aPassenger,TAM,auxId,&auxIndice)== 0)
						{
							// fx para imprimir un solo pa
							passengerPrint(aPassenger[auxIndice]);
							passenger_modificarMenu(&aPassenger[auxIndice],LENNAME);
						}

						break;
					case 3:

						if(flagAlta == 1 && printPassenger(aPassenger, TAM) == 0 && utn_getNumero(&auxId,
						"\nIngrese el id del pasajero que desea dar de baja.\n","\nError \n",1,5,2) == 0 &&
						findPassengerById(aPassenger,TAM ,auxId,&auxIndice) == 0 && removePassenger(&aPassenger[auxIndice]) ==0)
						{
							printf("Baja exitosa");
						}
						else{

							printf("ERROR. La baja no pudo realizarse con exito");
						}

						break;
					case 4: // INFORMAR
			 				if (flagAlta == 1 && sortPassengers(aPassenger,TAM) == 0)
							{
								printPassenger(aPassenger,TAM);
							}

						break;
					}
			} // FIN DEL MENU

		} while (option !=5 );
	} // FIN DEL IF INICIAL


	return EXIT_SUCCESS;
}
