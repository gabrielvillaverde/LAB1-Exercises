/*
 * utn.c
 *
 *  Created on: 9 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE_BUFFER_STRING 5000

static int esNumerica(char* cadena);
static int esFlotante(char* cadena);
static int getInt(int* pResultado);
static int getFloat(float* pResultado);


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
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}

/**
 * \brief Verifica si la cadena ingresada es numerica, se encarga de obtener un n�mero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */

static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	// Llamo a la funci�n myGets y le paso "buffer": el lugar donde me va a dejar el string, y aparte le paso el tama�o (sizeof) para que no lo desborde.
    	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
    	{
    		// atoi lo que hace es convertir texto a n�mero
			*pResultado = atoi(buffer);
			retorno = 0;
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
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
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
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n", mensaje);
			fflush(stdin);
			// getInt() Pretende que yo le de un lugar donde dejarme el resultado. Aparte ya me devuelve si sali� bien o mal.
			// getInt() Tiene que asegurarme que si me devuelve un 0 es porque obtuvo un entero, si no puede obtener un entero, no me devuelve un 0.
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo) // La funci�n getInt le da el servicio de obtener el entero. Si es igual a 0 es que sali� todo bien, y adem�s debe ser mayor o igual al minimo, y menor o igual al maximo.
			{
				*pResultado = buffer;
				retorno = 0;
				break; // Si logre conseguir el n�mero que estaba buscando, tengo que cortar. Si no hago esto, ingresar�a el 1000 y seguir�a pidiendo n�meros.
			}
			reintentos--;
			printf("%s\n", mensajeError);
		}while(reintentos >= 0);
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

// Esta funci�n solicita un nombre al usuario
// El par�metro int limite indica la cantidad de letras m�xima del nombre.

int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING]; // Lo suficientemente grande para que el usuario se canse de escribir.
	int retorno = -1;

	// Limite > 0, al ser el l�mite mayor que 0 significa que el nombre tiene por lo menos 1 letra.
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0 && limite > 0)
	{
		do
		{
			printf("%s\n", mensaje);
			fflush(stdin);

			// Si resultadoScanf lee la m�scara, me dar� un 1, y si el tama�o de bufferString es menor o igual al limite, y...
			if(myGets(bufferString,LIMITE_BUFFER_STRING)==0 && strnlen(bufferString, sizeof(bufferString)-1) <= limite &&
				//Funci�n que recibe el nombre y me dice si es v�lido o no.
				esUnNombreValido(bufferString,limite) != 0) // Si es distinto de 0, es TODO lo verdadero. Recordar que en C, todo lo que no sea 0 es verdadero.
			{
				//Si entra ac�, es porque est� todo bien validado.
				retorno = 0;
				// NO EXISTE: pResultado = bufferString: MAAAAL!
				// Funci�n para copiar en pResultado lo que hay en bufferString (creo).
				strncpy(pResultado, bufferString, limite);
				break; // Si logre conseguir el n�mero que estaba buscando, tengo que cortar. Si no hago esto, ingresar�a el 1000 y seguir�a pidiendo n�meros.
			}
			else
			{
				printf("%s\n", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



// Esta funci�n verifica una cadena recibida como par�metro para determinar si es un nombre v�lido.
// Su primer par�metro es un array de caracteres, una cadena a analizar.
// Su segundo par�metro es un int, un l�mite a analizar. Indica la cantidad de letras m�xima de la cadena.
// El return (0) indica que no es un nombre v�lido.
// El return (!=0) indica que es un nombre v�lido.
int esUnNombreValido(char* cadena, int limite)
{
	int retorno = 1; // Arranca suponiendo que est� todo bien.

	// Ahora la funci�n empieza a buscar mugre, eval�a cada lugar de la variable para determinar si lo que est� ah� adentro est� bien.
	// Se pregunta si est� fuera del intervalo, si acepta alg�n caracter raro, etc.
	// El for lo utilizo para incrementar un �ndice.
	for(int i=0 ; i <= limite && cadena[i] != '\0'; i++) // Es importante no superar el l�mite, adem�s si encuentro un '\0' en la cadena no itero m�s.
	{
		// MAL <------ A - Z ------> MAL
		// Para que sea un error tiene que estar fuera del intervalo de A-Z, del a-z, y distinto de un punto (por poner un ejemplo es el punto, podr�a ser otra cosa).
		if( (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') && cadena[i] != '.') // Si est� fuera del intervalo... y adem�s soporta un punto, esta funci�n se puede ir editando para agregar /, o un espacio, o etc.
		{
			retorno = 0; // Me informa que est� todo mal.
			break; // Rompo el bucle de iteraci�n, en este caso el for.
		}
	}
	return retorno;
}

