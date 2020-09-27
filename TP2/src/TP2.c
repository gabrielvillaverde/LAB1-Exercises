/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define QTY_EMPLOYEES 1000

int main(void) {

	setbuf(stdout,NULL);

	Employee arrayEmployees[QTY_EMPLOYEES];

	int opcion;
	int freeIndex; // No tengo claro esto
	int idToModify; // No tengo claro esto
	int index; // No tengo claro esto

	employee_initEmployees(arrayEmployees, QTY_EMPLOYEES); // Inicializo la función, no tengo claro bien qué pasa si no.

	do
	{
		if(utn_getNumberInt("Welcome to the system, choice an option: \n\n1 - Register employee\n2 - Modify registry\n3 - Remove employee\n4 - Report\n5 - Get out of the system","\nError. Elija una opción válida (1-5)\n", &opcion, 2, 1, 5)==0)
		{
			switch(opcion)
			{
				case 1:
					printf("\nYou entered option 1 - Register employee\n");
					if(employee_findEmpty(arrayEmployees, QTY_EMPLOYEES, &freeIndex)==0)
					{
						employee_addEmployee(arrayEmployees, QTY_EMPLOYEES, freeIndex);
					}
					break;
				case 2:
					printf("\nYou entered option 2 - Modify data of an employee:\n");
					if(utn_getNumberInt("Enter the ID of the employee you want to modify:\n", "Error, choose a valid or empty ID.\n", &idToModify, 2, 1, 1000)==0)
					{
						printf("\nYou are going to modify the following ID: %d\n",idToModify);
						if(employee_findEmployeeById(arrayEmployees, QTY_EMPLOYEES, &index, idToModify)==0)
						{
							printf("\nThis is the ID you modified: %d", idToModify);
							employee_modifyEmployee(arrayEmployees, QTY_EMPLOYEES, index);
						}
					}
					break;
				case 3:
					printf("\nYou entered option 3 - Remove employee:\n");
					if(utn_getNumberInt("Enter the ID of the employee you want to remove:\n", "Error, choose a valid or loaded ID.\n", &idToModify, 2, 1, 1000)==0)
					{
						printf("\nYou are going to remove the following ID: %d\n",idToModify);
						if(employee_findEmployeeById(arrayEmployees, QTY_EMPLOYEES, &index, idToModify)==0)
						{
							printf("\nThis is the ID you removed: %d\n", idToModify);
							employee_removeEmployee(arrayEmployees, QTY_EMPLOYEES, index);
						}
					}
					break;
				case 4:
					printf("\nYou entered option 4 - Report employees sorted alphabetically and by sector\n");
					employee_sortEmployees(arrayEmployees, QTY_EMPLOYEES, 1);
					employee_printEmployees(arrayEmployees, QTY_EMPLOYEES);
					break;
			}
		}
	}
	while(opcion!=5);

	return EXIT_SUCCESS;
}
