/*
 * utn.c
 *
 *  Created on: 9 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int sumar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;

	*pResultado = operadorA + operadorB;
	retorno = 0;

	return retorno;
}

int restar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;
	*pResultado = operadorA - operadorB;
	retorno = 0;

	return retorno;
}

int dividir (int operador1, int operador2, float* pResultado) {

	int retorno = -1;
	float resultado;
	if(pResultado != NULL && operador2 != 0){
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

int multiplicar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;

	*pResultado = operadorA * operadorB;
	retorno = 0;

	return retorno;
}

int funcionFactorial(int numero, long *pResultado) {

	int retorno = -1;

	long factorial = 1;

	for(int i = numero; i>= 1; i--)
	{
		factorial = factorial * i;
	}

	*pResultado = factorial;
	retorno = 0;

	return retorno;
}

int getFloat(char *mensaje,char *mensajeError,int reintentos,float *pResultado)
{
	int retorno = -1;
	int resultadoScan;
	float bufferFloat;
	printf("%s",mensaje);
	fflush(stdin);
	resultadoScan = scanf("%f", &bufferFloat);
	while (resultadoScan == 0 && reintentos > 0)
	{
		reintentos--;
		printf("%s",mensajeError);
		fflush(stdin);
		resultadoScan = scanf("%f", &bufferFloat);
	}
	if(resultadoScan != 0)
	{ //TODO OK
		*pResultado = bufferFloat;
		retorno = 0;
	}
	return retorno;
}

int getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt; // Variable para guardar el dato que obtengo de scanf
	int resultadoScanf; // Acá guardo lo que obtiene scanf

	// Evaluar todos los parámetros, desconfiar siempre de lo que ingresa el usuario.
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
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

int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar; // Variable de intercambio con el usuario, donde leeré y guardaré el dato que el usuario ingresa.

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do // Me asegura que la primera vez se va a cumplir aunque reintentos venga cargado en 0.
		{
			printf("%s", mensaje); // Recibo un dato string, el mensaje del usuario.
			fflush(stdin); // __fpurge(stdin); en Linux. Esto va siempre antes de la lectura del scanf.
			scanf("%c", &bufferChar); // Leo lo que recibo del usuario, y lo asigno a la dirección de memoria de bufferInt.
			if(bufferChar >= minimo && bufferChar <= maximo) // Si lo que hay dentro de bufferInt es mayor/igual al mínimo, y menor/igual al máximo...
			{
				retorno = 0; // Salió todo bien, por eso el retorno devuelve 0.
				*pResultado = bufferChar; // Le asigno al puntero, lo que hay en bufferInt.
				break; // Esto haría que deje de reintentar con la segunda forma.
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--; // Si viene en 1, lo decremento y sería mayor o igual a 0.
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

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
			fflush(stdin);
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
