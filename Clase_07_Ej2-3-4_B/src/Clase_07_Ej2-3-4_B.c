/*
 ============================================================================
CON BIBLIOTECAS DE MAURICIO

Crear un programa que permita registrar el valor de temperatura m�xima de cada d�a de un mes.
Definir un array de floats de 31 posiciones. Cada posici�n corresponder� a un d�a del mes.
Hacer un programa con un men� de dos opciones:

1. Imprimir array.
2. Cargar array.

Al elegir la opci�n 1, se imprimir� el �ndice y el valor de cada posici�n del array.
Al elegir la opci�n 2, que le pida al usuario que ingrese un n�mero de d�a (1 al 31), y luego
que ingrese un valor de temperatura. Almacenar el valor en el �ndice correspondiente.

Ambas opciones deben volver al menu principal.

Utilizar la funci�n utn_getNumeroFloat() de la biblioteca utn.h
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define DIAS 31

int initArrayFlotante(float* pArray, int longitud, float valorInicial);
int imprimeArrayFlotante(float* pArray, int longitud);
int cargarTemperatura(float* pArray, int longitud);

int main(void) {

	setbuf(stdout,NULL);

	int respuesta;
	int opcion;
	float arrayTemperaturas[DIAS];

	// Si esta funci�n me devolvi� 0 (si sali� OK).
	if(initArrayFlotante(arrayTemperaturas, DIAS, -1000) == 0)
	{
		printf("\nArray inicializado correctamente");
	}
	do
	{
		respuesta = utn_getNumero(&opcion, "\n1. Imprimir array\n2. Cargar temperatura\n3. Salir", "\nOpci�n inv�lida.", 1, 3, 1);
		if(respuesta == 0) // Si la respuesta de la funci�n es 0, significa que sali� OK.
		{
			switch(opcion)
			{
			case 1:
				printf("\nIMPRIMIR ARRAY");
				imprimeArrayFlotante(arrayTemperaturas,DIAS);
				break;
			case 2:
				printf("\nCARGAR TEMPERATURA ARRAY");
				cargarTemperatura(arrayTemperaturas,DIAS);
				break;

			}
		}
	}while(opcion!=3); // Mientras que la opci�n elegida sea distinta de 3 (que es la de salida)

	return EXIT_SUCCESS;
}

/**
 * \brief inicializa un array de flotantes
 * \param pArray Puntero al array
 * \param longitud Define el tama�o del array
 * \param valorInicial Es el valor a ser cargado en todas las posiciones del array
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */

int initArrayFlotante(float* pArray, int longitud, float valorInicial)
{
	int retorno = -1;
	int i;

	// Verifico que el puntero al array sea distinto de NULL y la longitud sea mayor a 0.
	if(pArray != NULL && longitud > 0)
	{
		retorno = 0;
		// Realizo un for que me permita recorrer el array desde el �ndice 0.
		// Mientras que el �ndice sea menor a la longitud, incrementar� el �ndice en 1.
		for(i=0 ; i<longitud ; i++)
		{
			// En cada posici�n del array, voy a cargar el valor inicial.
			pArray[i] = valorInicial;
		}
	}
	return retorno;
}

/**
 * \brief Imprime un array de flotantes
 * \param pArray Puntero al array
 * \param longitud Define el tama�o del array
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */

int imprimeArrayFlotante(float* pArray, int longitud)
{
	int retorno = -1;
	int i;

	// Verifico que el puntero al array sea distinto de NULL y la longitud sea mayor a 0.
	if(pArray != NULL && longitud > 0)
	{
		retorno = 0;
		// Realizo un for que me permita recorrer el array desde el �ndice 0.
		// Mientras que el �ndice sea menor a la longitud, incrementar� el �ndice en 1.
		for(i=0 ; i<longitud ; i++)
		{
			// Imprimo el �ndice, el d�a (que siempre es uno m�s que el �ndice) y el valor de cada elemento del array.
			printf("\n�ndice: [%d] - Dia: [%d] - Valor: %.2f", i, i+1, pArray[i]);
		}
	}
	return retorno;
}

/**
 * \brief Carga una temperatura en el array
 * \param pArray Puntero al array
 * \param longitud Define el tama�o del array
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */

int cargarTemperatura(float* pArray, int longitud)
{
	int retorno = -1;
	int respuesta;
	int dia; // Le voy a tener que restar siempre -1 para guardarmela en el array.
	float temperatura;


	// Verifico que el puntero al array sea distinto de NULL y la longitud sea mayor a 0.
	if(pArray != NULL && longitud > 0)
	{
		retorno = 0;
		respuesta = utn_getNumero(&dia, "\n�Qu� d�a quiere modificar?", "\nD�a inv�lido, es del d�a 1 al 31", 1, 31, 2);

		// Si la respuesta es == 0, es decir, ingres� un d�a v�lido entre 1 y 31.
		if(respuesta == 0)
		{
			// ...estoy en condiciones de pedir la temperatura.
			respuesta = utn_getNumeroFlotante(&temperatura, "\nIndique la temperatura: ", "\nError, fuera de rango.", -50, 70, 2);

			// Si la respuesta es == 0, es decir, si la temperatura ingresada es entre -50 y 70...
			if(respuesta == 0)
			{
				// En la posici�n del array dia, ajustada menos 1, voy a cargar lo que el usuario ingres� en temperatura.
				pArray[dia-1] = temperatura;
			}
		}
	}
	return retorno;
}
