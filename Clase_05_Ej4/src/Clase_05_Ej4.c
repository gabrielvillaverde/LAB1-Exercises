/*
 ============================================================================
Pedir 5 n�meros:

Pediremos el n�mero y lo guardaremos en el array.

- Opci�n 1 - Calcular m�ximo
- Opci�n 2 - Calcular promedio
- Opci�n 3 - Calcular m�nimo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"

#define CANTIDAD_ELEMENTOS 5 // Para poder definir con los array

int main(void)
{

	setbuf(stdout,NULL); // Windows

	int variableInt;
	char aMensaje[200];
	int arrayInt[CANTIDAD_ELEMENTOS];
	int flagCargaCorrecta = 0; // Flag de carga de datos correcta inicializado en 0.
	int maximo; // Para obtener el m�ximo, declaro esta variable.

	for(int i=0; i < CANTIDAD_ELEMENTOS; i++)
	{
		sprintf(aMensaje, "N�mero %d", i+1); // Imprime en un string, mensaje es un puntero, i+1 para adaptarlo a un humano porque es tonto.
		if(getInt(aMensaje,"Fuera de rango [0-1000]\n", &variableInt, 5, 1000, 0) != 0) // Si la funci�n getInt es distinta de 0, o sea, si da error.
		{
			printf("GAME OVER"); // Muestra el mensaje de GAME OVER.
			flagCargaCorrecta = -1; // Levanta el flag y lo modifica de 0 a -1.
			break; // Rompe la estructura iterativa.
		}
		else
		{
			arrayInt[i] = variableInt;
			// Si fue OK, el valor i del array obtiene el contenido de variableInt.
		}
	}
	if(flagCargaCorrecta == 0) // Si la carga fue correcta
	{
		if(calcularMaximo(arrayInt, CANTIDAD_ELEMENTOS, &maximo) == 0)
		{
			printf("\nEl m�ximo es: %d", maximo);
		}
		else
		{
			printf("\nError");
		}
	}
	return EXIT_SUCCESS;
}

/* Este ejercicio muestra el n�mero 22 de la variable i del array 1000 veces.
int main(void) {
	int variableInt;
	int arrayInt[1000];

	for(int i = 0; i<1000; i++)
	{
		arrayInt[i] = 22; // El array en todas sus posiciones tiene el valor 22.
		printf("%d", arrayInt[i]); // Quiero imprimir la posici�n i, que es variable y se modifica por el for.
		// Se imprime mil veces.
	}

	return EXIT_SUCCESS;
}
*/

