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

// Funci�n para dar de alta al alumno
// Recibe el array en modo disney
// El �ndice es el lugar donde quiero guardar los datos del alumno que quiero dar de alta.
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
			// Ac� podr�amos seguir agregando otros campos si el ejercicio lo pidiera.
		   )
		{
			// Si se ingres� un legajo y un nombre, isEmpty ya no est� vac�o justamente, ya est� ocupado.
			bufferAlumno.isEmpty = FALSE; // bufferAlumno[indice].isEmpty = FALSE; ES LO MISMO. Ya no est� m�s vac�o, tiene algo cargado.
			arrayAlumnos[indice] = bufferAlumno; // Una vez que est� todo validado, copio lo de bufferAlumno a la posici�n �ndice de mi array.
			retorno = 0;
		}
	}
	return retorno;
}

// Funci�n para imprimir los datos del alumno
// Recibe el array en modo profesional
// Recibe el l�mite
int alumno_imprimir(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		// Itera cada elemento.
		for(int i=0;i<limite;i++)
		{
			// Preguntar si esa l�nea que estoy por imprimir tiene sentido que la imprima.
			if(pArrayAlumnos[i].isEmpty == FALSE) // Quiere decir que tiene datos, que est� LLENO. Entonces si est� cargado...
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

// Tiene que ver con el isEmpty y adem�s para que no salgan caracteres raros creo en la consola tipo basura cuando mostramos los resultados.
int alumno_initArray(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			// Recorr� todo el array, y a todos los isEmpty les pas� un valor verdadero.
			pArrayAlumnos[i].isEmpty = TRUE; // Verdadero, todo lo que es distinto a 0. Con 1 es que est� vac�o, con 0 es que est� completo ese lugar.
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
