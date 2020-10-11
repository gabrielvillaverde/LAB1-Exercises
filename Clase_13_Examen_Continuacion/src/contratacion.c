/*
 * contratacion.c
 *
 *  Created on: 6 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contratacion.h"
#include "utn.h"

static int contratacion_generarNuevoId (void); // Prototipo

static int contratacion_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

int contratacion_init (Contratacion * pArray, int limite)
{
	int retorno = -1;
	if (pArray != NULL && limite > 0)
	{
		for (int i = 0; i < limite ; i++)
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

int contratacion_alta (Contratacion * pArray, int limite, Pantalla * pArrayPantalla, int limitePantalla)
{
	int retorno = -1;
	int indice;

	Contratacion bufferContratacion;

	if (pArray != NULL && limite > 0)
	{
		if (contratacion_buscarLibreRef (pArray, limite, &indice) == 0)
		{
		pantalla_imprimir(pArrayPantalla, limitePantalla);
			if (utn_getNumberInt("\nIngrese el ID de la pantalla que quiere contratar;\n", "\nError, intente nuevamente.\n", &bufferContratacion.idPantalla, 2, 0, 9999) == 0 &&
				pantalla_buscarIndicePorId(pArrayPantalla, limitePantalla, bufferContratacion.idPantalla, &indice /* No estoy seguro del índice. */) != -1 &&
				utn_getAlphaNum("\nIngrese el nombre del video a contratar:\n", "\nError, nombre de video inválido.\n", bufferContratacion.nombreVideo, 2, LONG) == 0 &&
				utn_getNumberInt("\nIngrese su CUIT:\n", "\nError, ingrese un CUIT válido.\n",&bufferContratacion.cuit, 2, 0, 99999999) == 0 &&
				utn_getNumberInt("\nIngrese la cantidad de días que quiere contratar el video:\n", "\nError, solo puede ingresar valores numéricos.\n", &bufferContratacion.cantidadDias, 2, 0, 9999) == 0)
			{
					pArray[indice] = bufferContratacion;
					pArray[indice].idContratacion = contratacion_generarNuevoId();
					pArray[indice].isEmpty = FALSE;
			}
			else
			{
				printf("\nNo quedan espacios libres.\n");
			}
		}
	}
	return retorno;
}

int contratacion_baja (Contratacion * pArray, int limite, Pantalla * pArrayPantalla, int limitePantalla)
{
	int retorno = -1;
	int cuitABorrar; // En vez de borrar por ID, borro por CUIT.
	int indiceABorrar;

	if (pArray != NULL && limite > 0)
	{
		contratacion_imprimir(pArray, limite, pArrayPantalla, limitePantalla); // Imprimo los 4 parámetros.
		if(utn_getNumberInt("\nIngrese CUIT a borrar:\n","\nError, CUIT inválido.\n",&cuitABorrar,2,0,9999) == 0)
		{
			// Busco el CUIT que quiero borrar.
			if(contratacion_buscarIndicePorCuit(pArray,limite,cuitABorrar,&indiceABorrar) == 0)
			{
				// Borro esa posición.
				pArray[indiceABorrar].isEmpty = TRUE;
			}
		}
	}
	return retorno;
}

