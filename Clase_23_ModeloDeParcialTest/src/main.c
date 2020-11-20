/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "controller.h"
#include "envio.h"

#define FALSE 0
#define TRUE 1

#define SIZE_ARCHIVO 200

/* Errores:
 * A) En el punto 3, la consigna pide calcular los costos e imprimir por pantalla. Solamente calcula los costos y no imprime.
 * B) En el punto 4, no se genera el archivo.
 */

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;

	char path[SIZE_ARCHIVO];

	LinkedList* listaEnvios = ll_newLinkedList();
	LinkedList* listaEnviosFiltrada = NULL;

	do
	{
    	if(utn_getIntConMinMax("\nBienvenido al sistema, elija una opción: \n\n"
    			"1  -  Cargar el archivo.\n"
    			"2  -  Imprimir envíos.\n"
    			"3  -  Calcular costos.\n"
    			"4  -  Generar archivo de costos para zona.\n"
    			"5  -  Imprimir lista de zonas.\n"
    			"6  -  Salir.\n",
				"\nError, ingrese una opción entre 1 y 6.\n", &opcion, 1, 6, 3) == 0)
    	{
    		switch(opcion)
    		{
    		case 1:
    			if(utn_getStringWithNumbersAndSymbols("\nIngrese el nombre del archivo que quiere abrir:\n", "\nError, ingrese un nombre válido.\n", path, SIZE_ARCHIVO, 3) == 0)
    			{
    				if(controller_loadFromText(path, listaEnvios) == 0)
    				{
        				printf("\nArchivo cargado como texto correctamente.\n");
    				}
    				else
    				{
        				printf("\nNo se pudo cargar el archivo.\n");
    				}
    			}
    			break;
    		case 2:
				if(controller_imprimirListaEnvios(listaEnvios) == 0)
				{
    				printf("\nArchivo impreso correctamente.\n");
				}
				else
				{
    				printf("\nNo se pudo imprimir el archivo.\n");
				}
				break;
    		case 3:
    			if(ll_map(listaEnvios, envio_calcularCostoDeEnvio) == 0)
    			{
    				printf("\nSe han calculado los costos correctamente.\n");
    				if(controller_imprimirListaEnvios(listaEnvios) == 0)
    				{
        				printf("\nPIOLAAA.\n"); // NO LLEGA ACÁ, NO RETORNA 0.
    				}
    			}
    			break;
    		case 4:
    			listaEnviosFiltrada = controller_generarArchivoDeCostosPorZona(listaEnviosFiltrada);
    			if(listaEnviosFiltrada != NULL)
    			{
    				printf("\nArchivo generado correctamente.\n");
    			}
    			break;
    		//case 5:
    			/* Sacar los repetidos y quedarme con las zonas una vez cada una.
    			 * La forma más simple es generar una lista nueva.
    			 * Tengo que ver si algo ya está o no, para agregarlo a una lista nueva.
    			 * Recorro la lista original y analizo cada elemento, si está en la lista nueva
    			 * no lo agrego, y si no está lo agrego.
    			 * HORA: 07:09 - No recomienda usar filter, sino una función
    			 * que tiene un algoritmo de detectar repetidos.
    			 * Tengo una lista de ciertos elementos, y de esos elementos quiero tomar
    			 * un campo en particular y ponerlo en una lista nueva, si es que
    			 * todavía no están en una lista nueva.
    			 * HORA: 07:10 IMPORTANTE explicación.
    			 */
    		}
    	}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}
