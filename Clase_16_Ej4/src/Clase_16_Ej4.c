/*
 ============================================================================
Puntero a función
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef int (*tipoPunteroAFuncionSaludar)(char *, int); // Esto es como definir un tipo de puntero a función

int saludarEsp(char * mensaje, int numero)
{
	printf("HOLA %s - %d\n", mensaje, numero);
	return 0; // Retorna 0 si está todo OK.
}

int saludarIng(char * mensaje, int numero)
{
	printf("HELLO %s - %d", mensaje, numero);
	return 0; // Retorna 0 si está todo OK.
}

void saludo(char * mensaje, int numero, tipoPunteroAFuncionSaludar pFuncionSaludar)
{
	pFuncionSaludar(mensaje, numero);
}

int main(void)
{
	saludo("Probando español", 222, saludarEsp);
	saludo("Probando inglés", 222, saludarIng);
	return EXIT_SUCCESS;
}
