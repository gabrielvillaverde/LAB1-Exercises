/*
 * informes.c
 *
 *  Created on: 10 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "cliente.h"
#include "aviso.h"
#include "informes.h"

#define SIZE_RUBROS 1000

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
			if(pArrayCliente[i].isEmpty == FALSE) // Si la posici�n "i" del array NO est� vac�a.
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
		printf("\nEl cliente con m�s avisos es %s %s, con %d avisos", auxCliente.nombre, auxCliente.apellido, nuevoMaximo);
		retorno = 0;
	}
	return retorno;
}

int informes_calcularCantidadDeAvisosPausados (Cliente * pArrayCliente, int limiteCliente, Aviso * pArrayAviso, int limiteAviso)
{
	int retorno = -1;
	int contadorAvisosPausados = 0;

	if (pArrayAviso != NULL && limiteAviso > 0)
	{
		for (int i = 0 ; i < limiteAviso ; i++)
		{
			if(pArrayAviso[i].isEmpty == FALSE && pArrayAviso[i].estado == AVISO_PAUSADO)
			{
				contadorAvisosPausados++;
			}
		}
		printf("\nLa cantidad de avisos pausados es: %d", contadorAvisosPausados);
		retorno = 0;
	}
	return retorno;
}

int informes_calcularRubroConMasAvisos (Aviso * pArrayAviso, int limiteAviso)
{
	int retorno = -1;
	int rubros[SIZE_RUBROS]; // Declaro un array de rubros m�ximos
	int flag = FALSE;
	int nuevoMaximoCantidadDeOcurrencias;
	int rubroMaximo;

	// Inicializo el array de rubros en 0.
	for (int indiceRubros = 1; indiceRubros < 1000; indiceRubros++)
	{
		rubros[indiceRubros] = 0;
	}

	if (pArrayAviso != NULL && limiteAviso > 0)
	{
		// Recorro el array de avisos
		for (int indiceAviso = 0 ; indiceAviso < limiteAviso ; indiceAviso++)
		{
			if(pArrayAviso[indiceAviso].isEmpty == FALSE)
			{
				// El rubro del aviso actual va a ser el indice del array de rubros
				// En la posicion de ese rubro contabilizo la cantidad de ocurrencias
				int numeroRubro = pArrayAviso[indiceAviso].numeroDeRubro; // Cada n�mero de rubro que encuentra mientras recorre el array de avisos, lo toma como �ndice.
				rubros[numeroRubro]++; // Aumenta el contador de ese n�mero de rubro
			}
		}
		// Termino de recorrer el array de avisos

		// Calculo el m�ximo recorriendo el array de rubros
		for (int indiceRubros = 1 ; indiceRubros < 1000 ; indiceRubros++)
		{
			if(flag == FALSE) // Si la bandera est� en FALSE...
			{
				nuevoMaximoCantidadDeOcurrencias = rubros[indiceRubros]; // Entro al if e indico que en el array de rubros el nuevo m�ximo es indiceRubros.
				rubroMaximo = indiceRubros;
				flag = TRUE;
			}
			if(rubros[indiceRubros] > nuevoMaximoCantidadDeOcurrencias)
			{
				flag = TRUE;
				nuevoMaximoCantidadDeOcurrencias = rubros[indiceRubros];
				rubroMaximo = indiceRubros;
			}
		}
		//Termino de recorrer el array de rubros
		retorno = 0;
		printf("\nEl rubro maximo es %d con una cantidad de: %d \n", rubroMaximo, nuevoMaximoCantidadDeOcurrencias);
	}
	return retorno;
}
