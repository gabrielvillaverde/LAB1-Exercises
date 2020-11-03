/*
 * cliente.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "cliente.h"

// Llamo a esta función y me devuelve un elemento del tipo cliente
Cliente* cliente_new(void)
{
	Cliente* puntero; // Si tengo un puntero del tipo Cliente, luego voy a poder acceder a sus campos con -> y cargarle valores.
	puntero = (Cliente*)malloc(sizeof(Cliente)); // En "puntero" guardo la dirección de memoria de un cliente.

	if(puntero != NULL)
	{
		puntero->nombre[0] = '\0';
		puntero->apellido[0] = '\0';
		puntero->cuit[0] = '\0';
		puntero->idCliente = 0;
		return puntero;
	}
	else
		return NULL; // Es lo mismo que poner return puntero, porque si no encontró memoria, puntero también devolverá NULL.
}

Cliente* cliente_newConParametros(char* nombre, char* apellido, char* cuit, int idCliente)
{
	Cliente* puntero = NULL; // Inicializo el puntero a cliente como NULL.

	if(nombre != NULL && apellido != NULL && cuit != NULL && idCliente > 0)
	{
		puntero = (Cliente*)malloc(sizeof(Cliente));

		if(puntero != NULL)
		{
			strncpy(puntero->nombre, nombre, sizeof(puntero->nombre));
			strncpy(puntero->apellido, nombre, sizeof(puntero->apellido));
			strncpy(puntero->cuit, nombre, sizeof(puntero->cuit));
			puntero->idCliente = idCliente;
		}
	}
	return puntero;
}

void cliente_delete(Cliente* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int cliente_inicializarArrayPunteros(Cliente* arrayPunterosACliente[], int limitePunterosACliente)
{
	int retorno = -1;

	if(arrayPunterosACliente != NULL && limitePunterosACliente > 0)
	{
		for (int i = 0 ; i < limitePunterosACliente ; i++)
		{
			arrayPunterosACliente[i] = NULL; // Es lo mismo poner pArrayCliente[i] = 0;
		}
		retorno = 0;
	}
	return retorno;
}

int cliente_borrarIndiceArrayPunteros(Cliente* arrayPunterosACliente[], int limitePunterosACliente, int indiceArrayPunterosACliente)
{
	int retorno = -1;

	if(arrayPunterosACliente != NULL && indiceArrayPunterosACliente >= 0 && indiceArrayPunterosACliente < limitePunterosACliente && arrayPunterosACliente[indiceArrayPunterosACliente] != NULL)
	{
		{
			// free(arrayPunterosACliente[indiceArrayPunterosACliente]); Puedo hacer esto, o llamar a cliente_delete()
			cliente_delete(arrayPunterosACliente[indiceArrayPunterosACliente]);
			arrayPunterosACliente[indiceArrayPunterosACliente] = NULL; // En esa posición del array la igualo a NULL para que la próxima vez que la llame, pueda utilizarla para otra tarea.
		}
		retorno = 0;
	}
	return retorno;
}

int cliente_buscarIndiceLibreArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente)
{
	int retorno = -1;
	int i;

	if(arrayPunterosACliente != NULL && limitePunterosACliente > 0)
	{
		for(i = 0 ; i < limitePunterosACliente ; i++)
		{
			if(arrayPunterosACliente[i] == NULL) // Si la posición del array vale NULL es porque está libre.
			{
				retorno = i;
				break; // Hago un break porque no tiene sentido que siga iterando, ya encontré el lugar libre.
			}
		}
	}
	return retorno;
}

int cliente_buscarIndiceLibreArrayPunterosRef (Cliente* arrayPunterosACliente[], int limitePunterosACliente, int* pIndice)
{
	int retorno = -1;
	int i;

	if(arrayPunterosACliente != NULL && limitePunterosACliente > 0 && pIndice != NULL)
	{
		for(i = 0 ; i < limitePunterosACliente ; i++)
		{
			if(arrayPunterosACliente[i] == NULL)
			{
				*pIndice = i; // Retorno el valor por referencia.
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int cliente_altaArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente, int indice, int* idCliente)
{
	int retorno = -1;

	Cliente bufferAux; // La defino para guardar los datos que ingresa el usuario en cada uno de sus campos.
	Cliente* pC;

	if (arrayPunterosACliente != NULL && limitePunterosACliente > 0)
	{
		if (utn_getName("\nIngrese el nombre:\n", "Error, ingrese un nombre válido:\n", bufferAux.nombre, 2, SIZE_NOMBRE) == 0 &&
			utn_getName("\nIngrese el apellido:\n", "Error, ingrese un apellido válido.\n", bufferAux.apellido, 2, SIZE_APELLIDO) == 0 &&
			utn_getCuit("\nIngrese el CUIT:\n", "Error, ingrese un CUIT válido.\n", bufferAux.cuit, 2, SIZE_CUIT) == 0)
		{
			bufferAux.idCliente = *idCliente;
			pC = cliente_new();
			if(pC != NULL)
			{
				*pC = bufferAux; // Copia los campos de bufferAux en el área dinámica que me devolvió cliente_new, y a la que apunta pC.
				arrayPunterosACliente[indice] = pC; // Copio la dirección en el array de punteros
				(*idCliente)++;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int cliente_altaForzadaArrayPunterosACliente(Cliente* arrayPunterosACliente[])
{
    int retorno = -1;
    char bufferNombre[5][SIZE_NOMBRE] =      { "Jorge",          "Luis",          "Domingo",       "Machu",        "Marcos"      };
    char bufferApellido[5][SIZE_APELLIDO] =  { "Mendez",         "González",      "Sarmiento",     "Pichu",        "Papas"       };
    char bufferCuit[5][SIZE_CUIT] =          { "20336330972",    "20456787196",   "32689210751",   "29903221487",  "41107389873" };
    int bufferId[5] =                        { 100,              101,             102,             103,            104           };

    Cliente* puntero;

    if (arrayPunterosACliente != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
        	// 1) Construyo el cliente
        	puntero = cliente_newConParametros(bufferNombre[i], bufferApellido[i], bufferCuit[i], bufferId[i]);
        	// 2) Agrego el cliente al array
        	arrayPunterosACliente[i] = puntero;
        }
        retorno = 0;
    }
    return retorno;
}

int cliente_imprimirArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente)
{
	int retorno = -1;
	int i;

	if(arrayPunterosACliente != NULL && limitePunterosACliente > 0)
	{
		printf("\n---LISTA DE CLIENTES---\n");
		for(i = 0 ; i < limitePunterosACliente ; i++)
		{
			if(arrayPunterosACliente[i] != NULL) // Si hay un puntero a un cliente en esta posición...
			{
				printf("Nombre: %s - Apellido: %s - CUIT: %s - ID: %d\n", arrayPunterosACliente[i]->nombre, arrayPunterosACliente[i]->apellido, arrayPunterosACliente[i]->cuit, arrayPunterosACliente[i]->idCliente);
			}
		}
	}
	return retorno;
}

int cliente_buscarIndicePorIdArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente, int idBuscado)
{
	int retorno = -1;

	if(arrayPunterosACliente != NULL && limitePunterosACliente > 0 && idBuscado >= 0)
	{
		retorno = -2;
		for (int i = 0 ; i < limitePunterosACliente ; i++)
		{
			if(arrayPunterosACliente[i] != NULL && arrayPunterosACliente[i]->idCliente == idBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int cliente_borrarIndiceArrayPunterosPorId (Cliente* arrayPunterosACliente[], int limitePunterosACliente, int idBuscado)
{
	int retorno = -1;
	int indiceBorrar;

	if(arrayPunterosACliente != NULL && limitePunterosACliente > 0 && idBuscado >= 0)
	{
		indiceBorrar = cliente_buscarIndicePorIdArrayPunteros(arrayPunterosACliente, limitePunterosACliente, idBuscado);
		if(indiceBorrar >= 0)
		{
			if(cliente_borrarIndiceArrayPunteros(arrayPunterosACliente, limitePunterosACliente, indiceBorrar) == 0)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

int cliente_agregarClienteArrayPunteros (Cliente* arrayPunterosACliente[], int limitePunterosACliente, char* nombre, char* apellido, char* cuit, int idCliente)
{
	int retorno = -1;
	int indiceLibre;

	if (arrayPunterosACliente != NULL && limitePunterosACliente > 0 && nombre != NULL && apellido != NULL && cuit != NULL && idCliente >= 0)
	{
		indiceLibre = cliente_buscarIndiceLibreArrayPunteros(arrayPunterosACliente, limitePunterosACliente);
		if(indiceLibre >= 0)
		{
			arrayPunterosACliente[indiceLibre] = cliente_newConParametros(nombre, apellido, cuit, idCliente);
			retorno = indiceLibre;
		}
	}
	return retorno;
}

// SETTERS Y GETTERS DE CLIENTE

/**
* Función de set
* \param Cliente* this recibe el puntero a un cliente
* \param char* nombre recibe el nombre del cliente
* \return
*/
int cliente_setNombre(Cliente* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		if(utn_itIsAValidName(nombre, SIZE_NOMBRE))
		{
			strncpy(this->nombre, nombre, SIZE_NOMBRE);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* Función de get
* \param Cliente* this recibe el puntero a un cliente
* \param char* nombre recibe el nombre del cliente
* \return
*/
int cliente_getNombre(Cliente* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, SIZE_NOMBRE);
		retorno = 0;
	}
	return retorno;
}

