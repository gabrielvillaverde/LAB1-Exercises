/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	//Ejercicio: Pedir 5 numeros enteros y mostrar el promedio
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
}

/*
int main(void) {

	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int resultado;
	int respuestaScanf;

	printf("Numero 1: ");
	fflush(stdin); // __fpurge(stdin); es de Linux, implica modificar la biblioteca de la línea 11. Ver video.
	respuestaScanf = scanf("%d",&numero1);
	while(respuestaScanf == 0)
	{
		printf("Error Numero 1: ");
		fflush(stdin);
		respuestaScanf = scanf("%d",&numero1);
	}

	printf("\nNumero 2: ");
	fflush(stdin);
	respuestaScanf = scanf("%d",&numero2);
	while(respuestaScanf == 0)
		{
			printf("Error Numero 2: ");
			fflush(stdin);
			respuestaScanf = scanf("%d",&numero2);
		}

	resultado = numero1 + numero2;
	printf("\nEl resultado es %d", resultado);

	return EXIT_SUCCESS;
}
*/
