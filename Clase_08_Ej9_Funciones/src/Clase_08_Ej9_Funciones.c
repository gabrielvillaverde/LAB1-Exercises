/*
 ============================================================================
Actualización de funciones como myGets, fgets, getInt, esNumerica, utn_getNumero, etcétera.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/*
// Primera prueba: comprobamos que myGets funcione, y pedimos un nombre.
int main(void) {

	setbuf(stdout,NULL);

	char nombre[50];

	printf("Ingrese un nombre:");

	if(myGets(nombre,sizeof(nombre)) == 0) // Si esta función nos devuelve 0, está todo bien.
	{
		printf("\nEl nombre es: %s",nombre);
	}
	return EXIT_SUCCESS;
}
*/

// Segunda prueba: comprobamos que getNumero funcione, pedimos una edad.
int main(void) {

	setbuf(stdout,NULL);

	int edad;

	if(utn_getNumero(&edad, "\nIngrese una edad", "\nError. Ingrese una edad entre 0 y 200", 0, 200, 2) == 0)
	{
		printf("\nLa edad es: %d",edad);
	}

	return EXIT_SUCCESS;
}