/**
* Función de
* \param
* \param
* \return
*/
int cliente_setIdTxtCliente(Cliente* this, char* idCliente)
{
	int retorno = -1;

	if(this != NULL && idCliente != NULL)
	{
		if(isNumber(idCliente))
		{
			this->idCliente = atoi(idCliente); // Convierto el string que recibo de idCliente a entero.
			retorno = 0;
		}
	}
	return retorno;
}

/**
* Función de
* \param
* \param
* \return
*/
int cliente_getIdTxtCliente(Cliente* this, char* idCliente)
{
	int retorno = -1;

	if(this != NULL && idCliente != NULL)
	{
		if(isNumber(idCliente))
		{
			sprintf(idCliente, "%d", this->idCliente);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* Función de
* \param
* \param
* \return
*/
int cliente_setIdNumCliente(Cliente* this, int idCliente)
{
	int retorno = -1;

	if(this != NULL && idCliente >= 0)
	{
		this->idCliente = idCliente;
		retorno = 0;
	}
	return retorno;
}

































// FUNCIONES VIEJAS: SIN MEMORIA DINAMICA //

static int cliente_generarNuevoId (void); // Prototipo

/**
* Función que genera un nuevo ID para cada cliente.
* \return ID del cliente.
*/
static int cliente_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

/**
* Función que inicializa el array de clientes
* \param pArrayCliente, recibe el array de clientes.
* \param limiteCliente, recibe el limite de los clientes.
* \return (-1) ERROR / 0 OK
*/
int cliente_init(Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		for (int i = 0 ; i < limiteCliente ; i++)
		{
			pArrayCliente[i].isEmpty = TRUE; // Indico que están vacías TODAS las posiciones del array de clientes.
		}
		retorno = 0;
	}
	return retorno;
}

/**
* Función que da de alta un cliente
* \param pArrayCliente, recibe el array de clientes.
* \param limiteCliente, recibe el limite de los clientes.
* \return (-1) ERROR / 0 OK
*/
int cliente_alta (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int indice;

	Cliente bufferCliente; // Creo una variable auxiliar del tipo de dato Cliente, para cargar los datos que obtendré más abajo y guardarlos en bufferCliente.

	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		if (cliente_buscarLibreRef (pArrayCliente, limiteCliente, &indice) == 0) // Si encontré un lugar libre en el array de clientes...
		{
			if (utn_getName("\nIngrese el nombre:\n", "Error, ingrese un nombre válido:\n", bufferCliente.nombre, 2, SIZE_NOMBRE) == 0 && // Le solicito los datos al usuario y los guardo en cada campo de bufferCliente.
				utn_getName("\nIngrese el apellido:\n", "Error, ingrese un apellido válido.\n", bufferCliente.apellido, 2, SIZE_APELLIDO) == 0 &&
				utn_getCuit("\nIngrese el CUIT:\n", "Error, ingrese un CUIT válido.\n", bufferCliente.cuit, 2, SIZE_CUIT) == 0)
			{	// Si obtuve los datos...
				pArrayCliente[indice] = bufferCliente; // DEEP COPY: Asigno los valores de bufferCliente en la posición del índice correspondiente.
				pArrayCliente[indice].idCliente = cliente_generarNuevoId(); // Genero un nuevo ID correspondiente a ese índice.
				printf("\nEl ID generado para este cliente es el: %d\n", pArrayCliente[indice].idCliente); // Muestro por consola el ID que se generó para ese cliente.
				pArrayCliente[indice].isEmpty = FALSE; // Indico que dicha posición ya no está vacía.
				printf("\nSe ha cargado el cliente correctamente.\n");
				retorno = 0;
			}
		}
		else
		{
			printf("\nNo se pueden cargar más clientes.\n");
		}
	}
	return retorno;
}

/**
* Función de hardcode. Obligo a mi programa a que inicialice con valores cargados por mí previamente.
* \param pArrayCliente, recibe el array de clientes.
* \param limiteCliente, recibe el limite de los clientes.
* \param nombre, recibe el nombre del cliente
* \param apellido, recibe el apellido del cliente
* \param cuit, recibe el cuit del cliente
* \return (-1) ERROR / 0 OK
*/
int cliente_altaForzada(Cliente * pArrayCliente, int limiteCliente, char * nombre, char * apellido, char * cuit)
{
	int retorno = -1;
	int indice;

	if(cliente_buscarLibreRef(pArrayCliente, limiteCliente, &indice) == 0) // Si hay un lugar libre en mi array de clientes...
	{
		strncpy(pArrayCliente[indice].nombre, nombre, SIZE_NOMBRE); // Uso la función de strncpy para copiar en el índice del array de clientes, el nombre, apellido y CUIT.
		strncpy(pArrayCliente[indice].apellido, apellido, SIZE_APELLIDO);
		strncpy(pArrayCliente[indice].cuit, cuit, SIZE_CUIT);
		pArrayCliente[indice].idCliente = cliente_generarNuevoId(); // Genero un nuevo ID.
		pArrayCliente[indice].isEmpty = FALSE; // Indico que ese índice ya no está vacío.
		retorno = 0;
	}
	return retorno;
}

/**
* Función que da de baja un cliente
* \param pArrayCliente, recibe el array de clientes.
* \param limiteCliente, recibe el limite de los clientes.
* \return (-1) ERROR / 0 OK
*/

int cliente_baja (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;
	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		printf("\nA continuación se listan los clientes que usted puede borrar:\n");
		cliente_imprimir(pArrayCliente, limiteCliente);
		if(utn_getNumberInt("\nIngrese ID del cliente que quiere borrar:\n","\nError.\n",&idABorrar,2,0,9999)==0)
		{
			// Busco la posición que quiero borrar
			if(cliente_buscarIndicePorId(pArrayCliente,limiteCliente,idABorrar,&indiceABorrar)==0)
			{
				// Borro esa posición
				pArrayCliente[indiceABorrar].isEmpty = TRUE; // Método de baja lógica, simplemente cambio el valor de este campo.
				printf("\nSe ha dado de baja el cliente correctamente.\n");
			}
			else
			{
				printf("\nEse ID no existe.\n");
			}
		}
	}
	return retorno;
}


