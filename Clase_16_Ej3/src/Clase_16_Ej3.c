/*
 ============================================================================
Puntero a función
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int saludar(char * mensaje, int numero)
{
	printf("%s - %d", mensaje, numero);
	return 0; // Retorna 0 si está todo OK.
}

int main(void)
{
	int (*pFuncionSaludar)(char *, int); // Declaro mi puntero a la función saludar.
	pFuncionSaludar = saludar; // Asigno la dirección de memoria de saludar a pSaludar.

	if(pFuncionSaludar("HOLA", 22) == 0)
	{
		printf("\nTodo OK.\n");
	}
	return EXIT_SUCCESS;
}



