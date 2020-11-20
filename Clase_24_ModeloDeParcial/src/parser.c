/*
 * parser.c
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#include "Parser.h"
#include "Envio.h"

#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int parser_EnvioTxt(FILE* pFile , LinkedList* pArray)
{
	int returnAux = ERROR;
	char header[500];
	char idEnvio[500];
	char nombreProducto[500];
	char idCamion[500];
	char zonaDestinos[500];
	char kmRecorridos[500];
	char tipoEntrega[500];
	float costoEnvio=10;
	Envio* pElement;

	if(pFile != NULL && pArray != NULL)
	{
		fscanf(pFile,"%[^\n]",header);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idEnvio,nombreProducto,idCamion,zonaDestinos,kmRecorridos,tipoEntrega)==6)
			{
				//costoEnvio = calcularCostoEnvio(atof(kmRecorridos), atoi(tipoEntrega));
				if(costoEnvio!= ERROR)
				{
					pElement = envio_newParametros(idEnvio, nombreProducto, idCamion, zonaDestinos, kmRecorridos, tipoEntrega, costoEnvio);
					returnAux = ll_add(pArray,pElement);
				}
			} else {
				returnAux = -2;
				break;
			}
		}while(!feof(pFile));
	}
	return returnAux;
}
int parser_EnvioBinario(FILE* pFile , LinkedList* pArray)
{
	int returnAux = ERROR;
	return returnAux;
}
