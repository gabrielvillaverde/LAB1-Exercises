/*
 ============================================================================
 Name        : Clase_16_Ej1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void saludar(void) // Esta funci�n no devuelve nada, lo �nico que hace es un printf.
{
	printf("Hola");
}

int main(void)
{
	// Si quiero declarar un puntero para esa funci�n, tengo que decir que no recibe nada (void al principio) y que no recibe nada (void al final).
	void (*pFuncion)(void);
	pFuncion = saludar; // A pFuncion le asigno la direcci�n de memoria de saludar. Los nombres de las funciones apuntan a donde est�n ubicadas ellas en memoria, es como llamar a printf o cualquier otra, NO VA EL &.
	pFuncion(); // Uso pFuncion como si fuese saludar.
	return EXIT_SUCCESS;
}
