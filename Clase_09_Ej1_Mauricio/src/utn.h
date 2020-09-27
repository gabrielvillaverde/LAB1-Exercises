/*
 * utn.h
 *
 *  Created on: 9 sep. 2020
 *      Author: Hzkr
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int myGets(char* cadena, int longitud);
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite);
int esUnNombreValido(char* cadena, int limite);

#endif /* UTN_H_ */
