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
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */

int myGets(char* cadena, int longitud)
{
	// Chequeo que cadena sea distinto de NULL (siempre valido punteros).
	// Chequeo que la longitud sea positiva, es decir, mayor a 0. ¿Para qué quiero una longitud de 0 o negativa?
	// fgets recibe tres parámetros: 1° Parámetro: espacio de memoria en el cuál quiero que me deje el resultado.
	                              // 2° Parámetro: cantidad de caracteres que quiere recibir, el tamaño.
	                              // 3° Parámetro: el archivo de texto de donde va a sacar la información: por ahora es stdin.
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin); // Lo que hace es limpiar, me aseguro de que no hay nada y que lo que voy a leer es lo que ingresará el usuario a continuación.
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}

/**
 * \brief Verifica si la cadena ingresada es numerica, se encarga de obtener un número entero
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
    	// Llamo a la función myGets y le paso "buffer": el lugar donde me va a dejar el string, y aparte le paso el tamaño (sizeof) para que no lo desborde.
    	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
    	{
    		// atoi lo que hace es convertir texto a número
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
	int retorno = 1; // Arrancamos presuponiendo que lo que nos pasaron es un número flotante.
	int contadorPuntos = 0;

	// Validamos que no sea null y que la cadena tenga algo adentro.
	if(cadena != NULL && strlen(cadena) > 0)
	{
		// For que itera mientras que la posición actual de cadena no sea un \0
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			// Si cadena está fuera del rango del 0 y el 9...
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				// Si en la posición de cadena 'i' detecté un punto, y si todavía el contador de puntos es igual a 0.
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					// Voy aumentando el contador de puntos, la próxima vez que haya más de un punto salteará el if de arriba e irá al else, ya que habría más de 1 punto.
					contadorPuntos++;
				}
				else // La falla la detectaré acá.
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
			// getInt() Pretende que yo le de un lugar donde dejarme el resultado. Aparte ya me devuelve si salió bien o mal.
			// getInt() Tiene que asegurarme que si me devuelve un 0 es porque obtuvo un entero, si no puede obtener un entero, no me devuelve un 0.
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo) // La función getInt le da el servicio de obtener el entero. Si es igual a 0 es que salió todo bien, y además debe ser mayor o igual al minimo, y menor o igual al maximo.
			{
				*pResultado = buffer;
				retorno = 0;
				break; // Si logre conseguir el número que estaba buscando, tengo que cortar. Si no hago esto, ingresaría el 1000 y seguiría pidiendo números.
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
		if(getFloat(&bufferFloat) == 0) // Con la función getFloat sale a buscar ese número
		{
			// Verifico que esté dentro del rango que me hayan pasado como parámetro
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				// Si está todo bien en el if de arriba, estoy en condiciones de devolver el resultado.
				*pResultado = bufferFloat; // Copio el resultado de bufferFloat en el puntero *pResultado
				retorno = 0; // Retorno lo pongo en 0 para indicar que salió bien.
				break; // ...y rompo la iteración.
			}
		}
		// Si la validación del if no se da, voy a imprimir el mensaje de error mientras queden intentos.
		printf("%s",mensajeError);
	}
	return retorno;
}

// Esta función solicita un nombre al usuario
// El parámetro int limite indica la cantidad de letras máxima del nombre.

int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING]; // Lo suficientemente grande para que el usuario se canse de escribir.
	int retorno = -1;

	// Limite > 0, al ser el límite mayor que 0 significa que el nombre tiene por lo menos 1 letra.
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0 && limite > 0)
	{
		do
		{
			printf("%s\n", mensaje);
			fflush(stdin);

			// Si resultadoScanf lee la máscara, me dará un 1, y si el tamaño de bufferString es menor o igual al limite, y...
			if(myGets(bufferString,LIMITE_BUFFER_STRING)==0 && strnlen(bufferString, sizeof(bufferString)-1) <= limite &&
				//Función que recibe el nombre y me dice si es válido o no.
				esUnNombreValido(bufferString,limite) != 0) // Si es distinto de 0, es TODO lo verdadero. Recordar que en C, todo lo que no sea 0 es verdadero.
			{
				//Si entra acá, es porque está todo bien validado.
				retorno = 0;
				// NO EXISTE: pResultado = bufferString: MAAAAL!
				// Función para copiar en pResultado lo que hay en bufferString (creo).
				strncpy(pResultado, bufferString, limite);
				break; // Si logre conseguir el número que estaba buscando, tengo que cortar. Si no hago esto, ingresaría el 1000 y seguiría pidiendo números.
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



// Esta función verifica una cadena recibida como parámetro para determinar si es un nombre válido.
// Su primer parámetro es un array de caracteres, una cadena a analizar.
// Su segundo parámetro es un int, un límite a analizar. Indica la cantidad de letras máxima de la cadena.
// El return (0) indica que no es un nombre válido.
// El return (!=0) indica que es un nombre válido.
int esUnNombreValido(char* cadena, int limite)
{
	int retorno = 1; // Arranca suponiendo que está todo bien.

	// Ahora la función empieza a buscar mugre, evalúa cada lugar de la variable para determinar si lo que está ahí adentro está bien.
	// Se pregunta si está fuera del intervalo, si acepta algún caracter raro, etc.
	// El for lo utilizo para incrementar un índice.
	for(int i=0 ; i <= limite && cadena[i] != '\0'; i++) // Es importante no superar el límite, además si encuentro un '\0' en la cadena no itero más.
	{
		// MAL <------ A - Z ------> MAL
		// Para que sea un error tiene que estar fuera del intervalo de A-Z, del a-z, y distinto de un punto (por poner un ejemplo es el punto, podría ser otra cosa).
		if( (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') && cadena[i] != '.') // Si está fuera del intervalo... y además soporta un punto, esta función se puede ir editando para agregar /, o un espacio, o etc.
		{
			retorno = 0; // Me informa que está todo mal.
			break; // Rompo el bucle de iteración, en este caso el for.
		}
	}
	return retorno;
}

