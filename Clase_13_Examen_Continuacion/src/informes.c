/*
 * informes.c
 *
 *  Created on: 8 oct. 2020
 *      Author: Hzkr
 */

/*#include "pantalla.h"
#include "contratacion.h"

int calcularCantidadContratacionesDeUnCliente(listaContrataciones, tama�o, cuit)
{

}

float calcularImporteAPagar (listaContrataciones, tama�o, listaPantallas, tama�oPantallas, cuit, idContratacion)
{

}

// Explicaci�n: 9:50 HS.
// Falta el chequeo de errores, validar la funci�n y todo eso que vimos siempre
// En esta funci�n le paso un array de clientes y quiero que lo llene con los cuits que est�n en la listaContrat
static void generarListaDeCuits(Cliente * cuits, int lenCuits, Contratacion * listaContrat)
{
	// Cliente cuits[1000]; Defino la lista de cuits, esto es lo que tengo que devolver por referencia.
	int indexCont;
	int indexCuits = 0; // Uso esto para que cada vez que agrego 1 CUIT, lo agrego a esa posici�n.
	cli_inicializarArray(cuits,lenCuits); // La inicializo toda en 0 para tener el isEmpty en TRUE, todo vac�o.

	for(indexCont = 0; indexCont < lenCuits; indexCont++) // Iteramos la lista de contrataciones, y accedo a cada contrataci�n.
	{
		// De cada contrataci�n, me fijo si el CUIT est� en la lista de clientes.

		// Nos quedamos con cada uno de los CUIT de cada contrataci�n.
		// A esta funci�n le pasamos el la lista de cuits, su tama�o y el cuit que yo quiero saber si ya est� o no.
		if(estaEnMiListaDeCuits(cuits, lenCuits, listaContrat[indexCont].cuit) == FALSE) // Si la funci�n me dice que ese CUIT no est� en la lista, lo agrego.
		{
			// Si no est�, lo agrego con la funci�n strcpy. Uso strcpy porque es un char, si fuera un int ser�a distinto.
			// cuits[?].cuit = listaContrat[indexCont].cuit; NO ES ASI, PORQUE ES UN STRING, NO SE PUEDE COMPARAR
			strcpy(cuits[indexCuits].cuit = listaContrat[indexCont].cuit); // Copio el CUIT en el indexCuits que estaba inicializado en 0.
			cuits[indexCuits].isEmpty = FALSE; // Indico que ya est� ocupada esa posici�n.
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
	// Debo saber si el cuit "cuit" est� en la lista de cuits o no.
	int i;
	int retorno = 0;
	for(i = 0 ; i < lenCuits ; i++)
	{
		// Accedo a la posici�n i y comparo los cuit.
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

void generarInforme(void) // Ac� vamos a tener que recibir todas las listas, incluidas las de pantallas o algo as�.
{
	Cliente cuits[1000];
	// Generar lista de clientes, llamo a la funci�n y le paso la lista de clientes
	generarListaDeCuits(cuits, lenCuits, listaContrat);

	// Pasar la maqueta del algoritmo del informe ac�.


}
*/


