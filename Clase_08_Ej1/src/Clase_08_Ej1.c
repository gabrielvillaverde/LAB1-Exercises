/*
 ============================================================================
1) Se tiene el siguiente array de variables del tipo int:

int numeros[12] = {3,7,4,5,2,3,7,1,7,3,2,7};

Hacer una funcion que reciba el array y su tamaño, y lo imprima. Escribir un programa para probar la funcion.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_NUMEROS 12

// Prototipos:
int printArrayInt(int* pArray, int limite);

int main(void) {

	setbuf(stdout,NULL);

	int numeros[CANTIDAD_NUMEROS] = {3,7,4,5,2,3,7,1,7,3,2,7};
	int respuesta;

	respuesta = printArrayInt(numeros,CANTIDAD_NUMEROS);

	if(respuesta == 0)
	{
		printf("\n\n Respuesta de la función: %d\n\n", respuesta);
	}
	return EXIT_SUCCESS;
}

int printArrayInt(int* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			printf("\nÍndice: %d - Valor: %d",i,pArray[i]); // Imprimimos el número del índice y el valor dentro del array.
		}
	}
	return retorno;
}
