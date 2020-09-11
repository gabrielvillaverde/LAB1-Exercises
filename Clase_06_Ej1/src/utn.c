/*
 * utn.c
 *
 *  Created on: 9 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int getInt(int* pResultado);
static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);

// Funciones est�ticas:
// Static es como si la funci�n fuese de uso SOLAMENTE para el archivo utn.c, y no se puede llamar desde el main por ejemplo. Adem�s su prototipo no hay que declararlo en el .h, hacerlo arriba de todo en el .c como prototipo.

// Busca como resultado un entero
// Llama a la que obtiene un string cualquiera de la terminal
static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096]; // Lo declaro as� de grande para asegurarme de que el usuario ingresar� menos caracteres que esa cantidad.

	fflush(stdin);
	// Llamo a la funci�n myGets y le paso el buffer y el tama�o que no quiero desbordar.
	if(myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer)) // Si myGets me devuelve un 0 es porque lo que la mand� a hacer lo hizo bien, y si es num�rica, entro al c�digo. La funci�n esNumerica me indica que lo que hay en buffer son n�meros.
	{ // Si son n�meros...
		retorno = 0; // Todo OK.
		*pResultado = atoi(buffer); // ...los puedo convertir. Con atoi convierto texto en un entero.
		// La funci�n atoi convierte un array de caracteres (una cadena, un string), en un n�mero entero.
		// Si ingresas el texto "10", te lo convierte en el entero 10.
	}
	return retorno;
}

// Verificar que en la cadena haya n�meros.
// Este tipo de funci�n devuelve verdadero (1) o falso (0).
static int esNumerica(char* cadena)
{
	int retorno = 1; // Inicializo el retorno en 1, VERDADERO.
	int i = 0;

	// CASO PARTICULAR:
	// Si estoy en la primer posici�n del array, es v�lido tener un n�mero negativo, pero SOLO en la primera, por eso hago el if a continuaci�n:

	if(cadena[0] == '-') // Si cadena en la posici�n 0 es igual a un negativo...
	{
		i = 1; // ...haremos que la cuenta arranque a partir de uno.
	}
	// Tengo que iterar hasta el \0.
	for( ; cadena[i] != '\0' ; i++) // Mientras que cadena en posici�n i sea distinto a \0, que siga iterando e incrementando la i.
	{ // Si es distinto a \0, entro al for.
		if(cadena[i] > '9' || cadena[i] < 0) // Si cadena en la posici�n i, estoy en ERROR. Si lo que encontr� en la cadena es m�s grande que 9, rompo, si lo que encontr� es m�s chico que 0, rompo.
		{
			retorno = 0; // Coloco el retorno en 0, o sea FALSO.
			break; // Y hago un break.
		}
	}
	return retorno;
}

static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	// fgets nos permite leer de un archivo una cadena de caracteres.
	// Leo del stdin una cadena de caracteres.
	// Como primer par�metro quiere saber d�nde dejar la informaci�n, como segundo par�metro quiere la longitud, y como tercero quiere saber de d�nde leer, en este caso stdin.
	fgets(cadena, longitud, stdin);
	cadena[strlen(cadena)-1] = '\0';
	// strncpy guarda el destino, el origen y el tama�o que no puedo desbordar.
	// strncpy(cadena, buffer, longitud);
	return 0;
}

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

int getFloat(float *pResultado, char *mensaje,char *mensajeError,int reintentos)
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

int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar; // Variable de intercambio con el usuario, donde leer� y guardar� el dato que el usuario ingresa.

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do // Me asegura que la primera vez se va a cumplir aunque reintentos venga cargado en 0.
		{
			printf("%s", mensaje); // Recibo un dato string, el mensaje del usuario.
			fflush(stdin); // __fpurge(stdin); en Linux. Esto va siempre antes de la lectura del scanf.
			scanf("%c", &bufferChar); // Leo lo que recibo del usuario, y lo asigno a la direcci�n de memoria de bufferInt.
			if(bufferChar >= minimo && bufferChar <= maximo) // Si lo que hay dentro de bufferInt es mayor/igual al m�nimo, y menor/igual al m�ximo...
			{
				retorno = 0; // Sali� todo bien, por eso el retorno devuelve 0.
				*pResultado = bufferChar; // Le asigno al puntero, lo que hay en bufferInt.
				break; // Esto har�a que deje de reintentar con la segunda forma.
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--; // Si viene en 1, lo decremento y ser�a mayor o igual a 0.
			}
		}while(reintentos >= 0);
	}
	return retorno;
}


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n", mensaje);
			fflush(stdin);
			// getInt() Pretende que yo le de un lugar donde dejarme el resultado. Aparte ya me devuelve si sali� bien o mal.
			// getInt() Tiene que asegurarme que si me devuelve un 0 es porque obtuvo un entero, si no puede obtener un entero, no me devuelve un 0.
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break; // Si logre conseguir el n�mero que estaba buscando, tengo que cortar. Si no hago esto, ingresar�a el 1000 y seguir�a pidiendo n�meros.
			}
			reintentos--;
			printf("%s\n", mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}
