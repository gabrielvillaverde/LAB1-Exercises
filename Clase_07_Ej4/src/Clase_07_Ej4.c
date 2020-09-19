/*
 ============================================================================
Completar la función getFloat() para que devuelva un número float ingresado por el usuario.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Siempre tiene que estar para trabajar con strings
#include "utn.h"

// Prototipos:
int getFloat(float* pResultado);
int validarFloat(char* stringRecibido);

int main(void)
{
	setbuf(stdout,NULL);
	float precio;
	printf("Ingrese el precio:");
	if(getFloat(&precio)==1)
	{
		printf("El precio es válido: %f", precio);
	}
	else
	{
	printf("Valor incorrecto");
	}
	return EXIT_SUCCESS;
}

int getFloat(float* pResultado)
{
	char buffer[128]; // Un array de un máximo de 128 elementos.
	int retorno = 0; // Significa que es inválido.

	// Llama a fgets que recibe la cadena, un tamaño máximo que tiene esa cadena y un puntero a algo llamado archivo/file, es una regla para leer de la consola.
	fgets(buffer, 128, stdin); // Esta función también lee cuando apretamos enter, algo que el scanf no lo hace.
	buffer[strlen(buffer)-1] = '\0'; // Borro el enter
	// Con strlen cuento la cantidad de caracteres que hay en buffer, le resto 1 para pisar el enter del final.

	int i;
	for(i=0;i<8;i++)
	{
		// Imprimimos para probar qué pasa y ver los valores de cada cosa.
		printf("%d %d %c\n", i, buffer[i], buffer[i]);
	}
	printf("---------\n"); // Línea para que se vea lindo.

	// El buffer va a tener guardado el texto de la función que ingresó el usuario por consola.
	if(validarFloat(buffer)==1) // Si es válido, o sea, si lo puede convertir.
	{
		// Puedo llamar al atof para convertir cadena a float.
		*pResultado = atof(buffer); // *pResultado apunta a la variable que está fuera de la función, en este caso precio. Le escribe el valor float que me devuelve atof, que a su vez lo sacó de convertir ese texto en float.
		retorno = 1; // Me devuelve 1 porque lo pudo convertir y me lo guarda en la variable externa.
	}
	return retorno;
}

int validarFloat(char* stringRecibido)
{
	int retorno = 1; // Inicializa un retorno en 1, que significaría que está todo bien, que es válida la cadena y es float.
	int i;
	int contadorDePuntos = 0; // Declaro esta variable para validar los casos en los que haya más de un punto en mi cadena de caracteres.

	// For inicializado en 0 que va aumentando. Mientras que en la posición i sea distinto de \0. Básicamente va a iterar mientras haya caracteres en el string.
	for(i=0 ; stringRecibido[i] != '\0' ; i++)
	{	// Si está por fuera del rango numérico 0-9.
		if(stringRecibido[i]<'0' || stringRecibido[i] > '9')
		{
			// No estoy en el rango de los números...
			if(stringRecibido[i] == '.') // Si el valor en i es un punto...
			{
				contadorDePuntos++; // ...simplemente voy contando.
				if(contadorDePuntos > 1) // Si el contador de puntos es mayor a 1...
				{
					// ...es porque encontré un segundo punto, y doy error.
					retorno = 0; // Retorno un valor 0, indicando error.
					break;
				}
			}
			else // Si no es un punto lo que encontró...
			{
				// ...también doy error, porque significa que no está en el rango numérico y tampoco es un punto.
				// ...hay algo que no es ni un punto ni un número, como signos y esas cosas.
				if(i==0) // Me pregunto si estoy en la primera posición. Esto permite ingresar + y - solo en la primer posición. Si estoy en la primera posición...
				{
					if(stringRecibido[i] != '+' && stringRecibido[i] != '-') // ...chequeo si no es un más y tampoco es un menos...
					// Ojo, si finalmente hay un + y un - pasa y funciona, pero SOLO en la primer posición, el tema es cuando no hay un + y un -
					{
						retorno = 0; // Retorno un valor 0, indicando error si no hay un + y un -
						break;
					}
				}
				else
				{
					retorno = 0; // Retorno un valor 0, indicando error.
					break;
				}
			}
		}
	}
	return retorno;
}
