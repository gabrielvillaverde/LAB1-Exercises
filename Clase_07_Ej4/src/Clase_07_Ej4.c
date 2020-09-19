/*
 ============================================================================
Completar la funci�n getFloat() para que devuelva un n�mero float ingresado por el usuario.
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
		printf("El precio es v�lido: %f", precio);
	}
	else
	{
	printf("Valor incorrecto");
	}
	return EXIT_SUCCESS;
}

int getFloat(float* pResultado)
{
	char buffer[128]; // Un array de un m�ximo de 128 elementos.
	int retorno = 0; // Significa que es inv�lido.

	// Llama a fgets que recibe la cadena, un tama�o m�ximo que tiene esa cadena y un puntero a algo llamado archivo/file, es una regla para leer de la consola.
	fgets(buffer, 128, stdin); // Esta funci�n tambi�n lee cuando apretamos enter, algo que el scanf no lo hace.
	buffer[strlen(buffer)-1] = '\0'; // Borro el enter
	// Con strlen cuento la cantidad de caracteres que hay en buffer, le resto 1 para pisar el enter del final.

	int i;
	for(i=0;i<8;i++)
	{
		// Imprimimos para probar qu� pasa y ver los valores de cada cosa.
		printf("%d %d %c\n", i, buffer[i], buffer[i]);
	}
	printf("---------\n"); // L�nea para que se vea lindo.

	// El buffer va a tener guardado el texto de la funci�n que ingres� el usuario por consola.
	if(validarFloat(buffer)==1) // Si es v�lido, o sea, si lo puede convertir.
	{
		// Puedo llamar al atof para convertir cadena a float.
		*pResultado = atof(buffer); // *pResultado apunta a la variable que est� fuera de la funci�n, en este caso precio. Le escribe el valor float que me devuelve atof, que a su vez lo sac� de convertir ese texto en float.
		retorno = 1; // Me devuelve 1 porque lo pudo convertir y me lo guarda en la variable externa.
	}
	return retorno;
}

int validarFloat(char* stringRecibido)
{
	int retorno = 1; // Inicializa un retorno en 1, que significar�a que est� todo bien, que es v�lida la cadena y es float.
	int i;
	int contadorDePuntos = 0; // Declaro esta variable para validar los casos en los que haya m�s de un punto en mi cadena de caracteres.

	// For inicializado en 0 que va aumentando. Mientras que en la posici�n i sea distinto de \0. B�sicamente va a iterar mientras haya caracteres en el string.
	for(i=0 ; stringRecibido[i] != '\0' ; i++)
	{	// Si est� por fuera del rango num�rico 0-9.
		if(stringRecibido[i]<'0' || stringRecibido[i] > '9')
		{
			// No estoy en el rango de los n�meros...
			if(stringRecibido[i] == '.') // Si el valor en i es un punto...
			{
				contadorDePuntos++; // ...simplemente voy contando.
				if(contadorDePuntos > 1) // Si el contador de puntos es mayor a 1...
				{
					// ...es porque encontr� un segundo punto, y doy error.
					retorno = 0; // Retorno un valor 0, indicando error.
					break;
				}
			}
			else // Si no es un punto lo que encontr�...
			{
				// ...tambi�n doy error, porque significa que no est� en el rango num�rico y tampoco es un punto.
				// ...hay algo que no es ni un punto ni un n�mero, como signos y esas cosas.
				if(i==0) // Me pregunto si estoy en la primera posici�n. Esto permite ingresar + y - solo en la primer posici�n. Si estoy en la primera posici�n...
				{
					if(stringRecibido[i] != '+' && stringRecibido[i] != '-') // ...chequeo si no es un m�s y tampoco es un menos...
					// Ojo, si finalmente hay un + y un - pasa y funciona, pero SOLO en la primer posici�n, el tema es cuando no hay un + y un -
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
