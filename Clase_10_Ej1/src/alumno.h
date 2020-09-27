/*
 * alumno.h
 *
 *  Created on: 22 sep. 2020
 *      Author:
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define LONG_NAME 50


	// TYPEDEF redefine un tipo de dato del sistema
	//EJ : typedef int JUAN, podemos hacer JUAN num1 = 0; ya que JUAN define un INT en este ej
	typedef struct
	{
		char nombre[LONG_NAME];
		int legajo;
		int isEmpty;
	}Alumno;

	int alumno_altaAlumno(Alumno* pArrayAlumno, int limite, int indice);
	int alumno_imprimirAlumnos(Alumno* pArrayAlumno, int limite);
	int alumno_initAlumnos(Alumno* pArrayAlumno, int limite);
	int alumno_modificarAlumno(Alumno* pArrayAlumno, int limite, int indice);
	int alumno_bajaAlumno(Alumno* pArrayAlumno, int limite, int indice);
	int alumno_sortAlumnoByName(Alumno* pArrayAlumno, int limite);
	int alumno_sortAlumnoByLegajo(Alumno* pArrayAlumno, int limite);


#endif /* ALUMNO_H_ */
