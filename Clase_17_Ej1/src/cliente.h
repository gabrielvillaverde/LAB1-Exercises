/*
 * cliente.h
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define SIZE_NOMBRE 50
#define SIZE_APELLIDO 50
#define SIZE_CUIT 14
#define TRUE 1
#define FALSE 0

typedef struct
{
	char nombre [SIZE_NOMBRE];
	char apellido [SIZE_APELLIDO];
	char cuit [SIZE_CUIT];
	int idCliente;
	int isEmpty;
} Cliente;

int cliente_init(Cliente * pArrayCliente, int limiteCliente);
int cliente_alta (Cliente * pArrayCliente, int limiteCliente);
int cliente_altaForzada(Cliente * pArrayCliente, int limiteCliente, char * nombre, char * apellido, char * cuit);
//int cliente_baja (Cliente * pArrayCliente, int limiteCliente);
int cliente_modificar (Cliente * pArrayCliente, int limiteCliente);
int cliente_imprimir (Cliente * pArrayCliente , int limiteCliente);
int cliente_buscarLibre (Cliente * pArrayCliente, int limiteCliente);
int cliente_buscarLibreRef (Cliente * pArrayCliente, int limiteCliente, int * pIndice);
int cliente_buscarIndicePorId (Cliente * pArrayCliente, int limiteCliente, int idBuscado, int * pIndice);

// Memoria dinámica:
Cliente* cliente_new(void);
Cliente* cliente_newConParametros(char* nombre, char* apellido, char* cuit, int idCliente);
int cliente_inicializarArrayPunteros(Cliente* arrayPunterosACliente[], int limitePunterosACliente);
int cliente_buscarIndiceLibreArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente);
int cliente_buscarIndiceLibreArrayPunterosRef (Cliente* arrayPunterosACliente[], int limitePunterosACliente, int* pIndice);
int cliente_altaArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente, int indice, int* idCliente);
int cliente_altaForzadaArrayPunterosACliente(Cliente* arrayPunterosACliente[]);
int cliente_agregarClienteArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente, char* nombre, char* apellido, char* cuit, int idCliente);
int cliente_imprimirArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente);
int cliente_buscarIndicePorIdArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente, int idBuscado);
int cliente_borrarIndiceArrayPunteros(Cliente* arrayPunterosACliente[], int limitePunterosACliente, int indiceArrayPunterosACliente);
int cliente_borrarIndiceArrayPunterosPorId (Cliente* arrayPunterosACliente[], int limitePunterosACliente, int idBuscado);

#endif /* CLIENTE_H_ */
