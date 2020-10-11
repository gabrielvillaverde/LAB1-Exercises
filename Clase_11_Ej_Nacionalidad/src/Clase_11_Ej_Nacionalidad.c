/*
 ============================================================================
 Name        : Clase_11_Ej_Nacionalidad.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include "utn.h"
#include "alumno.h"
#include "nacionalidad.h"

#define QTY_ALUMNOS 3
#define QTY_NACIONALIDADES 3


int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int indice;
	int indice2;
	int idBuscar;

	Alumno arrayAlumno[QTY_ALUMNOS];
	Nacionalidad arrayNacionalidades[QTY_NACIONALIDADES];
	if (alumno_init(arrayAlumno, QTY_ALUMNOS) == 0){
		do {
			 utn_getNumberInt("\n 1-Alta \n 2- Imprimir \n 3-Baja  \n  4-Modificar 5-Imprimir indice 6- buscarLibre 7- SALIR \n ", "serror",&opcion,1,15,2);
			 switch (opcion){
			 case 1:
				alumno_alta(arrayAlumno,QTY_ALUMNOS);
				 break;
			 case 2:
				alumno_imprimir(arrayAlumno,QTY_ALUMNOS);
				 break;
			 case 3:
				 alumno_baja(arrayAlumno,QTY_ALUMNOS);
				 break;
			 case 4:
				utn_getNumberInt ("Que ID desea buscar","ERRROR",&idBuscar,2,0,50);
				alumno_buscarIndice (arrayAlumno,QTY_ALUMNOS,idBuscar,&indice2);
				printf("%d",indice2);
				// alumno_modificar (arrayAlumno,SIZESTRUCT_ALUMNO);
				 break;
			 case 5:
				 utn_getNumberInt("Ingrese indice", "seerror",&indice,2,0,4);
				 alumno_imprimirIndice(arrayAlumno,QTY_ALUMNOS,indice);
				 break;
			 case 6:
				 indice = alumno_buscarLibre(arrayAlumno,QTY_ALUMNOS);
				if (indice != -1){
					printf("El indice libre es: %d", indice);
				} else {
					printf("No hay indices libres :( ");
				}
				break;
			 case 7:
				 alumno_ordenarPorNombre(arrayAlumno,QTY_ALUMNOS,1);
				 break;
			 // NUEVA ENTIDAD
			 case 8:
				 nacionalidad_alta(arrayNacionalidades, QTY_NACIONALIDADES);
				 break;
			 case 9:
				 nacionalidad_imprimir(arrayNacionalidades,QTY_NACIONALIDADES);
				 break;
			 case 10:
				 nacionalidad_baja(arrayNacionalidades, QTY_NACIONALIDADES);
				 break;
			 case 11:
			 	 break;
			 }
		 }while (opcion != 15);
	}
}
