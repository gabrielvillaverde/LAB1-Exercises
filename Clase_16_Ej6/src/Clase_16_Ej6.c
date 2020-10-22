/*
 ============================================================================

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int initArray(int * pArray, int limite, int valorInicial)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		retorno = 0;
		for(int i = 0 ; i < limite ; i++)
		{
			*(pArray+i) = valorInicial; // Algebra de punteros
			// Modo Disney: pArray[i] = 0;
		}
	}
	return retorno;
}

int imprimirArray(int * pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		retorno = 0;
		for(int i = 0 ; i < limite ; i++)
		{
			printf("%d\n", *(pArray+i));
		}
	}
	return retorno;
}

// Explicación, minuto 1:39:00 VIDEO CLASE 16

// int ** pArray significa que estoy recibiendo el puntero de una variable del tipo puntero
int resizeArray(int ** pArray, int * sizeActual, int sizeNuevo)
{
	int retorno = -1;
	int * pArrayTemp = NULL;

	if(pArray != NULL && sizeActual != NULL && sizeNuevo >= 0)
	{
		pArrayTemp = (int *) realloc(*pArray, sizeof(int) * sizeNuevo);
		if(pArrayTemp != NULL) // Si lo que me devolvió es distinto de NULL, es porque realloc consiguió más lugares..
		{
			*sizeActual = sizeNuevo;
			*pArray = pArrayTemp;
			pArrayTemp = NULL;
			retorno = 0;
		}
	}
	return retorno;
}

// Explicación, minuto 1:50:00 VIDEO CLASE 16

// Función que da error, no le paso el doble puntero
int resizeArrayError(int * pArray, int * sizeActual, int sizeNuevo)
{
	int retorno = -1;
	int * pArrayTemp = NULL;

	if(pArray != NULL && sizeActual != NULL && sizeNuevo >= 0)
	{
		pArrayTemp = (int *) realloc(pArray, sizeof(int) * sizeNuevo);
		if(pArrayTemp != NULL) // Si lo que me devolvió es distinto de NULL, es porque realloc consiguió más lugares..
		{
			*sizeActual = sizeNuevo;
			pArray = pArrayTemp;
			pArrayTemp = NULL;
			retorno = 0;
		}
	}
	return retorno;
}

int main(void)
{
	int * pArrayEdades = NULL;
	int sizeArrayEdades = 10;
	int * pArrayTemp = NULL; // Para escribir realloc acá.

	pArrayEdades = (int *) malloc (sizeof(int) * sizeArrayEdades);
	if(pArrayEdades != NULL)
	{
		// Todo OK.
		if(initArray(pArrayEdades, sizeArrayEdades, 0) == 0) // Si initArray me devuelve 0...
		{
			printf("\nArray inicializado correctamente con 10 posiciones.\n");
			imprimirArray(pArrayEdades, sizeArrayEdades);
		}
		pArrayTemp = (int *) realloc(pArrayEdades, sizeof(int) * (sizeArrayEdades+50));
		if(pArrayTemp != NULL) // Si lo que me devolvió es distinto de NULL, es porque realloc consiguió 50 lugares más.
		{
			sizeArrayEdades = sizeArrayEdades + 50;
			pArrayEdades = pArrayTemp;
		}
		if(resizeArray(&pArrayEdades, &sizeArrayEdades, 25) == 0)
		{
			printf("\nResize del array hecho correctamente, ahora tiene 25 posiciones.\n");
		}
		imprimirArray(pArrayEdades, sizeArrayEdades);
	}
	else
	{
		// Error, no encontró espacio libre.
	}
	free(pArrayEdades);

	return EXIT_SUCCESS;
}
