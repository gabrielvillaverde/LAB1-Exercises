/*
 ============================================================================
CON BIBLIOTECAS DE MAURICIO

Crear un programa que permita registrar el valor de temperatura máxima de cada día de un mes.
Definir un array de floats de 31 posiciones. Cada posición corresponderá a un día del mes.
Hacer un programa con un menú de dos opciones:

1. Imprimir array.
2. Cargar array.

Al elegir la opción 1, se imprimirá el índice y el valor de cada posición del array.
Al elegir la opción 2, que le pida al usuario que ingrese un número de día (1 al 31), y luego
que ingrese un valor de temperatura. Almacenar el valor en el índice correspondiente.

Ambas opciones deben volver al menu principal.

Utilizar la función utn_getNumeroFloat() de la biblioteca utn.h
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

	// Si esta función me devolvió 0 (si salió OK).
	if(initArrayFlotante(arrayTemperaturas, DIAS, -1000) == 0)
	{
		printf("\nArray inicializado correctamente");
	}
	do
	{
		respuesta = utn_getNumero(&opcion, "\n1. Imprimir array\n2. Cargar temperatura\n3. Salir", "\nOpción inválida.", 1, 3, 1);
		if(respuesta == 0) // Si la respuesta de la función es 0, significa que salió OK.
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
	}while(opcion!=3); // Mientras que la opción elegida sea distinta de 3 (que es la de salida)

	return EXIT_SUCCESS;
}

/**
 * \brief inicializa un array de flotantes
 * \param pArray Puntero al array
 * \param longitud Define el tamaño del array
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
		// Realizo un for que me permita recorrer el array desde el índice 0.
		// Mientras que el índice sea menor a la longitud, incrementaré el índice en 1.
		for(i=0 ; i<longitud ; i++)
		{
			// En cada posición del array, voy a cargar el valor inicial.
			pArray[i] = valorInicial;
		}
	}
	return retorno;
}

/**
 * \brief Imprime un array de flotantes
 * \param pArray Puntero al array
 * \param longitud Define el tamaño del array
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
		// Realizo un for que me permita recorrer el array desde el índice 0.
		// Mientras que el índice sea menor a la longitud, incrementaré el índice en 1.
		for(i=0 ; i<longitud ; i++)
		{
			// Imprimo el índice, el día (que siempre es uno más que el índice) y el valor de cada elemento del array.
			printf("\nÍndice: [%d] - Dia: [%d] - Valor: %.2f", i, i+1, pArray[i]);
		}
	}
	return retorno;
}

/**
 * \brief Carga una temperatura en el array
 * \param pArray Puntero al array
 * \param longitud Define el tamaño del array
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
		respuesta = utn_getNumero(&dia, "\n¿Qué día quiere modificar?", "\nDía inválido, es del día 1 al 31", 1, 31, 2);

		// Si la respuesta es == 0, es decir, ingresó un día válido entre 1 y 31.
		if(respuesta == 0)
		{
			// ...estoy en condiciones de pedir la temperatura.
			respuesta = utn_getNumeroFlotante(&temperatura, "\nIndique la temperatura: ", "\nError, fuera de rango.", -50, 70, 2);

			// Si la respuesta es == 0, es decir, si la temperatura ingresada es entre -50 y 70...
			if(respuesta == 0)
			{
				// En la posición del array dia, ajustada menos 1, voy a cargar lo que el usuario ingresó en temperatura.
				pArray[dia-1] = temperatura;
			}
		}
	}
	return retorno;
}
