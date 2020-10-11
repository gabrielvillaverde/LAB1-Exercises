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
	#define MIN_LEGAJO 1
	#define MAX_LEGAJO 5


	typedef struct {
	char nombre[SIZE_NOMBRE];
	int legajo;
	int isEmpty;
	int id;
	}Alumno;

	int alumno_alta (Alumno * pArrayAlumnos, int limite);
	int alumno_init(Alumno * pArrayAlumnos, int limite);
	int alumno_imprimir (Alumno * pArrayAlumnos , int limite);
	int alumno_baja (Alumno * pArrayAlumnos, int limite);
	int alumno_modificar (Alumno * pArrayAlumnos, int limite);
	int alumno_imprimirIndice (Alumno * pArrayAlumnos, int limite, int indice);
	int alumno_buscarLibre (Alumno * pArrayAlumnos, int limite);
	int alumno_buscarLibreRef (Alumno * pArrayAlumnos, int limite, int * pIndice);
	int alumno_alta2 (Alumno * pArrayAlumnos, int limite);
	int alumno_buscarIndice (Alumno * pArrayAlumnos, int limite, int idBuscar,int * pIndice);
	int alumno_ordenarPorNombre (Alumno * pArrayAlumnos, int limite, int order);
#endif /* ALUMNO_H_ */
