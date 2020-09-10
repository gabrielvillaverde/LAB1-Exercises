/*
 ============================================================================
Pedirle al usuario 5 edades y luego imprimir las 5 edades.
Definir un array de 5 posiciones y usar la función getNumero() para pedir los valores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define EDADESSIZE 5 // Tamaño de las edades

int main(void)
{
	setbuf(stdout,NULL); // Windows

	int edad;
	int edades[EDADESSIZE];  // Asigno el tamaño del array con el define de la línea 12
	int i; // Variable i para mi bucle for

	// Recorro para cargar en forma secuencial
	for(i = 0; i<EDADESSIZE; i++)
	{
		if(utn_getNumero(&edad, "Ingrese edad:", "Esta edad no va\n", 1, 120, 3)==0) //Si la función es igual a 0, significa que respondió bien.
		{
			// printf("La edad ingresada es: %d\n", edad);
			// En edades escribo edad en la posición "i"
			edades[i] = edad; // Guardo la variable edad en la posición i
		}
		else
		{
			printf("ERROR, eso ni siquiera una edad numérica");
		}
	}

	// Recorro para imprimir
	for(i = 0; i<EDADESSIZE; i++) // Necesito recorrer nuevamente el bucle para imprimirlo
	{
		printf("%d ", edades[i]);
	}

	return EXIT_SUCCESS;
}
