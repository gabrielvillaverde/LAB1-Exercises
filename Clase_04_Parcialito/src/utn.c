/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
{

	int retorno = -1;
	int bufferInt;
	int contadorIntentos = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL){
		do{
			if(contadorIntentos == reintentos){
				retorno = -2;
				break;
			}
			printf("%s\n", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else{
				printf("%s\n", mensajeError);
			}
			contadorIntentos++;
		}while(1);
	}
	return retorno;
}
