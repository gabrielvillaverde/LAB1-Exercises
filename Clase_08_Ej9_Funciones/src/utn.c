/*
 * utn.c
 *
 *  Created on: 9 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getFloat(float* pResultado);
static int esFlotante(char* cadena);

static int getInt(int* pResultado);
// Primera manera: static int esNumerica(char* cadena);
static int esNumerica(char* cadena, int limite);


/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un m�ximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tama�o de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */

int myGets(char* cadena, int longitud)
{
	// Chequeo que cadena sea distinto de NULL (siempre valido punteros).
	// Chequeo que la longitud sea positiva, es decir, mayor a 0. �Para qu� quiero una longitud de 0 o negativa?
	// fgets recibe tres par�metros: 1� Par�metro: espacio de memoria en el cu�l quiero que me deje el resultado.
	                              // 2� Par�metro: cantidad de caracteres que quiere recibir, el tama�o.
	                              // 3� Par�metro: el archivo de texto de donde va a sacar la informaci�n: por ahora es stdin.
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin); // Lo que hace es limpiar, me aseguro de que no hay nada y que lo que voy a leer es lo que ingresar� el usuario a continuaci�n.

		// La explicaci�n de esto est� en el video de la clase 8, parte 1, minuto 1:10:00 aprox.
		if(cadena[strlen(cadena)-1] == '\n') // Me pregunto si en el tama�o total de la cadena menos 1 hay un \n (un enter)...
		{
			cadena[strlen(cadena)-1] = '\0'; // ...lo piso con un \0.
		}
		return 0;
	}
	return -1;
}

/*
// Segunda manera de hacer la funci�n myGets, la de Mauricio.

int myGets(char* cadena, int longitud)
// myGets recibe una cadena y una longitud.
// Uso strlen porque strnlen no me lo toma.
{
	int retorno = -1;
	char bufferString[4096]; // Parte asquerosa del c�digo hasta que trabajemos con memoria din�mica.

	// Chequeo que recib� un puntero, es decir, que sea distinto de NULL.
	// Chequeo que la longitud sea positiva.
	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin); // Limpio el stdin, si alguien hab�a dejado algo ah�, ya no est� m�s. Est� limpio.
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL) // Voy a leer en stdin hasta que el usuario ingresa un enter, o hasta que se llega al l�mite de bufferString.
		{
			if(bufferString[strlen(bufferString)-1] == '\n') // Me pregunto si en el tama�o total de la cadena menos 1 hay un \n (un enter)...
			{
				bufferString[strlen(bufferString)-1] = '\0'; // ...lo piso con un \0.
			}
			// Si la cadena resultante es menor o igual a longitud, reci�n ah� lo copio en el puntero de cadena.
			if(strlen(bufferString) <= longitud) // Dicho de otro modo, si la longitud resultante de la cadena que acabo de obtener es menor o igual a la longitud...
			{
				// Copio el string, cadena es el destino a donde voy a copiar, bufferString es el origen, y la longitud marca el l�mite.
				strncpy(cadena, bufferString, longitud);
				// Reci�n ac� estoy en condiciones de confirmar que est� todo bien, cuando pude copiar la cadena.
				retorno = 0;
			}
		}
	}
	return retorno;
}
*/



