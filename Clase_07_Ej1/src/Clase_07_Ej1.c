/*
 ============================================================================
Escribir la función calcularMayor(). La función debe recibir dos
números int y devolver por referencia el número mayor.
La función debe retornar un 1 si se encontró un mayor, o un 0 si ambos números son iguales.
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

	// Pedir dos números al usuario con utn_getNumero() y guardarlos en num1 y num2
	if(utn_getNumero(&num1, "Por favor, ingrese el primer número: ", "ERROR, ingrese un número entre -1000 y 1000", -1000, 1000, 2)==0)
	{
		printf("El primer número es: %d\n",num1);
	}
	else
	{
		printf("No se encontraron números.");
	}
	if(utn_getNumero(&num2, "Por favor, ingrese el segundo número: ", "ERROR, ingrese un número entre -1000 y 1000", -1000, 1000, 2)==0)
		{
			printf("El segundo número es: %d\n",num2);
		}
		else
		{
			printf("No se encontraron números.");
		}

	// Luego llamo a la función calcularMayor()
	if(calcularMayor(&resultado,num1,num2)==0) // Si la función es como resultado 0, los números son iguales.
	{
		printf("Los números son iguales\n");
	}
	else
	{
		printf("El mayor es: %d\n",resultado);
	}
}
