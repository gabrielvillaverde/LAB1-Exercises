/*
 ============================================================================
6) Realizar un programa para probar la función del punto 5, permitiendo
que el usuario ingrese un texto y luego validamos si lo ingresado es un
nombre válido. Usar el scanf para tomar el texto.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE_NOMBRE 8

// Prototipos:
int validarLetras(char* pArray);

int main(void) {

	setbuf(stdout,NULL);

	char nombre[SIZE_NOMBRE];

	printf("\nIngrese un nombre, no se aceptan números ni caracteres especiales: ");
	fflush(stdin);
	scanf("%s",nombre);

	int respuestaDeFuncion;

	respuestaDeFuncion = validarLetras(nombre);
	if(respuestaDeFuncion == 0)
	{
		printf("\nEs un nombre válido.");
	}
	else // Si la respuesta de la función es -1..
	{
		printf("\nNo es un nombre válido.");
	}

	return EXIT_SUCCESS;
}

// Esta función sirve para que cuando el usuario ingresa algo, validar si es un nombre, por ejemplo. Ya que no admite números.
// No hacen falta dos argumentos, no hace falta el puntero de resultado del anterior ejercicio.
int validarLetras(char* pArray)
{
	int retorno = 0; // Arranca asumiendo que la función devuelve un valor correcto dentro del rango.
	int i;
	if(pArray != NULL) // Chequea que los punteros sean distintos de NULL.
	{
		for(i=0 ; pArray[i] != '\0' ; i++) // Iteración para cada valor de i.
		{
			// Chequea que esté fuera del rango de la 'a' a la 'z' y la 'A' a la 'Z'
			if((pArray[i] < 'a' || pArray[i] > 'z') && (pArray[i] < 'A' || pArray[i] > 'Z'))
			{
				// Entonces dará error.
				retorno = -1;
				break; // Si ya se cumplió el error, ya no quiero saber que los caracteres que siguen también dan error. Con ya tener un error me voy de la iteración.
			}
		}
	}
	return retorno;
}
