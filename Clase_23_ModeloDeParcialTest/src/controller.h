/*
 * controller.h
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path, LinkedList* pArrayListaEnvios);
int controller_imprimirListaEnvios(LinkedList* pArrayListaEnvios);
LinkedList* controller_generarArchivoDeCostosPorZona(LinkedList* pArrayListaEnvios);
#endif /* CONTROLLER_H_ */
