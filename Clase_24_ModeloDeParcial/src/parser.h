/*
 * parser.h
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int parser_EnvioTxt(FILE* pFile , LinkedList* pArray);
int parser_EnvioBinario(FILE* pFile , LinkedList* pArray);

#endif /* PARSER_H_ */
