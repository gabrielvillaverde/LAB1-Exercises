/*
 * nacionalidad.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "nacionalidad.h"

#define TRUE 1
#define FALSE 0
#define SIZE_NOMBRE 50
#define SIZE_LASTNAME 50
#define QTY_ALUMNOS 1000
#define MIN_LEGAJO 0
#define MAX_LEGAJO 50

static int nacionalidad_generarNuevoId (void);

int nacionalidad_init(Nacionalidad* pArray, int limite)
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

int nacionalidad_alta(Nacionalidad* pArray, int limite, int indice)
{
	int retorno = -1;
	Nacionalidad bufferNacionalidad;
	if(pArray != NULL && limite > 0 && indice >= 0 && indice < limite && pArray[indice].isEmpty == TRUE)
	{
		if((utn_getName("Nombre:\n","Error\n",bufferNacionalidad.nombre,2,SIZE_NOMBRE)==0 &&
			utn_getNumberInt("Legajo:\n", "Error\n", &bufferNacionalidad.legajo, 2, MIN_LEGAJO, MAX_LEGAJO)==0))
		{
			bufferNacionalidad.id = nacionalidad_generarNuevoId();
			bufferNacionalidad.isEmpty = FALSE;
			pArray[indice] = bufferNacionalidad;
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

int nacionalidad_baja(Nacionalidad* pArray, int limite, int indice)
{
	int retorno = -1;
	if(pArray != NULL && indice < limite && limite > 0 && pArray[indice].isEmpty == FALSE)
	{
		pArray[indice].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}

int nacionalidad_baja2(Nacionalidad* pArray, int limite)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;
	if(pArray != NULL && limite > 0)
	{
		nacionalidad_imprimir(pArray, limite);
		if(utn_getNumberInt("Ingrese ID del país a borrar\n", "Error", &idABorrar, 3, 0, 9999)==0)
		{
			// Busco la posición a borrar
			if(nacionalidad_buscarIndicePorId(pArray, limite, idABorrar, &indiceABorrar)==0)
			{	// Borro la posición elegida
				pArray[indiceABorrar].isEmpty = TRUE;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int nacionalidad_modificar(Nacionalidad* pArray, int limite, int indice)
{
	int retorno = -1;
	Nacionalidad bufferNacionalidad;
	if(pArray != NULL && limite > 0 && indice < limite && pArray[indice].isEmpty == 0)
	{
		if(	(utn_getName("Nombre: \n", "Error\n", bufferNacionalidad.nombre, 2, SIZE_NOMBRE)==0) &&
			(utn_getNumberInt("Legajo: \n", "Error\n", &bufferNacionalidad.legajo, 2, MIN_LEGAJO, MAX_LEGAJO)==0))
		{
			bufferNacionalidad.id = pArray[indice].id;
			pArray[indice] = bufferNacionalidad;
			bufferNacionalidad.isEmpty = FALSE;
			retorno = 0;
		}
	}
	else
	{
		printf("No hay ningun valor para modificar\n");
	}
	return retorno;
}

int nacionalidad_modificar2(Nacionalidad* pArray, int limite, int indice)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;

	Nacionalidad bufferNacionalidad;

	if(pArray != NULL && limite > 0)
	{
		nacionalidad_imprimir(pArray, SIZE_NOMBRE);
		if(utn_getNumberInt("ID del país a modificar: \n", "Error\n", &idBuscar, 2, 0, 9999)==0)
		{
			if(nacionalidad_buscarIndicePorId(pArray, limite, idBuscar, &indiceAModificar)==0)
			{
				if(	(utn_getName("País: \n", "Error\n", bufferNacionalidad.nombre, 2, SIZE_NOMBRE)==0) &&
					(utn_getNumberInt("Legajo: \n", "Error\n", &bufferNacionalidad.legajo, 2, MIN_LEGAJO, MAX_LEGAJO)==0))
				{
					bufferNacionalidad.id = pArray[indice].id;
					pArray[indice] = bufferNacionalidad;
					bufferNacionalidad.isEmpty = FALSE;
					retorno = 0;
				}
			}
		}
	}
	else
	{
		printf("No hay ningun valor para modificar\n");
	}
	return retorno;
}

int nacionalidad_imprimir(Nacionalidad* pArray , int limite)
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

int nacionalidad_imprimirPorId (Nacionalidad * pArray, int limite, int indice)
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

int nacionalidad_imprimirIndice (Nacionalidad * pArrayNacionalidads, int limite, int indice)
{
	int retorno = -1;
	if (pArrayNacionalidads != NULL && limite >0)
	{
		if(pArrayNacionalidads[indice].isEmpty == FALSE)
		{
			printf("\nNombre: %s - Legajo: %d",pArrayNacionalidads[indice].nombre,pArrayNacionalidads[indice].legajo);
		}
		retorno = 0;
	}
	return retorno;
}

int nacionalidad_buscarLibre (Nacionalidad * pArray, int limite){
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

int nacionalidad_buscarLibreRef (Nacionalidad * pArray, int limite, int * pIndice){
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

static int nacionalidad_generarNuevoId (void)
{
	// El ID es inicializado en 0. ID es algo así como una variable global, que vive más allá de esta función. Lo que hace es que la primera vez que entre, la incremento en 1, ahora ID vale 1 y retorno 1.
	static int id = 0; // "Se ejecuta solo la primera vez (modo Disney)". La próxima vez que venga a esta función, esta línea de código ya no sirve, porque el ID vale 1.
	id = id+1;
	return id;
}

int nacionalidad_buscarIndicePorId (Nacionalidad * pArray, int limite, int idBuscar, int * pIndice)
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
				printf("Error");
			}
		return retorno;
}

int nacionalidad_buscarId(Nacionalidad* pArray, int limite, int *pIndice, int id)
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

// Las funciones de ordenar reciben como mínimo el array y el límite, y se puede agregar otro parámetro que agrega el orden
int nacionalidad_ordenarPorNombre (Nacionalidad * pArray, int limite, int order)
{
	int retorno = -1;
	int flagSwap;
	Nacionalidad bufferNacionalidad; // Variable auxiliar
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
						bufferNacionalidad = pArray[i]; // Guardo en buffer el valor de i
						pArray[i] = pArray[i+1]; // En este momento tienen el mismo valor i e i+1
						pArray[i+1] = bufferNacionalidad; // Copio lo que guardé en el buffer auxiliar
						flagSwap = 1; // Tengo que poner la bandera en TRUE para seguir iterando.
					}
				//}
			}
		}while(flagSwap); // Mientras que la bandera esté en 1 (o sea, mientras me diga que tengo que seguir swapeando)
	}
	return retorno;
}

int nacionalidad_ordenarPorNombre2 (Nacionalidad * pArray, int limite, int order)
{
	int retorno = -1;
	int flagSwap;
	Nacionalidad bufferNacionalidad; // Variable auxiliar
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
				(order == 1 && strcmp (pArray[i].nombre, pArray[i + 1].nombre) > 0) ||
				(0==strcmp (pArray[i].nombre, pArray[i + 1].nombre) &&
				 (((pArray[i].legajo > pArray[i + 1].legajo)&&(order == 1))
				 ||((pArray[i].legajo < pArray[i + 1].legajo) &&(order == 0)))))
				{
					bufferNacionalidad = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i + 1] = bufferNacionalidad;
					flagSwap = 1;
					retorno = 0;
				}
			}
		}while(flagSwap); // Mientras que la bandera esté en 1 (o sea, mientras me diga que tengo que seguir swapeando)
	}
	return retorno;
}

int nac_init(Nac * pArrays, int limite){
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrays[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}


int nac_alta (Nac * pArrays, int limite)
{
	int retorno = -1;
	int indice;

	Nac bufferNac;
	if (pArrays != NULL && limite >0)
	{
		if (nac_buscarLibreRef (pArrays, limite, &indice) == 0)
		{
				if (utn_getName("\n pais?", "error", bufferNac.pais,LONG ,2) == 0 &&
					utn_getName(" \n Ingrese nombre","ERROR",bufferNac.nombre, LONG, 3) == 0)
				{
						pArrays[indice] = bufferNac;
						pArrays[indice].id = nacionalidad_generarNuevoId();
						pArrays[indice].isEmpty = FALSE;
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


int nac_imprimir (Nac * pArrays , int limite) {
	int retorno = -1;
	if (pArrays != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - pais: %s - ID %d",pArrays[i].nombre,pArrays[i].pais , pArrays[i].id);
			}
		}
		retorno = 0;
	}
return retorno;
}

int nac_baja (Nac * pArrays, int limite){
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArrays != NULL && limite>0)
	{
		nac_imprimir(pArrays, limite);
		if(utn_getNumberInt("Ingrese pais de nac a borrar","Error",&idABorrar,3,0,9999)==0)
		{
			// busco la posicion a borrar
			if(nac_buscarIndicePorId(pArrays,limite,idABorrar,&indiceABorrar)==0)
			{
				// borro esa posicion
				pArrays[indiceABorrar].isEmpty=TRUE;
			}
		}
	}
	return retorno;
}

// ver de no perder el ID y usar las nuevas FN
int nac_modificar (Nac * pArrays, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	Nac bufferNac;

	if (pArrays != NULL && limite>0)
	{
		nac_imprimir(pArrays, limite);

		if(utn_getNumberInt("ID:","ERROR!",&idBuscar,3,0,9999)==0)
		{
			if(nac_buscarIndicePorId(pArrays, limite,idBuscar,&indiceAModificar)==0)
			{
				bufferNac = pArrays[indiceAModificar]; // IMPORTANTE!

				if (utn_getName("\n Nuevo pais?", "error",bufferNac.pais, 2 ,LONG) == 0)
				{
					if (utn_getName(" \n Ingrese nuevo nombre","ERROR",bufferNac.nombre, 2, LONG) == 0)
					{
						pArrays[indiceAModificar] = bufferNac; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}


int nac_buscarLibre (Nac * pArrays, int limite){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0){
			for ( i = 0; i<limite; i++) {
				if(pArrays[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int nac_buscarLibreRef (Nac * pArrays, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArrays[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}

/*
static int nac_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}
*/

int nac_buscarIndicePorId (Nac * pArrays, int limite,
		               int idBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrays[i].id == idBuscar)
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

int nac_ordenarPorNombre (Nac * pArrays, int limite , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Nac aux;
	if (pArrays != NULL && limite >0){
	while(estadoDesordenado)//mientras este desordenado
	{
		estadoDesordenado = 0;
		for(int i = 0; i < (limite - 1); i++)
		{
			if((orden == 1 && strncmp(pArrays[i].nombre, pArrays[i + 1].nombre,LONG)>0)
					||
			  (orden == 0 && strncmp(pArrays[i].nombre, pArrays[i + 1].nombre,LONG)<0))
			{
				aux = pArrays[i];
				pArrays[i] = pArrays[i + 1];
				pArrays[i + 1] = aux;
				estadoDesordenado = 1;
			}
		}
	}
	retorno = 0;


	}
	return retorno;
}
