/*
 * parser.c
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>

#include "envio.h"
#include "LinkedList.h"

/*
* \brief Parsea los datos los datos de los envíos desde el archivo indicado (modo texto).
* \param FILE* puntero al archivo.
* \param pArrayListaEnvios LinkedList* puntero al array de envíos.
* \return (-1) Error (0) todo OK
*/


int parser_EnvioFromText(FILE* pFile, LinkedList* pArrayListaEnvios)
{
	int retorno = -1;

	Envio* pEnvio;

	char idProducto[10000];
	char nombreProducto[10000];
	char idCamion[10000];
	char zonaDestino[10000];
	char kmRecorridos[10000];
	char tipoEntrega[10000];
	char costoEnvio[10000] = "0"; // ?

	if(pFile != NULL && pArrayListaEnvios != NULL)
	{
		do
		{
			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idProducto, nombreProducto, idCamion, zonaDestino, kmRecorridos, tipoEntrega) == 6)
			{
				pEnvio = envio_newParametros(idProducto, nombreProducto, idCamion, zonaDestino, kmRecorridos, tipoEntrega, costoEnvio);
				if(pEnvio != NULL)
				{
					// ¿Debería agregar el parámetro costoEnvio?
					printf("%s - %s - %s - %s - %s - %s\n", idProducto, nombreProducto, idCamion, zonaDestino, kmRecorridos, tipoEntrega);
					ll_add(pArrayListaEnvios, pEnvio);
					retorno = 0;
				}
			}
		}while(feof(pFile) == 0);
	}
    return retorno;
}

