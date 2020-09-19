/*
 ============================================================================
7) Al ejercicio anterior, reemplazar scanf por fgets, para evitar que
el programa crashee si ingresa muchos caracteres.
Esto es porque el programa no sabe d�nde termina el array por culpa del scanf.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define SIZE_NOMBRE 30

// Prototipos:
int validarLetras(char* pArray);

int main(void) {

	setbuf(stdout,NULL);

	char nombre[SIZE_NOMBRE];

	printf("\nIngrese un nombre, no se aceptan n�meros ni caracteres especiales: ");
	fflush(stdin);

	// Para evitar desbordar el programa usamos fgets, en vez de scanf.
	// Sin embargo, el fgets se come el enter, hay que solucionarlo.
	// Ac� uso myGets porque fgets la tengo validada dentro de esta funci�n en utn.c
	if(myGets(nombre, SIZE_NOMBRE)==0)
	{
		printf("\nEl nombre es: %s",nombre);
	}

	int respuestaDeFuncion;
	respuestaDeFuncion = validarLetras(nombre);
	if(respuestaDeFuncion == 0)
	{
		printf("\nEs un nombre v�lido.");
	}
	else // Si la respuesta de la funci�n es -1..
	{
		printf("\nNo es un nombre v�lido.");
	}

	return EXIT_SUCCESS;
}

// Esta funci�n sirve para que cuando el usuario ingresa algo, validar si es un nombre, por ejemplo. Ya que no admite n�meros.
// No hacen falta dos argumentos, no hace falta el puntero de resultado del anterior ejercicio.
int validarLetras(char* pArray)
{
	int retorno = 0; // Arranca asumiendo que la funci�n devuelve un valor correcto dentro del rango.
	int i;
	if(pArray != NULL) // Chequea que los punteros sean distintos de NULL.
	{
		for(i=0 ; pArray[i] != '\0' ; i++) // Iteraci�n para cada valor de i.
		{
			// Chequea que est� fuera del rango de la 'a' a la 'z' y la 'A' a la 'Z'
			if((pArray[i] < 'a' || pArray[i] > 'z') && (pArray[i] < 'A' || pArray[i] > 'Z'))
			{
				// Entonces dar� error.
				retorno = -1;
				break; // Si ya se cumpli� el error, ya no quiero saber que los caracteres que siguen tambi�n dan error. Con ya tener un error me voy de la iteraci�n.
			}
		}
	}
	return retorno;
}
