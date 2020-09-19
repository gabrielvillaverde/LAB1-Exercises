/*
 ============================================================================
5) Hacer una funci�n que reciba el array del punto 4 y verifique que las letras dentro del mismo
est�n en el rango de la 'a' a la 'z' o de la 'A' a la 'Z'. Si est�n dentro del rango, la funci�n
deber� devolver por valor (usando el return) un 0, de lo contrario un -1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_LETRAS 8

// Prototipos:
int validarLetras(char* pArray);

int main(void) {

	setbuf(stdout,NULL);


	// Prueba 1: No deber�an estar dentro del rango:
	// char letras[CANTIDAD_LETRAS] = {'p','e','p','e','1','2','3','\0'};

	// Prueba 2: Deber�an estar dentro del rango:
	char letras[CANTIDAD_LETRAS] = {'a','c','e','f','G','J','I','\0'};
	int respuestaDeFuncion;

	respuestaDeFuncion = validarLetras(letras);
	if(respuestaDeFuncion == 0)
	{
		printf("\nLas letras est�n dentro del rango.");
	}
	else // Si la respuesta de la funci�n es -1..
	{
		printf("\nLas letras no est�n dentro del rango.");
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
