/*
 * ArrayEmployees.c
 *
 *  Created on: 25 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define TRUE 1
#define FALSE 0

#define LONG_NAME 51
#define LONG_LASTNAME 51

// Prototipo:
static int generateNewId(void);
static int compareElements(Employee employee1, Employee employee2, int order, int sort);

/* Función employee_initEmployees:
 * Para indicar que todas las posiciones del array están vacías, esta función pone la
 * bandera (isEmpty) en TRUE en todas las posiciones del array.
 */

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all the positions of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int employee_initEmployees(Employee* pArrayList, int len)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0)
	{
		for(int i= 0;i<len;i++)
		{
			pArrayList[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/* Función employee_addEmployee:
* Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
* posición libre.
 */

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/

int employee_addEmployee(Employee* pArrayList, int len, int index)
{
	int retorno = -1;
	Employee bufferEmployee;
	if(pArrayList != NULL && len > 0 && index >= 0 && index <= len && pArrayList[index].isEmpty == TRUE)
	{
		if
		(
		utn_getName("\nName of employee:\n","Error, please type a correct name.\n",bufferEmployee.name,2,LONG_NAME)==0 // Me tiraba error porque estaba usando &bufferEmployee, ¿por qué acá no y en las otras sí el &?
			&&
		utn_getName("\nLast name of employee:\n","Error, please type a correct last name.\n",bufferEmployee.lastName,2,LONG_LASTNAME)==0 // Me tiraba error porque estaba usando &bufferEmployee, ¿por qué acá no y en las otras sí el &?
			&&
		utn_getNumberFloat("\nSalary:\n","Error, please type a correct salary between $0 and $999999.\n", &bufferEmployee.salary,2, 0, 999999)==0
			&&
		utn_getNumberInt("\nSector:\n", "Error, please type a correct sector\n", &bufferEmployee.sector, 2, 0, 999999)==0
		)
		{
			bufferEmployee.id = generateNewId();
			pArrayList[index] = bufferEmployee;
			pArrayList[index].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}

/* Función employee_removeEmployee: Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.*/
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int employee_removeEmployee(Employee* pArrayList, int len, int index)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0 && index < len && pArrayList[index].isEmpty == FALSE)
	{
		pArrayList[index].isEmpty = TRUE;
		retorno = 0;
	}
	else
	{
		printf("There's no employee to remove");
	}
	return retorno;
}

static int generateNewId(void)
{
	static int id=0; // es global para solo la fn puede usarla

	//guardar el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id+1;
	return id;
}

int employee_findEmpty(Employee* pArrayList, int len, int* pIndex)
{
	int retorno = -1;
	if(pArrayList != NULL && pIndex != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArrayList[i].isEmpty == TRUE)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \param pIndex int*
* \return int Return (-1) if Error [Invalid length or NULL pointer received or employee not found] - (0) if Ok
*/
int employee_findEmployeeById(Employee* pArrayList, int len, int* pIndex, int id)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArrayList[i].isEmpty == FALSE)
			{
				if(pArrayList[i].id == id) // Estaba poniendo pArrayList[id].id == id, tenía que poner en vez de [id] era [i]
				{
					*pIndex = i;
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Modifica los datos de un alumno solo si el indice corresponde a un NO Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */

int employee_modifyEmployee(Employee* pArrayList, int len, int index)
{
	int retorno = -1;
	Employee bufferEmployee;
	if
		(
		utn_getName("\nName of employee:\n","Error, please type a correct name.\n",bufferEmployee.name,2,LONG_NAME)==0 // Me tiraba error porque estaba usando &bufferEmployee, ¿por qué acá no y en las otras sí el &?
			&&
		utn_getName("\nLast name of employee:\n","Error, please type a correct last name.\n",bufferEmployee.lastName,2,LONG_LASTNAME)==0 // Me tiraba error porque estaba usando &bufferEmployee, ¿por qué acá no y en las otras sí el &?
			&&
		utn_getNumberFloat("\nSalary:\n","Error, please type a correct salary between $0 and $999999.\n", &bufferEmployee.salary,2, 0, 999999)==0
			&&
		utn_getNumberInt("\nSector:\n", "Error, please type a correct sector\n", &bufferEmployee.sector, 2, 0, 999999)==0
		)
		{
			bufferEmployee.id = pArrayList[index].id;
			pArrayList[index] = bufferEmployee;
			pArrayList[index].isEmpty = FALSE;
			retorno = 0;
		}
	return retorno;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int employee_printEmployees(Employee* pArrayList, int len)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArrayList[i].isEmpty == FALSE)
			{
				printf("Name: %s - Last name: %s - Salary: %f - Sector: %d - ID: %d\n\n", pArrayList[i].name, pArrayList[i].lastName, pArrayList[i].salary, pArrayList[i].sector, pArrayList[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/*
 * Función sortEmployees
Ordena el array de empleados por apellido y sector de manera ascendente o descendente.*/
/* \brief Sort the elements in the array of employees, the argument order*
indicate UP or DOWN order*
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/


int employee_sortEmployees(Employee* pArrayList, int len, int order)
{
	int sort;
	if(order == 1)
	{
		sort = 1;
	}
	else if(order == 0)
	{
		sort = -1;
	}

	int retorno = -1;
	int i;
	int newLen;
	int flagSwap;
	Employee bufferEmployee;
	if(pArrayList != NULL && len > 0)
	{
		newLen = len -1;
		do
		{

			flagSwap = 0;
			for(i=0;i<newLen;i++)
			{
				if(pArrayList[i+1].isEmpty == 0)
				{

					if(compareElements(pArrayList[i], pArrayList[i+1], order, sort))
					{
						flagSwap = 1;
						bufferEmployee=pArrayList[i];
						pArrayList[i]=pArrayList[i+1];
						pArrayList[i+1]=bufferEmployee;
					}

				}
			}
			newLen--;
			retorno=0;
		}while(flagSwap);
	}
	return retorno;
}

static int compareElements(Employee employee1, Employee employee2, int order, int sort)
{
	if(strcmp(employee1.lastName, employee2.lastName) == sort)
	{
		return 1;
	}
	else if(strcmp(employee1.lastName, employee2.lastName) == 0)
	{
		if(order)
		{
			if(employee1.sector > employee2.sector)
			{
				return 1;
			}
			else
			{
			return 0;
			}
		}
		else
		{
			if(employee1.sector < employee2.sector)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
	return 0;
	}
}

int employee_calculateTotalAndAverageSalary(Employee* pArrayList, int len, float* pTotalSalary, float* pAverageSalary, int *pGreaterThanAverage)
{
	int i;
	int retorno = -1;
	int counter = 0;
	int aboveAverageCounter = 0;
	int salaryAcumulator = 0;

	if(pArrayList != NULL && pTotalSalary != NULL && pAverageSalary != NULL && len > 0)
	{

		for(i=0;i<len;i++)
		{
			if(!pArrayList[i].isEmpty)
			{
				salaryAcumulator += pArrayList[i].salary;
				counter++;
			}
		}
		*pTotalSalary = salaryAcumulator;
		*pAverageSalary = (float)salaryAcumulator / counter;

		for(i=0;i<len;i++)
		{
			if(!pArrayList[i].isEmpty)
			{
				if(pArrayList[i].salary > *pAverageSalary)
				{
					aboveAverageCounter++;
				}
			}
		}
		*pGreaterThanAverage = aboveAverageCounter;
		printf("Average wages: %f - Total wages: %f - Quantity of employees that are above the average wage: %d\n",*pAverageSalary,*pTotalSalary,*pGreaterThanAverage);
		retorno = 0;
	}
return retorno;
}
