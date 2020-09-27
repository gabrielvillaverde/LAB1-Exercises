/******************************************************************************
Continuación del ejercicio de la clase pasada (Clase 9)

5)Realizar una funcion que reciba el array y un indice,
e imprima los datos del item de esa posicion, si es que tiene datos validos.

6) Ejercicio 6 resuelto en el alumno.c
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

	int op;
	int indice=0;
	int flagCase1 = 1;

	Alumno arrayAlumnos[QTY_ALUMNOS];

	alumno_initAlumnos(arrayAlumnos, QTY_ALUMNOS);
	do
	{
		utn_getNumberInt("Ingrese una opción\n1 - Alta de alumno\n2 - Modificar alumno\n3 - Baja de alumno\n4 - Ordenar por nombre\n5 - Ordenar por legajo de menor a mayor\n6 - Imprimir alumnos\n7 - Salir\n", "ERROR, ingrese una opción válida\n", &op, 3, 1, 7);
		switch(op)
		{
		case 1:
			if(indice<QTY_ALUMNOS)
			{
				do
				{
					if(arrayAlumnos[indice].isEmpty == 1)
					{
						//RECIBE EL INDICE INICIALIZADO EN 0 Y SE VA SUMMANDO CON EL ++ DE ABAJO LO QUE HACE QUE
						//LA PROXIMA SEA UN INDICE ADELANTE
						alumno_altaAlumno(arrayAlumnos, QTY_ALUMNOS, indice);
						flagCase1 = 0;
					}
					else
					{
						indice++;
					}
				}while(flagCase1);
			}
			else
			{
				printf("No hay mas espacios para cargar\n");
			}
			break;
		case 2:
			if(utn_getNumberInt("Que indice desea modificar? \n", "ERROR indice inválido (0 - 4)\n", &indice, 3, 0, QTY_ALUMNOS-1 )==0)
			{
				alumno_modificarAlumno(arrayAlumnos, QTY_ALUMNOS, indice);
			}
			break;
		case 3:
			if(utn_getNumberInt("Ingrese el indice que desea dar de baja\n", "ERROR indice inválido\n", &indice, 3, 0, QTY_ALUMNOS-1)==0)
			{
				alumno_bajaAlumno(arrayAlumnos, QTY_ALUMNOS, indice);
			}
			indice--;
			break;
		case 4:
			//ORDENAR POR NOMBRE ORDEN DE A - Z
			alumno_sortAlumnoByName(arrayAlumnos, QTY_ALUMNOS);
			break;
		case 5:
			//ORDENAR POR LEGAJO DE MENOR A MAYOR
			alumno_sortAlumnoByLegajo(arrayAlumnos, QTY_ALUMNOS);
			break;
		case 6:
			alumno_imprimirAlumnos(arrayAlumnos, QTY_ALUMNOS);
			break;
		}
	}while(op != 7);

	return EXIT_SUCCESS;
}


