/*
 * template.h
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#define LONG 50
#define TRUE 1
#define FALSE 0

typedef struct
{
	char pais[LONG];
	char nombre [LONG];
	int isEmpty;
	int id;
} Tem;

int template_init(Tem * pArray, int limite);
int template_alta (Tem * pArray, int limite);
int template_baja (Tem * pArray, int limite);
int template_modificar (Tem * pArray, int limite);
int template_imprimir (Tem * pArray , int limite);
int template_buscarLibre (Tem * pArray, int limite);
int template_buscarLibreRef (Tem * pArray, int limite, int * pIndice);
int template_buscarIndicePorId (Tem * pArray, int limite, int idBuscar,int * pIndice);
int template_ordenarPorNombre (Tem * pArrays, int limite , int orden);

#endif /* TEMPLATE_H_ */
