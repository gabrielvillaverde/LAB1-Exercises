/*
 ============================================================================
Escribir la funci�n calcularMayor(). La funci�n debe recibir dos
n�meros int y devolver por referencia el n�mero mayor.
La funci�n debe retornar un 1 si se encontr� un mayor, o un 0 si ambos n�meros son iguales.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)

{
	setbuf(stdout,NULL);
	int resultado;
	int num1,num2;

	// Pedir dos n�meros al usuario con utn_getNumero() y guardarlos en num1 y num2
	if(utn_getNumero(&num1, "Por favor, ingrese el primer n�mero: ", "ERROR, ingrese un n�mero entre -1000 y 1000", -1000, 1000, 2)==0)
	{
		printf("El primer n�mero es: %d\n",num1);
	}
	else
	{
		printf("No se encontraron n�meros.");
	}
	if(utn_getNumero(&num2, "Por favor, ingrese el segundo n�mero: ", "ERROR, ingrese un n�mero entre -1000 y 1000", -1000, 1000, 2)==0)
		{
			printf("El segundo n�mero es: %d\n",num2);
		}
		else
		{
			printf("No se encontraron n�meros.");
		}

	// Luego llamo a la funci�n calcularMayor()
	if(calcularMayor(&resultado,num1,num2)==0) // Si la funci�n es como resultado 0, los n�meros son iguales.
	{
		printf("Los n�meros son iguales\n");
	}
	else
	{
		printf("El mayor es: %d\n",resultado);
	}
}
