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

/*Recibe como parámetro un puntero al array del tipo de dato Cliente y un límite.
Devuelve un entero, -1 y 0.*/
int clienteAviso_imprimir (Cliente * pArrayCliente, int limiteCliente, Aviso * pArrayAviso, int limiteAviso)
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
				aviso_imprimirAvisoPorIdCliente(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, pArrayCliente[i].idCliente);
				printf("\n##########################################\n\n");
			}
		}
		retorno = 0;
	}
	return retorno;
}