static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[50]; // Genero un buffer string, porque esta funci�n debe obtener un string y convertirlo a entero (creo).

    if(pResultado != NULL) // Como la funci�n recibe un puntero, siempre lo validamos.
    {
    	// Llamo a la funci�n myGets y le paso "bufferString": el lugar donde me va a dejar el string, y aparte le paso el tama�o/longitud (sizeof) para que no lo desborde.
    	// Tambi�n llamo a la funci�n esNumerica que me indica si el string obtenido es num�rico.
    	if( myGets(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString,sizeof(bufferString)) )
    	{
    		// Le asigno al puntero pResultado el valor de bufferString.
			*pResultado = atoi(bufferString); // atoi lo que hace es convertir texto a n�mero
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *

static int esNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
 */

/*
// Segunda manera de hacer la funci�n esNumerica, la de Mauricio
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // Arranco retornando un error.
	int i;

	// Valido el puntero y que el l�mite sea mayor a 0.
	if(cadena != NULL && limite > 0)
	{
		// Si llegu� hasta ac�, es porque se valid� que recibi� algo.
		retorno = 1; // Retorno verdadero.
		// Voy a iterar mientras que no me haya pasado del l�mite, y no me haya topado con un \0.
		for(i = 0; i<limite && cadena[i] != '\0' ; i++)
		{
			// Caso particular: para validar n�meros del tipo +100 o -100...
			// Si la i est� en la posici�n 0 y en esa posici�n de la cadena hay un - o un +...
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue; // ...continue obliga a seguir iterando, va de nuevo a ejecutar el for.
			}
			if(cadena[i] < '0' || cadena[i] > '9' ) // Si es menor que 0 y mayor que 9 no es un n�mero...
			{
				retorno = 0; // ...entonces el retorno ser� falso, porque la funci�n no encontr� un n�mero.
				break; // Y pongo un break porque quiero dejar de iterar.
			}
			/* A este lugar me envia el continue. */
		}
	}

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	// myGets se utiliza para obtener el string, y esFlotante verifica si es flotante o no.
    	if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
    		// Con atof convertiremos un string validado en un flotante.
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1; // Arrancamos presuponiendo que lo que nos pasaron es un n�mero flotante.
	int contadorPuntos = 0;

	// Validamos que no sea null y que la cadena tenga algo adentro.
	if(cadena != NULL && strlen(cadena) > 0)
	{
		// For que itera mientras que la posici�n actual de cadena no sea un \0
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			// Si cadena est� fuera del rango del 0 y el 9...
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				// Si en la posici�n de cadena 'i' detect� un punto, y si todav�a el contador de puntos es igual a 0.
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					// Voy aumentando el contador de puntos, la pr�xima vez que haya m�s de un punto saltear� el if de arriba e ir� al else, ya que habr�a m�s de 1 punto.
					contadorPuntos++;
				}
				else // La falla la detectar� ac�.
				{
					retorno = 0;
					break;
				}

			}
		}
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do // Hacer... --->
		{
			printf("%s\n", mensaje); // Imprimo un mensaje para solicitar el n�mero.
			fflush(stdin); // Limpio stdin.
			// getInt() Pretende que yo le de un lugar donde dejarme el resultado. Aparte ya me devuelve si sali� bien o mal.
			// getInt() Tiene que asegurarme que si me devuelve un 0 es porque obtuvo un entero, si no puede obtener un entero, no me devuelve un 0.
			// getInt obtiene un entero, y le pasamos la direcci�n de memoria de la variable bufferInt. Si es igual a 0 es que sali� bien.
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo) // La variable bufferInt debe ser mayor o igual al minimo, y menor o igual al maximo.
			{
				retorno = 0;
				*pResultado = bufferInt; // Le asigno al puntero pResultado lo que hay en bufferInt.
				break; // Si logre conseguir el n�mero que estaba buscando, tengo que cortar.
			}
			printf("%s\n", mensajeError);
			reintentos--;
		}while(reintentos >= 0); // ---> ...mientras que haya reintentos.
	}
	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0) // Mientras que queden reintentos...
	{
		reintentos--; // ...en cada pasada decrementa la cantidad de reintentos.
		printf("%s",mensaje); // Imprime un mensaje.
		if(getFloat(&bufferFloat) == 0) // Con la funci�n getFloat sale a buscar ese n�mero
		{
			// Verifico que est� dentro del rango que me hayan pasado como par�metro
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				// Si est� todo bien en el if de arriba, estoy en condiciones de devolver el resultado.
				*pResultado = bufferFloat; // Copio el resultado de bufferFloat en el puntero *pResultado
				retorno = 0; // Retorno lo pongo en 0 para indicar que sali� bien.
				break; // ...y rompo la iteraci�n.
			}
		}
		// Si la validaci�n del if no se da, voy a imprimir el mensaje de error mientras queden intentos.
		printf("%s",mensajeError);
	}
	return retorno;
}