/**
* Función que modifica los clientes
* \param pArrayCliente, recibe el array de clientes.
* \param limiteCliente, recibe el limite de los clientes.
* \return (-1) ERROR / 0 OK
*/
int cliente_modificar (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idBuscado;
	int indiceAModificar;

	Cliente bufferCliente; // Me creo una variable auxiliar del tipo de dato Cliente, donde voy a guardar luego los datos que solicito al usuario para modificar los campos correspondientes.
	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		printf("\nA continuación se listan los clientes que usted puede modificar:\n");
		cliente_imprimir(pArrayCliente, limiteCliente); // Llamo a la función para modificar clientes.

		if(utn_getNumberInt("\nIngrese el ID del cliente que desea modificar:\n","\nError.\n",&idBuscado,2,0,9999) == 0) // Llamo a la función que obtiene un número para guardarme el ID en idBuscado.
		{
			if(cliente_buscarIndicePorId(pArrayCliente, limiteCliente,idBuscado,&indiceAModificar) == 0) // Llamo a la función que busca el índice a modificar por ID. Recibe el ID buscado que obtuvo la función getNumberInt y devuelve el índice por valor de referencia.
			{
				bufferCliente = pArrayCliente[indiceAModificar]; // Me guardo en mi variable auxiliar bufferCliente el índice que voy a modificar del array de clientes.

				if (utn_getName("\nIngrese el nuevo nombre:\n", "Error, ingrese un nombre válido:\n", bufferCliente.nombre, 2, SIZE_NOMBRE) == 0 && // Le pido los datos al usuario y los voy guardando en bufferCliente.
					utn_getName("\nIngrese el nuevo apellido:\n", "Error, ingrese un apellido válido.\n", bufferCliente.apellido, 2, SIZE_APELLIDO) == 0 &&
					utn_getCuit("\nIngrese el nuevo CUIT:\n", "Error, ingrese un CUIT válido.\n", bufferCliente.cuit, 2, SIZE_CUIT) == 0)
				{
					pArrayCliente[indiceAModificar] = bufferCliente; // Copio en el índice a modificar del array lo que contiene bufferCliente ya con los datos nuevos.
					printf("\nCliente modificado correctamente.\n");
					retorno = 0;
				}
			}
			else
			{
				printf("\nEse ID no existe.\n");
			}
		}
	}
	return retorno;
}

