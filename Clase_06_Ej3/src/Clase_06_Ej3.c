/*
 ============================================================================
1) agregarle al codigo del martes (usuario que ingresa numeros y se guarda en array)
la funcion de ordenar
2) hacer la funcion para imprimir el array
3) imprimir el array antes de ordenar y despues.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define ARRAY_SIZE 5

int main(void) {
	setbuf(stdout,NULL);
	int variableInt;
	int arrayInt[ARRAY_SIZE];
	int flagCargaCorrecta = 0;
	int maximoInt;
	for(int i=0; i < ARRAY_SIZE ; i++)
	{
		if(utn_getInt("\nNumero: ","Fuera de rango [0-1000]\n",&variableInt,5,1000,0) != 0)
		{
			printf("GAME OVER");
			flagCargaCorrecta = -1;
			break;
		}
		else
		{
			arrayInt[i] = variableInt;
		}
	}
	if(flagCargaCorrecta == 0)
	{
		maximoInt = arrayInt[0];
		for(int i=0; i<5; i++)
		{
			if(arrayInt[i] > maximoInt)
			{
				maximoInt = arrayInt[i];
			}
		}
		printf("El maximo es: %d", maximoInt);

		imprimirArray(arrayInt, ARRAY_SIZE);
		ordenar(arrayInt, ARRAY_SIZE);
		printf("\n\nArray ordenado!\n");
		imprimirArray(arrayInt, ARRAY_SIZE);
	}
	return EXIT_SUCCESS;
}

