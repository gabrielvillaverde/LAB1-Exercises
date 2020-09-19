/*
 ============================================================================
3) Modificar la funcion del punto 2 para que NO imprima el valor contado,
sino que lo devuelva por referencia (recibiendo la direccion de memoria de
una variable donde escribirá el valor contado). Escribir un programa para probar
la funcion.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_NUMEROS 12

// Prototipos:
int printArrayInt(int* pArray, int limite);
int contarSietes(int* pResultado, int* pArray, int limite);

int main(void) {

	setbuf(stdout,NULL);

	int numeros[CANTIDAD_NUMEROS] = {3,7,4,5,2,3,7,1,7,3,2,7};
	int resultado;
	int respuestaDeFuncion;

	printArrayInt(numeros,CANTIDAD_NUMEROS);
	respuestaDeFuncion = contarSietes(&resultado,numeros,CANTIDAD_NUMEROS);
	if(respuestaDeFuncion == 0)
	{
		printf("\nLa cantidad de números 7 que hay son: %d", resultado);
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
			printf("\nÍndice: %d - Valor: %d\n",i,pArray[i]); // Imprimimos el número del índice y el valor dentro del array.
		}
	}
	return retorno;
}

// Devuelve por valor de referencia.
int contarSietes(int* pResultado, int* pArray, int limite)
{
	int retorno = -1;
	int i;
	int contadorDeSietes = 0;
	if(pArray != NULL && limite >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i] == 7) // Si el elemento del array es igual a 7...
			{
				contadorDeSietes++; // ...incremento el contador.
			}
		}
		*pResultado = contadorDeSietes; // Le asigno al puntero de resultado, el contador de sietes. En la función main va a estar representado con &resultado.
		retorno = 0;
	}
	return retorno;
}
