/*
 * alumno.h
 *
 *  Created on: 22 sep. 2020
 *      Author: Hzkr
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

// 1. Declaro los define para Alumno
#define LONG_NOMBRE 50
#define CANTIDAD_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999
#define TRUE 1
#define FALSE 0

// 2. Defino la estructura Alumno, que guarda dos tipos de variables, char e int
typedef struct{
	char nombre[LONG_NOMBRE];
	int legajo;
	int isEmpty; // Sirve para indicar si en esa posición tenés un valor cargado o todavía no cargaste ningún valor.
}Alumno;

// 3. Prototipos para Alumno
int alumno_alta(Alumno arrayAlumnos[], int limite, int indice);
int alumno_imprimir(Alumno* pArrayAlumnos, int limite);
int alumno_initArray(Alumno* pArrayAlumnos, int limite);
int alumno_modificar(Alumno arrayAlumnos[],int limite, int indice);

#endif /* ALUMNO_H_ */
