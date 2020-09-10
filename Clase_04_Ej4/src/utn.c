/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: Hzkr
 */

// Función utn_getNumero

/* Pide al usuario un número.
Recibe pResultado, que es la dirección de memoria de la variable donde escribe el valor.
Recibe el mínimo (inclusive) y el máximo.
Mensaje: el mensaje que imprime para pedir un valor.
Retorno: Si está todo OK, devuelve 0. Si hubo un error, devuelve -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int utn_getNumero(int* pResultado,int min,int max,char* msg,char* msgError, int reintentos) // Función getNumero

	{

		int numeroIngresado;
		int variableDeRetorno = -1;
		int retornoScanf;

		while(reintentos > 0)
		{
			printf("%s\n",msg);
			fflush(stdin);
			retornoScanf = scanf("%d",&numeroIngresado); // Si ingresa un "hola", el "1" no se cumple.
			if(retornoScanf == 1 && numeroIngresado >= min && numeroIngresado < max)
			{ // Si verifica que ingresó un número valido...
				*pResultado = numeroIngresado; // ...utiliza el puntero para escribir en la variable numeroIngresado.
				variableDeRetorno = 0; // ...la variable de retorno devolverá un 0, indicando que está OK.
				break; // Rompe la estructura iterativa.
			}
			else // Sino...
			{
				printf("%s\n", msgError); // Imprime un mensaje de error.
				reintentos--; // Y decrementa el contador de intentos.
			}
		}
		return variableDeRetorno;
	}
