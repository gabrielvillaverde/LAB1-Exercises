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

typedef struct
{
	char nombre [LONG];
	char direccion [LONG];
	int tipo;
	float precioPublicidad;
	int isEmpty;
	int idPantalla;
} Pantalla;

#define PANTALLA_TIPO_LCD 0
#define PANTALLA_TIPO_LED 1

int pantalla_init(Pantalla * pArray, int limite);
int pantalla_alta (Pantalla * pArray, int limite);
int pantalla_baja (Pantalla * pArray, int limite);
int pantalla_modificar (Pantalla * pArray, int limite);
int pantalla_imprimir (Pantalla * pArray , int limite);
int pantalla_buscarLibre (Pantalla * pArray, int limite);
int pantalla_buscarLibreRef (Pantalla * pArray, int limite, int * pIndice);
int pantalla_buscarIndicePorId (Pantalla * pArray, int limite, int idBuscar,int * pIndice);
int pantalla_ordenarPorNombre (Pantalla * pArrays, int limite , int orden);

#endif /* PANTALLA_H_ */
