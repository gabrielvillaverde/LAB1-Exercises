/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int* pEdad;

	pEdad = (int*) malloc(sizeof(int));

	if(pEdad != NULL)
	{
		*pEdad = 24;
	}

	// Array de edades

	int* pArrayEdades;
	int* pArrayEdadesAuxiliar;
	int sizeArrayEdades = 100;

	pArrayEdades = (int*) malloc(sizeof(int) * sizeArrayEdades); // No usamos un define porque es estático.

	if(pArrayEdades != NULL)
	{
		// Inicializo todas las posiciones del array en 0.
		for(int i = 0 ; i < sizeArrayEdades ; i++)
		{
			// Dos opciones:
			pArrayEdades[i] = 0; // Modo Disney
			// *(pArrayEdades+i) = 0;
		}
	}

	// Realloc

	sizeArrayEdades = 200;
	pArrayEdadesAuxiliar = realloc(pArrayEdades, sizeof(int) * sizeArrayEdades);
	if(pArrayEdadesAuxiliar != NULL) // Si el auxiliar recibe algo distinto a NULL.
	{
		pArrayEdades = pArrayEdadesAuxiliar; // Guardo lo que tiene pArrayEdadesAuxiliar a pArrayEdades.
		pArrayEdadesAuxiliar = NULL; // Hora 08:59 de clase aprox.
	}
	else
	{
		// Informo el error
	}

	// Si quiero liberar espacio de memoria dinámica
	free(pArrayEdades);

	return EXIT_SUCCESS;
}

int * crearArrayInt (int cantidad)
{
	int* pArray;
	pArray = (int*) malloc(sizeof(int) * cantidad); // No usamos un define porque es estático.

	if(pArray != NULL)
	{
		// Inicializo todas las posiciones del array en 0.
		for(int i = 0 ; i < cantidad ; i++)
		{
			// Dos opciones:
			pArray[i] = 0; // Modo Disney
			// *(pArrayEdades+i) = 0;
		}
	}
	return pArray;
}

int * newArrayInt (int cantidad, int valorInit)
{
	int* pArray;
	pArray = (int*) malloc(sizeof(int) * cantidad); // No usamos un define porque es estático.

	if(pArray != NULL)
	{
		// Inicializo todas las posiciones del array en 0.
		for(int i = 0 ; i < cantidad ; i++)
		{
			// Dos opciones:
			pArray[i] = valorInit; // Modo Disney
			// *(pArrayEdades+i) = valorInit;
		}
	}
	return pArray;
}

int * resizeArrayInt (int * pArray, int cantidad)
{
	int* pArrayAuxiliar;
	pArrayAuxiliar = (int*) realloc(pArray, sizeof(int) * cantidad);
	return pArrayAuxiliar;
}
