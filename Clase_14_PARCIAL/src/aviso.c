/*
 * aviso.c
 *
 *  Created on: 6 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "aviso.h"
#include "clienteAviso.h"

static int aviso_generarNuevoId (void); // Prototipo

static int aviso_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

int aviso_init (Aviso * pArrayAviso, int limiteAviso)
{
	int retorno = -1;
	if (pArrayAviso != NULL && limiteAviso > 0)
	{
		for (int i = 0; i < limiteAviso ; i++)
		{
			pArrayAviso[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/*
int aviso_alta (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int indice;

	Aviso bufferAviso;

	if (pArrayAviso != NULL && limiteAviso > 0) // Verifico lo que recibo como parámetro.
	{
		if (aviso_buscarLibreRef (pArrayAviso, limiteAviso, &indice) == 0) // Si encontré un lugar libre...
		{
			// Le solicito los datos al usuario y los guardo en cada campo del auxiliar bufferAviso.
			if (utn_getNumberInt("\nIngrese el ID del cliente:\n", "\nError, intente nuevamente.\n", &bufferAviso.idCliente, 2, 0, 9999) == 0 &&
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, bufferAviso.idCliente, &indice) != -1 && // Si no encuentra el ID, me devuelve -1. Por lo tanto, si me devolvió algo distinto a -1 quiere decir que existe ese ID.
				utn_getNumberInt("\nIngrese el número de rubro:\n", "\nError, ingrese un número de rubro válido entre 0 y 9999.\n",&bufferAviso.numeroDeRubro, 2, 0, 9999) == 0 &&
				utn_getAlphaNum("\nIngrese el texto del aviso:\n", "\nError, ingrese un texto válido de máximo 64 caracteres:\n", bufferAviso.textoDelAviso, 2, SIZE_TEXTO_AVISO) == 0)
			{
					pArrayAviso[indice] = bufferAviso;
					pArrayAviso[indice].idAviso = aviso_generarNuevoId();
					printf("\nEl ID generado para este aviso es el: %d\n",pArrayAviso[indice].idAviso);
					pArrayAviso[indice].isEmpty = FALSE;
					pArrayAviso[indice].estado = AVISO_ACTIVO;
					retorno = 0;
			}
			else
			{
				printf("\nError, ese ID no existe.\n");
			}
		}
	}
	return retorno;
}*/

int aviso_alta (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente, int * indiceAvisos)
{
	int retorno = -1;
	int indice;

	Aviso bufferAviso;

	if (pArrayAviso != NULL && limiteAviso > 0) // Verifico lo que recibo como parámetro.
	{
		if (aviso_buscarLibreRef (pArrayAviso, limiteAviso, &indice) == 0) // Si encontré un lugar libre...
		{
			// Le solicito los datos al usuario y los guardo en cada campo del auxiliar bufferAviso.
			if (utn_getNumberInt("\nIngrese el ID del cliente:\n", "\nError, intente nuevamente.\n", &bufferAviso.idCliente, 2, 0, 9999) == 0 &&
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, bufferAviso.idCliente, &indice) != -1 && // Si no encuentra el ID, me devuelve -1. Por lo tanto, si me devolvió algo distinto a -1 quiere decir que existe ese ID.
				utn_getNumberInt("\nIngrese el número de rubro:\n", "\nError, ingrese un número de rubro válido entre 0 y 9999.\n",&bufferAviso.numeroDeRubro, 2, 0, 9999) == 0 &&
				utn_getAlphaNum("\nIngrese el texto del aviso:\n", "\nError, ingrese un texto válido de máximo 64 caracteres:\n", bufferAviso.textoDelAviso, 2, SIZE_TEXTO_AVISO) == 0)
			{
					pArrayAviso[*indiceAvisos] = bufferAviso;
					pArrayAviso[*indiceAvisos].idAviso = aviso_generarNuevoId();
					printf("\nEl ID generado para este aviso es el: %d\n",pArrayAviso[*indiceAvisos].idAviso);
					pArrayAviso[*indiceAvisos].isEmpty = FALSE;
					pArrayAviso[*indiceAvisos].estado = AVISO_ACTIVO;
					*indiceAvisos = *indiceAvisos + 1; // mismo que *indiceAvisos++
					retorno = 0;
			}
			else
			{
				printf("\nError, ese ID no existe.\n");
			}
		}
	}
	return retorno;
}

