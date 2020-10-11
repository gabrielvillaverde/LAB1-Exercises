/*
 * template.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "template.h"
#include "utn.h"

static int template_generarNuevoId (void); // Prototipo

static int template_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int template_init(Tem * pArray, int limite){
	int retorno = -1;
	if (pArray != NULL && limite >0)
	{
		for (int i = 0; i<limite; i++ )
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

int template_alta (Tem * pArray, int limite)
{
	int retorno = -1;
	int indice;

	Tem bufferTem;
	if (pArray != NULL && limite >0)
	{
		if (template_buscarLibreRef (pArray, limite, &indice) == 0)
		{
				if (utn_getName("\n pais?","error",bufferTem.pais,3,LONG) == 0 &&
					utn_getName("\n Ingrese nombre","ERROR",bufferTem.nombre, 3, LONG) == 0)
				{
						pArray[indice] = bufferTem;
						pArray[indice].id = template_generarNuevoId();
						pArray[indice].isEmpty = FALSE;
				} else
					{
						printf("Horror");
					}
			} else
			{
				printf(" \n No quedan espacios libres");
			}
		}
		return retorno ;
}

int template_baja (Tem * pArray, int limite){
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArray != NULL && limite>0)
	{
		template_imprimir(pArray, limite);
		if(utn_getNumberInt("Ingrese ID de template a borrar","Error",&idABorrar,3,0,9999)==0)
		{
			// busco la posicion a borrar
			if(template_buscarIndicePorId(pArray,limite,idABorrar,&indiceABorrar)==0)
			{
				// borro esa posicion
				pArray[indiceABorrar].isEmpty=TRUE;
			}
		}
	}
	return retorno;
}

int template_modificar (Tem * pArray, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;

	Tem bufferTem;
	if (pArray != NULL && limite>0)
	{
		template_imprimir(pArray, limite);

		if(utn_getNumberInt("ID:","ERROR!",&idBuscar,2,0,9999)==0)
		{
			if(template_buscarIndicePorId(pArray, limite,idBuscar,&indiceAModificar)==0)
			{
				bufferTem = pArray[indiceAModificar]; // IMPORTANTE!

				if (utn_getName("\n Nuevo pais?", "error",bufferTem.pais,2,LONG) == 0)
				{
					if (utn_getName(" \n Ingrese nuevo nombre","ERROR",bufferTem.nombre, 2,LONG) == 0)
					{
						pArray[indiceAModificar] = bufferTem; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}

int template_imprimir (Tem * pArray , int limite) {
	int retorno = -1;
	if (pArray != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - pais: %s - ID %d",pArray[i].nombre,pArray[i].pais , pArray[i].id);
			}
		}
		retorno = 0;
	}
return retorno;
}

int template_buscarLibre (Tem * pArray, int limite){
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

int template_buscarLibreRef (Tem * pArray, int limite, int * pIndice){
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

int template_buscarIndicePorId (Tem * pArray, int limite, int idBuscar, int * pIndice)
{
	int retorno = -1;
	int i ;
	if (pArray != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
	{
			for ( i = 0; i<limite; i++)
			{
				if(pArray[i].isEmpty == FALSE && pArray[i].id == idBuscar)
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

int template_ordenarPorNombre (Tem * pArray, int limite , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Tem aux;
	if (pArray != NULL && limite >0){
	while(estadoDesordenado)//mientras este desordenado
	{
		estadoDesordenado = 0;
		for(int i = 0; i < (limite - 1); i++)
		{
			if((orden == 1 && strncmp(pArray[i].nombre, pArray[i + 1].nombre,LONG)>0)
					||
			  (orden == 0 && strncmp(pArray[i].nombre, pArray[i + 1].nombre,LONG)<0))
			{
				aux = pArray[i];
				pArray[i] = pArray[i + 1];
				pArray[i + 1] = aux;
				estadoDesordenado = 1;
			}
		}
	}
	retorno = 0;
	}
return retorno;
}
