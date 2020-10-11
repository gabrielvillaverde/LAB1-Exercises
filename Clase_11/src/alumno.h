/*
 * alumno.h
 *
 *  Created on: 22 sep. 2020
 *      Author:
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#define SIZE_NOMBRE 50
#define TRUE 1
#define FALSE 0
#define MIN_LEGAJO 0
#define MAX_LEGAJO 50

typedef struct
{
	char nombre[SIZE_NOMBRE];
	int legajo;
	int isEmpty;
	int id;
}Alumno;

	int alumno_init(Alumno* pArray, int limite);
	int alumno_alta(Alumno* pArray, int limite, int indice);
	int alumno_baja (Alumno* pArray, int limite, int indice);
	int alumno_modificar (Alumno* pArray, int limite, int indice);
	int alumno_imprimir (Alumno* pArray , int limite);
	int alumno_imprimirIndice (Alumno * pArray, int limite, int indice);
	int alumno_imprimirPorId (Alumno * pArray, int limite, int indice);
	int alumno_buscarLibre (Alumno* pArray, int limite);
	int alumno_buscarLibreRef (Alumno* pArray, int limite, int * pIndice);
	int alumno_alta2 (Alumno* pArray, int limite);
	int alumno_buscarIndice (Alumno* pArray, int limite, int idBuscar,int * pIndice);
	int alumno_ordenarPorNombre (Alumno * pArray, int limite, int order);
	int alumno_ordenarPorNombreEdgardo (Alumno * pArray, int limite, int order);
	int alumno_buscarId(Alumno* pArrayAlumnos, int limite, int *pIndice, int id);
#endif /* ALUMNO_H_ */
