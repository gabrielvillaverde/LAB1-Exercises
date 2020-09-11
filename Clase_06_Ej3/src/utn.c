/*
 * utn.c
 *
 *  Created on: 10 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int utn_getInt(char* mensaje, char* mensajeError, int* pResultado, int reintentos, int maximo, int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && (maximo >= minimo))
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d",&bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				fflush(stdin);
				reintentos--;
			}
		}
		while(reintentos > 0);
	}
	return retorno;
}

int utn_calcularMaximo(int *pArray, int cantidadElementos, int *pResultado)
{
	int retorno = -1;
	int maximo;
	if(pArray != NULL && cantidadElementos > 0 && pResultado != NULL)
	{
		for(int i = 0; i < cantidadElementos; i++)
		{
			if(i==0 || pArray[i] > maximo)
			{
				maximo = pArray[i];
			}
		}
		*pResultado = maximo;
		retorno = 0;
	}
	return retorno;
}

void ordenar(int array[], int len)
{
	int indice;
	int aux;
	int flagEstadoDesordenado=1;

	while(flagEstadoDesordenado==1)
	{
		flagEstadoDesordenado=0;
		for(indice=0 ; indice<(len-1)  ; indice++)
		{
			if(array[indice] > array[indice+1])
			{
				// intercambiar (swap)
				aux = array[indice];
				array[indice] = array[indice+1];
				array[indice+1] = aux;
				flagEstadoDesordenado=1;
			}
		}
	}

}

void imprimirArray(int array[], int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("\nEl numero de la posicion %d es: %d", i, array[i]);
	}
}