int aviso_altaForzada(Aviso * pArrayAviso, int limiteAviso, int numeroDeRubro, char * textoDelAviso, int idCliente, int estadoAviso)
{
	int retorno = -1;
	int indice;

	if(aviso_buscarLibreRef(pArrayAviso, limiteAviso, &indice) == 0)
	{
		pArrayAviso[indice].numeroDeRubro = numeroDeRubro;
		pArrayAviso[indice].idCliente = idCliente;
		strncpy(pArrayAviso[indice].textoDelAviso, textoDelAviso, SIZE_TEXTO_AVISO);
		pArrayAviso[indice].idAviso = aviso_generarNuevoId();
		pArrayAviso[indice].isEmpty = FALSE;
		pArrayAviso[indice].estado = AVISO_ACTIVO;
		retorno = 0;
	}
	return retorno;
}

/*
int aviso_baja (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente) // ORIGINAL
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;
	int opcionDeEliminar;

	if (pArrayAviso != NULL && limiteAviso > 0)
	{
		printf("\nA continuación se listan los avisos de todos los clientes que puede borrar:\n");
		aviso_imprimir(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente);
		if(		utn_getNumberInt("\nIngrese el ID del cliente que quiere borrar:\n","\nError, ID inválido.\n",&idABorrar,2,0,9999) == 0 &&
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, idABorrar, &indiceABorrar) != -1)
		{
			printf("\nA continuación se listan los avisos que corresponden al ID seleccionado:\n"); // CORREGIR, no muestra todos los avisos correspondientes a ese ID.
			if(aviso_imprimirPorId(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, idABorrar) == 0)
			{
				if(utn_getNumberInt("\n¿Desea borrar este cliente junto con todas sus publicaciones? [1 - SI] - [2 - NO]\n", "Error, ingrese: [1 - SI] - [2 - NO].\n", &opcionDeEliminar, 2, 1, 2) == 0)
				{
					if(opcionDeEliminar == 1)
					{
						// Busco el ID que quiero borrar.
						if(aviso_buscarIndicePorId(pArrayAviso,limiteAviso,idABorrar,&indiceABorrar) == 0)
						{
							// Borro al cliente y el aviso
							pArrayAviso[indiceABorrar].isEmpty = TRUE;
							pArrayCliente[indiceABorrar].isEmpty = TRUE;
							printf("\nSe ha borrado el cliente junto con todas sus publicaciones:\n");
						}
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
}*/

