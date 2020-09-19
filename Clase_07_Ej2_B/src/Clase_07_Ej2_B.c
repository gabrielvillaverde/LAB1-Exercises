/*
 ============================================================================
CON BIBLIOTECAS DE MAURICIO

Crear un programa que permita registrar el valor de temperatura m�xima de cada d�a de un mes.
Definir un array de floats de 31 posiciones. Cada posici�n corresponder� a un d�a del mes.
Hacer un programa con un men� de dos opciones:

1. Imprimir array.
2. Cargar array.

Al elegir la opci�n 1, se imprimir� el �ndice y el valor de cada posici�n del array.
Al elegir la opci�n 2, que le pida al usuario que ingrese un n�mero de d�a (1 al 31), y luego
que ingrese un valor de temperatura. Almacenar el valor en el �ndice correspondiente.

Ambas opciones deben volver al menu principal.

Utilizar la funci�n utn_getNumeroFloat() de la biblioteca utn.h
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);
	int respuesta;
	float resultado;

	while(1)
	{
	respuesta = utn_getNumeroFlotante(&resultado, "\nN�mero", "\nError", -1.5, 1.8, 2);
	printf("\nResultado %.2f - Respuesta: %d", resultado,respuesta);
	}
	return EXIT_SUCCESS;
}