/**
* Función que imprime los clientes
* \param pArrayCliente, recibe el array de clientes.
* \param limiteCliente, recibe el limite de los clientes.
* \return (-1) ERROR / 0 OK
*/
int cliente_imprimir (Cliente * pArrayCliente , int limiteCliente)
{
	int retorno = -1;

	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		for (int i = 0 ; i < limiteCliente ; i++) // Recorro el array de clientes
		{
			if(pArrayCliente[i].isEmpty == FALSE) // Si la posición "i" del array de clientes NO está vacía...
			{
				// Estoy en condiciones de poder imprimir cada elemento del tipo de dato Cliente.
				printf("\nID: %d - Nombre del cliente: %s - Apellido del cliente: %s - CUIT: %s\n",pArrayCliente[i].idCliente,pArrayCliente[i].nombre, pArrayCliente[i].apellido, pArrayCliente[i].cuit);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
* Función que busca un lugar libre en el array de clientes, devuelve el índice por valor de retorno.
* \param pArrayCliente, recibe el array de clientes.
* \param limiteCliente, recibe el limite de los clientes.
* \return (-1) ERROR / 0 OK
*/
int cliente_buscarLibre (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int i;

	if (pArrayCliente != NULL && limiteCliente > 0)
	{
		for ( i = 0 ; i < limiteCliente ; i++)
		{
			if(pArrayCliente[i].isEmpty == TRUE)
			{
				retorno = i; // Retorno por valor.
				break;
			}
		}
	}
	return retorno;
}

/**
* Función que busca un lugar libre en el array de clientes, devuelve el valor por referencia
* \param pArrayCliente, recibe el array de clientes.
* \param limiteCliente, recibe el limite de los clientes.
* \param pIndice, es el puntero al índice que se está buscando, devuelve el índice por valor de referencia.
* \return (-1) ERROR / 0 OK
*/
int cliente_buscarLibreRef (Cliente * pArrayCliente, int limiteCliente, int * pIndice)
{
	int retorno = -1;
	int i;

	if (pArrayCliente != NULL && limiteCliente > 0 && pIndice != NULL)
	{
		for (i = 0 ; i < limiteCliente ; i++)
		{
			if(pArrayCliente[i].isEmpty == TRUE) // Si el elemento i en el array de clientes está vacío...
			{
				*pIndice = i; // Retorno el valor por referencia.
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
* Función que busca el índice en el array de clientes por ID del cliente.
* \param pArrayCliente, recibe el array de clientes.
* \param limiteCliente, recibe el limite de los clientes.
* \param idBuscado, recibe el ID del cliente que se está buscando.
* \param pIndice, es el puntero al índice que se está buscando, devuelve el índice por valor de referencia.
* \return (-1) ERROR / 0 OK
*/
int cliente_buscarIndicePorId (Cliente * pArrayCliente, int limiteCliente, int idBuscado, int * pIndice)
{
	int retorno = -1;
	int i;

	if (pArrayCliente != NULL && limiteCliente > 0 && pIndice != NULL && idBuscado >= 0)
	{
		for (i = 0 ; i < limiteCliente ; i++) // Recorro el array de clientes
		{
			if(pArrayCliente[i].isEmpty == FALSE && pArrayCliente[i].idCliente == idBuscado) // Si la posición i del array no está vacía, y además coincide en el campo idCliente con el idBuscado...
			{
				*pIndice = i; // Devuelvo el índice por valor de referencia.
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*int cliente_ordenarPorNombre (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int flagSwap;
	int indiceCliente;
	Cliente bufferAuxiliar;
	if(pArrayCliente != NULL && limiteCliente > 0)
	{
		do
		{
			flagSwap = 0;
			for(indiceCliente = 0 ; indiceCliente < limiteCliente-1 ; indiceCliente++)
			{
				if(strncmp(pArrayCliente[indiceCliente].nombre, pArrayCliente[indiceCliente+1].nombre, SIZE_NOMBRE) > 0)
				{
					flagSwap = 1;
					bufferAuxiliar = pArrayCliente[indiceCliente];
					pArrayCliente[indiceCliente] = pArrayCliente[indiceCliente+1];
					pArrayCliente[indiceCliente+1] = bufferAuxiliar;
				}
			}
			limiteCliente--;
		}while(flagSwap);
	}
	return retorno;
}*/


/*int cliente_ordenarPorNombreLuegoPorId (Cliente * pArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int flagSwap;
	int indiceCliente;
	Cliente bufferAuxiliar;
	if(pArrayCliente != NULL && limiteCliente > 0)
	{
		do
		{
			flagSwap = 0;
			for(indiceCliente = 0 ; indiceCliente < limiteCliente-1 ; indiceCliente++)
			{
				if(strncmp(pArrayCliente[indiceCliente].nombre, pArrayCliente[indiceCliente+1].nombre, SIZE_NOMBRE) > 0)
				{
					flagSwap = 1;
					bufferAuxiliar = pArrayCliente[indiceCliente];
					pArrayCliente[indiceCliente] = pArrayCliente[indiceCliente+1];
					pArrayCliente[indiceCliente+1] = bufferAuxiliar;
				}
				else if(strncmp(pArrayCliente[indiceCliente].nombre, pArrayCliente[indiceCliente+1].nombre, SIZE_NOMBRE) == 0 &&
						pArrayCliente[indiceCliente].idCliente < pArrayCliente[indiceCliente+1].idCliente)
				{
					{
						flagSwap = 1;
						bufferAuxiliar = pArrayCliente[indiceCliente];
						pArrayCliente[indiceCliente] = pArrayCliente[indiceCliente+1];
						pArrayCliente[indiceCliente+1] = bufferAuxiliar;
					}
				}
			}
			limiteCliente--;
		}while(flagSwap);
	}
	return retorno;
}
*/


