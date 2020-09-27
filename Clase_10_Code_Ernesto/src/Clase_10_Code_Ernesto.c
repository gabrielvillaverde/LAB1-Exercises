/*
 ============================================================================
 Name        : Clase_10_Code_Ernesto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"
#include "alumno.h"

int main(void)
{
	setbuf(stdout,NULL);

	int op;
	int indiceVacio;
	int idModificar;
	int indice;
	Alumno arrayAlumnos[QTY_ALUMNOS];

	alumno_initArray(arrayAlumnos,QTY_ALUMNOS);
	do
	{
		utn_getInt("\n1-Alta\n2-Modificar\n5-Mostrar\n6-Salir","\nError",&op,2,6,1);
		switch(op)
		{
			case 1:
				if(alumno_buscarLibreRef(arrayAlumnos, QTY_ALUMNOS, &indiceVacio)==0)
				{
					alumno_alta(arrayAlumnos, QTY_ALUMNOS, indiceVacio);

				}
				break;
			case 2:
				// MODIFICAR POR ID
				if(utn_getInt("Ingrese el ID a modificar:","e!",&idModificar,5,1000,1)==0)
				{
					printf("\nVas a modificar el ID: %d",idModificar);
					if(alumno_buscarId(arrayAlumnos, QTY_ALUMNOS, &indice, idModificar)==0)
					{
						alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice);
					}
				}
				break;
			case 3:
				// alumno_baja(arrayAlumnos,QTY_ALUMNOS,indice);
				break;
			case 4:
				// alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 5:
				alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
				break;

		}
	}while(op != 6);
	return EXIT_SUCCESS;
}
