/*
 * envio.c
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "envio.h"
#include "utn.h"

Envio* envio_new()
{
	Envio* this = NULL;
	this = (Envio*) malloc (sizeof(Envio));
	return this;
}

void envio_delete(Envio* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

Envio* envio_newParametros(char* idProducto, char* nombreProducto, char* idCamion, char* zonaDestino, char* kmRecorridos, char* tipoEntrega, char* costoEnvio)
{
	Envio* this = NULL;

	this = envio_new();

	if(this != NULL && idProducto != NULL && nombreProducto != NULL && idCamion != NULL && zonaDestino != NULL && kmRecorridos != NULL && tipoEntrega != NULL && costoEnvio != NULL)
	{
		if( envio_setIdProductoTxt(this, idProducto) == -1 ||
			envio_setNombreProducto(this, nombreProducto) == -1 ||
			envio_setIdCamionTxt(this, idCamion) == -1 ||
			envio_setZonaDestino(this, zonaDestino) == -1 ||
			envio_setKmRecorridosTxt(this, kmRecorridos) == -1 ||
			envio_setTipoEntregaTxt(this, tipoEntrega) == -1 ||
			envio_setCostoDeEnvioTxt(this, costoEnvio) == -1)
		{
			envio_delete(this);
			this = NULL;
		}
	}
	return this;
}

/* Función que permite obtener el costo total del envio
* \param pElement puntero al elemento de la lista de envios
* \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el puntero al atributo recibido es NULL
                           ( 0) Si funcionó correctamente
*/

