/*
 * nacionalidad.h
 *
 *  Created on: 29 sep. 2020
 *      Author: Hzkr
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_

#define SIZE_NAC 50
#define MIN_ID 1
#define MAX_ID 1000

	typedef struct {
	char nombre[SIZE_NAC];
	int isEmpty;
	int id;
}Nacionalidad;

	int nacionalidad_alta (Nacionalidad * pArray, int limite);
	int nacionalidad_init(Nacionalidad * pArray, int limite);
	int nacionalidad_imprimir (Nacionalidad * pArray, int limite);
	int nacionalidad_baja (Nacionalidad * pArray, int limite);
	int nacionalidad_modificar (Nacionalidad * pArray, int limite);
	int nacionalidad_imprimirIndice (Nacionalidad * pArray, int limite, int indice);
	int nacionalidad_buscarLibre (Nacionalidad * pArray, int limite);
	int nacionalidad_buscarLibreRef (Nacionalidad * pArray, int limite, int * pIndice);
	int nacionalidad_alta2 (Nacionalidad * pArray, int limite);
	int nacionalidad_buscarIndice (Nacionalidad * pArray, int limite, int idBuscar,int * pIndice);
	int nacionalidad_ordenarPorNombre (Nacionalidad * pArray, int limite, int order);

#endif /* NACIONALIDAD_H_ */
