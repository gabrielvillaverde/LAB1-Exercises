/*
 * informes.c
 *
 *  Created on: 10 oct. 2020
 *      Author: Hzkr
 */

// informe_calcularClienteConMasAvisos

// informe_calcularCantidadDeAvisosPausados

// informe_calcularRubroConMasAvisos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "cliente.h"
#include "aviso.h"
#include "informes.h"

int informes_calcularClienteConMasAvisos (Cliente * pArrayCliente, int limiteCliente, Aviso * pArrayAviso, int limiteAviso)
{
	int retorno = -1;
	int buffer;
	int nuevoMaximo;
	int flag = FALSE;
	Cliente auxCliente;

	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		for (int i = 0 ; i < limiteCliente ; i++)
		{
			if(pArrayCliente[i].isEmpty == FALSE) // Si la posición "i" del array NO está vacía.
			{
				buffer = aviso_contarAvisosPorIdCliente(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, pArrayCliente[i].idCliente);
				if(flag == FALSE) {
					flag = TRUE;
					nuevoMaximo = buffer;
					auxCliente = pArrayCliente[i];
				}
				else if(buffer > nuevoMaximo) {
					nuevoMaximo = buffer;
					auxCliente = pArrayCliente[i];
				}
			}
		}
		printf("\nEl cliente con más avisos es %s %s, con %d avisos activos", auxCliente.nombre, auxCliente.apellido, nuevoMaximo);
		retorno = 0;
	}
	return retorno;
}
