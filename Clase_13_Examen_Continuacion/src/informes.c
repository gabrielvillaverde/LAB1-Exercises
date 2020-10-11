/*
 * informes.c
 *
 *  Created on: 8 oct. 2020
 *      Author: Hzkr
 */

/*#include "pantalla.h"
#include "contratacion.h"

int calcularCantidadContratacionesDeUnCliente(listaContrataciones, tamaño, cuit)
{

}

float calcularImporteAPagar (listaContrataciones, tamaño, listaPantallas, tamañoPantallas, cuit, idContratacion)
{

}

// Explicación: 9:50 HS.
// Falta el chequeo de errores, validar la función y todo eso que vimos siempre
// En esta función le paso un array de clientes y quiero que lo llene con los cuits que están en la listaContrat
static void generarListaDeCuits(Cliente * cuits, int lenCuits, Contratacion * listaContrat)
{
	// Cliente cuits[1000]; Defino la lista de cuits, esto es lo que tengo que devolver por referencia.
	int indexCont;
	int indexCuits = 0; // Uso esto para que cada vez que agrego 1 CUIT, lo agrego a esa posición.
	cli_inicializarArray(cuits,lenCuits); // La inicializo toda en 0 para tener el isEmpty en TRUE, todo vacío.

	for(indexCont = 0; indexCont < lenCuits; indexCont++) // Iteramos la lista de contrataciones, y accedo a cada contratación.
	{
		// De cada contratación, me fijo si el CUIT está en la lista de clientes.

		// Nos quedamos con cada uno de los CUIT de cada contratación.
		// A esta función le pasamos el la lista de cuits, su tamaño y el cuit que yo quiero saber si ya está o no.
		if(estaEnMiListaDeCuits(cuits, lenCuits, listaContrat[indexCont].cuit) == FALSE) // Si la función me dice que ese CUIT no está en la lista, lo agrego.
		{
			// Si no está, lo agrego con la función strcpy. Uso strcpy porque es un char, si fuera un int sería distinto.
			// cuits[?].cuit = listaContrat[indexCont].cuit; NO ES ASI, PORQUE ES UN STRING, NO SE PUEDE COMPARAR
			strcpy(cuits[indexCuits].cuit = listaContrat[indexCont].cuit); // Copio el CUIT en el indexCuits que estaba inicializado en 0.
			cuits[indexCuits].isEmpty = FALSE; // Indico que ya está ocupada esa posición.
			indexCuits++; // Aumento el contador de indexCuits.
		}
	}
}

void cli_inicializarArray(Cliente * cuits, int lenCuits)
{
	int i;
	for(i = 0 ; i < lenCuits ; i++)
	{
		cuits[i].isEmpty = TRUE;
	}
}

// Falta chequeo de NULL y eso..
static int estaEnMiListaDeCuits(Cliente * cuits, int lenCuits, char * cuit)
{
	// Debo saber si el cuit "cuit" está en la lista de cuits o no.
	int i;
	int retorno = 0;
	for(i = 0 ; i < lenCuits ; i++)
	{
		// Accedo a la posición i y comparo los cuit.
		if(cuits[i].cuit == cuit)
		{
			if(cuits[i].isEmpty == FALSE && strncmp(cuit,cuits[i].cuit,lenCuits)==0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

void generarInforme(void) // Acá vamos a tener que recibir todas las listas, incluidas las de pantallas o algo así.
{
	Cliente cuits[1000];
	// Generar lista de clientes, llamo a la función y le paso la lista de clientes
	generarListaDeCuits(cuits, lenCuits, listaContrat);

	// Pasar la maqueta del algoritmo del informe acá.


}
*/


