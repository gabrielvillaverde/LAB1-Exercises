/*
 * alumno.h
 *
 *  Created on: Sep 22, 2020
 *      Author: Mauro
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999

typedef struct
{
	char nombre[LONG_NOMBRE];
	int legajo;
	int isEmpty;
	int id;
}Alumno;

int alumno_buscarId(Alumno* pArrayAlumnos, int limite, int* pIndex, int id);
int alumno_alta(Alumno arrayAlumnos[],int limite,int indice);
int alumno_imprimir(Alumno* pArrayAlumnos, int limite);
int alumno_initArray(Alumno* pArrayAlumnos, int limite);
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice);
int alumno_buscarLibreRef(Alumno pArrayAlumnos[], int limit, int *pIndex);
#endif /* ALUMNO_H_ */
