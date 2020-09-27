/*
 * alumno.c
 *
 *  Created on: 22 sep. 2020
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"

#define MAX_LEGAJOS 1000
#define MIN_LEGAJOS 1
#define QTY_ALUMNOS 5
#define LONG_NAME 50
#define TRUE 1
#define FALSE 0

static int generarIdNuevo(void);

/**
 * \brief Realiza el alta de un alumno solo si el isEmpty es == 1
 * \param Alumno*, es el puntero al array de alumnos
 * \param int limite, es el limite del array
 * \param int indice, es el indice donde se cargara el alumno
 * \return 0 ok / -1 ERROR
 */
int alumno_altaAlumno(Alumno* pArrayAlumno, int limite, int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(pArrayAlumno != NULL && limite > 0 && indice >= 0 && indice < limite && pArrayAlumno[indice].isEmpty == 1)
	{
		if(	(utn_getNumberInt("Legajo\n", "ERROR\n", &bufferAlumno.legajo, 3, MIN_LEGAJOS, MAX_LEGAJOS)==0) &&
			(utn_getName("Nombre\n", "ERROR\n", bufferAlumno.nombre, 3, LONG_NAME)==0))
			{
				bufferAlumno.id = generarIdNuevo(); // Ejercicio 8
				bufferAlumno.isEmpty = 0; // FALSE
				pArrayAlumno[indice] = bufferAlumno;
				retorno = 0;
			}
	}
	else
	{
		if(pArrayAlumno[indice].isEmpty == 0)
		{
			printf("Error indice ya cargado, por favor dirijase a la opci�n modificar para este indice\n\n");
		}
	}
	return retorno;
}

/**
 * \brief Inicializa el array alumnos con 1
 * \param Alumno*, es el puntero al array de alumnos
 * \param int limite, es el limite del array
 * \return 0 ok / -1 ERROR
 */
