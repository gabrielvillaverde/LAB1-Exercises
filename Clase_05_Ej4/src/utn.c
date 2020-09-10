/*
 * utn.c
 *
 *  Created on: 8 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/* Documentación del código, BUENA PRÁCTICA, va en el .h
\brief - Solicita un entero al usuario
\param - char* mensaje, es el mensaje a ser mostrado al usuario
\param - char* mensajeError, es el mensaje de error a ser mostrado al usuario
\param - int* pResultado, puntero al espacio de memoria donde se dejará el valor obtenido
\param - int reintentos, cantidad de oportunidades para ingresar el dato
\param - int minimo, valor mínimo admitido
\param - int máximo, valor máximo admitido
\return - (-1) Error / (0) OK
*/

int getInt(char* mensaje, char* mensajeError, int* pResultado, int reintentos, int maximo, int minimo)
{
	int retorno = -1;
	int bufferInt; // Variable para guardar el dato que obtengo de scanf
	int resultadoScanf; // Acá guardo lo que obtiene scanf

	if(		// Evaluar todos los parámetros, desconfiar siempre de lo que ingresa el usuario.
			mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{

		do // Hago esto...
		{
			printf("%s", mensaje);
			fflush(stdin); // __fpurge(stdin) en Linux.
			resultadoScanf = scanf("%d", &bufferInt); // Podría ponerse directamente scanf("%d", &bufferInt) == 1 en el if en vez de crear la variable resultadoScanf.
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo) // Si cumple esto, estará todo bien.
			{
				retorno = 0;
				*pResultado = bufferInt;
				break; // Hago la sentencia break porque tengo que romper el bucle. Ya conseguí lo que tenía que conseguir.
			}
			else
			{
				 // ERROR.
				printf("%s", mensajeError);
				reintentos--; // Cada vez que haya un error, decremento la cantidad de intentos.
			}

		}while(reintentos >= 0); // Mientras que reintentos sea mayor o igual a 0. Pongo mayor o igual a 0 porque ya antes de llegar acá lo estoy decrementando en el do.
	}
	return retorno;
}

/* Documentación del código, BUENA PRÁCTICA
\brief - Calcula el número máximo del array recibido como parámetro
\param - int pArray[], Array a ser procesado
\param - int cantidadElementos, cantidad de elementos a ser procesados
\param - int* pResultado, puntero al espacio de memoria donde se dejará el valor obtenido
\return - (-1) Error / (0) OK
*/

// Cualquier función que procese un array, hay que pasarle los siguientes 3 argumentos:
int calcularMaximo(/* Modo profesional: int *pArray */int pArray [], int cantidadElementos, int *pResultado)
{
	int retorno = -1; // Siempre primero hacer el retorno
	int maximo;
	// Luego, verificar qué es lo que recibimos
	if(pArray != NULL && cantidadElementos > 0 && pResultado != NULL)
	{
		// Acá escribir lo que haga falta para imprimir por pantalla cual es el máximo. Hacer la función del maximo.
		for(int i = 0; i < cantidadElementos; i++) // Mientras que, estando en la posición
		{
			// Preguntarme ante qué condiciones se encontró el nuevo máximo
			if(i == 0 || pArray[i] > maximo) // Si en la posición del array i hay un número que es más grande que el máximo, y la variable i es igual a 0...
			{
				maximo = pArray[i]; // ...en máximo guardo lo que tiene el array en esa posición.
			}
		}
		*pResultado = maximo;
		retorno = 0; // Está todo OK
	}
	return retorno;
}

/* Otra manera de hacer lo de adentro del do:
	printf("%s", mensaje);
	resultadoScanf = scanf("%d", &bufferInt);
	while(resultadoScanf == 0 || (bufferInt < minimo || bufferInt > maximo)) // Si me da 0, está mal. Además, si el bufferInt es más chico que el mínimo y más grande que el máximo también estará mal, mientras que pase todo eso surgirá el bucle con el mensaje de error.
	{
		printf("%s", mensaje);
		resultadoScanf = scanf("%d", &bufferInt);
	}
	*/
