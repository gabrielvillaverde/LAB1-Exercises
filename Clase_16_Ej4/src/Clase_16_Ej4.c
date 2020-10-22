/*
 ============================================================================
Puntero a funci�n
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef int (*tipoPunteroAFuncionSaludar)(char *, int); // Esto es como definir un tipo de puntero a funci�n

int saludarEsp(char * mensaje, int numero)
{
	printf("HOLA %s - %d\n", mensaje, numero);
	return 0; // Retorna 0 si est� todo OK.
}

int saludarIng(char * mensaje, int numero)
{
	printf("HELLO %s - %d", mensaje, numero);
	return 0; // Retorna 0 si est� todo OK.
}

void saludo(char * mensaje, int numero, tipoPunteroAFuncionSaludar pFuncionSaludar)
{
	pFuncionSaludar(mensaje, numero);
}

int main(void)
{
	saludo("Probando espa�ol", 222, saludarEsp);
	saludo("Probando ingl�s", 222, saludarIng);
	return EXIT_SUCCESS;
}
