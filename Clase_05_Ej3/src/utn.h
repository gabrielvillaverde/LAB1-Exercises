/*
 * utn.h
 *
 *  Created on: 8 sep. 2020
 *      Author: Hzkr
 */

#ifndef UTN_H_
#define UTN_H_
#define EDADESSIZE 5

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
float promediarArrayInt(int arrayInt[], int len);
int promediarArrayIntV2(int* pPromedioResultado, int array[], int len);

#endif /* UTN_H_ */

