/*
 * controller.c
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "envio.h"
#include "parser.h"
#include "utn.h"


/*
* \brief Función que carga los datos de los envíos desde el archivo indicado.
* \param path char* es la ruta del archivo.
* \param pArrayListaEnvios LinkedList* es el puntero al array de envíos.
* \return (-1) Error (0) todo OK
*/

int controller_loadFromText(char* path, LinkedList* pArrayListaEnvios)
{
	int retorno = -1;

	FILE* pFile;

	if(path != NULL && pArrayListaEnvios != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if(parser_EnvioFromText(pFile, pArrayListaEnvios) == 0)
			{
				retorno = 0;
			}
		}
		fclose(pFile);
	}
    return retorno;
}

int controller_imprimirListaEnvios(LinkedList* pArrayListaEnvios)
{
	int retorno = -1;

	char idProducto[10000];
	char nombreProducto[10000];
	char idCamion[10000];
	char zonaDestino[10000];
	char kmRecorridos[10000];
	char tipoEntrega[10000];
	char costoEnvio[10000];

	Envio* pEnvio;

	if(pArrayListaEnvios != NULL)
	{
		printf("\nLista de envíos:\n");
		for(int i ; i < ll_len(pArrayListaEnvios) ; i++)
		{
			retorno = 0;
			pEnvio = ll_get(pArrayListaEnvios, i);
			envio_getIdProductoTxt(pEnvio, idProducto);
			envio_getNombreProducto(pEnvio, nombreProducto);
			envio_getIdCamionTxt(pEnvio, idCamion);
			envio_getZonaDestino(pEnvio, zonaDestino);
			envio_getKmRecorridosTxt(pEnvio, kmRecorridos);
			envio_getTipoEntregaTxt(pEnvio, tipoEntrega);
			envio_getCostoDeEnvioTxt(pEnvio, costoEnvio);
			printf("%s - %s - %s - %s - %s - %s - %s\n", idProducto, nombreProducto, idCamion, zonaDestino, kmRecorridos, tipoEntrega, costoEnvio);
		}
	}
	return retorno;
}

LinkedList* controller_generarArchivoDeCostosPorZona(LinkedList* pArrayListaEnvios)
{
	char zonaDeseada[10000];

	char idProducto[10000];
	char nombreProducto[10000];
	char idCamion[10000];
	char zonaDestino[10000];
	char kmRecorridos[10000];
	char tipoEntrega[10000];
	char costoEnvio[10000];

	FILE* pFile = NULL;
	Envio* pElement;
	LinkedList* pArrayListaFiltrada;

	if(pArrayListaEnvios != NULL)
	{
		if(utn_getStringWithNumbersAndSymbols("\nIngrese el nombre de la zona por la que desea filtrar:\n", "\nError, ingrese una zona válida.\n", zonaDeseada, SIZE_ZONE, 3) == 0)
		{
			strncat(zonaDeseada, ".csv", sizeof(zonaDeseada)); // Concateno las dos cadenas.
			pFile = fopen(zonaDeseada, "w");
			if(pFile != NULL)
			{
				// HORA: 07:23 (Clase 19/11)
				pArrayListaFiltrada = ll_filterWithOneMoreArgument(pArrayListaEnvios, envio_identificarZona, zonaDeseada);
				if(pArrayListaFiltrada != NULL)
				{
					controller_imprimirListaEnvios(pArrayListaFiltrada);
					fprintf(pFile, "\nID del producto \tNombre del producto\tID del camión\tZona destino\tKilómetros recorridos\tTipo de entrega\tCosto de envío\n");
					for(int i = 0; i < ll_len(pArrayListaFiltrada) ; i++)
					{
						pElement = (Envio*)ll_get(pArrayListaFiltrada, i);
						if(pElement != NULL)
						{
							if(envio_leerAtributosDeManeraConjunta(pElement, idProducto, nombreProducto, idCamion, zonaDestino, kmRecorridos, tipoEntrega, costoEnvio) == 0)
							{
								fprintf(pFile,"%s, %s, %s, %s, %s, %s, %s\n", idProducto, nombreProducto, idCamion, zonaDestino, kmRecorridos, tipoEntrega, costoEnvio);
							}
						}
					}
				}
				fclose(pFile);
			}
		}
	}
	return pArrayListaFiltrada;
}
