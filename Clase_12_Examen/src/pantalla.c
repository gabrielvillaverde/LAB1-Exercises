/*
 * pantalla.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

static int pantalla_generarNuevoId (void); // Prototipo

static int pantalla_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int pantalla_init(Pantalla * pArray, int limite){
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

int pantalla_alta (Pantalla * pArray, int limite)
{
	int retorno = -1;
	int indice;

	Pantalla bufferPantalla;
	if (pArray != NULL && limite >0)
	{
		if (pantalla_buscarLibreRef (pArray, limite, &indice) == 0)
		{
				// Faltan agregar más cosas que pedirle al usuario
				if (utn_getName("\nIngrese la pantalla:\n","Error, pantalla inválida",bufferPantalla.nombre,2,LONG) == 0 &&
					utn_getName("\n Ingrese nombre","ERROR",bufferPantalla.nombre, 3, LONG) == 0)
				{
					pArray[indice] = bufferPantalla;
					pArray[indice].idPantalla = pantalla_generarNuevoId();
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

int pantalla_baja (Pantalla * pArray, int limite){
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArray != NULL && limite>0)
	{
		pantalla_imprimir(pArray, limite);
		if(utn_getNumberInt("Ingrese ID de pantalla a borrar","Error",&idABorrar,3,0,9999)==0)
		{
			// busco la posicion a borrar
			if(pantalla_buscarIndicePorId(pArray,limite,idABorrar,&indiceABorrar)==0)
			{
				// borro esa posicion
				pArray[indiceABorrar].isEmpty=TRUE;
			}
		}
	}
	return retorno;
}

int pantalla_modificar (Pantalla * pArray, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;

	Pantalla bufferPantalla;
	if (pArray != NULL && limite>0)
	{
		pantalla_imprimir(pArray, limite);

		if(utn_getNumberInt("ID:","ERROR!",&idBuscar,2,0,9999)==0)
		{
			if(pantalla_buscarIndicePorId(pArray, limite,idBuscar,&indiceAModificar)==0)
			{
				bufferPantalla = pArray[indiceAModificar]; // IMPORTANTE!

				if (utn_getName("\n Ingrese nuevo nombre", "error",bufferPantalla.nombre,2,LONG) == 0)
				{
					if (utn_getName(" \n Ingrese nueva dirección","ERROR",bufferPantalla.direccion, 2,LONG) == 0)
					{
						pArray[indiceAModificar] = bufferPantalla; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}

int pantalla_imprimir (Pantalla * pArray , int limite) {
	int retorno = -1;
	char strTipo[8]; // Le doy un valor chico porque las palabras que quiero son LED y LCD.
	if (pArray != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				// evaluo el numero y cargo en strTipo = LCD o LED
				if(pArray[i].tipo == PANTALLA_TIPO_LCD)
				{
					// strcpy es otra opción válida.
					sprintf(strTipo,"LCD"); // Cargo la cadena strTipo con LCD
				}
				else
					sprintf(strTipo,"LED"); // Cargo la cadena strTipo con LED
				printf("\nNombre: %s - Dirección: %s - ID: %d - Tipo: %s\n",pArray[i].nombre,pArray[i].direccion, pArray[i].idPantalla,strTipo);
			}
		}
		retorno = 0;
	}
return retorno;
}

int pantalla_buscarLibre (Pantalla * pArray, int limite){
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

int pantalla_buscarLibreRef (Pantalla * pArray, int limite, int * pIndice){
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

int pantalla_buscarIndicePorId (Pantalla * pArray, int limite, int idBuscar, int * pIndice)
{
	int retorno = -1;
	int i ;
	if (pArray != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
	{
			for ( i = 0; i<limite; i++)
			{
				if(pArray[i].isEmpty == FALSE && pArray[i].idPantalla == idBuscar)
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

int pantalla_ordenarPorNombre (Pantalla * pArray, int limite , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Pantalla aux;
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
