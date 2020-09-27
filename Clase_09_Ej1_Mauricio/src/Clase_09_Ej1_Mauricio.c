/******************************************************************************
Pedirle al usuario los datos de 3 alumnos e imprimir esos datos por pantalla

Dar de alta alumnos

Dos funciones separadas:

Función de cargar
Función de imprimir

getNombre para obtener nombre
getNumero para obtener número

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"

// Función main
int main(void){
	setbuf(stdout,NULL);
	int opcion;
	int indice;
	Alumno arrayAlumnos[CANTIDAD_ALUMNOS]; // Declaro un array de Alumnos del tipo Alumno (cada elemento va a tener un nombre y un legajo)

	// Llamamos a esta función.
	alumno_initArray(arrayAlumnos,CANTIDAD_ALUMNOS);
	do{
		utn_getNumero(&opcion, "\n1 - Alta\n2 - Mostrar\n10 - Salir","Error", 1, 3, 2);
		switch(opcion)
		{
		case 1:
			if(utn_getNumero(&indice, "\nIndice?","Error", 0, CANTIDAD_ALUMNOS-1, 2)==0)
			// alumno_buscarLibre(arrayAlumnos,CANTIDAD_ALUMNOS)
			{
				alumno_alta(arrayAlumnos,CANTIDAD_ALUMNOS,indice);
			}
			break;
		case 2:
			alumno_imprimir(arrayAlumnos,CANTIDAD_ALUMNOS);
			break;
		}
	}while(opcion != 10);
	return EXIT_SUCCESS;
}
