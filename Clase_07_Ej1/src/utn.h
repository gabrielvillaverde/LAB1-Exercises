/*
 * utn.h
 *
 *  Created on: 9 sep. 2020
 *      Author: Hzkr
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int sumar(float operadorA, float operadorB, float *pResultado);
int restar(float operadorA, float operadorB, float *pResultado);
int multiplicar(float operadorA, float operadorB, float *pResultado);
int dividir (int operador1, int operador2, float* pResultado);
int funcionFactorial(int numero, long *pResultado);
int calcularMayor(int* pResultado, int n1, int n2);

#endif /* UTN_H_ */
