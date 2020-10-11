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

#define TRUE 1
#define FALSE 0
#define SIZE_NOMBRE 50
#define SIZE_LASTNAME 50
#define QTY_ALUMNOS 1000
#define MIN_LEGAJO 0
#define MAX_LEGAJO 50

static int alumno_generarNuevoId (void);

int alumno_init(Alumno* pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite >0)
	{
		for(int i = 0; i<limite; i++)
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
return retorno;
}

int alumno_alta(Alumno* pArray, int limite, int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(pArray != NULL && limite > 0 && indice >= 0 && indice < limite && pArray[indice].isEmpty == TRUE)
	{
		if((utn_getName("Nombre:\n","Error\n",&bufferAlumno.nombre,2,SIZE_NOMBRE)==0 &&
			utn_getNumberInt("Legajo:\n", "Error\n", &bufferAlumno.legajo, 2, MIN_LEGAJO, MAX_LEGAJO)==0))
		{
			bufferAlumno.id = alumno_generarNuevoId();
			bufferAlumno.isEmpty = FALSE;
			pArray[indice] = bufferAlumno;
			retorno = 0;
		}
	}
	else
	{
		if(pArray[indice].isEmpty == FALSE)
		{
			printf("Error, esta posición ya está cargada.\n");
		}
	}
return retorno;
}

int alumno_imprimir(Alumno* pArray , int limite)
{
	int retorno = -1;
	if (pArray != NULL && limite > 0)
	{
		for (int i = 0 ; i < limite ; i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				printf("Índice: %d - Nombre: %s - Legajo: %d - ID: %d\n",i,pArray[i].nombre,pArray[i].legajo,pArray[i].id);
			}
		}
	retorno = 0;
	}
return retorno;
}

int alumno_imprimirPorId (Alumno * pArray, int limite, int indice)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0 && indice < limite)
	{
			if(pArray[indice].isEmpty == FALSE)
			{
				printf("Índice: %d - Nombre: %s - Legajo: %d - ID: %d\n",indice,pArray[indice].nombre,pArray[indice].legajo,pArray[indice].id);
			}
		retorno = 0;
	}
	return retorno;
}

int alumno_imprimirIndice (Alumno * pArrayAlumnos, int limite, int indice)
{
	int retorno = -1;
	if (pArrayAlumnos != NULL && limite >0)
	{
		if(pArrayAlumnos[indice].isEmpty == FALSE)
		{
			printf("\nNombre: %s - Legajo: %d",pArrayAlumnos[indice].nombre,pArrayAlumnos[indice].legajo);
		}
		retorno = 0;
	}
	return retorno;
}

int alumno_baja(Alumno* pArray, int limite, int indice)
{
	int retorno = -1;
	if(pArray != NULL && indice < limite && limite > 0 && pArray[indice].isEmpty == FALSE)
	{
		pArray[indice].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}

int alumno_modificar(Alumno* pArray, int limite, int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(pArray != NULL && limite > 0 && indice < limite && pArray[indice].isEmpty == 0)
	{
		if(	(utn_getName("Nombre: \n", "Error\n", bufferAlumno.nombre, 2, SIZE_NOMBRE)==0) &&
			(utn_getNumberInt("Legajo: \n", "Error\n", &bufferAlumno.legajo, 2, MIN_LEGAJO, MAX_LEGAJO)==0))
		{
			bufferAlumno.id = pArray[indice].id;
			pArray[indice] = bufferAlumno;
			bufferAlumno.isEmpty = FALSE;
			retorno = 0;
		}
	}
	else
	{
		printf("No hay ningun valor para modificar\n");
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

static int alumno_generarNuevoId (void)
{
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
					(
					// Ascendente
					 strncmp(pArray[i].nombre,pArray[i+1].nombre,SIZE_NOMBRE) > 0 ||
					 strncmp(pArray[i].nombre,pArray[i+1].nombre,SIZE_NOMBRE) < 0 ||
					// Descendente
					(strncmp(pArray[i].nombre,pArray[i+1].nombre,SIZE_NOMBRE) == 0 &&
							 pArray[i].legajo > pArray[i+1].legajo)
					)
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

int alumno_ordenarPorNombreEdgardo (Alumno * pArray, int limite, int order)
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
				if
				((order == 0 && strcmp (pArray[i].nombre, pArray[i + 1].nombre) < 0)||
				(order == 1 && strcmp (pArray[i].nombre, pArray[i + 1].legajo) > 0) ||
				(0==strcmp (pArray[i].nombre, pArray[i + 1].nombre) &&
				 (((pArray[i].legajo > pArray[i + 1].legajo)&&(order == 1))
				 ||((pArray[i].legajo < pArray[i + 1].legajo) &&(order == 0)))))
				{
					bufferAlumno = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i + 1] = bufferAlumno;
					flagSwap = 1;
					retorno = 0;
				}
			}
		}while(flagSwap); // Mientras que la bandera esté en 1 (o sea, mientras me diga que tengo que seguir swapeando)
	}
	return retorno;
}

int alumno_buscarId(Alumno* pArray, int limite, int *pIndice, int id)
{
	int retorno = -1;
	if(pArray != NULL && pIndice != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			// Si hay datos válidos adentro, o sea isEmpty FALSE.. && si el campo ID de ese elemento es igual al que vino como argumento en la función, encontré el ID que yo quería.
			if(pArray[i].isEmpty == FALSE && pArray[i].id == id)
			{
				*pIndice = i; // En la dirección de memoria que tiene pIndice escribo el valor de i.
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
