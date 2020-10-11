/*
 ============================================================================
 Name        : Clase_14_PARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "aviso.h"

#define QTY_CLIENTES 100
#define QTY_AVISOS 10000

int main(void) {

	setbuf(stdout,NULL);

	Cliente arrayCliente[QTY_CLIENTES];
	Aviso arrayAviso[QTY_AVISOS];

	int opcion;
	int opcionSubMenu;
	int contadorClientes = 4; // Despu�s modificar y poner en 0 cuando haya borrado la funci�n de altaForzada (ya que dicha funci�n es para ya tener datos cargados)

	// Inventos

	int opcionEstado;

	cliente_init(arrayCliente, QTY_CLIENTES); // Inicializo el array de clientes con todos los valores de isEmpty en TRUE, es decir, todo el array est� vac�o.
	aviso_init(arrayAviso, QTY_AVISOS); // Inicializo el array de avisos con todos los valores de isEmpty en TRUE, es decir, todo el array est� vac�o.

	cliente_altaForzada(arrayCliente, QTY_CLIENTES, "Esteban", "Ramos", "20-38428752-9");
	cliente_altaForzada(arrayCliente, QTY_CLIENTES, "Gabriel", "Villaverde", "20-39493486-9");
	cliente_altaForzada(arrayCliente, QTY_CLIENTES, "Huevo", "Diaz", "20-38542751-9");
	cliente_altaForzada(arrayCliente, QTY_CLIENTES, "Facundo", "Colavini", "20-37472450-9");

	aviso_altaForzada(arrayAviso, QTY_AVISOS, 1, "Busco empleados para mi negocio.", 57);
	aviso_altaForzada(arrayAviso, QTY_AVISOS, 2, "Necesito mec�nico para mi coche.", 60);
	aviso_altaForzada(arrayAviso, QTY_AVISOS, 3, "Compro muebles.", 132);
	aviso_altaForzada(arrayAviso, QTY_AVISOS, 4, "Urgente: Se solicita ni�era para cuidar a Vampi", 70);

	// Fuerzo a tener una publicacion activa
	arrayAviso[0].estado = AVISO_ACTIVO;

	do
	{
		if(utn_getNumberInt("Bienvenido al sistema, seleccione una opci�n: \n\n1 - Alta de cliente\n2 - Modificar datos de cliente\n3 - Baja de cliente\n"
		"4 - Publicar un nuevo aviso\n5 - Pausar publicaci�n\n6 - Reanudar publicaci�n\n7 - Imprimir clientes\n8 - Informar\n"
		"9 - Impresi�n de prueba de todos los clientes dados de alta\n10 - Impresi�n de prueba de todos los avisos dados de alta\n11 - Impresi�n de avisos pausados o activos\n12 - Salir del sistema","\nError. Seleccione una opci�n v�lida (1-15)\n", &opcion, 2, 1, 15)==0)
		{
			switch(opcion)
			{
			case 1:
				printf("\nUsted quiere dar de alta un cliente.\n");
				cliente_alta(arrayCliente, QTY_CLIENTES);
				contadorClientes++;
				break;
			case 2:
				printf("\nUsted quiere modificar datos de un cliente.\n");
				if(contadorClientes > 0 )
				{
					cliente_modificar(arrayCliente, QTY_CLIENTES);
				}
				else
				{
					printf("\nDebe cargar al menos un cliente para poder hacer modificaciones.\n");
				}
				break;
			case 3:
				printf("\nUsted quiere dar de baja un cliente.\n");
				if(contadorClientes > 0 )
				{
					// La funci�n deber�a llamarse clienteAviso_baja o algo as�.
					aviso_baja(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES);
					contadorClientes--;
				}
				else
				{
					printf("\nDebe cargar al menos un cliente para poder hacer eliminaciones.\n");
				}

				break;
			case 4:
				if(contadorClientes > 0)
				{
					printf("\nUsted quiere publicar un nuevo aviso.\n");
					aviso_alta(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES);
				}
				else
				{
					printf("\nA�n no hay ning�n cliente cargado. Primero reg�stre sus datos como cliente, luego vuelva a la opci�n 4 e ingrese el ID que se le asign� para publicar un aviso.\n");
				}
				break;
			case 5:
				printf("\nUsted quiere pausar una publicaci�n.\n");
				aviso_pausar(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES);
				break;
			case 6:
				printf("\nUsted quiere reanudar una publicaci�n.\n");
				aviso_activar(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES);
				break;
			case 7:
				printf("\nUsted quiere imprimir el listado de los clientes junto con la cantidad de avisos activos que cada uno posee.\n");
				aviso_imprimir(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES);
				break;
			case 8:
				do
				{
					if(utn_getNumberInt("\nUsted est� en el submen� de informes, seleccione una opci�n: \n\n1 - Cliente con m�s avisos.\n2 - Cantidad de avisos pausados.\n3 - Rubro con m�s avisos.\n", "\nError. Seleccione una opci�n v�lida (1-3)\n", &opcionSubMenu, 2, 0, 3) == 0)
					{
						switch(opcionSubMenu)
						{
						case 1:
							printf("\nUsted quiere un informe del cliente con m�s avisos.\n");
							break;
						case 2:
							printf("\nUsted quiere un informe de la cantidad de avisos pausados.\n");
							break;
						case 3:
							printf("\nUsted quiere un informe del rubro con m�s avisos.\n");
							break;
						}
					}
				}while(opcionSubMenu != 4);
				break;
			case 9:
				if(cliente_imprimir(arrayCliente, QTY_CLIENTES) == 0)
				{
					printf("\nImpresi�n correcta.\n");
				}
				break;
			case 10:
				if(aviso_imprimir(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES) == 0)
				{
					printf("\nImpresi�n correcta.\n");
				}
				break;
			case 11:
				printf("\nUsted quiere ver todas las publicaciones pausadas o activas.\n");
				if(utn_getNumberInt("\nIngrese: [1 - PAUSADAS] - [2 - ACTIVAS].\n", "\nError, debe ingresar 1 o 2.\n", &opcionEstado, 2, 1, 2) == 0)
				{
					if(opcionEstado == 1)
					{
						aviso_imprimirPorEstado(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES, 0);
					}
					else if(opcionEstado == 2)
					{
						aviso_imprimirPorEstado(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES, 1);
					}
				}
				break;
			}
		}
	}while(opcion != 15);
	return EXIT_SUCCESS;
}
