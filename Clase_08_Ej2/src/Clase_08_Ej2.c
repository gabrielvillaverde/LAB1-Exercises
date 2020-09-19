/*
 ============================================================================
2) Hacer una funcion que reciba el array del punto 1 y su tamaño, y cuente cuantas veces
aparece el numero 7. Al terminar de contar, la funcion deberá imprimir por pantalla
el valor contado. Escribir un programa para probar la funcion.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_NUMEROS 12

// Prototipos:
int printArrayInt(int* pArray, int limite);
int contarSietes(int *pArray, int limite);

int main(void) {

	setbuf(stdout,NULL);

	int numeros[CANTIDAD_NUMEROS] = {3,7,4,5,2,3,7,1,7,3,2,7};

	printArrayInt(numeros,CANTIDAD_NUMEROS);
	contarSietes(numeros,CANTIDAD_NUMEROS);

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

// Devuelve por valor de retorno.
int contarSietes(int *pArray, int limite)
{
	int retorno = -1;
	int i;
	int contadorDeSietes = 0;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(pArray[i] == 7) // Si el elemento del array es igual a 7...
			{
				contadorDeSietes++; // ...incremento el contador.
			}
		}
	printf("\nLa cantidad de números 7 que hay son: %d", contadorDeSietes);
	}
	return retorno;
}
