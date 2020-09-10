/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: Hzkr
 */

// Funci�n utn_getNumero

/* Pide al usuario un n�mero.
Recibe pResultado, que es la direcci�n de memoria de la variable donde escribe el valor.
Recibe el m�nimo (inclusive) y el m�ximo.
Mensaje: el mensaje que imprime para pedir un valor.
Retorno: Si est� todo OK, devuelve 0. Si hubo un error, devuelve -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int utn_getNumero(int* pResultado,int min,int max,char* msg,char* msgError, int reintentos) // Funci�n getNumero

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
			{ // Si verifica que ingres� un n�mero valido...
				*pResultado = numeroIngresado; // ...utiliza el puntero para escribir en la variable numeroIngresado.
				variableDeRetorno = 0; // ...la variable de retorno devolver� un 0, indicando que est� OK.
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
