/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>

int dividir (float* pResultado, int operador1, int operador2)
{
	float resultado;
	int retorno = -1;
	if(pResultado != NULL && operador2 != 0){
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}
