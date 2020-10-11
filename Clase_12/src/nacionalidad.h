/*
 * nacionalidad.h
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_

#define SIZE_NOMBRE 50
#define LONG 50
#define TRUE 1
#define FALSE 0

typedef struct
{
	char nombre[SIZE_NOMBRE];
	int legajo;
	int isEmpty;
	int id;
}Nacionalidad;

	int nacionalidad_init(Nacionalidad* pArray, int limite); // Para inicializar el array, cargándole el campo de isEmpty en TRUE.

	int nacionalidad_alta(Nacionalidad* pArray, int limite, int indice);
	int nacionalidad_baja (Nacionalidad* pArray, int limite, int indice);
	int nacionalidad_modificar (Nacionalidad* pArray, int limite, int indice);

	int nacionalidad_imprimir (Nacionalidad* pArray , int limite);

	int nacionalidad_buscarLibre (Nacionalidad* pArray, int limite); // Verifica si hay algún lugar libre en el array. Devuelve un índice donde hay un lugar libre.
	int nacionalidad_buscarLibreRef (Nacionalidad* pArray, int limite, int * pIndice); // Devuelve el valor del lugar libre pero por referencia.
	int nacionalidad_buscarIndicePorId (Nacionalidad* pArray, int limite, int idBuscar, int * pIndice); //
	int nacionalidad_ordenarPorNombre (Nacionalidad * pArray, int limite, int order);
	int nacionalidad_ordenarPorNombre2 (Nacionalidad * pArray, int limite, int order);
	int nacionalidad_buscarId(Nacionalidad* pArrayNacionalidads, int limite, int *pIndice, int id);

typedef struct
{
	char pais[LONG];
	char nombre [LONG];
	int isEmpty;
	int id;
} Nac;

	int nac_init(Nac * pArrayNacs, int limite);

	int nac_alta (Nac * pArrayNacs, int limite);
	int nac_baja (Nac * pArrayNacs, int limite);
	int nac_modificar (Nac * pArrayNacs, int limite);

	int nac_imprimir (Nac * pArrayNacs , int limite);

	int nac_buscarLibre (Nac * pArrayNacs, int limite);
	int nac_buscarLibreRef (Nac * pArrayNacs, int limite, int * pIndice);
	int nac_buscarIndicePorId (Nac * pArrayNacs, int limite, int idBuscar,int * pIndice);
	int nac_ordenarPorNombre (Nac * pArrays, int limite , int orden);

#endif /* NACIONALIDAD_H_ */
