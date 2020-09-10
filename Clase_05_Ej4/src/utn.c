/*
 * utn.c
 *
 *  Created on: 8 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/* Documentaci�n del c�digo, BUENA PR�CTICA, va en el .h
\brief - Solicita un entero al usuario
\param - char* mensaje, es el mensaje a ser mostrado al usuario
\param - char* mensajeError, es el mensaje de error a ser mostrado al usuario
\param - int* pResultado, puntero al espacio de memoria donde se dejar� el valor obtenido
\param - int reintentos, cantidad de oportunidades para ingresar el dato
\param - int minimo, valor m�nimo admitido
\param - int m�ximo, valor m�ximo admitido
\return - (-1) Error / (0) OK
*/

int getInt(char* mensaje, char* mensajeError, int* pResultado, int reintentos, int maximo, int minimo)
{
	int retorno = -1;
	int bufferInt; // Variable para guardar el dato que obtengo de scanf
	int resultadoScanf; // Ac� guardo lo que obtiene scanf

	if(		// Evaluar todos los par�metros, desconfiar siempre de lo que ingresa el usuario.
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
			resultadoScanf = scanf("%d", &bufferInt); // Podr�a ponerse directamente scanf("%d", &bufferInt) == 1 en el if en vez de crear la variable resultadoScanf.
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo) // Si cumple esto, estar� todo bien.
			{
				retorno = 0;
				*pResultado = bufferInt;
				break; // Hago la sentencia break porque tengo que romper el bucle. Ya consegu� lo que ten�a que conseguir.
			}
			else
			{
				 // ERROR.
				printf("%s", mensajeError);
				reintentos--; // Cada vez que haya un error, decremento la cantidad de intentos.
			}

		}while(reintentos >= 0); // Mientras que reintentos sea mayor o igual a 0. Pongo mayor o igual a 0 porque ya antes de llegar ac� lo estoy decrementando en el do.
	}
	return retorno;
}

/* Documentaci�n del c�digo, BUENA PR�CTICA
\brief - Calcula el n�mero m�ximo del array recibido como par�metro
\param - int pArray[], Array a ser procesado
\param - int cantidadElementos, cantidad de elementos a ser procesados
\param - int* pResultado, puntero al espacio de memoria donde se dejar� el valor obtenido
\return - (-1) Error / (0) OK
*/

// Cualquier funci�n que procese un array, hay que pasarle los siguientes 3 argumentos:
int calcularMaximo(/* Modo profesional: int *pArray */int pArray [], int cantidadElementos, int *pResultado)
{
	int retorno = -1; // Siempre primero hacer el retorno
	int maximo;
	// Luego, verificar qu� es lo que recibimos
	if(pArray != NULL && cantidadElementos > 0 && pResultado != NULL)
	{
		// Ac� escribir lo que haga falta para imprimir por pantalla cual es el m�ximo. Hacer la funci�n del maximo.
		for(int i = 0; i < cantidadElementos; i++) // Mientras que, estando en la posici�n
		{
			// Preguntarme ante qu� condiciones se encontr� el nuevo m�ximo
			if(i == 0 || pArray[i] > maximo) // Si en la posici�n del array i hay un n�mero que es m�s grande que el m�ximo, y la variable i es igual a 0...
			{
				maximo = pArray[i]; // ...en m�ximo guardo lo que tiene el array en esa posici�n.
			}
		}
		*pResultado = maximo;
		retorno = 0; // Est� todo OK
	}
	return retorno;
}

/* Otra manera de hacer lo de adentro del do:
	printf("%s", mensaje);
	resultadoScanf = scanf("%d", &bufferInt);
	while(resultadoScanf == 0 || (bufferInt < minimo || bufferInt > maximo)) // Si me da 0, est� mal. Adem�s, si el bufferInt es m�s chico que el m�nimo y m�s grande que el m�ximo tambi�n estar� mal, mientras que pase todo eso surgir� el bucle con el mensaje de error.
	{
		printf("%s", mensaje);
		resultadoScanf = scanf("%d", &bufferInt);
	}
	*/
