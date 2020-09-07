/*
 ============================================================================
 Solicitar al usuario que ingrese una serie de números la cual finaliza al introducir
 el 999 (el 999 no debe ser tenido en cuenta para dicho cálculo).
 Una vez finalizado el ingreso de números el programa deberá mostrar
 el promedio de dichos números por pantalla.
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
		printf("Ingrese un número: ");
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
