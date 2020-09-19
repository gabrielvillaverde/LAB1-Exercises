/*
 ============================================================================
CON BIBLIOTECAS DE MAURICIO

Crear un programa que permita registrar el valor de temperatura máxima de cada día de un mes.
Definir un array de floats de 31 posiciones. Cada posición corresponderá a un día del mes.
Hacer un programa con un menú de dos opciones:

1. Imprimir array.
2. Cargar array.

Al elegir la opción 1, se imprimirá el índice y el valor de cada posición del array.
Al elegir la opción 2, que le pida al usuario que ingrese un número de día (1 al 31), y luego
que ingrese un valor de temperatura. Almacenar el valor en el índice correspondiente.

Ambas opciones deben volver al menu principal.

Utilizar la función utn_getNumeroFloat() de la biblioteca utn.h
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
	respuesta = utn_getNumeroFlotante(&resultado, "\nNúmero", "\nError", -1.5, 1.8, 2);
	printf("\nResultado %.2f - Respuesta: %d", resultado,respuesta);
	}
	return EXIT_SUCCESS;
}
