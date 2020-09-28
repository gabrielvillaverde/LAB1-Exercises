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

	setbuf(stdout, NULL);

	Employee arrayEmployees[QTY_EMPLOYEES];

	int option;
	int reportOption;
	int orderOption;
	int freeIndex; // No tengo claro esto
	int idToModify; // No tengo claro esto
	int index; // No tengo claro esto

	// Inventos míos
	float totalSalary;
	float averageSalary;
	int greaterThanAverage;

	// Inventos míos
	int counterEmployee = 0;

	employee_initEmployees(arrayEmployees, QTY_EMPLOYEES); // Inicializo la función, no tengo claro bien qué pasa si no.

	do
	{
		if (utn_getNumberInt("Welcome to the system, choice an option: \n\n1 - Register employee\n2 - Modify registry\n3 - Remove employee\n4 - Report\n5 - Get out of the system\n","\nError. select a valid option (1-5)\n", &option, 2, 1, 5)== 0)
		{
			switch (option)
			{
			case 1:
				printf("\nYou entered option 1 - Register employee\n");
				if (employee_findEmpty(arrayEmployees, QTY_EMPLOYEES,&freeIndex) == 0)
				{
					employee_addEmployee(arrayEmployees, QTY_EMPLOYEES,freeIndex);
					counterEmployee++;
				}
				break;
			case 2:
				if(counterEmployee > 0)
				{
				printf("\nYou entered option 2 - Modify data of an employee:\n");
					if (utn_getNumberInt("Enter the ID of the employee you want to modify:\n","Error, select a valid or empty ID.\n", &idToModify,2,1,1000) == 0)
					{
						printf("\nYou are going to modify the following ID: %d\n",idToModify);
						if (employee_findEmployeeById(arrayEmployees, QTY_EMPLOYEES,&index,idToModify) == 0)
						{
							printf("\nThis is the ID you modified: %d", idToModify);
							employee_modifyEmployee(arrayEmployees, QTY_EMPLOYEES,index);
						}
					}
				}
				else
				{
					printf("You must load an employee before making modifications.\n");
				}
				break;
			case 3:
				if(counterEmployee > 0)
				{
				printf("\nYou entered option 3 - Remove employee\nYou can delete the following employees:\n");
				employee_printEmployees(arrayEmployees, QTY_EMPLOYEES);
					if (utn_getNumberInt("Enter the ID of the employee you want to remove:\n","Error, select a valid or loaded ID.\n",&idToModify,2,1,1000) == 0)
					{
						printf("\nYou are going to remove the following ID: %d\n",idToModify);
						if (employee_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,&index,idToModify) == 0)
						{
							printf("\nThis is the ID you removed: %d\n",idToModify);
							employee_removeEmployee(arrayEmployees, QTY_EMPLOYEES,index);
							counterEmployee--;
						}
					}
				}
				else
				{
					printf("\nYou must load an employee before deleting.\n");
				}

				break;
			case 4:
				if(counterEmployee > 0)
				{
				printf("\nYou entered option 4 - Report\n");
					if(utn_getNumberInt("Choice an option:\n1 - Report employees sorted alphabetically and by sector\n2 - Total and average salaries, and how many employees are above the average salary\n","\nError, choice a correct option [1-2]\n", &reportOption, 2, 1, 2)==0)
					{
						switch (reportOption)
						{
						case 1:
							if (utn_getNumberInt("Choice an option to order: \n\n1 - Sort employees in ascending order\n2 - Sort employees in descending order\n","\nError, select a correct option [1-2]\n",&orderOption,2,1,2) == 0)
							{
								switch (orderOption)
								{
								case 1:
									printf("\nYou entered option 1 - Sort employees in ascending order by surname and then by sector if the surnames are the same\n");
									employee_sortEmployees(arrayEmployees,QTY_EMPLOYEES,1);
									employee_printEmployees(arrayEmployees,QTY_EMPLOYEES);

									break;

								case 2:
									printf("\nYou entered option 2 - Sort employees in descending order by surname and then by sector if the surnames are the same\n");
									employee_sortEmployees(arrayEmployees, QTY_EMPLOYEES,0);
									employee_printEmployees(arrayEmployees, QTY_EMPLOYEES);

									break;
								}
							}
							break;
						case 2:
							printf("You want to find out the total and average wages, and how many employees are above the average salary:\n");
							employee_calculateTotalAndAverageSalary(arrayEmployees, QTY_EMPLOYEES, &totalSalary, &averageSalary, &greaterThanAverage);
							break;
						}
					}
				}
				else
				{
					printf("\nYou must load an employee before requesting a report.\n");
				}
				break;
			}
		}
	} while (option != 5);
return EXIT_SUCCESS;
}
