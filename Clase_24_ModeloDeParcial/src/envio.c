/*
 * envio.c
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Envio.h"
#include "Validations.h"
#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define NORMAL 0
#define EXPRESS 1
#define SEGUN_DISPO 2

Envio* envio_new(void)
{
	return (Envio*) malloc(sizeof(Envio));
}

Envio* envio_newParametros(char* idEnvio, char* nombreProducto, char* idCamion, char* zonaDestinos, char* kmRecorridos, char* tipoEntrega, float costoEnvio)
{
	Envio* this = NULL;

	if (idEnvio != NULL && nombreProducto != NULL && idCamion != NULL &&  zonaDestinos != NULL && kmRecorridos != NULL &&  tipoEntrega != NULL && costoEnvio > 0)
	{
		this = envio_new();
		if (this != NULL)
		{
			envio_setIdTxt(this,idEnvio);
			envio_setNombreProducto(this,nombreProducto);
			envio_setIdCamionTxt(this,idCamion);
			envio_setZonaDestinos(this,zonaDestinos);
			envio_setKmRecorridosTxt(this,kmRecorridos);
			envio_setTipoEntregaTxt(this,tipoEntrega);
			envio_setCostoEnvio(this,costoEnvio);
		}
	}
	return this;
}

void envio_delete(Envio* this)
{
	free(this);
}

int envio_setId(Envio* this, int id)
{
	int result = ERROR;
	if (this != NULL && id >= 0)
	{
		this->idEnvio = id;
		result = SUCCESS;
	}
	return result;
}

int envio_getId(Envio* this, int* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        *id = this->idEnvio;
        result = SUCCESS;
    }
    return result;
}

int envio_setIdTxt(Envio* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL && isValidNumber(id, sizeof(id)))
    {
        this->idEnvio = atoi(id);
        result = SUCCESS;
    }
    return result;
}

int envio_getIdTxt(Envio* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->idEnvio);
        result = SUCCESS;
    }
    return result;
}

int envio_setNombreProducto(Envio *this, char* name)
{
	int result = ERROR;
	if (this != NULL && name != NULL && isValidLetters(name, NAME_LEN))
	{
		strncpy(this->nombreProducto, name, NAME_LEN);
		result = SUCCESS;
	}
	return result;
}

int envio_getNombreProducto(Envio* this, char* name)
{
    int result = ERROR;
    if (this != NULL && name != NULL)
    {
        strncpy(name, this->nombreProducto, NAME_LEN);
        result = SUCCESS;
    }
    return result;
}

int envio_setIdCamion(Envio* this, int id)
{
	int result = ERROR;
	if (this != NULL && id >= 0)
	{
		this->idCamion = id;
		result = SUCCESS;
	}
	return result;
}

int envio_getIdCamion(Envio* this, int* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        *id = this->idCamion;
        result = SUCCESS;
    }
    return result;
}

int envio_setIdCamionTxt(Envio* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL && isValidNumber(id, sizeof(id)))
    {
        this->idCamion = atoi(id);
        result = SUCCESS;
    }
    return result;
}

int envio_getIdCamionTxt(Envio* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->idCamion);
        result = SUCCESS;
    }
    return result;
}

int envio_setZonaDestinos(Envio *this, char* zona)
{
	int result = ERROR;
	if (this != NULL && zona != NULL && isValidLetters(zona, ZONE_LEN))
	{
		strncpy(this->zonaDestinos, zona, ZONE_LEN);
		result = SUCCESS;
	}
	return result;
}

int envio_getZonaDestinos(Envio* this, char* zona)
{
    int result = ERROR;
    if (this != NULL && zona != NULL)
    {
        strncpy(zona, this->zonaDestinos, ZONE_LEN);
        result = SUCCESS;
    }
    return result;
}

int envio_setKmRecorridos(Envio* this, float kmRecorridos)
{
	int result = ERROR;
	if(this != NULL && kmRecorridos > 0)
	{
		this->kmRecorridos = kmRecorridos;
		result = SUCCESS;
	}
	return result;
}

int envio_getKmRecorridos(Envio* this, float* kmRecorridos)
{
    int result = ERROR;
    if (this != NULL && kmRecorridos != NULL)
    {
        *kmRecorridos = this->kmRecorridos;
        result = SUCCESS;
    }
    return result;
}

int envio_setKmRecorridosTxt(Envio* this, char* kmRecorridos)
{
    int result = ERROR;
    if (this != NULL && kmRecorridos != NULL && isValidNumberFloat(kmRecorridos, sizeof(kmRecorridos)))
    {
        this->kmRecorridos = atof(kmRecorridos);
        result = SUCCESS;
    }
    return result;
}

int envio_getKmRecorridosTxt(Envio* this, char* kmRecorridos)
{
    int result = ERROR;
    if (this != NULL && kmRecorridos != NULL)
    {
        sprintf(kmRecorridos, "%f", this->kmRecorridos);
        result = SUCCESS;
    }
    return result;
}

int envio_setTipoEntrega(Envio* this, int tipoEntrega)
{
	int result = ERROR;
	if(this != NULL && tipoEntrega >= 0)
	{
		this->tipoEntrega = tipoEntrega;
		result = SUCCESS;
	}
	return result;
}

int envio_getTipoEntrega(Envio* this, int* tipoEntrega)
{
    int result = ERROR;
    if (this != NULL && tipoEntrega != NULL)
    {
        *tipoEntrega = this->tipoEntrega;
        result = SUCCESS;
    }
    return result;
}

int envio_setTipoEntregaTxt(Envio* this, char* tipoEntrega)
{
    int result = ERROR;
    if (this != NULL && tipoEntrega != NULL && isValidNumber(tipoEntrega, sizeof(tipoEntrega)))
    {
        this->tipoEntrega = atoi(tipoEntrega);
        result = SUCCESS;
    }
    return result;
}

int envio_getTipoEntregaTxt(Envio* this, char* tipoEntrega)
{
    int result = ERROR;
    if (this != NULL && tipoEntrega != NULL)
    {
        sprintf(tipoEntrega, "%d", this->tipoEntrega);
        result = SUCCESS;
    }
    return result;
}

int envio_setCostoEnvio(Envio* this, float costoEnvio)
{
	int result = ERROR;
	if(this != NULL && costoEnvio > 0)
	{
		this->costoEnvio = costoEnvio;
		result = SUCCESS;
	}
	return result;
}

int envio_getCostoEnvio(Envio* this, float* costoEnvio)
{
    int result = ERROR;
    if (this != NULL && costoEnvio != NULL)
    {
        *costoEnvio = this->costoEnvio;
        result = SUCCESS;
    }
    return result;
}

int envio_setCostoEnvioTxt(Envio* this, char* costoEnvio)
{
    int result = ERROR;
    if (this != NULL && costoEnvio != NULL && isValidNumberFloat(costoEnvio, sizeof(costoEnvio)))
    {
        this->costoEnvio = atof(costoEnvio);
        result = SUCCESS;
    }
    return result;
}

int envio_getCostoEnvioTxt(Envio* this, char* costoEnvio)
{
    int result = ERROR;
    if (this != NULL && costoEnvio != NULL)
    {
        sprintf(costoEnvio, "%f", this->costoEnvio);
        result = SUCCESS;
    }
    return result;
}

float calcularCostoEnvio(float kmRecorridos, int tipoEntrega)
{
	float costo = ERROR;

	if (kmRecorridos > 0 && (tipoEntrega == 0 || tipoEntrega == 1 || tipoEntrega == 2))
	{
		if(kmRecorridos<50)
		{
			costo = 150*kmRecorridos;

		} else {
			costo = 100*kmRecorridos;
		}

		if(tipoEntrega == NORMAL)
		{
			costo = costo+350;
		}
		else if(tipoEntrega == EXPRESS)
		{
			costo = costo+420;
		}
		else
		{
			costo = costo+275;
		}
	}
	return costo;
}