int alumno_initAlumnos(Alumno* pArrayAlumno, int limite)
{
	int retorno = -1;
	if(pArrayAlumno != NULL && limite > 0 )
	{
		for(int i = 0; i < limite; i++)
		{
			pArrayAlumno[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Imprime el array alumnos con valores en isEmpty == 0.
 * \param Alumno*, es el puntero al array de alumnos
 * \param int limite, es el limite del array
 * \return 0 ok / -1 ERROR
 */
int alumno_imprimirAlumnos(Alumno* pArrayAlumno, int limite)
{
	int retorno = -1;
	if(pArrayAlumno != NULL && limite > 0 )
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayAlumno[i].isEmpty == 0)
			{
				printf("\nIndice: %d   -  Nombre: %s  -  Legajo: %d - ID: %d\n", i, pArrayAlumno[i].nombre, pArrayAlumno[i].legajo, pArrayAlumno[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}


/**
 * \brief Modifica un alumno solo si el isEmpty es == 0
 * \param Alumno*, es el puntero al array de alumnos
 * \param int limite, es el limite del array
 * \param int indice, es el indice donde se cargara el alumno
 * \return 0 ok / -1 ERROR
 */
int alumno_modificarAlumno(Alumno* pArrayAlumno, int limite, int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(pArrayAlumno != NULL && limite > 0 && indice < limite && pArrayAlumno[indice].isEmpty == 0)
	{
		if(	(utn_getName("Ingrese Nombre: \n", "ERROR nombre inv�lido\n", bufferAlumno.nombre, 3, LONG_NAME)==0) &&
			(utn_getNumberInt("Ingrese Legajo:\n", "ERROR ingrese numero\n", &bufferAlumno.legajo, 3, 0, 1000)==0))
		{
			bufferAlumno.id = pArrayAlumno[indice].id;
			bufferAlumno.isEmpty = FALSE;
			pArrayAlumno[indice] = bufferAlumno;
			retorno = 0;
		}
	}
	else
	{
		printf("No hay ningun valor para modificar\n");
	}
	return retorno;
}

/**
 * \brief Reemplaza el valor de isEmpy = 0 por un = 1 para que la funcion cargar lo reconozca y no se imprima
 * \param Alumno*, es el puntero al array de alumnos
 * \param int limite, es el limite del array
 * \param int indice, es el indice donde se cargara el alumno
 * \return 0 ok / -1 ERROR
 */
int alumno_bajaAlumno(Alumno* pArrayAlumno, int limite, int indice)
{
	int retorno = -1;
	if(pArrayAlumno != NULL && indice < limite && limite > 0 && pArrayAlumno[indice].isEmpty == 0)
	{
		pArrayAlumno[indice].isEmpty = 1;
		retorno = 0;
	}
	else
	{
		printf("No existe indice para dar de baja\n");
	}
	return retorno;
}

/**
 *
 */
int alumno_sortAlumnoByName(Alumno* pArrayAlumno, int limite)
{
	int retorno = -1;
	int i;
	int nuevoLimite;
	int flagSwap;
	Alumno bufferAlumno;
	if(pArrayAlumno != NULL && limite > 0)
	{
		nuevoLimite = limite -1;
		do
		{

			flagSwap = 0;
			for(i=0;i<nuevoLimite;i++)
			{
				//if(strncmp(pArrayAlumno[i].nombre, pArrayAlumno[i+1].nombre, limite) == 1)
				//printf("Indice: %d - Nombre: %s - Legajo: %d - eMPTY: %d\n",i ,pArrayAlumno[i].nombre, pArrayAlumno[i].legajo, pArrayAlumno[i].isEmpty);
				if(pArrayAlumno[i+1].isEmpty == 0)
				{
					//if(pArrayAlumno[i].nombre < pArrayAlumno[i+1].nombre)
					if(strcmp(pArrayAlumno[i].nombre, pArrayAlumno[i+1].nombre)== 1)
						/*
						strcmp(A=97, B=98)==(-1)
						strcmp(A=98, B=98)==(0)
						strcmp(A=97, B=96)==(1)
						*/
					{
						flagSwap = 1;
						bufferAlumno=pArrayAlumno[i];
						pArrayAlumno[i]=pArrayAlumno[i+1];
						pArrayAlumno[i+1]=bufferAlumno;
						printf("Dentro del if %s --   %d --- Indice %d\n", pArrayAlumno[i].nombre, pArrayAlumno[i].legajo, i);
					}
				}
				printf("///////////////\n");
			}
			nuevoLimite--;
			retorno=0;
		}while(flagSwap);
	}
	return retorno;
}

/**
int alumno_ordenarArray(Alumno* listaAlumnos,int len)
{
	int retorno = ERROR;
	int i;
	Alumno aux;
	int estadoDesordenado=1;

	if(listaAlumnos != NULL && len > 0)
	{
		while(estadoDesordenado)//mientras este desordenado
		{
			estadoDesordenado = 0;
			for(i = 0; i < (len - 1); i++)
			{
				// strncmp compara listaAlumnos en la posici�n i y tambi�n en i+1
				// Como es la strncmp le pasa el l�mite tambi�n como par�metro, NOMBRE_LEN
				if(strncmp(listaAlumnos[i].nombre, listaAlumnos[i + 1].nombre,NOMBRE_LEN)>0)//aca establezco por que criterio quiero ordenar
				{
					aux = listaAlumnos[i];
					listaAlumnos[i] = listaAlumnos[i + 1];
					listaAlumnos[i + 1] = aux;
					estadoDesordenado = 1;
				}
			}
		}
		retorno = EXITO;
	}
	return retorno;
 */
int alumno_sortAlumnoByLegajo(Alumno* pArrayAlumno, int limite)
{
	int retorno = -1;
	int i;
	int flagSwap;
	Alumno bufferAlumno;
	int nuevoLimite;
	if(pArrayAlumno != NULL && limite > 0)
	{
		nuevoLimite = limite - 1;
		do
		{
			flagSwap = 0;
			for(i=0; i < nuevoLimite; i++)
			{
				if(pArrayAlumno[i+1].isEmpty == 0)
				{
					if(pArrayAlumno[i].legajo > pArrayAlumno[i+1].legajo)
					{
						bufferAlumno = pArrayAlumno[i];
						pArrayAlumno[i] = pArrayAlumno[i+1];
						pArrayAlumno[i+1] = bufferAlumno;
						flagSwap=1;
					}
				}
			}
			nuevoLimite--;
			retorno = 0;
		}while(flagSwap);
	}
	return retorno;
}

// Ejercicio 6, clase 10.
/* Realizar una funci�n que reciba el array y un �ndice, e imprima los datos del item
de esa posici�n, si es que tiene datos v�lidos. */
int alumno_printById(Alumno* pArray, int limite, int indice)
{
		int retorno = -1;
		if(pArray != NULL && limite > 0 && indice < limite)
		{
			if(pArray[indice].isEmpty == 0)
			{
				printf("Nombre: %s - Legajo: %d\n",pArray[indice].nombre, pArray[indice].legajo);
				retorno = 0;
			}
		}
		return retorno;
}

// Ejercicio 6, clase 10.
/* Realizar una funci�n que me devuelva el �ndice de un item vac�o, sin cargar, o
me devuelva -1 si no hay m�s vac�os o si hay error.
CORREGIR VIENDO FUNCION alumno_buscarLibreRef y alumno_buscarLibreValor
int alumno_itemVacio(Alumno* pArray, int limite)
{
		int retorno = -1;
		if(pArray != NULL && limite > 0)
		{
			for(int indice = 0;indice<limite;indice++)
			{
				if(pArray[indice].isEmpty == TRUE) // Se puede poner 1.
				{
					printf("�ndice: %d\n",pArray[indice]);
					retorno = 0;
				}
			}
		}
		return retorno;
} */

// Ejercicio 6, clase 10.
// Revisar c�mo llamar a esta funci�n en el word de la clase 10.
/* Realizar una funci�n que me devuelva el �ndice de un item vac�o, sin cargar, o
me devuelva -1 si no hay m�s vac�os o si hay error.
Hecho por referencia */
int alumno_buscarLibreRef(Alumno pArrayAlumnos[], int limite, int *pIndice)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && pIndice != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayAlumnos[i].isEmpty == TRUE) // Se puede poner 1.
			{
				*pIndice = i; // Escribo el �ndice en el puntero Index. Luego, cuando la funci�n sea llamada, en el argumento 3 la llamar� con el & creo.
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

// Ejercicio 6, clase 10.
// Revisar c�mo llamar a esta funci�n en el word de la clase 10.
/* Realizar una funci�n que me devuelva el �ndice de un item vac�o, sin cargar, o
me devuelva -1 si no hay m�s vac�os o si hay error.
Hecho por valor de retorno */
int alumno_buscarLibreValor(Alumno pArrayAlumnos[], int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArrayAlumnos[i].isEmpty == TRUE) // Se puede poner 1.
			{
				retorno = i; // Porque la funci�n debe devolver una posici�n del array donde el �ndice est� vac�o.
				break; // Hace un break para no seguir, ya encontr� 1 y listo, sale.
			}
		}
	}
	return retorno;
}

/* 8) Agregar al tipo de dato el campo ID que represente un identificador unico.
Modificar el codigo anterior para que el ID se genere automaticamente.
Se debera cargar el ID automaticamente al cargar un alumno, y
se debera imprimir al imprimir la lista.

Cada vez que llamo a esta funci�n me devuelve un ID nuevo que nunca me devolvi� antes.

Opci�n 1: definir ID en el main y pasarla por referencia a la funci�n de alta.
La funci�n debe usar el valor que tiene y luego incrementarlo.

Opci�n 2: con static int id = 0; // Variable global SOLO del archivo alumno.c.

Opci�n 3: con static int id = 0; // Pero esta vez DENTRO de la funci�n. Sigue siendo global pero solo la funci�n puede usarla. */

// Si le ponemos static a la FUNCION, la misma pasa a ser privada del archivo.
static int generarIdNuevo(void)
{
	static int id = 0;
	id = id+1;
	return id;
}

/* 9) Realizar una funcion que reciba el array y un ID,
y me devuelva el indice del item con dicho ID. (buscar por ID) */

int alumno_buscarId(Alumno* pArrayAlumnos, int limite, int *pIndice, int id)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && pIndice != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			// Si hay datos v�lidos adentro, o sea isEmpty FALSE.. && si el campo ID de ese elemento es igual al que vino como argumento en la funci�n, encontr� el ID que yo quer�a.
			if(pArrayAlumnos[i].isEmpty == FALSE && pArrayAlumnos[i].id == id)
			{
				*pIndice = i; // En la direcci�n de memoria que tiene pIndice escribo el valor de i.
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

// �C�mo usar la funci�n?
// Declaro la variable posicionBuscada...
//int posicionBuscada;

// Y llamo a la funci�n...

//int alumno_buscarId(alumnos, QTY_ALUMNOS, &posicionBuscada, IdQueQuiero)