int aviso_baja (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente) // PRUEBA
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;
	int opcionDeEliminar;

	if (pArrayAviso != NULL && limiteAviso > 0)
	{
		printf("\nA continuación se listan los avisos de todos los clientes que puede borrar:\n");
		aviso_imprimir(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente);
		if(		utn_getNumberInt("\nIngrese el ID del cliente que quiere borrar:\n","\nError, ID inválido.\n",&idABorrar,2,0,9999) == 0 &&
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, idABorrar, &indiceABorrar) != -1)
		{
			printf("\nA continuación se listan los avisos que corresponden al ID seleccionado:\n"); // CORREGIR, no muestra todos los avisos correspondientes a ese ID.
			if(clienteAviso_imprimir(pArrayCliente, limiteCliente, pArrayAviso, limiteAviso) == 0)
			{
				if(utn_getNumberInt("\n¿Desea borrar este cliente junto con todas sus publicaciones? [1 - SI] - [2 - NO]\n", "Error, ingrese: [1 - SI] - [2 - NO].\n", &opcionDeEliminar, 2, 1, 2) == 0)
				{
					if(opcionDeEliminar == 1)
					{
						// Busco el ID que quiero borrar.
						if(aviso_buscarIndicePorId(pArrayAviso,limiteAviso,idABorrar,&indiceABorrar) == 0)
						{
							// Borro al cliente y el aviso
							pArrayAviso[indiceABorrar].isEmpty = TRUE;
							pArrayCliente[indiceABorrar].isEmpty = TRUE;
							printf("\nSe ha borrado el cliente junto con todas sus publicaciones:\n");
						}
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

/*int cliente_baja (Cliente * pArrayCliente, int limiteCliente)
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
}*/

/*int aviso_modificar (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idBuscar;
	int cuitBuscar;
	int indiceAModificar;

	Aviso bufferAviso;

	if (pArrayAviso != NULL && limiteAviso > 0)
	{
		if(utn_getNumberInt("\nIngrese su CUIT:\n", "\nCUIT inválido.\n", &cuitBuscar, 2, 0, 99999999) == 0)
		{
			if(aviso_imprimirPorCuit(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, cuitBuscar) == 0)
			{
				if(utn_getNumberInt("Ingrese el ID de la contratación que quiere modificar:\n", "Error, ID inválido.\n", &idBuscar, 2, 0, 9999) == 0)
				{
					if(aviso_buscarIndicePorId(pArrayAviso, limiteAviso, idBuscar, &indiceAModificar) == 0)
					{
						bufferAviso = pArrayAviso[indiceAModificar];

						if (utn_getNumberInt("\nIngrese el ID de la cliente que quiere modificar;\n", "\nError, intente nuevamente.\n", &bufferAviso.idCliente, 2, 0, 9999) == 0 &&
							cliente_buscarIndicePorId(pArrayCliente, limiteCliente, bufferAviso.idCliente, &indiceAModificar) != -1 && // No estoy seguro del índice.
							utn_getAlphaNum("\nIngrese el nombre del video a modificar:\n", "\nError, nombre de video inválido.\n", bufferAviso.nombreVideo, 2, SIZE_NOMBRE) == 0 &&
							utn_getNumberInt("\nIngrese la nueva cantidad de días:\n", "\nError, solo puede ingresar valores numéricos.\n", &bufferAviso.cantidadDias, 2, 0, 9999) == 0)
						{
							pArrayAviso[indiceAModificar] = bufferAviso;
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}*/

int aviso_pausar (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idAvisoAPausar;
	int indiceAPausar;
	int opcionDePausar;

	if (pArrayAviso != NULL && limiteAviso > 0)
	{
		printf("\nEstos son los avisos activos de todos los clientes:\n");
		aviso_imprimirPorEstado(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, AVISO_ACTIVO);
		if(utn_getNumberInt("\nIngrese el ID del aviso que quiere pausar:\n","\nError, ID inválido.\n",&idAvisoAPausar,2,0,9999) == 0)
		{
			printf("\nEstos son los datos del cliente al que corresponde ese aviso:.\n");
			if(aviso_imprimirPorId(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, idAvisoAPausar) == 0)
			{
				if(utn_getNumberInt("\n¿Desea pausar esta publicación? [1 - SI] - [2 - NO]\n", "Error, ingrese: [1 - SI] - [2 - NO].\n", &opcionDePausar, 2, 1, 2) == 0)
				{
					if(opcionDePausar == 1)
					{
						// Busco el ID que quiero pausar.
						if(aviso_buscarIndicePorId(pArrayAviso,limiteAviso,idAvisoAPausar,&indiceAPausar) == 0)
						{
							// Pongo en pausa el aviso.
							pArrayAviso[indiceAPausar].estado = AVISO_PAUSADO; // Pausado.
							printf("\nLa publicación se ha pausado correctamente.\n");
						}
					}
				}
			}
		}
	}
	return retorno;
}

int aviso_activar (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idAvisoActivar;
	int indiceActivar;
	int opcionDeActivar;

	if (pArrayAviso != NULL && limiteAviso > 0)
	{
		printf("\nEstos son los avisos pausados de todos los clientes:\n");
		aviso_imprimirPorEstado(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, AVISO_PAUSADO);
		if(utn_getNumberInt("\nIngrese el ID del aviso que quiere activar:\n","\nError, ID inválido.\n",&idAvisoActivar,2,0,9999) == 0)
		{
			if(pArrayAviso[indiceActivar].estado == 0) // Es decir, si el estado de ese índice está pausado.
			{
				printf("\nEstos son los datos del cliente al que corresponde ese aviso:.\n");
				if(aviso_imprimirPorId(pArrayAviso, limiteAviso, pArrayCliente, limiteCliente, idAvisoActivar) == 0)
				{
					if(utn_getNumberInt("\n¿Desea activar esta publicación? [1 - SI] - [2 - NO]\n", "Error, ingrese: [1 - SI] - [2 - NO].\n", &opcionDeActivar, 2, 1, 2) == 0)
					{
						if(opcionDeActivar == 1)
						{
							// Busco el ID que quiero activar.
							if(aviso_buscarIndicePorId(pArrayAviso,limiteAviso,idAvisoActivar,&indiceActivar) == 0)
							{
								// Pongo en activo el aviso.
								pArrayAviso[indiceActivar].estado = AVISO_ACTIVO; // Activado.
								printf("\nLa publicación se ha activado correctamente.\n");
							}
						}
					}
				}
			}
			else
			{
				printf("\nEste aviso ya está activo.\n");
			}
		}
	}
	return retorno;
}

int aviso_imprimirPorEstado (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente, int estadoAviso)
{
	int retorno = -1;
	int indiceCliente;
	char strEstado[10];

	if (pArrayAviso != NULL && limiteAviso > 0 && pArrayCliente != NULL && limiteCliente > 0)
	{
		for(int i ; i < limiteAviso ; i++)
		{
			if(pArrayAviso[i].estado == estadoAviso && pArrayAviso[i].isEmpty == FALSE)
			{
				if(pArrayAviso[i].estado == AVISO_PAUSADO)
				{
					sprintf(strEstado,"Pausado"); // Cargo la cadena strEstado con "Pausado".
				}
				else
					sprintf(strEstado,"Activo"); // Cargo la cadena strEstado con "Pausado".
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, pArrayAviso[i].idCliente, &indiceCliente);
				printf("\nID del cliente: %d - ID del aviso: %d - Nombre del cliente: %s - Apellido del cliente: %s - CUIT: %s - Número de rubro: %d - Texto del aviso: %s - Estado del aviso: %s\n", pArrayCliente[indiceCliente].idCliente, pArrayAviso[i].idAviso, pArrayCliente[indiceCliente].nombre, pArrayCliente[indiceCliente].apellido, pArrayCliente[indiceCliente].cuit, pArrayAviso[i].numeroDeRubro, pArrayAviso[i].textoDelAviso, strEstado);
			}

		}
		retorno = 0;
	}
	return retorno;
}

/*int aviso_imprimir (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int indiceCliente;
	if (pArrayAviso != NULL && limiteAviso > 0 && pArrayCliente != NULL && limiteCliente > 0)
	{
		for (int i = 0 ; i < limiteAviso ; i++)
		{
			if(pArrayAviso[i].isEmpty == FALSE)
			{
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, pArrayAviso[i].idCliente, &indiceCliente);
				printf("\nID del cliente: %d - ID del aviso: %d - Nombre del cliente: %s - Apellido del cliente: %s - CUIT: %s - Número de rubro: %d - Texto del aviso: %s - Estado del Aviso: %d", pArrayCliente[i].idCliente, pArrayAviso[i].idAviso, pArrayCliente[i].nombre, pArrayCliente[i].apellido, pArrayCliente[i].cuit, pArrayAviso[i].numeroDeRubro, pArrayAviso[i].textoDelAviso, pArrayAviso[i].estado);
			}
		}
		retorno = 0;
	}
	return retorno;
}*/

int aviso_imprimir (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int indiceCliente;
	char strEstado[10];
	if (pArrayAviso != NULL && limiteAviso > 0 && pArrayCliente != NULL && limiteCliente > 0)
	{
		for (int i = 0 ; i < limiteAviso ; i++)
		{
			if(pArrayAviso[i].isEmpty == FALSE)
			{
				if(pArrayAviso[i].estado == AVISO_PAUSADO)
				{
					sprintf(strEstado,"Pausado"); // Cargo la cadena strEstado con "Pausado".
				}
				else
				{
					sprintf(strEstado,"Activo"); // Cargo la cadena strEstado con "Pausado".
				}
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, pArrayAviso[i].idCliente, &indiceCliente);
				printf("\nID del cliente: %d - ID del aviso: %d - Nombre del cliente: %s - Apellido del cliente: %s - CUIT: %s - Número de rubro: %d - Texto del aviso: %s - Estado del aviso: %s", pArrayCliente[indiceCliente].idCliente, pArrayAviso[i].idAviso, pArrayCliente[indiceCliente].nombre, pArrayCliente[indiceCliente].apellido, pArrayCliente[indiceCliente].cuit, pArrayAviso[i].numeroDeRubro, pArrayAviso[i].textoDelAviso, strEstado);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int aviso_imprimirPorId (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente, int idAviso)
{
	int retorno = -1;
	int indiceCliente;

	if (pArrayAviso != NULL && limiteAviso > 0 && pArrayCliente != NULL && limiteCliente > 0)
	{
		for(int i ; i < limiteAviso ; i++)
		{
			if(pArrayAviso[i].idAviso == idAviso)
			{
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, pArrayAviso[i].idCliente, &indiceCliente);
				printf("\nID del cliente: %d - ID del aviso: %d - Nombre del cliente: %s - Apellido del cliente: %s - CUIT: %s - Número de rubro: %d - Texto del aviso: %s", pArrayCliente[i].idCliente, pArrayAviso[i].idAviso, pArrayCliente[i].nombre, pArrayCliente[i].apellido, pArrayCliente[i].cuit, pArrayAviso[i].numeroDeRubro, pArrayAviso[i].textoDelAviso);
			}
		}
		retorno = 0;
	}
	return retorno;
}


int aviso_imprimirAvisoPorIdCliente (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente, int idCliente)
{
	int retorno = -1;
	int indiceCliente;
	int contadorAvisosActivos = 0;
	char strEstado[10];


	if (pArrayAviso != NULL && limiteAviso > 0 && pArrayCliente != NULL && limiteCliente > 0)
	{

		for(int i = 0 ; i < limiteAviso ; i++)
		{
			if(pArrayAviso[i].idCliente == idCliente) {

				if(pArrayAviso[i].estado == AVISO_ACTIVO){
				sprintf(strEstado,"Activo"); // Cargo la cadena strEstado con "Pausado".
				contadorAvisosActivos++;
				cliente_buscarIndicePorId(pArrayCliente, limiteCliente, pArrayAviso[i].idCliente, &indiceCliente);
				printf("\nNúmero de rubro: %d - Texto del aviso: %s - Estado: %s\n", pArrayAviso[i].numeroDeRubro, pArrayAviso[i].textoDelAviso, strEstado);
				}
			}
		}
		printf("\nLa cantidad de avisos activos que posee son: %d\n", contadorAvisosActivos);
		retorno = 0;
	}
	return retorno;
}

int aviso_contarAvisosPorIdCliente (Aviso * pArrayAviso, int limiteAviso, Cliente * pArrayCliente, int limiteCliente, int idCliente)
{
	int contadorAvisosActivos = 0;

	if (pArrayAviso != NULL && limiteAviso > 0 && pArrayCliente != NULL && limiteCliente > 0)
	{
		for(int i = 0 ; i < limiteCliente ; i++)
		{
			if(pArrayAviso[i].idCliente == idCliente && pArrayAviso[i].estado == AVISO_ACTIVO)
			{
				contadorAvisosActivos++;
			}
		}
	}
	return contadorAvisosActivos;
}

int aviso_buscarLibre (Aviso * pArrayAviso, int limiteAviso){
	int retorno = -1;
	int i ;
		if (pArrayAviso != NULL && limiteAviso >0){
			for ( i = 0; i<limiteAviso; i++) {
				if(pArrayAviso[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int aviso_buscarLibreRef (Aviso * pArrayAviso, int limiteAviso, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayAviso != NULL && limiteAviso >0 && pIndice != NULL){
			for ( i = 0; i<limiteAviso; i++) {
				if(pArrayAviso[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}

int aviso_buscarIndicePorId (Aviso * pArrayAviso, int limiteAviso, int idBuscado, int * pIndice)
{
	int retorno = -1;
	int i;

	if (pArrayAviso != NULL && limiteAviso > 0 && pIndice != NULL && idBuscado >= 0)
	{
		for (i = 0; i < limiteAviso ; i++)
		{
			if(pArrayAviso[i].isEmpty == FALSE && pArrayAviso[i].idAviso == idBuscado)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*int aviso_buscarIndicePorCuit (Aviso * pArrayAviso, int limiteAviso, int cuitBuscar, int * pIndice)
{
	int retorno = -1;
	int i;

	if(pArrayAviso != NULL && limiteAviso > 0 && pIndice != NULL && cuitBuscar >= 0)
	{
		for (i = 0; i < limiteAviso ; i++)
		{
			if(pArrayAviso[i].isEmpty == FALSE && pArrayAviso[i].cuit == cuitBuscar)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}*/

/*int aviso_ordenarPorNombre (Aviso * pArrayAviso, int limiteAviso , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Aviso aux;

	if (pArrayAviso != NULL && limiteAviso > 0 && (orden == 1 || orden == 0))
	{
		while(estadoDesordenado) // Mientras esté desordenado
		{
			estadoDesordenado = 0;
			for(int i = 0 ; i < (limiteAviso - 1) ; i++)
			{
				if( (orden == 1 && strncmp(pArrayAviso[i].nombreVideo, pArrayAviso[i + 1].nombreVideo,SIZE) > 0)
						||
					(orden == 0 && strncmp(pArrayAviso[i].nombreVideo, pArrayAviso[i + 1].nombreVideo,SIZE) < 0) )
				{
					aux = pArrayAviso[i];
					pArrayAviso[i] = pArrayAviso[i + 1];
					pArrayAviso[i + 1] = aux;
					estadoDesordenado = 1;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}*/
