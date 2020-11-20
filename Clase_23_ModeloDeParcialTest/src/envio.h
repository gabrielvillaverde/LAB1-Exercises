/*
 * envio.h
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#ifndef ENVIO_H_
#define ENVIO_H_

#define SIZE_NAME 300
#define SIZE_ZONE 300

typedef struct
{
	int idProducto;
	char nombreProducto[SIZE_NAME];
	int idCamion;
	char zonaDestino[SIZE_ZONE];
	float kmRecorridos;
	int tipoEntrega;
	float costoEnvio;

}Envio;

Envio* envio_new();
Envio* envio_newParametros(char* idProducto, char* nombreProducto, char* idCamion, char* zonaDestino, char* kmRecorridos, char* tipoEntrega, char* costoEnvio);
void envio_delete(Envio* this);
int envio_calcularCostoDeEnvio(void* pElement);
int envio_calcularCostoFijo(Envio* this, float* costoFijo);
int envio_identificarZona(void* pElement, char* zonaDeseada);
int envio_leerAtributosDeManeraConjunta(Envio* this, char* idProducto, char* nombreProducto, char* idCamion, char* zonaDestino, char* kmRecorridos, char* tipoEntrega, char* costoEnvio);

int envio_setId(Envio* this, int idProducto);
int envio_getId(Envio* this, int* idProducto);
int envio_setIdProductoTxt(Envio* this, char* idProducto);
int envio_getIdProductoTxt(Envio* this, char* idProducto);

int envio_setNombreProducto(Envio *this, char* name);
int envio_getNombreProducto(Envio* this, char* name);

int envio_setIdCamion(Envio* this, int idCamion);
int envio_getIdCamion(Envio* this, int* idCamion);
int envio_setIdCamionTxt(Envio* this, char* idCamion);
int envio_getIdCamionTxt(Envio* this, char* idCamion);

int envio_setZonaDestino(Envio *this, char* zona);
int envio_getZonaDestino(Envio* this, char* zona);

int envio_setKmRecorridos(Envio* this, float kmRecorridos);
int envio_getKmRecorridos(Envio* this, float* kmRecorridos);
int envio_setKmRecorridosTxt(Envio* this, char* kmRecorridos);
int envio_getKmRecorridosTxt(Envio* this, char* kmRecorridos);

int envio_setTipoEntrega(Envio* this, int tipoEntrega);
int envio_getTipoEntrega(Envio* this, int* tipoEntrega);
int envio_setTipoEntregaTxt(Envio* this, char* tipoEntrega);
int envio_getTipoEntregaTxt(Envio* this, char* tipoEntrega);

int envio_setCostoDeEnvio(Envio* this, float costoEnvio);
int envio_getCostoDeEnvio(Envio* this, float* costoEnvio);
int envio_setCostoDeEnvioTxt(Envio* this, char* costoEnvio);
int envio_getCostoDeEnvioTxt(Envio* this, char* costoEnvio);

#endif /* ENVIO_H_ */
