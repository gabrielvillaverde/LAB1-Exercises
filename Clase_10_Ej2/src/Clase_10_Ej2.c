/******************************************************************************
Continuación del ejercicio de la clase pasada (Clase 9)

Ejercicio 7, clase 10.
Realizar un programa con un menú de dos opciones:
A) Alta de alumno, no pedir índice.
B) Imprimir lista de alumnos.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#include "alumno.h"

#define MAX_LEGAJOS 1000
#define MIN_LEGAJOS 1
#define QTY_ALUMNOS 5
#define LONG_NAME 50


int main(void) {
	setbuf(stdout,NULL);
	int opcionIngresada;
	int indiceVacio;
	Alumno arrayAlumnos[QTY_ALUMNOS];

	alumno_initAlumnos(arrayAlumnos,QTY_ALUMNOS);
	do{
		if(utn_getNumberInt("Elija una opcion:\n1- Alta de alumnos\n2- Modificar un registro\n3- Salir del programa",
			"Error. Ingrese una opción valida",&opcionIngresada,3,1,2)==0)
		{
			switch(opcionIngresada)
			{
				case 1:
						if(alumno_buscarLibreRef(arrayAlumnos, QTY_ALUMNOS, &indiceVacio)==0)
						{
							alumno_altaAlumno(arrayAlumnos, QTY_ALUMNOS, indiceVacio);
						}
				break;
				case 2:
					alumno_imprimirAlumnos(arrayAlumnos, QTY_ALUMNOS);
				break;
			}
		}

	}while(opcionIngresada!=3);
return EXIT_SUCCESS;
}
