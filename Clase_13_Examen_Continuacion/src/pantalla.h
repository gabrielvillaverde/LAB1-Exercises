/*
 * pantalla.h
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define LONG 50
#define TRUE 1
#define FALSE 0
#define PANTALLA_TIPO_LCD 0
#define PANTALLA_TIPO_LED 1

typedef struct
{
	char nombre [LONG];
	char direccion [LONG];
	int tipo; // Hago un #define para el tipo: [LCD - 0] - [LED - 1]
	float precio;
	int isEmpty;
	int idPantalla;
} Pantalla;

int pantalla_init(Pantalla * pArrayPantalla, int limitePantalla);
int pantalla_alta (Pantalla * pArrayPantalla, int limitePantalla);
int pantalla_baja (Pantalla * pArrayPantalla, int limitePantalla);
int pantalla_modificar (Pantalla * pArrayPantalla, int limitePantalla);
int pantalla_imprimir (Pantalla * pArrayPantalla , int limitePantalla);
int pantalla_buscarLibre (Pantalla * pArrayPantalla, int limitePantalla);
int pantalla_buscarLibreRef (Pantalla * pArrayPantalla, int limitePantalla, int * pIndice);
int pantalla_buscarIndicePorId (Pantalla * pArrayPantalla, int limitePantalla, int idBuscar,int * pIndice);
int pantalla_ordenarPorNombre (Pantalla * pArrayPantallas, int limitePantalla , int orden);

#endif /* PANTALLA_H_ */