int envio_calcularCostoDeEnvio(void* pElement)
{
	int retorno = -1;

	float costoFijo;
	float kmRecorridos;
	float precioPorKm;
	float costoTotal;

	Envio* this;

	if(pElement != NULL)
	{
		this = (Envio*) pElement;
		if(envio_calcularCostoFijo(this, &costoFijo) == 0)
		{
			if(envio_getKmRecorridos(this, &kmRecorridos) == 0)
			{
				if(kmRecorridos < 50)
				{
					precioPorKm = 150;
				}
				else
				{
					precioPorKm = 100;
				}
				costoTotal = (kmRecorridos * precioPorKm) + costoFijo;
				if(envio_setCostoDeEnvio(this, costoTotal) == 0)
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int envio_calcularCostoFijo(Envio* this, float* costoFijo)
{
	int retorno = -1;

	int tipoEntrega;

	if(this != NULL && costoFijo != NULL)
	{
		if(envio_getTipoEntrega(this, &tipoEntrega) == 0)
		{
			switch(tipoEntrega)
			{
			case 0: // Tipo de entrega: normal.
				*costoFijo = 350;
				break;
			case 1: // Tipo de entrega: express.
				*costoFijo = 420;
				break;
			case 2: // Tipo de entrega: según disponibilidad.
				*costoFijo = 275;
				break;
			}
			retorno = 0;
		}
	}
	return retorno;
}

// HORA: 07:20 (Clase 19/11)
int envio_identificarZona(void* pElement, char* zonaDeseada)
{
	int retorno = 0;

	Envio* this = (Envio*) pElement;

	char zonaDestino[SIZE_ZONE];

	if(envio_getZonaDestino(this, zonaDestino) == 0)
	{
		// strcmpi para mayúsculas y minúsculas.
		// HORA: 07:33 (Clase 19/11) Hay que tener en cuenta la mayúscula y minúscula del principio de cada zona cuando se busca.
		if(strncmp(zonaDestino, zonaDeseada, SIZE_ZONE) == 0) // Si son iguales...
		{
			retorno = 1;
		}
	}
	return retorno;
}

int envio_leerAtributosDeManeraConjunta(Envio* this, char* idProducto, char* nombreProducto, char* idCamion, char* zonaDestino, char* kmRecorridos, char* tipoEntrega, char* costoEnvio)
{
	int retorno = -1;
	if(
	envio_getIdProductoTxt(this, idProducto) == 0 &&
	envio_getNombreProducto(this, nombreProducto) == 0 &&
	envio_getIdCamionTxt(this, idCamion) == 0 &&
	envio_getZonaDestino(this, zonaDestino) == 0 &&
	envio_getKmRecorridosTxt(this, kmRecorridos) == 0 &&
	envio_getTipoEntregaTxt(this, tipoEntrega) == 0 &&
	envio_getCostoDeEnvioTxt(this, costoEnvio) == 0)
	{
		retorno = 0;
	}
	return retorno;
}

/* SETTERS AND GETTERS. */

int envio_setIdEnvio(Envio* this, int idProducto)
{
	int retorno = -1;
	if (this != NULL && idProducto >= 0)
	{
		this->idProducto = idProducto;
		retorno = 0;
	}
	return retorno;
}

int envio_getIdEnvio(Envio* this, int* idProducto)
{
    int retorno = -1;
    if (this != NULL && idProducto != NULL)
    {
        *idProducto = this->idProducto;
        retorno = 0;
    }
    return retorno;
}

int envio_setIdProductoTxt(Envio* this, char* idProducto)
{
    int retorno = -1;
    if (this != NULL && idProducto != NULL && utn_isNumeric(idProducto))
    {
        this->idProducto = atoi(idProducto);
        retorno = 0;
    }
    return retorno;
}

int envio_getIdProductoTxt(Envio* this, char* idProducto)
{
    int retorno = -1;
    if (this != NULL && idProducto != NULL)
    {
        sprintf(idProducto, "%d", this->idProducto);
        retorno = 0;
    }
    return retorno;
}

int envio_setNombreProducto(Envio *this, char* name)
{
	int retorno = -1;
	if (this != NULL && name != NULL && utn_isAlphabetic(name))
	{
		strncpy(this->nombreProducto, name, SIZE_NAME);
		retorno = 0;
	}
	return retorno;
}

int envio_getNombreProducto(Envio* this, char* name)
{
    int retorno = -1;
    if (this != NULL && name != NULL)
    {
        strncpy(name, this->nombreProducto, SIZE_NAME);
        retorno = 0;
    }
    return retorno;
}

int envio_setIdCamion(Envio* this, int idCamion)
{
	int retorno = -1;
	if (this != NULL && idCamion >= 0)
	{
		this->idCamion = idCamion;
		retorno = 0;
	}
	return retorno;
}

int envio_getIdCamion(Envio* this, int* idCamion)
{
    int retorno = -1;
    if (this != NULL && idCamion != NULL)
    {
        *idCamion = this->idCamion;
        retorno = 0;
    }
    return retorno;
}

int envio_setIdCamionTxt(Envio* this, char* idCamion)
{
    int retorno = -1;
    if (this != NULL && idCamion != NULL && utn_isNumeric(idCamion))
    {
        this->idCamion = atoi(idCamion);
        retorno = 0;
    }
    return retorno;
}

int envio_getIdCamionTxt(Envio* this, char* idCamion)
{
    int retorno = -1;
    if (this != NULL && idCamion != NULL)
    {
        sprintf(idCamion, "%d", this->idCamion);
        retorno = 0;
    }
    return retorno;
}

int envio_setZonaDestino(Envio *this, char* zonaDestino)
{
	int retorno = -1;
	if (this != NULL && zonaDestino != NULL && utn_isAlphabetic(zonaDestino))
	{
		strncpy(this->zonaDestino, zonaDestino, SIZE_ZONE);
		retorno = 0;
	}
	return retorno;
}

int envio_getZonaDestino(Envio* this, char* zonaDestino)
{
    int retorno = -1;
    if (this != NULL && zonaDestino != NULL)
    {
        strncpy(zonaDestino, this->zonaDestino, SIZE_ZONE);
        retorno = 0;
    }
    return retorno;
}

int envio_setKmRecorridos(Envio* this, float kmRecorridos)
{
	int retorno = -1;
	if(this != NULL && kmRecorridos > 0)
	{
		this->kmRecorridos = kmRecorridos;
		retorno = 0;
	}
	return retorno;
}

int envio_getKmRecorridos(Envio* this, float* kmRecorridos)
{
    int retorno = -1;
    if (this != NULL && kmRecorridos != NULL)
    {
        *kmRecorridos = this->kmRecorridos;
        retorno = 0;
    }
    return retorno;
}

int envio_setKmRecorridosTxt(Envio* this, char* kmRecorridos)
{
    int retorno = -1;
    if (this != NULL && kmRecorridos != NULL && utn_isFloatNumber(kmRecorridos))
    {
        this->kmRecorridos = atof(kmRecorridos);
        retorno = 0;
    }
    return retorno;
}

int envio_getKmRecorridosTxt(Envio* this, char* kmRecorridos)
{
    int retorno = -1;
    if (this != NULL && kmRecorridos != NULL)
    {
        sprintf(kmRecorridos, "%f", this->kmRecorridos);
        retorno = 0;
    }
    return retorno;
}

int envio_setTipoEntrega(Envio* this, int tipoEntrega)
{
	int retorno = -1;
	if(this != NULL && tipoEntrega >= 0)
	{
		this->tipoEntrega = tipoEntrega;
		retorno = 0;
	}
	return retorno;
}

int envio_getTipoEntrega(Envio* this, int* tipoEntrega)
{
    int retorno = -1;
    if (this != NULL && tipoEntrega != NULL)
    {
        *tipoEntrega = this->tipoEntrega;
        retorno = 0;
    }
    return retorno;
}

int envio_setTipoEntregaTxt(Envio* this, char* tipoEntrega)
{
    int retorno = -1;
    if (this != NULL && tipoEntrega != NULL && utn_isNumeric(tipoEntrega))
    {
        this->tipoEntrega = atoi(tipoEntrega);
        retorno = 0;
    }
    return retorno;
}

int envio_getTipoEntregaTxt(Envio* this, char* tipoEntrega)
{
    int retorno = -1;
    if (this != NULL && tipoEntrega != NULL)
    {
        sprintf(tipoEntrega, "%d", this->tipoEntrega);
        retorno = 0;
    }
    return retorno;
}

int envio_setCostoDeEnvio(Envio* this, float costoEnvio)
{
	int retorno = -1;

	if(this != NULL && costoEnvio >= 0)
	{
		retorno = 0;
		this->costoEnvio = costoEnvio;
	}
	return retorno;
}

int envio_getCostoDeEnvio(Envio* this, float* costoEnvio)
{
	int retorno = -1;
	if(this != NULL && costoEnvio != NULL)
	{
		retorno = 0;
		*costoEnvio = this->costoEnvio;
	}
	return retorno;
}

int envio_setCostoDeEnvioTxt(Envio* this, char* costoEnvio)
{
	int retorno = -1;

	if(this != NULL && costoEnvio!= NULL && utn_isFloatNumber(costoEnvio))
	{
			this->costoEnvio = atof(costoEnvio);
			retorno = 0;
	}
	return retorno;
}

int envio_getCostoDeEnvioTxt(Envio* this, char* costoEnvio)
{

	int retorno = -1;

	if(this != NULL && costoEnvio != NULL)
	{
		sprintf(costoEnvio, "%f", this->costoEnvio);
		retorno = 0;
	}
	return retorno;

}
