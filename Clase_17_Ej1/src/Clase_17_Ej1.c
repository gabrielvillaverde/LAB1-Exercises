/*
 ============================================================================

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "aviso.h"
#include "clienteAviso.h"
#include "informes.h"


#define QTY_CLIENTES 100
#define QTY_AVISOS 1000

int main(void) {

	setbuf(stdout,NULL);

	Cliente* arrayPunterosAClientes[QTY_CLIENTES]; // Al ser del tipo Cliente* (puntero a Cliente), guarda un número, la dirección de memoria a un área en donde está todo.
	// Cliente punterosClientes[QTY_CLIENTES]; En este caso, sin el * es un tipo de dato del tipo Cliente, que significa que la variable tendría espacio para guardar todos los datos del cliente, todo lo definido en la estructura Cliente.

	Cliente arrayCliente[QTY_CLIENTES];
	Aviso arrayAviso[QTY_AVISOS];

	int opcion;
	int opcionSubMenu;
	int indiceAvisos = 6;

	int auxiliarIndiceLibre;
	int auxiliarIndiceBorrar;
	int idCliente;
	int idClienteABorrar;

	if(cliente_inicializarArrayPunteros(arrayPunterosAClientes, QTY_CLIENTES) == 0)
	{
		printf("\nArray de clientes inicializado correctamente.\n");
	}

	cliente_altaForzadaArrayPunterosACliente(arrayPunterosAClientes);

	cliente_init(arrayCliente, QTY_CLIENTES); // Inicializo el array de clientes con todos los valores de isEmpty en TRUE, es decir, todo el array está vacío.
	aviso_init(arrayAviso, QTY_AVISOS); // Inicializo el array de avisos con todos los valores de isEmpty en TRUE, es decir, todo el array está vacío.

	do
	{
		if(utn_getNumberInt("Bienvenido al sistema, seleccione una opción: \n\n1 - Alta de cliente\n2 - Modificar datos de cliente\n3 - Baja de cliente\n"
		"4 - Publicar un nuevo aviso\n5 - Pausar publicación\n6 - Reanudar publicación\n7 - Imprimir clientes\n8 - Informar\n"
		"8 - Salir del sistema","\nError. Seleccione una opción válida (1-8)\n", &opcion, 2, 1, 8) == 0)
		{
			switch(opcion)
			{
			case 1:
				printf("\nUsted quiere dar de alta un cliente.\n");
				//cliente_alta(arrayCliente, QTY_CLIENTES);
				auxiliarIndiceLibre = cliente_buscarIndiceLibreArrayPunteros(arrayPunterosAClientes, QTY_CLIENTES);
				if(auxiliarIndiceLibre >= 0)
				{
					if(cliente_altaArrayPunteros(arrayPunterosAClientes, QTY_CLIENTES, auxiliarIndiceLibre, &idCliente) == 0)
					{
						printf("\nCliente dado de alta correctamente.\n");
					}
				}
				break;
			case 2:
				printf("\nUsted quiere modificar datos de un cliente.\n");
				cliente_modificar(arrayCliente, QTY_CLIENTES);
				break;
			case 3:
				printf("\nUsted quiere dar de baja un cliente, por favor elija cuál desea eliminar:.\n");
				//cliente_imprimir(arrayCliente, QTY_CLIENTES);
				//clienteAviso_baja(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES);
				cliente_imprimirArrayPunteros(arrayPunterosAClientes, QTY_CLIENTES);
				utn_getNumberInt("Ingrese el ID del cliente que quiere borrar:\n", "\nError, ingrese un ID válido.\n", &idClienteABorrar, 2, 0, 10000);
				auxiliarIndiceBorrar = cliente_buscarIndicePorIdArrayPunteros(arrayPunterosAClientes, QTY_CLIENTES, idClienteABorrar);
				if(auxiliarIndiceBorrar >= 0)
				{
					if(cliente_borrarIndiceArrayPunteros(arrayPunterosAClientes, QTY_CLIENTES, auxiliarIndiceBorrar) == 0)
					{
						printf("\nEl cliente se eliminó con éxito.\n");
					}
				}
				break;
			case 4:
				printf("\nUsted quiere publicar un nuevo aviso.\n");
				aviso_alta(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES, &indiceAvisos);
				break;
			case 5:
				printf("\nUsted quiere pausar una publicación.\n");
				aviso_pausar(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES);
				break;
			case 6:
				printf("\nUsted quiere reanudar una publicación.\n");
				aviso_activar(arrayAviso, QTY_AVISOS, arrayCliente, QTY_CLIENTES);
				break;
			case 7:
				printf("\nUsted quiere imprimir el listado de los clientes.\n");
				//clienteAviso_avisosActivosImprimir(arrayCliente, QTY_CLIENTES, arrayAviso, QTY_AVISOS);
				cliente_imprimirArrayPunteros(arrayPunterosAClientes, QTY_CLIENTES);
				break;
			case 8:
				do
				{
				if(utn_getNumberInt("\nUsted está en el submenú de informes, seleccione una opción: \n\n1 - Cliente con más avisos.\n2 - Cantidad de avisos pausados.\n3 - Rubro con más avisos.\n4 - Cliente con más avisos activos.\n5 - Cliente con más avisos pausados\n6 - Salir del menú.\n", "\nError. Seleccione una opción válida (1-5)\n", &opcionSubMenu, 2, 1, 6) == 0)
					{
						switch(opcionSubMenu)
						{
						case 1:
							printf("\nUsted quiere un informe del cliente con más avisos.\n");
							informes_calcularClienteConMasAvisos(arrayCliente, QTY_CLIENTES, arrayAviso, QTY_AVISOS);
							break;
						case 2:
							printf("\nUsted quiere un informe de la cantidad de avisos pausados.\n");
							informes_calcularCantidadDeAvisosPausados(arrayAviso, QTY_AVISOS);
							break;
						case 3:
							printf("\nUsted quiere un informe del rubro con más avisos.\n");
							informes_calcularRubroConMasAvisos(arrayAviso, QTY_AVISOS);
							break;
						case 4:
							printf("\nUsted quiere un informe del cliente con más avisos activos.\n");
							informes_calcularClienteConMasAvisosPorEstado (arrayCliente, QTY_CLIENTES, arrayAviso, QTY_AVISOS, AVISO_ACTIVO);
							break;
						case 5:
							printf("\nUsted quiere un informe del cliente con más avisos pausados.\n");
							informes_calcularClienteConMasAvisosPorEstado (arrayCliente, QTY_CLIENTES, arrayAviso, QTY_AVISOS, AVISO_PAUSADO);
							break;
						}
					}
				}while(opcionSubMenu != 6);
				break;
			}
		}
	}while(opcion != 8);
	return EXIT_SUCCESS;
}
