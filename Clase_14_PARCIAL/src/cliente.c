/*
 * cliente.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "cliente.h"

static int cliente_generarNuevoId (void); // Prototipo

static int cliente_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.
Recorre todo el array, e indica que el campo isEmpty está todo vacío.*/
int cliente_init(Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	if (pArrayCliente != NULL && limiteCliente >0)
	{
		for (int i = 0 ; i < limiteCliente ; i++)
		{
			pArrayCliente[i].isEmpty = TRUE; // Indico que están vacías todas las posiciones del array.
		}
		retorno = 0;
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.*/
int cliente_alta (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int indice;

	Cliente bufferCliente; // Creo una variable auxiliar del tipo de dato Cliente, para cargar los datos ahí.
	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		if (cliente_buscarLibreRef (pArrayCliente, limiteCliente, &indice) == 0)
		{	// Le solicito los datos al cliente y los guardo en cada campo de bufferCliente.
			if (utn_getName("\nIngrese el nombre:\n", "Error, ingrese un nombre válido:\n", bufferCliente.nombre, 2, SIZE_NOMBRE) == 0 &&
				utn_getName("\nIngrese el apellido:\n", "Error, ingrese un apellido válido.\n", bufferCliente.apellido, 2, SIZE_APELLIDO) == 0 &&
				utn_getAlphaNum("\nIngrese el CUIT:\n", "Error, ingrese un CUIT válido.\n", bufferCliente.cuit, 2, SIZE_CUIT) == 0)
			{	// Si obtuve los datos...
				pArrayCliente[indice] = bufferCliente; // DEEP COPY: Copio el buffer en la posición indicada.
				pArrayCliente[indice].idCliente = cliente_generarNuevoId(); // Genero un nuevo ID.
				pArrayCliente[indice].isEmpty = FALSE; // Indico que dicha posición ya no está vacía.
				printf("\nSe ha cargado el cliente correctamente.\n");
				retorno = 0;
			}
		}
		else
		{
			printf("\nNo se pueden cargar más clientes.\n");
		}
	}
	return retorno;
}

// La explicación de esta función es en el minuto 19:15 de la clase.
int cliente_altaForzada(Cliente * pArrayCliente, int limiteCliente, char * nombre, char * apellido, char * cuit)
{
	int retorno = -1;
	int indice;

	if(cliente_buscarLibreRef(pArrayCliente, limiteCliente, &indice) == 0)
	{
		strncpy(pArrayCliente[indice].nombre, nombre, SIZE_NOMBRE);
		strncpy(pArrayCliente[indice].apellido, apellido, SIZE_APELLIDO);
		strncpy(pArrayCliente[indice].cuit, cuit, SIZE_CUIT);
		pArrayCliente[indice].idCliente = cliente_generarNuevoId();
		pArrayCliente[indice].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.*/
int cliente_baja (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		printf("\nA continuación se listan los clientes que usted puede borrar:\n");
		cliente_imprimir(pArrayCliente, limiteCliente);
		if(utn_getNumberInt("\nIngrese ID del cliente que quiere borrar:\n","\nError.\n",&idABorrar,2,0,9999)==0)
		{
			// Busco la posición que quiero borrar
			if(cliente_buscarIndicePorId(pArrayCliente,limiteCliente,idABorrar,&indiceABorrar)==0)
			{
				// Borro esa posición
				pArrayCliente[indiceABorrar].isEmpty = TRUE; // Método de baja lógica, simplemente cambio el valor de este campo.
				printf("\nSe ha dado de baja el cliente correctamente.\n");
			}
			else
			{
				printf("\nEse ID no existe.\n");
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.*/
int cliente_modificar (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idBuscado;
	int indiceAModificar;

	Cliente bufferCliente;
	if (pArrayCliente != NULL && limiteCliente> 0)
	{
		printf("\nA continuación se listan los clientes que usted puede modificar:\n");
		cliente_imprimir(pArrayCliente, limiteCliente);

		if(utn_getNumberInt("\nIngrese el ID del cliente que desea modificar:\n","\nError.\n",&idBuscado,2,0,9999)==0)
		{
			if(cliente_buscarIndicePorId(pArrayCliente, limiteCliente,idBuscado,&indiceAModificar)==0)
			{
				bufferCliente = pArrayCliente[indiceAModificar]; // Importante.

				if (utn_getName("\nIngrese el nuevo nombre:\n", "Error, ingrese un nombre válido:\n", bufferCliente.nombre, 2, SIZE_NOMBRE) == 0 &&
					utn_getName("\nIngrese el nuevo apellido:\n", "Error, ingrese un apellido válido.\n", bufferCliente.apellido, 2, SIZE_APELLIDO) == 0 &&
					utn_getAlphaNum("\nIngrese el nuevo CUIT:\n", "Error, ingrese un CUIT válido.\n", bufferCliente.cuit, 2, SIZE_CUIT) == 0)
				{
					pArrayCliente[indiceAModificar] = bufferCliente; // Copio en el índice a modificar del array lo que contiene bufferCliente.
					retorno = 0;
					printf("\nCliente modificado correctamente.\n");
				}
			}
			else
			{
				printf("\nEse ID no existe.\n");
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.*/
int cliente_imprimir (Cliente * pArrayCliente , int limiteCliente)
{
	int retorno = -1;

	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		for (int i = 0 ; i < limiteCliente ; i++) // Recorro el array de elementos
		{
			if(pArrayCliente[i].isEmpty == FALSE) // Si la posición "i" del array NO está vacía.
			{
				// Estoy en condiciones de poder imprimir.
				printf("\nID: %d - Nombre del cliente: %s - Apellido del cliente: %s - CUIT: %s\n",pArrayCliente[i].idCliente,pArrayCliente[i].nombre, pArrayCliente[i].apellido, pArrayCliente[i].cuit);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0. Retorna el valor del índice por valor, NO por referencia.
*/
int cliente_buscarLibre (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int i;

	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		for ( i = 0 ; i < limiteCliente ; i++)
		{
			if(pArrayCliente[i].isEmpty == TRUE)
			{
				retorno = i; // Retorno por valor.
				break;
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.
Recibe también el puntero del índice, devuelve el índice por referencia.*/
int cliente_buscarLibreRef (Cliente * pArrayCliente, int limiteCliente, int * pIndice)
{
	int retorno = -1;
	int i;

	if (pArrayCliente != NULL && limiteCliente > 0 && pIndice != NULL)
	{
		for (i = 0 ; i < limiteCliente ; i++)
		{
			if(pArrayCliente[i].isEmpty == TRUE) // Si el elemento i en el array está vacío...
			{
				*pIndice = i; // Retorno el valor por referencia.
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.
Recibe el parámetro del ID a buscar.
Recibe también el puntero del índice, devuelve el índice por referencia.*/
int cliente_buscarIndicePorId (Cliente * pArrayCliente, int limiteCliente, int idBuscado, int * pIndice)
{
	int retorno = -1;
	int i ;

	if (pArrayCliente != NULL && limiteCliente > 0 && pIndice != NULL && idBuscado >= 0)
	{
		for (i = 0 ; i < limiteCliente ; i++)
		{
			if(pArrayCliente[i].isEmpty == FALSE && pArrayCliente[i].idCliente == idBuscado)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.
Si ordena por nombre, tiene que recibir el parámetro de orden. */
int cliente_ordenarPorNombre (Cliente * pArrayCliente, int limiteCliente , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Cliente aux; // El tipo de dato del buffer/auxiliar siempre tiene que ser el mismo tipo de dato del array que estoy ordenando.

	if (pArrayCliente != NULL && limiteCliente > 0 && (orden == 1 || orden == 0))
	{
		while(estadoDesordenado) // Mientras esté desordenado
		{
			estadoDesordenado = 0; // Indico que no está desordenado.
			for(int i = 0 ; i < (limiteCliente - 1) ; i++)
			{
				if( (orden == 1 && strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE) > 0)
						||
					(orden == 0 && strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE) < 0) )
				{
					aux = pArrayCliente[i]; // Copio en mi variable auxiliar lo que hay en el elemento i.
					pArrayCliente[i] = pArrayCliente[i + 1];
					pArrayCliente[i + 1] = aux;
					estadoDesordenado = 1;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

// Esta función ordena por más de un criterio.
/*int cliente_ordenarPorNombreLuegoPorId (Cliente * pArrayCliente, int limiteCliente , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Cliente buffer; // El tipo de dato del buffer/auxiliar siempre tiene que ser el mismo tipo de dato del array que estoy ordenando.

	if (pArrayCliente != NULL && limiteCliente > 0 && (orden == 1 || orden == 0))
	{
		while(estadoDesordenado) // Mientras esté desordenado
		{
			estadoDesordenado = 0; // Indico que no está desordenado.
			for(int i = 0 ; i < (limiteCliente - 1) ; i++)
			{
				if( (orden == 1 && strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE) > 0)
						||
					(orden == 0 && strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE) < 0) )
				{
					buffer = pArrayCliente[i]; // Copio en mi variable auxiliar lo que hay en el elemento i.
					pArrayCliente[i] = pArrayCliente[i + 1];
					pArrayCliente[i + 1] = buffer;
					estadoDesordenado = 1;
					retorno = 0;
				}
				else if(strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE) == 0)
				{
					if(pArrayCliente[i].idCliente < pArrayCliente[i + 1].idCliente)
					{
						buffer = pArrayCliente[i]; // Copio en mi variable auxiliar lo que hay en el elemento i.
						pArrayCliente[i] = pArrayCliente[i + 1];
						pArrayCliente[i + 1] = buffer;
						estadoDesordenado = 1;
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}*/

/*int cliente_ordenarPorNombreLuegoPorIdOptimizado (Cliente * pArrayCliente, int limiteCliente , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Cliente buffer; // El tipo de dato del buffer/auxiliar siempre tiene que ser el mismo tipo de dato del array que estoy ordenando.

	if (pArrayCliente != NULL && limiteCliente > 0 && (orden == 1 || orden == 0))
	{
		while(estadoDesordenado) // Mientras esté desordenado
		{
			estadoDesordenado = 0; // Indico que no está desordenado.
			for(int i = 0 ; i < (limiteCliente - 1) ; i++)
			{
				// CORREGIR Y CORROBORAR
				if( (orden == 1 && strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE) > 0)
						||
					(orden == 0 && strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE) < 0)
						||
					(orden == 1 && strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE) == 0 && pArrayCliente[i].idCliente < pArrayCliente[i + 1].idCliente)
						||
					(orden == 0 && strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE) == 0 && pArrayCliente[i].idCliente > pArrayCliente[i + 1].idCliente))
				{
					buffer = pArrayCliente[i]; // Copio en mi variable auxiliar lo que hay en el elemento i.
					pArrayCliente[i] = pArrayCliente[i + 1];
					pArrayCliente[i + 1] = buffer;
					estadoDesordenado = 1;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}*/

int cliente_ordenarPorNombreLuegoPorIdMauricio (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int flagSwap;
	int i;
	Cliente buffer;
	int auxiliarCmp;

	if(pArrayCliente != NULL && limiteCliente > 0)
	{
		do
		{
			flagSwap = 0;
			for(i = 0 ; i < limiteCliente-1 ; i++)
			{
				if(pArrayCliente[i].isEmpty || pArrayCliente[i + 1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(pArrayCliente[i].nombre, pArrayCliente[i + 1].nombre, SIZE_NOMBRE);
				if(auxiliarCmp > 0 || (auxiliarCmp == 0 && pArrayCliente[i].idCliente < pArrayCliente[i + 1].idCliente) )
				{
					flagSwap = 1;
					buffer = pArrayCliente[i];
					pArrayCliente[i] = pArrayCliente[i + 1];
					pArrayCliente[i + 1] = buffer;
				}
				limiteCliente--;
			}
		}while(flagSwap);
	}
	return retorno;
}
