#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "UTN.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int flagAlta = 0;
    int flagGuardar = 0;
    setbuf(stdout, NULL);
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	if(utn_getNumero(&option,"\n\n \t *** INGRESO DE PASAJEROS *** \n\nPor favor ingrese una opcion: \n\n"

    					"1) Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n"
    			 		"2) Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
    					"3) Alta de pasajero.\n"
    					"4) Modificar datos de pasajero.\n"
    					"5) Baja de pasajero. \n"
						"6) Listar pasajeros. \n"
						"7) Ordenar pasajeros. \n"
						"8) Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n"
						"9) Guardar los datos de los pasajeros en el archivo data.csv (modo binario). \n"
						"10) Salir. \n",
    					"\n**ERROR!! Opcion incorrecta** \nPor favor elegir algunas de las opciones del menu.\n",1,10,3)==0){

			switch(option)
			{
				case 1:
					controller_loadFromText("data.csv",listaPasajeros);
					flagAlta = 1;
					break;

				case 2 :
					controller_loadFromBinary("data.bin",listaPasajeros);
					flagAlta = 1;
					break;

				case 3 :
					if (controller_addPassenger("data.csv",listaPasajeros))
					{
						flagAlta = 1;
					}
					break;

				case 4 :
					if (flagAlta == 1)
					{
						controller_editPassenger(listaPasajeros);
					}
					else {
						printf ("\n\nPara realizar alguna modificacion primero debe realizar al menos un alta.");
					}
					break;

				case 5 :
					if (flagAlta == 1)
					{
						controller_removePassenger(listaPasajeros);
					}
					else {
						printf ("\n\nPara realizar alguna baja primero debe realizar al menos un alta.");
					}
					break;

				case 6 :
					if (flagAlta == 1)
					{
						controller_ListPassenger(listaPasajeros);
					}
					else {
						printf ("\n\nPara visualizar el listado de pasajeros primero debe realizar al menos un alta.");
					}
					break;

				case 7 :
					if (flagAlta == 1)
					{
						controller_sortPassenger(listaPasajeros);
					}
					else{
						printf ("\n\nPara visualizar el listado de pasajeros ordenado primero debe realizar al menos un alta.");
					}

					break;

				case 8 :
					if(controller_saveAsText("data.csv",listaPasajeros))
					{
						printf ("\n\nEl archivo en modo texto se guardo correctamente.");
						flagGuardar = 1;
					}

					break;

				case 9 :
					if (controller_saveAsBinary("data.bin",listaPasajeros))
					{
						printf ("\n\nEl archivo en modo binario se guardo correctamente.");
						flagGuardar = 1;
					}
					break;

				case 10 :
					if(flagGuardar == 1)
					{
						printf ("\n*** EL PROGRAMA HA FINALIZADO ***.");
						option = 666;
					}
					else
					{
						printf ("\n*** Para poder SALIR del programa primero tiene que guardar los datos***"
								"\n\n ingrese en la opcion 8 o 9 del menu principal");
					}
					break;

			}// FIN DEL SWITCH
    	}// FIN DEL MENU
    }while(option != 666);
    ll_deleteLinkedList(listaPasajeros);
    return 0;
}

