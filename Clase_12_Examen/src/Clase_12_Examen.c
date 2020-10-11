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
#include "template.h"
#include "pantalla.h"
#include "utn.h"

#define QTY_PANTALLAS 100

int main(void)
{
	Pantalla arrayPantallas[QTY_PANTALLAS];
	setbuf(stdout,NULL);
	int opcion;

	pantalla_init(arrayPantallas, QTY_PANTALLAS);
	do
	{
		if(utn_getNumberInt("Bienvenido al sistema, seleccione una opción: \n\n1 - Alta de pantalla\n2 - Modificar datos de pantalla\n3 - Baja de pantalla\n4 - Contratar una publicidad\n5 - Modificar condiciones de publicación\n6 - Cancelar contratación\n7 - Consultar facturación\n8 - Listar contrataciones\n9 - Listar pantallas\n10 - Informar\n11 - Salir del sistema","\nError. Seleccione una opción válida (1-10)\n", &opcion, 2, 1, 10)==0)
		{
			switch(opcion)
			{
			case 1:
				printf("Alta de pantalla\n");
				pantalla_alta(arrayPantallas, QTY_PANTALLAS);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			}
		}
	}while(opcion != 11);
return EXIT_SUCCESS;
}
