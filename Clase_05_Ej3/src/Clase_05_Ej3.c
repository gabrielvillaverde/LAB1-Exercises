/*
 ============================================================================
 Hacer una función que calcule el promedio de los valores del array que recibe,
 y me devuelva el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define EDADESSIZE 5 // Tamaño de las edades

int main(void)
{
	setbuf(stdout,NULL); // Windows

	int edad;
	int edades[EDADESSIZE];  // Asigno el tamaño del array con el define de la línea 12
	int i; // Variable i para mi bucle for
	float promedioEdad;

	// Recorro para cargar en forma secuencial
	for(i = 0; i<EDADESSIZE; i++)
	{
		if(utn_getNumero(&edad, "Ingrese edad:", "Esta edad no va\n", 1, 120, 3)==0) //Si la función es igual a 0, significa que respondió bien.
		{
			// printf("La edad ingresada es: %d\n", edad);
			// En edades escribo edad en la posición "i"
			edades[i] = edad; // Guardo la variable edad en la posición i
		}
		else
		{
			printf("ERROR, eso ni siquiera una edad.");
		}
	}
	// Esto es para la primer versión de la función, por valor de retorno: promedioEdad = promediarArrayInt(edades, EDADESSIZE);
	promedioEdad = promediarArrayInt(edades,EDADESSIZE); // Llamo a la función del array y le asigno la dirección de memoria del array edades, y además el tamaño.
	// Esto es para la segunda versión de la función, por referencia (tira un warning, solucionar):
	//promediarArrayIntV2(&promedioEdad,edades,EDADESSIZE); (TIRA WARNING)

	printf("Promedio de edades:%f",promedioEdad);
	return EXIT_SUCCESS;
}

// Primer versión de devolver la función, por valor de retorno.
float promediarArrayInt(int arrayInt[], int len) // Además de tener como primer argumento el array, tengo que tener el tamaño.
{
	int i;
	float resultado;
	int acumulador = 0;

	for(i=0; i<len; i++)
	{
		acumulador = acumulador + arrayInt[i];
	}

	resultado = (float)acumulador / len;

	return resultado; // Está devolviendo el resultado por valor de retorno, y no por referencia.
}

// Segunda versión de devolver la función, por valor de referencia.
int promediarArrayIntV2(int* pPromedioResultado, int array[], int len)
{
	int i;
	int acumulador = 0;
	int retorno = -1;

	if(len>0 && pPromedioResultado != NULL && array != NULL) // Si está todo bien...
	{
		for (i=0; i<len; i++) // ...entro al bucle for.
		{
			acumulador = acumulador + array[1];
		}
		*pPromedioResultado = acumulador / len;
		retorno = 0; // OK
	}
	return retorno; // Si hubo un problema, el return contiene el -1, que significa error.
}
