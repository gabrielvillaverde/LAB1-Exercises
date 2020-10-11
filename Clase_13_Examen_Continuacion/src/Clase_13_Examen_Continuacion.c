/*
 ============================================================================
EXAMEN DE PRUEBA
Hay dos tipos de reproductores:
1. Pantallas LCD
2. Pantallas LED

1° Definir palabras claves: pantalla, contratación, publicidad, dirección, cliente,
tipo de pantalla, ID de pantalla, nombre de pantalla, precio de publicidad, cantidad de dias,
nombre del archivo, CUIT del cliente.

2° Identificar entidades y campos

Primera entidad encontrada: PANTALLA
Campos de la entidad pantalla: ID, isEmpty, nombre, tipo, precio de publicidad en la pantalla por día, dirección

Segunda entidad encontrada: CLIENTE (NO VA)
Campos de la entidad cliente: ID de cliente, isEmpty, CUIT (NO VA)

Tercera entidad encontrada: CONTRATACION
Campos de la entidad contratación: ID, isEmpty, nombre del archivo, cantidad de días, CUIT de cliente, ID de pantalla

3° Agregar a cada entidad un isEmpty y un ID

4° Ver cómo se relacionan las entidades
En la entidad contratación, debo referenciar al cliente y a la pantalla, por eso me guardo sus IDs (CUIT en el caso del cliente)

5° Simplificar entidades y ver si puedo eliminar alguna, en este caso CLIENTE
En vez de ID de cliente, puedo usar el CUIT del cliente, que es el único campo importante que tiene. Me guardo el CUIT
en la entidad contratación.

Tengo que hacer un array de 100 pantallas y un array de 1000 contrataciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "contratacion.h"
#include "utn.h"

#define QTY_PANTALLAS 100
#define QTY_CONTRATACIONES 1000

int main(void)
{
	setbuf(stdout,NULL);

	Pantalla arrayPantallas[QTY_PANTALLAS];
	pantalla_init(arrayPantallas, QTY_PANTALLAS);

	Contratacion arrayContratacion[QTY_CONTRATACIONES];
	contratacion_init(arrayContratacion, QTY_CONTRATACIONES);

	int opcion;

	do
	{
		if(utn_getNumberInt("Bienvenido al sistema, seleccione una opción: \n\n1 - Alta de pantalla\n2 - Modificar datos de pantalla\n3 - Baja de pantalla\n"
		"4 - Contratar una publicidad\n5 - Modificar condiciones de publicación\n6 - Cancelar contratación\n7 - Consultar facturación\n8 - Listar contrataciones\n"
		"9 - Listar pantallas\n10 - Informar\n11 - Salir del sistema","\nError. Seleccione una opción válida (1-10)\n", &opcion, 2, 1, 10)==0)
		{
			switch(opcion)
			{
			case 1:
				printf("\nUsted quiere dar de alta una pantalla.\n");
				if(pantalla_alta(arrayPantallas, QTY_PANTALLAS)==0)
				{
					printf("\nSe ha cargado una pantalla correctamente.\n");
				}
				else
				{
					printf("\nHa ocurrido un error al cargar la pantalla.\n");
				}
				break;
			case 2:
				printf("\nUsted quiere modificar datos de una pantalla.\n");
				if(pantalla_modificar(arrayPantallas, QTY_PANTALLAS)==0)
				{
					printf("\nSe han modificado los datos de la pantalla correctamente.\n");
				}
				else
				{
					printf("\nHa ocurrido un error al modificar la pantalla.\n");
				}
				break;
			case 3:
				printf("\nUsted quiere dar de baja una pantalla.\n");
				if(pantalla_baja(arrayPantallas, QTY_PANTALLAS)==0)
				{
					printf("\nSe ha dado de baja la pantalla correctamente.\n");
				}
				else
				{
					printf("\nHa ocurrido un error al dar de baja la pantalla.\n");
				}
				break;
			case 4:
				printf("\nUsted quiere contratar una publicidad.\n");
				if(contratacion_alta(arrayContratacion, QTY_CONTRATACIONES, arrayPantallas, QTY_PANTALLAS)==0)
				{
					printf("\nUsted ha contratado una publicidad correctamente.\n");
				}
				break;
			case 5:
				printf("\nUsted quiere modificar condiciones de una publicación.\n");
				if(contratacion_modificar(arrayContratacion, QTY_CONTRATACIONES, arrayPantallas, QTY_PANTALLAS)==0)
				{
					printf("\nUsted ha modificado las condiciones correctamente.\n");
				}
				break;
			case 6:
				printf("\nUsted quiere cancelar una contratación.\n");
				if(contratacion_baja(arrayContratacion, QTY_CONTRATACIONES, arrayPantallas, QTY_PANTALLAS)==0)
				{
					printf("\nUsted ha cancelado correctamente la contratación.\n");
				}
				break;
			case 7:
				// CONSULTAR FACTURACION
				break;
			case 8:
				printf("\nImprimir contrataciones\n");
				if(contratacion_imprimir(arrayContratacion, QTY_CONTRATACIONES, arrayPantallas, QTY_PANTALLAS)==0)
				{
					printf("\nSe han impreso todas las contrataciones cargadas.\n");
				}
				else
				{
					printf("\nHa ocurrido un error al imprimir las contrataciones.\n");
				}
				break;
			case 9:
				printf("\nImprimir pantallas\n");
				if(pantalla_imprimir(arrayPantallas, QTY_PANTALLAS)==0)
				{
					printf("\nSe han impreso todas las pantallas cargadas.\n");
				}
				else
				{
					printf("\nHa ocurrido un error al imprimir las pantallas.\n");
				}
				break;
			case 10:
				// INFORMAR
				break;
			}
		}
	}while(opcion != 11);
return EXIT_SUCCESS;
}
