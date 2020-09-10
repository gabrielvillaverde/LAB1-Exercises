/*
 * utn.c
 *
 *  Created on: 8 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>

// Devuelve un 0 si se pudo ingresar el valor correctamente.
// Devuelve un 1 si se ingresó un valor incorrecto.
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
				break; // Si logre conseguir el número que estaba buscando, tengo que cortar. Si no hago esto, ingresaría el 1000 y seguiría pidiendo números.
			}
			else{
				printf("%s\n", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

