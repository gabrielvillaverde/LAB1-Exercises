/*
 * contratacion.h
 *
 *  Created on: 6 oct. 2020
 *      Author: Hzkr
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define LONG 50
#define TRUE 1
#define FALSE 0

#include "pantalla.h" // Si no lo incluyo, no reconoce el tipo de dato Pantalla en mis funciones.

typedef struct
{
	int cuit;
	char nombreVideo [LONG]; // Es un array de caracteres
	int cantidadDias;
	int isEmpty;
	int idContratacion;
	int idPantalla; // Nos permite relacionar con la otra entidad
} Contratacion;

int contratacion_init(Contratacion * pArray, int limite);
int contratacion_alta (Contratacion * pArray, int limite, Pantalla * pArrayPantalla, int limitePantalla);
int contratacion_baja (Contratacion * pArray, int limite, Pantalla * pArrayPantalla, int limitePantalla);
int contratacion_modificar (Contratacion * pArray, int limite, Pantalla * pArrayPantalla, int limitePantalla);
int contratacion_imprimir (Contratacion * pArray , int limite, Pantalla * pArrayPantalla, int limitePantalla);
int contratacion_imprimirPorCuit (Contratacion * pArray, int limite, Pantalla * pArrayPantalla, int limitePantalla, int cuit);
int contratacion_buscarLibre (Contratacion * pArray, int limite);
int contratacion_buscarLibreRef (Contratacion * pArray, int limite, int * pIndice);
int contratacion_buscarIndicePorId (Contratacion * pArray, int limite, int idBuscar,int * pIndice);
int contratacion_buscarIndicePorCuit (Contratacion * pArray, int limite, int cuitBuscar, int * pIndice);
int contratacion_ordenarPorNombre (Contratacion * pArray, int limite , int orden);

#endif /* CONTRATACION_H_ */
