/*
 ============================================================================
 Solicitar al usuario que ingrese una serie de n�meros la cual finaliza al introducir
 el 999 (el 999 no debe ser tenido en cuenta para dicho c�lculo).
 Una vez finalizado el ingreso de n�meros el programa deber� mostrar
 el promedio de dichos n�meros por pantalla.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL); // Windows

	int acumulador = 0; // A
	int numero; // B
	int contador = 0; // C
	float promedio; // D

	while(1){ // E
		printf("Ingrese un n�mero: ");
		scanf("%d",&numero); // F
		if(numero!=999){ // G
			acumulador+=numero; // H
			contador++;
		}
		else{
			break; // I
		}
	}
	promedio =  (float) acumulador / contador; // J
	printf("\n El promedio es: %.2f",promedio);

	return EXIT_SUCCESS;
}
