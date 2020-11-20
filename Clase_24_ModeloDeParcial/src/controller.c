/*
 * controller.c
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#include <stdlib.h>
#include <stdio.h>
#include "Controller.h"
#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define NORMAL 0
#define EXPRESS 1
#define SEGUN_DISPO 2

int controller_loadTexto(LinkedList* pArray, char* ruta)
{
	int returnAux = ERROR;
	FILE* pArchivo;

	if(pArray != NULL && ruta != NULL)
	{
		pArchivo = fopen(ruta,"r");
		if(pArchivo != NULL)
		{
			returnAux = parser_EnvioTxt(pArchivo, pArray);
		}
		fclose(pArchivo);
	}
	return returnAux;
}

int controller_printOne(void* pElement)
{
	int returnAux = ERROR;
	Envio* unEnvio;
	Envio buffer;
	char tipoEntrega[25];

	if(pElement != NULL)
	{
		unEnvio = (Envio*)pElement;
		envio_getId(unEnvio,&buffer.idEnvio);
		envio_getNombreProducto(unEnvio,buffer.nombreProducto);
		envio_getIdCamion(unEnvio,&buffer.idCamion);
		envio_getZonaDestinos(unEnvio,buffer.zonaDestinos);
		envio_getKmRecorridos(unEnvio,&buffer.kmRecorridos);
		envio_getTipoEntrega(unEnvio,&buffer.tipoEntrega);
		envio_getCostoEnvio(unEnvio,&buffer.costoEnvio);
		if(buffer.tipoEntrega == NORMAL)
		{
			sprintf(tipoEntrega,"NORMAL");
		} else if(buffer.tipoEntrega == EXPRESS) {
			sprintf(tipoEntrega,"EXPRESS");
		} else {
			sprintf(tipoEntrega,"SEGUN DISPO");
		}
		printf("%15d %15s %15d %15s %10.1f %25s \t$%.2f\n",
				buffer.idEnvio,
				buffer.nombreProducto,
				buffer.idCamion,
				buffer.zonaDestinos,
				buffer.kmRecorridos,
				tipoEntrega,
				buffer.costoEnvio);
		returnAux = SUCCESS;
	}
	return returnAux;
}

int controller_printList(LinkedList* pArray)
{
	int returnAux = ERROR;

	if(pArray != NULL)
	{
		printf("\n%15s %15s %15s %15s %10s %25s %12s\n\n","ID ENVIO","NOMBRE","ID CAMION","ZONA","KM","TIPO ENT","COSTO ENVIO");
		returnAux = ll_map(pArray,controller_printOne);
	}
	return returnAux;
}