int contratacion_modificar (Contratacion * pArray, int limite, Pantalla * pArrayPantalla, int limitePantalla)
{
	int retorno = -1;
	int idBuscar;
	int cuitBuscar;
	int indiceAModificar;

	Contratacion bufferContratacion;

	if (pArray != NULL && limite > 0)
	{
		if(utn_getNumberInt("\nIngrese su CUIT:\n", "\nCUIT inválido.\n", &cuitBuscar, 2, 0, 99999999) == 0)
		{
			if(contratacion_imprimirPorCuit(pArray, limite, pArrayPantalla, limitePantalla, cuitBuscar) == 0)
			{
				if(utn_getNumberInt("Ingrese el ID de la contratación que quiere modificar:\n", "Error, ID inválido.\n", &idBuscar, 2, 0, 9999) == 0)
				{
					if(contratacion_buscarIndicePorId(pArray, limite, idBuscar, &indiceAModificar) == 0)
					{
						bufferContratacion = pArray[indiceAModificar];

						if (utn_getNumberInt("\nIngrese el ID de la pantalla que quiere modificar;\n", "\nError, intente nuevamente.\n", &bufferContratacion.idPantalla, 2, 0, 9999) == 0 &&
							pantalla_buscarIndicePorId(pArrayPantalla, limitePantalla, bufferContratacion.idPantalla, &indiceAModificar /* No estoy seguro del índice. */) != -1 &&
							utn_getAlphaNum("\nIngrese el nombre del video a modificar:\n", "\nError, nombre de video inválido.\n", bufferContratacion.nombreVideo, 2, LONG) == 0 &&
							utn_getNumberInt("\nIngrese la nueva cantidad de días:\n", "\nError, solo puede ingresar valores numéricos.\n", &bufferContratacion.cantidadDias, 2, 0, 9999) == 0)
						{
							pArray[indiceAModificar] = bufferContratacion;
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}

int contratacion_imprimir (Contratacion * pArray, int limite, Pantalla * pArrayPantalla, int limitePantalla)
{
	int retorno = -1;
	int indicePantalla;
	if (pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0)
	{
		for (int i = 0 ; i < limite ; i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				pantalla_buscarIndicePorId(pArrayPantalla, limitePantalla, pArray[i].idPantalla, &indicePantalla);
				printf("\nNombre del video: %s - CUIT: %d - Cantidad de días de contratación: %d - ID de la contratación: %d\n",pArray[i].nombreVideo,pArray[i].cuit,pArray[i].cantidadDias,pArray[i].idContratacion);
				pantalla_imprimir(pArrayPantalla, limitePantalla);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int contratacion_imprimirPorCuit (Contratacion * pArray, int limite, Pantalla * pArrayPantalla, int limitePantalla, int cuit)
{
	int retorno = -1;
	int indicePantalla;

	if (pArray != NULL && limite > 0 && pArrayPantalla != NULL && limitePantalla > 0)
	{
		for(int i ; i < limite ; i++)
		{
			if(pArray[i].cuit == cuit)
			{
				pantalla_buscarIndicePorId(pArrayPantalla, limitePantalla, pArray[i].idPantalla, &indicePantalla);
				printf("\nNombre del video: %s - CUIT: %d - Cantidad de días de contratación: %d - ID de la contratación: %d\n",pArray[i].nombreVideo,pArray[i].cuit,pArray[i].cantidadDias,pArray[i].idContratacion);
				pantalla_imprimir(pArrayPantalla, limitePantalla);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int contratacion_buscarLibre (Contratacion * pArray, int limite){
	int retorno = -1;
	int i ;
		if (pArray != NULL && limite >0){
			for ( i = 0; i<limite; i++) {
				if(pArray[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int contratacion_buscarLibreRef (Contratacion * pArray, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArray != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArray[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}

int contratacion_buscarIndicePorId (Contratacion * pArray, int limite, int idBuscar, int * pIndice)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0 && pIndice != NULL && idBuscar >= 0)
	{
		for (i = 0; i < limite ; i++)
		{
			if(pArray[i].isEmpty == FALSE && pArray[i].idContratacion == idBuscar)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int contratacion_buscarIndicePorCuit (Contratacion * pArray, int limite, int cuitBuscar, int * pIndice)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite > 0 && pIndice != NULL && cuitBuscar >= 0)
	{
		for (i = 0; i < limite ; i++)
		{
			if(pArray[i].isEmpty == FALSE && pArray[i].cuit == cuitBuscar)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int contratacion_ordenarPorNombre (Contratacion * pArray, int limite , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Contratacion aux;

	if (pArray != NULL && limite > 0 && (orden == 1 || orden == 0))
	{
		while(estadoDesordenado) // Mientras esté desordenado
		{
			estadoDesordenado = 0;
			for(int i = 0 ; i < (limite - 1) ; i++)
			{
				if( (orden == 1 && strncmp(pArray[i].nombreVideo, pArray[i + 1].nombreVideo,LONG) > 0)
						||
					(orden == 0 && strncmp(pArray[i].nombreVideo, pArray[i + 1].nombreVideo,LONG) < 0) )
				{
					aux = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = aux;
					estadoDesordenado = 1;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
