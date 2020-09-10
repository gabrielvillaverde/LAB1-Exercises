/*
 ============================================================================
Pedir la edad a través de la función getNumero
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

// La función utn_getNumero devuelve 0 si salió bien.
// La función utn_getNumero devuelve 1 si salió mal.

int main(void)
{
	setbuf(stdout,NULL);
	int edad;

	if(utn_getNumero(&edad, "Ingrese edad:", "Esta edad no va\n", 1, 120, 3)==0) //Si la función es igual a 0, significa que respondió bien.
	{
		printf("La edad ingresada es: %d\n", edad);
	}
	else
	{
		printf("ERROR, eso no es ni siquiera una edad numérica");
	}

	return EXIT_SUCCESS;
}
