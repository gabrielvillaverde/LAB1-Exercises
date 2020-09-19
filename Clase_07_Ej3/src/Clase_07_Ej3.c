/*
 ============================================================================
Definir una funci�n validarFloat() que reciba un array de chars (cadena de caracteres, o string)
en donde los caracteres representan un n�mero decimal.

La funci�n deber� devolver en su valor de retorno si la cadena recibida contiene
o no un valor num�rico en formato texto.
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
	Prueba 1, con el n�mero 3.14.
	numero[0] = '3';
	numero[1] = '.';
	numero[2] = '1';
	numero[3] = '4';
	numero[4] = '\0';
	// Otra opci�n es:
	// strcpy (numero, "3,14"); numero ser�a el destino, y "3.14" el origen.
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
	// Prueba 3, con el n�mero "-4.6".

	numero[0] = '-';
	numero[1] = '4';
	numero[2] = '.';
	numero[3] = '6';
	numero[4] = '\0';
	*/

	/*
	// Prueba 4, con el n�mero "55.60".

	numero[0] = '5';
	numero[1] = '5';
	numero[2] = '.';
	numero[3] = '6';
	numero[4] = '0';
	*/

	// Llamo a la funci�n validarFloat y le paso la cadena. Si esa funci�n devuelve un 1 es porque la cadena que est� ac� es un n�mero convertible a float.
	if(validarFloat(numero)==1)
	{
		printf("El n�mero %s es v�lido, se puede convertir a float.\n", numero);
		printf("Es un n�mero flotante %f.", atof(numero)); // Lo convierte a float y lo imprimo para verlo.
	}
	else
	{
		printf("El n�mero %s es inv�lido, no se puede convertir a float.\n", numero);
		printf("No es un n�mero flotante.");
	}
	return 0;
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
