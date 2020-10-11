/*
 * pantalla.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

static int pantalla_generarNuevoId (void); // Prototipo

static int pantalla_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

/*Recibe como parámetro un puntero al array del tipo de dato Pantalla y un límite.
Devuelve un entero, -1 y 0.
Recorre todo el array, e indica que el campo isEmpty está todo vacío.*/
int pantalla_init(Pantalla * pArrayPantalla, int limitePantalla)
{
	int retorno = -1;
	if (pArrayPantalla != NULL && limitePantalla >0)
	{
		for (int i = 0 ; i < limitePantalla ; i++)
		{
			pArrayPantalla[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Pantalla y un límite.
Devuelve un entero, -1 y 0.*/
int pantalla_alta (Pantalla * pArrayPantalla, int limitePantalla)
{
	int retorno = -1;
	int indice;

	Pantalla bufferPantalla;
	if (pArrayPantalla != NULL && limitePantalla > 0)
	{
		if (pantalla_buscarLibreRef (pArrayPantalla, limitePantalla, &indice) == 0)
		{
			// No entiendo por qué a bufferPantalla.tipo y bufferPantalla.precio hay que pasarle un & y a las otras dos no.
			if (utn_getNumberInt("\nIngrese el tipo de pantalla que quiere: [LCD - 0] - [LED - 1]", "Error, debe ingresar el número 0 para LCD y 1 para LED", &bufferPantalla.tipo, 2, 0, 1) == 0 &&
				utn_getNumberFloat("\nIngrese el precio:\n", "Error, ingrese un precio válido entre $1,00 y $10,000.\n", &bufferPantalla.precio, 2, 1, 10000) == 0 &&
				utn_getName("\nIngrese el nombre del video:\n", "Error, ingrese un nombre válido.\n", bufferPantalla.nombre, 2, LONG) == 0 &&
				utn_getAlphaNum("\nIngrese su dirección:\n", "Error, ingrese una dirección válida.\n", bufferPantalla.direccion, 2, LONG) == 0)
			{
				pArrayPantalla[indice] = bufferPantalla;
				pArrayPantalla[indice].idPantalla = pantalla_generarNuevoId();
				pArrayPantalla[indice].isEmpty = FALSE;
			}
		}
		else
		{
			printf("\nNo quedan espacios libres\n");
		}
	}
	return retorno;
}

// La explicación de esta función es en el minuto 19:15 de la clase.
int pantalla_altaForzada(Pantalla * pArrayPantalla, int limitePantalla, char * nombre, int tipo, float precio, char * direccion)
{
	int retorno = -1;
	if (pArrayPantalla != NULL && limitePantalla >0)
	{
		for (int i = 0; i<limitePantalla; i++ )
		{
			pArrayPantalla[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Pantalla y un límite.
Devuelve un entero, -1 y 0.*/
int pantalla_baja (Pantalla * pArrayPantalla, int limitePantalla)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArrayPantalla != NULL && limitePantalla > 0)
	{
		pantalla_imprimir(pArrayPantalla, limitePantalla);
		if(utn_getNumberInt("\nIngrese ID de la pantalla que quiere borrar:\n","\nError.\n",&idABorrar,2,0,9999)==0)
		{
			// Busco la posición que quiero borrar
			if(pantalla_buscarIndicePorId(pArrayPantalla,limitePantalla,idABorrar,&indiceABorrar)==0)
			{
				// Borro esa posición
				pArrayPantalla[indiceABorrar].isEmpty = TRUE;
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Pantalla y un límite.
Devuelve un entero, -1 y 0.*/
int pantalla_modificar (Pantalla * pArrayPantalla, int limitePantalla)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;

	Pantalla bufferPantalla;
	if (pArrayPantalla != NULL && limitePantalla> 0)
	{
		// Le imprimo los datos de las pantallas al usuario para que pueda elegir.
		pantalla_imprimir(pArrayPantalla, limitePantalla);

		if(utn_getNumberInt("\nIngrese el ID de la pantalla que desea modificar:\n","\nError, ingrese un ID válido entre 0 y 9999.\n",&idBuscar,2,0,9999)==0)
		{
			if(pantalla_buscarIndicePorId(pArrayPantalla, limitePantalla,idBuscar,&indiceAModificar)==0)
			{
				bufferPantalla = pArrayPantalla[indiceAModificar]; // IMPORTANTE!

				if (utn_getNumberInt("\nIngrese el nuevo tipo de pantalla que quiere: [LCD - 0] - [LED - 1]", "Error, debe ingresar el número 0 para LCD y 1 para LED", &bufferPantalla.tipo, 2, 0, 1) == 0 &&
					utn_getNumberFloat("\nIngrese el nuevo precio:\n", "Error, ingrese un precio válido entre $1,00 y $10,000.\n", &bufferPantalla.precio, 2, 1, 10000) == 0 &&
					utn_getName("\nIngrese el nuevo nombre del video:\n", "Error, ingrese un nombre válido.\n", bufferPantalla.nombre, 2, LONG) == 0 &&
					utn_getAlphaNum("\nIngrese su nueva dirección:\n", "Error, ingrese una dirección válida.\n", bufferPantalla.direccion, 2, LONG) == 0)
				{
					pArrayPantalla[indiceAModificar] = bufferPantalla; // COPIAMOS AL ARRAY
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Pantalla y un límite.
Devuelve un entero, -1 y 0.*/
int pantalla_imprimir (Pantalla * pArrayPantalla , int limitePantalla)
{
	int retorno = -1;
	char strTipo[8]; // Le doy un valor chico porque las palabras que quiero son LED y LCD.

	if (pArrayPantalla != NULL && limitePantalla > 0)
	{
		for (int i = 0 ; i < limitePantalla ; i++)
		{
			if(pArrayPantalla[i].isEmpty == FALSE) // Si la posición "i" del array NO está vacía.
			{
				// Evaluo el número y cargo en strTipo = LCD o LED
				if(pArrayPantalla[i].tipo == PANTALLA_TIPO_LCD)
				{
					// strcpy es otra opción válida en vez de sprintf.
					sprintf(strTipo,"LCD"); // Cargo la cadena strTipo con LCD.
				}
				else
					sprintf(strTipo,"LED"); // Cargo la cadena strTipo con LED.
				printf("\nNombre del video: %s - Dirección: %s - ID: %d - Tipo: %s - Precio: %.2f\n",pArrayPantalla[i].nombre,pArrayPantalla[i].direccion, pArrayPantalla[i].idPantalla, strTipo, pArrayPantalla[i].precio);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Pantalla y un límite.
Devuelve un entero, -1 y 0. Retorna el valor del índice por valor, NO por referencia.
*/
int pantalla_buscarLibre (Pantalla * pArrayPantalla, int limitePantalla)
{
	int retorno = -1;
	int i;

	if (pArrayPantalla != NULL && limitePantalla > 0)
	{
		for ( i = 0 ; i < limitePantalla ; i++)
		{
			if(pArrayPantalla[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Pantalla y un límite.
Devuelve un entero, -1 y 0.
Recibe también el puntero del índice, devuelve el índice por referencia.*/
int pantalla_buscarLibreRef (Pantalla * pArrayPantalla, int limitePantalla, int * pIndice)
{
	int retorno = -1;
	int i;

	if (pArrayPantalla != NULL && limitePantalla > 0 && pIndice != NULL)
	{
		for (i = 0 ; i < limitePantalla ; i++)
		{
			if(pArrayPantalla[i].isEmpty == TRUE)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Pantalla y un límite.
Devuelve un entero, -1 y 0.
Recibe el parámetro del ID a buscar.
Recibe también el puntero del índice, devuelve el índice por referencia.*/
int pantalla_buscarIndicePorId (Pantalla * pArrayPantalla, int limitePantalla, int idBuscar, int * pIndice)
{
	int retorno = -1;
	int i ;

	if (pArrayPantalla != NULL && limitePantalla > 0 && pIndice != NULL && idBuscar >= 0)
	{
		for (i = 0 ; i < limitePantalla ; i++)
		{
			if(pArrayPantalla[i].isEmpty == FALSE && pArrayPantalla[i].idPantalla == idBuscar)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Pantalla y un límite.
Devuelve un entero, -1 y 0.
Si ordena por nombre, tiene que recibir el parámetro de orden. */
int pantalla_ordenarPorNombre (Pantalla * pArrayPantalla, int limitePantalla , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Pantalla aux;

	if (pArrayPantalla != NULL && limitePantalla > 0 && (orden == 1 || orden == 0))
	{
		while(estadoDesordenado) // Mientras esté desordenado
		{
			estadoDesordenado = 0;
			for(int i = 0 ; i < (limitePantalla - 1) ; i++)
			{
				if( (orden == 1 && strncmp(pArrayPantalla[i].nombre, pArrayPantalla[i + 1].nombre,LONG) > 0)
						||
					(orden == 0 && strncmp(pArrayPantalla[i].nombre, pArrayPantalla[i + 1].nombre,LONG) < 0) )
				{
					aux = pArrayPantalla[i];
					pArrayPantalla[i] = pArrayPantalla[i + 1];
					pArrayPantalla[i + 1] = aux;
					estadoDesordenado = 1;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
