/******************************************************************************
Clase 11
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"

#define QTY_ALUMNOS 50
#define MIN_LEGAJO 0
#define MAX_LEGAJO 50


int main(void)
{
	setbuf(stdout,NULL);

	int contadorAlumnos = 0;
	int opcion;
	int idBuscado;
	int indiceLibre;
	int indice;

	Alumno arrayAlumno[QTY_ALUMNOS];
	alumno_init(arrayAlumno, QTY_ALUMNOS);

	do
	{
		if(utn_getNumberInt("Bienvenido al sistema, elija una opción: \n\n1 - Dar de alta\n2 - Imprimir\n3 - Dar de baja\n4 - Modificar\n5 - Imprimir índice\n6 - Buscar libre\n7 - Imprimir ordenados [UP-DOWN]\n8 - Salir","\nError. Seleccione una opción valida\n",&opcion,2,1,8)==0)
		{
			switch(opcion)
			{
			case 1:
				if(alumno_buscarLibreRef(arrayAlumno, QTY_ALUMNOS, &indiceLibre)==0)
				{
					alumno_alta(arrayAlumno,QTY_ALUMNOS,indiceLibre);
					contadorAlumnos++;
				}
				break;
			case 2:
				alumno_imprimir(arrayAlumno,QTY_ALUMNOS);
				break;
			case 3:
				if(utn_getNumberInt("Ingrese el ID que desea eliminar","Error",&idBuscado,2,0,50)==0)
				{
					alumno_buscarId(arrayAlumno, QTY_ALUMNOS, &indice, idBuscado);
					alumno_baja(arrayAlumno, QTY_ALUMNOS,indice);
					contadorAlumnos--;
				}
				break;
			case 4:
				if(utn_getNumberInt("Ingrese el ID que desea modificar","Error",&idBuscado,2,0,50)==0)
				{
					alumno_buscarId(arrayAlumno, QTY_ALUMNOS, &indice, idBuscado);
					alumno_modificar(arrayAlumno,QTY_ALUMNOS,indice);
				}
				break;
			case 5:
				if(utn_getNumberInt("Ingrese el índice que desea imprimir:\n", "Error\n",&indice,2,0,50)==0)
				{
					alumno_imprimirIndice(arrayAlumno,QTY_ALUMNOS,indice);
				}
				break;
			case 6:
				if(alumno_buscarLibreRef(arrayAlumno, QTY_ALUMNOS, &indiceLibre)==0)
				{
					printf("El índice libre es: %d\n", indiceLibre);
				}
				else
				{
					printf("No hay índices libres");
				}
				break;
			case 7:
				printf("Orden descendente\n");
				alumno_ordenarPorNombreEdgardo(arrayAlumno, QTY_ALUMNOS, 0);
				alumno_imprimir(arrayAlumno, QTY_ALUMNOS);
				printf("Orden ascendente\n");
				alumno_ordenarPorNombreEdgardo(arrayAlumno, QTY_ALUMNOS, -1); // -1 crashea, y con 1 ordena descendente también
				alumno_imprimir(arrayAlumno, QTY_ALUMNOS);
				break;
			}
		}

	}while(opcion != 8);
return EXIT_SUCCESS;
}
