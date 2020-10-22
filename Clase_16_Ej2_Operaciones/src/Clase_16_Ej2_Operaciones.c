/*
 ============================================================================
 Name        : Clase_16_Ej2_Operaciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void sumar(int parametroA, int parametroB, int * pResultado)
{
	*pResultado = parametroA + parametroB;
}

void restar(int parametroA, int parametroB, int * pResultado)
{
	*pResultado = parametroA - parametroB;
}

/* El tercer par�metro de esta funci�n es un puntero a una funci�n que tenga la siguiente firma: void(ac� usa el puntero a la funci�n)(int, int, int *)).
Las funciones sumar y restar cumplen con los requisitos, por eso pueden ser llamadas por calcular. */
int calcular(int parametroA, int parametroB, void(*pFuncion)(int, int, int *))
{
	int auxResultado;
	pFuncion(parametroA, parametroB, &auxResultado); // A trav�s del puntero pFuncion, le pasa los dos par�metros A y B, y el espacio del resultado.
	return auxResultado;
}

int main(void)
{
	int auxiliar; // Declaro un auxiliar para que me devuelva el valor

	auxiliar = calcular(10, 5, restar); // Llamo a calcular y le paso 10, 5, y la direcci�n de memoria de restar.
	printf("El resultado de la resta es: %d\n", auxiliar);

	auxiliar = calcular(10, 5, sumar);
	printf("El resultado de la suma es: %d\n", auxiliar);

	return EXIT_SUCCESS;
}
