/*
 * alumno.h
 *
 *  Created on: 25 sep. 2020
 *      Author: Hzkr
 */

#ifndef ALUMNOS_H_
#define ALUMNOS_H_

#define LONG_NAME 51
#define LONG_LASTNAME 51

typedef struct
{
	int id;
	char name[LONG_NAME];
	char lastName[LONG_LASTNAME];
	float salary;
	int sector;
	int isEmpty;
}Alumno;

int alumno_initAlumnos(Alumno* list, int len);
int alumno_addAlumno(Alumno* pArrayList, int len, int index);
int alumno_removeAlumno(Alumno* pArrayList, int len, int index, int id);
int alumno_findEmpty(Alumno* pArrayList, int len, int* pIndex);
int alumno_modifyAlumno(Alumno* pArrayList, int len, int index);
int alumno_findAlumnoById(Alumno* pArrayList, int len, int* pIndex, int id);
int alumno_printAlumnos(Alumno* pArrayList, int len);
int alumno_sortAlumnos(Alumno* pArrayList, int len, int order);
int alumno_calculateTotalAndAverageSalary(Alumno* pArrayList, int len, float* pTotalSalary, float* pAverageSalary, int *pGreaterThanAverage);
int returnId();

#endif /* ALUMNOS_H_ */
