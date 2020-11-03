/*
 * utn.h
 *      Author: Hzkr
 */

#ifndef UTN_H_
#define UTN_H_

	int utn_getNumberInt(char* pMensaje, char* pMensajeError, int* pResultado, int reintentos, int minimo, int maximo);
	int utn_getNumberFloat(char* pMensaje, char* pMensajeError, float* pResultado, int reintentos, float minimo, float maximo);
	int utn_getChar(char* pMensaje, char* pMensajeError, char* pResultado, int reintentos, int limite);
	int utn_getName(char* pMensaje, char* pMensajeError, char* pResultado, int reintentos, int limite);
	int utn_getAlphaNum(char* pMensaje, char* pMensajeError, char* pResultado, int reintentos, int limite);
	int utn_getCuit(char* pMensaje, char* pMensajeError, char* pResultado, int reintentos, int limite);

	int isNumber(char cadena[]);
	int getInt(int* pResultado);
	int myGets(char array[], int longitud);
	int utn_itIsAValidName(char array[], int limite);
	int isOnlyLettersAndSpace(char cadena[]);
	int isAlphNum(char cadena[]);
	int getFloat(float* pResultado);
	int isNumberFloat(char cadena[]);
	int isCuit(char cadena[]);

#endif /* UTN_H_ */
