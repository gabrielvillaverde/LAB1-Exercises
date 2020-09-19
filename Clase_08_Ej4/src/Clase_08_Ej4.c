/*
 ============================================================================
4) Dada la siguiente cadena de caracteres:
	char nombre[8]={'p','e','p','e','1','2','3','\0'};
Hacer una función que reciba el array y su tamaño, y cuente cuantas veces
aparece la letra 'e'. Al terminar de contar, la función deberá imprimir por pantalla
el valor contado. Escribir un programa para probar la función.

 ============================================================================
 */


// Misma idea pero en vez de números son letras

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_LETRAS 8

// Prototipos:
int contarLetrasE(int* pResultado, char* pArray, int limite);

int main(void) {

	setbuf(stdout,NULL);

	char nombre[8]={'p','e','p','e','1','2','3','\0'};

	int resultado;
	int respuestaDeFuncion;

	respuestaDeFuncion = contarLetrasE(&resultado,nombre,CANTIDAD_LETRAS);
	if(respuestaDeFuncion == 0)
	{
		printf("\nLa cantidad de letras E que hay son: %d", resultado);
	}

	return EXIT_SUCCESS;
}

// Devuelve por valor de referencia.
int contarLetrasE(int* pResultado, char* pArray, int limite)
{
	int retorno = -1;
	int i;
	int contadorDeE = 0;
	if(pArray != NULL && limite >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i] == 'e')
			{
				contadorDeE++;
			}
		}
		*pResultado = contadorDeE;
		retorno = 0;
	}
	return retorno;
}
