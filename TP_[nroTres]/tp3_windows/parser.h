
/*
 * brief parser_PassengerFromText
 * Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 * param pFile direccion de memoria del archivo
 * param pArrayListPassenger puntero a el listado de paxs
 * retorna un verdadero si funciona o en caso contrario un falso (0).
 * */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
/*
 * brief parser_PassengerFromBinary
 * Parsea los datos los datos de los pasajeros desde el archivo data(modo binario)
 * param pFile direccion de memoria del archivo
 * param pArrayListPassenger puntero a el listado de paxs
 * retorna un verdadero si funciona o en caso contrario un falso (0).
 * */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
