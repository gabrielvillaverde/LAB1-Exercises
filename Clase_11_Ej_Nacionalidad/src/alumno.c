/*
 * alumno.c
 *
 *  Created on: 22 sep. 2020
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"

static int alumno_generarNuevoId (void);

int alumno_init(Alumno* pArray, int limite){
	int retorno = -1;
	if (pArray != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int alumno_alta (Alumno * pArray, int limite){
int retorno = -1;
int indice;

Alumno bufferAlumno;
	if (pArray != NULL && limite >0)
	{
		if (alumno_buscarLibreRef (pArray, limite, &indice) == 0)
		{
				if (utn_getNumberInt("\n Legajo?", "error",&bufferAlumno.legajo, 2,MIN_LEGAJO, MAX_LEGAJO) == 0 &&
					utn_getName(" \n Ingrese nombre","ERROR",bufferAlumno.nombre, 3,SIZE_NOMBRE) == 0)
				{
						pArray[indice] = bufferAlumno;
						pArray[indice].id = alumno_generarNuevoId();
						pArray[indice].isEmpty = FALSE;
				} else
					{
						printf("horror");
					}
			} else
			{
				printf(" \n No quedan espacios libres");
			}
		}
	return retorno ;
	}


int alumno_imprimir (Alumno * pArray , int limite) {
	int retorno = -1;
	if (pArray != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - Legajo: %d - ID %d",pArray[i].nombre,pArray[i].legajo , pArray[i].id);
			}
		}
		retorno = 0;
	}
return retorno;
}


int alumno_baja (Alumno * pArray, int limite){
	int retorno = -1;
	int buffer;
			if (pArray != NULL && limite>0){
			alumno_imprimir(pArray, limite);
			utn_getNumberInt("Ingrese legajo de alumno a borrar","Error", &buffer, 3,MIN_LEGAJO, MAX_LEGAJO);
			for (int i = 0 ; i<limite ;  i++){
				if (buffer == pArray[i].legajo){
					pArray[i].isEmpty = TRUE;
				}
			}
		}
	return retorno;
}
// ver de no perder el ID y usar las nuevas FN
int alumno_modificar (Alumno * pArray, int limite){
	int retorno = -1;
	char modificar[20];
	int buffer;
	Alumno bufferAlumno;
			if (pArray != NULL && limite>0){
			alumno_imprimir(pArray, limite);
			utn_getNumberInt("Ingrese ID de alumno a modificar","Error",&buffer,3,MIN_LEGAJO, MAX_LEGAJO);
			for (int i = 0 ; i<limite ;  i++){
				if (buffer == pArray[i].id){
				utn_getName("Que desea modificar? (nombre / legajo)", "error",modificar, 2, 20);
				if (strcmp(modificar, "legajo") == 0){
					if (utn_getNumberInt("\n Nuevo Legajo?", "error",&bufferAlumno.legajo, 2,MIN_LEGAJO, MAX_LEGAJO) == 0){
							pArray[i].legajo = bufferAlumno.legajo;
					} else {
						printf("horror");
					}
				}else {
					if (utn_getName(" \n Ingrese nuevo nombre","ERROR",bufferAlumno.nombre,3, SIZE_NOMBRE) == 0){
						strncpy(pArray[i].nombre,bufferAlumno.nombre,SIZE_NOMBRE);
				}else {
					printf("horror");
				}
				}
				}
			}
		}
	return retorno;
}

int alumno_imprimirIndice (Alumno * pArray, int limite, int indice){
	int retorno = -1;
		if (pArray != NULL && limite >0){

				if(pArray[indice].isEmpty == FALSE)
				{
					printf("\nNombre: %s - Legajo: %d",pArray[indice].nombre,pArray[indice].legajo);
				}

			retorno = 0;
		}
	return retorno;
}

int alumno_buscarLibre (Alumno * pArray, int limite){
	int retorno = -1;
	int i ;
		if (pArray != NULL && limite >0){
			for ( i = 0; i<limite; i++) {
				if(pArray[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int alumno_buscarLibreRef (Alumno * pArray, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArray != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArray[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}


static int alumno_generarNuevoId (void) {
	// El ID es inicializado en 0. ID es algo así como una variable global, que vive más allá de esta función. Lo que hace es que la primera vez que entre, la incremento en 1, ahora ID vale 1 y retorno 1.
	static int id = 0; // "Se ejecuta solo la primera vez (modo Disney)". La próxima vez que venga a esta función, esta línea de código ya no sirve, porque el ID vale 1.
	id = id+1;
	return id;
}

int alumno_buscarIndice (Alumno * pArray, int limite, int idBuscar,int * pIndice)
{
	int retorno = -1;
	int i ;
		if (pArray != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArray[i].id == idBuscar)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
				}
			}
			else
			{
				printf("errrror");
			}
		return retorno;
}

// Las funciones de ordenar reciben como mínimo el array y el límite, y se puede agregar otro parámetro que agrega el orden
int alumno_ordenarPorNombre (Alumno * pArray, int limite, int order)
{
	int retorno = -1;
	int flagSwap;
	Alumno bufferAlumno; // Variable auxiliar
	if (pArray != NULL && limite > 0 && (order == 0 || order == 1))
	{
		do
		{
			flagSwap = 0; // Solamente la pongo en 1 si tengo que swapear.
			// Se le pone limite -1 porque no puedo salirme del array, esto me hace comparar el anteúltimo con el último, y no el último con algo que está fuera del array.
			for(int i=0;i<limite-1;i++)
			{
				// Antes de la comparación de strncmp, tengo que preguntar si en ambos lugares hay algo cargado, porque ¿qué sentido tendría comparar lugares vacíos?
				// Si en la posición i hay algo cargado y en la posición i+1 también hay algo cargado...
				//if(pArray[i].isEmpty == FALSE && pArray[i+1].isEmpty == FALSE)
				//{ NO VA
					// ...Tengo que comparar el nombre del array en la posición i con el nombre del array en la siguiente posición de i
					if
					// Ascendente
					(strncmp(pArray[i].nombre,pArray[i+1].nombre,SIZE_NOMBRE) > 0 ||
					// Descendente
					(strncmp(pArray[i].nombre,pArray[i+1].nombre,SIZE_NOMBRE) == 0
							&& pArray[i].legajo > pArray[i+1].legajo))
					{	// Si entré acá, es porque tengo que hacer un swap.
						bufferAlumno = pArray[i]; // Guardo en buffer el valor de i
						pArray[i] = pArray[i+1]; // En este momento tienen el mismo valor i e i+1
						pArray[i+1] = bufferAlumno; // Copio lo que guardé en el buffer auxiliar
						flagSwap = 1; // Tengo que poner la bandera en TRUE para seguir iterando.
					}
				//}
			}
		}while(flagSwap); // Mientras que la bandera esté en 1 (o sea, mientras me diga que tengo que seguir swapeando)
	}
	return retorno;
}

// Crear .c y .h, robamos todo el alumno.c y .h y lo vamos tuneando para que se adapte a nuestra nueva entidad
