/*
 ============================================================================
 Name        : Clase_05_Ej5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_EMPLEADOS 9 // Buena pr�ctica, con esto solamente tengo que cambiar el valor del n�mero �nicamente en esta l�nea.

// Prototipo de funci�n
int printArrayInt(int* pArray, int limite);
int ordernarArrayInt(int* pArray, int limite);

int main(void) {

	int arrayEdades[CANTIDAD_EMPLEADOS] = {54,26,93,17,77,31,44,55,27};
	int respuesta;

	printArrayInt(arrayEdades,CANTIDAD_EMPLEADOS); // Imprimo el array.
	respuesta = ordernarArrayInt(arrayEdades,CANTIDAD_EMPLEADOS); // Llamo a la funci�n que lo ordena.
	if(respuesta > 0) // Si sali� todo bien...
	{
		printf("\n\n Cantidad de iteraciones: %d\n\n", respuesta); // ...imprimo la cantidad de iteraciones.
	}
	printArrayInt(arrayEdades,CANTIDAD_EMPLEADOS); // Llamo a la funci�n para que muestre el array de edades, sino no aparece en consola.

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
			printf("\n[DEBUG] �ndice: %d - Valor: %d",i,pArray[i]); // Imprimimos el n�mero del �ndice y el valor dentro del array.
		}
	}
	return retorno;
}

// Funci�n que ordena los valores del array
int ordernarArrayInt(int* pArray, int limite)
{
	int flagSwap;
	int i;
	int contador = 0;
	int retorno = -1;
	int buffer;

	if(pArray != NULL && limite >= 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(pArray[i] < pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
				contador++;
			}
		}while(flagSwap);
		retorno = contador; // Si sali� todo bien, imprimimos lo que tiene el contador.
	}
	return retorno;
}



