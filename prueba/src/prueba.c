/*
 ============================================================================
 Name        : prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumar(int num1, int num2);

int main(void) {
	setbuf(stdout,NULL);
	int primerNum;
	int segundoNum;
	int resultado;

	printf("Ingrese número 1: ");
	scanf("%d",&primerNum);

	printf("Ingrese número 2: ");
	scanf("%d",&segundoNum);

	resultado = sumar(num1, num2);
	printf("El resultado es: %d", resultado);

	return EXIT_SUCCESS;
}


int sumar(int num1, int num2)
{
	int resultado;
	resultado = num1 + num2;
	return resultado;
}
