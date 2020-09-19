/*
 ============================================================================
Definir una función validarFloat() que reciba un array de chars (cadena de caracteres, o string)
en donde los caracteres representan un número decimal.

La función deberá devolver en su valor de retorno si la cadena recibida contiene
o no un valor numérico en formato texto.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Siempre tiene que estar para trabajar con strings


static int validarFloat(char* stringRecibido);

int main(void)

{

	char numero[8]; // Defino una cadena de 8 lugares

	/*
	Prueba 1, con el número 3.14.
	numero[0] = '3';
	numero[1] = '.';
	numero[2] = '1';
	numero[3] = '4';
	numero[4] = '\0';
	// Otra opción es:
	// strcpy (numero, "3,14"); numero sería el destino, y "3.14" el origen.
	// snprintf(numero, 8,"%f", 3.14);
	*/


	/*
	Prueba 2, con la palabra "hola".

	numero[0] = 'h';
	numero[1] = 'o';
	numero[2] = 'l';
	numero[3] = 'a';
	numero[4] = '\0';
	*/

	/*
	// Prueba 3, con el número "-4.6".

	numero[0] = '-';
	numero[1] = '4';
	numero[2] = '.';
	numero[3] = '6';
	numero[4] = '\0';
	*/

	/*
	// Prueba 4, con el número "55.60".

	numero[0] = '5';
	numero[1] = '5';
	numero[2] = '.';
	numero[3] = '6';
	numero[4] = '0';
	*/

	// Llamo a la función validarFloat y le paso la cadena. Si esa función devuelve un 1 es porque la cadena que está acá es un número convertible a float.
	if(validarFloat(numero)==1)
	{
		printf("El número %s es válido, se puede convertir a float.\n", numero);
		printf("Es un número flotante %f.", atof(numero)); // Lo convierte a float y lo imprimo para verlo.
	}
	else
	{
		printf("El número %s es inválido, no se puede convertir a float.\n", numero);
		printf("No es un número flotante.");
	}
	return 0;
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
