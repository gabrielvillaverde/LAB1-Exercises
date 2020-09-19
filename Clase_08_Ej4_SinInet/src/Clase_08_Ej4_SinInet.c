/*
 ============================================================================
Dada la siguiente cadena de caracteres:
char nombre[8]={'p','e','p','e','1','2','3','\9'}

Hacer una funci�n que reciba el array y su tama�o.
Y cuente cu�ntas veces aparece la letra 'e'. Al terminar de contar,
la funci�n deber� imprimir por pantalla el valor contado.
Escribir un programa para probar la funci�n.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_LETRAS 8

// Prototipos:
int contarLetrasE(int* pResultado, char* pArray);

int main(void) {

	setbuf(stdout,NULL);

	int resultado;
	char letras[CANTIDAD_LETRAS] = {'p','e','p','e','1','2','3','\0'};
	int respuestaDeFuncion;

	respuestaDeFuncion = contarLetrasE(&resultado,letras);
	if(respuestaDeFuncion == 0)
	{
		printf("\nLa cantidad de letras E que hay son: %d", resultado);
	}

	return EXIT_SUCCESS;
}

// A diferencia del contador de sietes, saca el par�metro de l�mite porque te lo dice el mismo \0.
// Devuelve por valor de referencia.
int contarLetrasE(int* pResultado, char* pArray)
{
	int retorno = -1;
	int i = 0; // Esto es del for
	int contadorDeLetrasE = 0;
	if(pArray != NULL && pResultado != NULL)
	{
		// for(i=0;i<limite;i++)
		while(pArray[i] != '\0') // Iterar� mientras el �ndice sea distinto de \0
		{
			if(pArray[i] == 'e')
			{
				contadorDeLetrasE++;
			}
			i++; // Esto es del for
		}
		*pResultado = contadorDeLetrasE;
		retorno = 0;
	}
	return retorno;
}
