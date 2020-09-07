/*
 ============================================================================
 Name        : Clase_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Pedir 5 numeros y mostrar promedio. */

int main(void) {

	setbuf(stdout,NULL);

	int numero;
	int acumulador=0;
	float promedio;
	int respuestaScan;
	int i;

	for(i = 0; i < 5; i++){
		printf("\nIngrese un numero: ");
		respuestaScan = scanf("%d", &numero);
		while(respuestaScan == 0){
			printf("Error, reingrese el numero");
			fflush(stdin);
			respuestaScan = scanf("%d", &numero);
		}
		acumulador += numero;
	}
	promedio = (float)acumulador / i;
	printf("\nEl promedio es: %.2f", promedio);
	return EXIT_SUCCESS;
}
