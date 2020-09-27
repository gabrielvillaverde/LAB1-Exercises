/*
 * utn.h
 *
 *  Created on: Sep 8, 2020
 *      Author: Mauro
 */

#ifndef UTN_H_
#define UTN_H_

#define LIMITE_BUFFER_STRING 4096
int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int esUnNombreValido(char* cadena,int limite);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);

#endif /* UTN_H_ */
