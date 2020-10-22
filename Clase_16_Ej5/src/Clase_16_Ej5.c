/*
 ============================================================================
Inicializar array de manera dinámica.
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

int main(void)
{
	int * pArrayEdades = NULL;
	int sizeArrayEdades = 10;

	pArrayEdades = (int *) malloc (sizeof(int) * sizeArrayEdades);
	if(pArrayEdades != NULL)
	{
		// Todo OK.
		if(initArray(pArrayEdades, sizeArrayEdades, 0) == 0) // Si initArray me devuelve 0...
		{
			printf("Array inicializado correctamente.\n");
		}
	}
	else
	{
		// Error, no encontró espacio libre.
	}

	return EXIT_SUCCESS;
}
