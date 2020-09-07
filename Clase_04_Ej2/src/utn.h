/*
 * utn.h
 *
 *  Created on: 3 sep. 2020
 *      Author: Hzkr
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos); // Una obtiene el número como entero.
int utn_getNumeroFlotante( float * pResultado, char * mensaje, char * mensajeError, float minimo, float maximo, int reintentos); // Otra obtiene el número como flotante.
int utn_getCaracter( char * pResultado, char * mensaje, char * mensajeError, char minimo, char maximo, int reintentos); // Otra obtiene el número como caracter.

#endif /* UTN_H_ */
