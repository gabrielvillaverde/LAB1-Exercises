/*
 ============================================================================
 Name        : Clase_04_Ej4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

// Funci�n principal
int main(void) {

	setbuf(stdout,NULL);

	int edad;

	if(utn_getNumero(&edad,1,120, "Ingrese edad: ", "Ingrese una edad correcta.",2) == 0){
		printf("Ingresaste: %d", edad);
	}

	return EXIT_SUCCESS;
}
