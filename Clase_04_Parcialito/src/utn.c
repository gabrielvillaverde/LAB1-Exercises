/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break; // Si logre conseguir el n�mero que estaba buscando, tengo que cortar. Si no hago esto, ingresar�a el 1000 y seguir�a pidiendo n�meros.
			}
			else{
				printf("%s\n", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
