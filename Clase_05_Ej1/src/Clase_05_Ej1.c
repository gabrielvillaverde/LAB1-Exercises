/*
 ============================================================================
Pedir la edad a trav�s de la funci�n getNumero
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

// La funci�n utn_getNumero devuelve 0 si sali� bien.
// La funci�n utn_getNumero devuelve 1 si sali� mal.

int main(void)
{
	setbuf(stdout,NULL);
	int edad;

	if(utn_getNumero(&edad, "Ingrese edad:", "Esta edad no va\n", 1, 120, 3)==0) //Si la funci�n es igual a 0, significa que respondi� bien.
	{
		printf("La edad ingresada es: %d\n", edad);
	}
	else
	{
		printf("ERROR, eso no es ni siquiera una edad num�rica");
	}

	return EXIT_SUCCESS;
}
