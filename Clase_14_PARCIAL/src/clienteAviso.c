/*
 * clienteAviso.c
 *
 *  Created on: 11 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "clienteAviso.h"

int clienteAviso_baja (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;
	int opcionDeEliminar;

	if (pArrayAviso != NULL && limiteAviso > 0)
	{
		if(		utn_getNumberInt("\nIngrese el ID del cliente que quiere borrar:\n","\nError, ID inválido.\n",&idABorrar,2,0,9999) == 0 &&
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, idABorrar, &indiceABorrar) != -1)
		{
			printf("\nA continuación se listan los avisos que corresponden al ID seleccionado:\n"); // CORREGIR, no muestra todos los avisos correspondientes a ese ID.
			if(aviso_imprimirTodosLosAvisosPorIdCliente(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, idABorrar) == 0)
			{
				if(utn_getNumberInt("\n¿Desea borrar este cliente junto con todas sus publicaciones? [1 - SI] - [2 - NO]\n", "Error, ingrese: [1 - SI] - [2 - NO].\n", &opcionDeEliminar, 2, 1, 2) == 0)
				{
					if(opcionDeEliminar == 1)
					{
						// Busco el ID que quiero borrar.

							// Borro al cliente y el aviso
							aviso_borrarPorId(pArrayAviso, limiteAviso, idABorrar);
							pArrayCliente[indiceABorrar].isEmpty = TRUE;
							printf("\nSe ha borrado el cliente junto con todas sus publicaciones:\n");

					}
				}
				else
				{
					printf("\nNo se ha borrado al cliente.\n");
				}

			}
		}
		else
		{
			printf("\nEse ID de cliente no existe.\n");
		}
	}
	return retorno;
}

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.*/
int clienteAviso_avisosActivosImprimir (Cliente * pArrayCliente, int limiteCliente, Aviso * pArrayAviso, int limiteAviso)
{
	int retorno = -1;

	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		for (int i = 0 ; i < limiteCliente ; i++) // Recorro el array de elementos
		{
			if(pArrayCliente[i].isEmpty == FALSE) // Si la posición "i" del array NO está vacía.
			{
				// Estoy en condiciones de poder imprimir.
				printf("\n##########################################\n");
				printf("\nID: %d - Nombre del cliente: %s - Apellido del cliente: %s - CUIT: %s\n",pArrayCliente[i].idCliente,pArrayCliente[i].nombre, pArrayCliente[i].apellido, pArrayCliente[i].cuit);
				aviso_imprimirAvisoActivoPorIdCliente(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, pArrayCliente[i].idCliente);
				printf("\n##########################################\n\n");
			}
		}
		retorno = 0;
	}
	return retorno;
}
