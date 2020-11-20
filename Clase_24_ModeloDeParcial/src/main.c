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
#include "Inputs.h"
#include "LinkedList.h"
#include "Controller.h"
#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int main(void) {

	setbuf(stdout,NULL);

	int option;
	LinkedList* listaEnvios = ll_newLinkedList();
	int estaCargado = FALSE;

	if(listaEnvios != NULL)
	{
		do
		{
			if(utn_getNumber(&option,
					"\n\nIngrese una opcion: \n"
					"\n1. Cargar los datos desde el archivo data.csv (modo texto)."
					"\n2. Cargar los datos desde el archivo data.bin (modo binario)."
					"\n3. Imprimir Envios"
					"\n4. Calcular costos"
					"\n5. Generar archivo de costos para zona"
					"\n6. Imprimir lista de zonas"
					"\n7. Guardar los datos en el archivo data.csv (modo texto)."
					"\n8. Guardar los datos en el archivo data.csv (modo binario)."
					"\n9. SALIR\n\n","\nError! elija una opcion valida",1,9,5)==SUCCESS)
			{
				switch(option)
				{
				case 1:
					if(estaCargado == FALSE)
					{
						if(controller_loadTexto(listaEnvios,"data.csv") == SUCCESS)
						{
							printf("Cargado con exito");
							estaCargado = TRUE;
						} else {
							printf("ERROR");
						}
					} else {
						printf("Ya esta cargado");
					}
					break;
				case 2:
					break;
				case 3:
					controller_printList(listaEnvios);
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
					printf("ADIOS");
					break;
				}//fin switch
			}//fin if get menu
		}while(option!=9);
	} else {
		printf("no hay memoria para iniciar el programa");
	}
	return EXIT_SUCCESS;
}
