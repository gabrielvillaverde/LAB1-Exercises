/*
 ============================================================================
Pedirle al usuario 5 edades y luego imprimir las 5 edades.
Definir un array de 5 posiciones y usar la funci�n getNumero() para pedir los valores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define EDADESSIZE 5 // Tama�o de las edades

int main(void)
{
	setbuf(stdout,NULL); // Windows

	int edad;
	int edades[EDADESSIZE];  // Asigno el tama�o del array con el define de la l�nea 12
	int i; // Variable i para mi bucle for

	// Recorro para cargar en forma secuencial
	for(i = 0; i<EDADESSIZE; i++)
	{
		if(utn_getNumero(&edad, "Ingrese edad:", "Esta edad no va\n", 1, 120, 3)==0) //Si la funci�n es igual a 0, significa que respondi� bien.
		{
			// printf("La edad ingresada es: %d\n", edad);
			// En edades escribo edad en la posici�n "i"
			edades[i] = edad; // Guardo la variable edad en la posici�n i
		}
		else
		{
			printf("ERROR, eso ni siquiera una edad num�rica");
		}
	}

	// Recorro para imprimir
	for(i = 0; i<EDADESSIZE; i++) // Necesito recorrer nuevamente el bucle para imprimirlo
	{
		printf("%d ", edades[i]);
	}

	return EXIT_SUCCESS;
}
