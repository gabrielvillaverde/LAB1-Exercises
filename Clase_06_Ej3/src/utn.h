/*
 * utn.h
 *
 *  Created on: 10 sep. 2020
 *      Author: Hzkr
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(char* mensaje, char* mensajeError, int* pResultado, int reintentos, int maximo, int minimo);
int utn_calcularMaximo(int *pArray, int cantidadElementos, int *pResultado);
void imprimirArray(int array[], int len);
void ordenar(int array[], int len);

#endif /* UTN_H_ */
