/*
 * alumno.c
 *
 *  Created on: 22 sep. 2020
 *      Author: Hzkr
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"

// Función para dar de alta al alumno
// Recibe el array en modo disney
// El índice es el lugar donde quiero guardar los datos del alumno que quiero dar de alta.
int alumno_alta(Alumno arrayAlumnos[], int limite, int indice)
{
	int retorno = -1;
	Alumno bufferAlumno; // Creamos una variable auxiliar del tipo Alumno
	if(arrayAlumnos != NULL && limite > 0 && indice >= 0 && indice < limite)
	{
		// Le pasa el & a bufferAlumno.legajo porque legajo no es un ARRAY (el array no lleva &), es una variable dentro de una estructura.
		if (
			utn_getNumero(&bufferAlumno.legajo, "\nLegajo?","Error", MIN_LEGAJO, MAX_LEGAJO, 2) == 0
				&&
			utn_getNombre(bufferAlumno.nombre,"\nNombre?","\nError",2,LONG_NOMBRE) == 0
			// Acá podríamos seguir agregando otros campos si el ejercicio lo pidiera.
		   )
		{
			// Si se ingresó un legajo y un nombre, isEmpty ya no está vacío justamente, ya está ocupado.
			bufferAlumno.isEmpty = FALSE; // bufferAlumno[indice].isEmpty = FALSE; ES LO MISMO. Ya no está más vacío, tiene algo cargado.
			arrayAlumnos[indice] = bufferAlumno; // Una vez que está todo validado, copio lo de bufferAlumno a la posición índice de mi array.
			retorno = 0;
		}
	}
	return retorno;
}

// Función para imprimir los datos del alumno
// Recibe el array en modo profesional
// Recibe el límite
int alumno_imprimir(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		// Itera cada elemento.
		for(int i=0;i<limite;i++)
		{
			// Preguntar si esa línea que estoy por imprimir tiene sentido que la imprima.
			if(pArrayAlumnos[i].isEmpty == FALSE) // Quiere decir que tiene datos, que está LLENO. Entonces si está cargado...
			{
				// ...me imprime los valores.
				// Modo Disney de pArrayAlumnos
				printf("\nNombre: %s - Legajo: %d",pArrayAlumnos[i].nombre,pArrayAlumnos[i].legajo);
			}
		}
		retorno = 0;
	}
	return retorno;
}

// Tiene que ver con el isEmpty y además para que no salgan caracteres raros creo en la consola tipo basura cuando mostramos los resultados.
int alumno_initArray(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			// Recorrí todo el array, y a todos los isEmpty les pasé un valor verdadero.
			pArrayAlumnos[i].isEmpty = TRUE; // Verdadero, todo lo que es distinto a 0. Con 1 es que está vacío, con 0 es que está completo ese lugar.
		}
		retorno = 0;
	}
	return retorno;
}

int alumno_modificar(Alumno arrayAlumnos[],int limite, int indice)
{
	int retorno = -1;

	return retorno;
}
