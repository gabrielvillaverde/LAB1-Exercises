/*
 * utn.c
 *
 *  Created on: 9 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int getInt(int* pResultado);
static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);

// Funciones estáticas:
// Static es como si la función fuese de uso SOLAMENTE para el archivo utn.c, y no se puede llamar desde el main por ejemplo. Además su prototipo no hay que declararlo en el .h, hacerlo arriba de todo en el .c como prototipo.

// Busca como resultado un entero
// Llama a la que obtiene un string cualquiera de la terminal
static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096]; // Lo declaro así de grande para asegurarme de que el usuario ingresará menos caracteres que esa cantidad.

	fflush(stdin);
	// Llamo a la función myGets y le paso el buffer y el tamaño que no quiero desbordar.
	if(myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer)) // Si myGets me devuelve un 0 es porque lo que la mandé a hacer lo hizo bien, y además si es numérica, entro al código. La función esNumerica me indica que lo que hay en buffer son solamente números.
	{ // Si son números...
		retorno = 0; // Todo OK.
		*pResultado = atoi(buffer); // ...los puedo convertir. Con atoi convierto texto en un entero. Cuando una cadena contiene solamente números, la transforma en un entero. atoi transforma un array de strings a entero.
		// La función atoi convierte un array de caracteres (una cadena, un string), en un número entero.
		// Si ingresas el texto "10", te lo convierte en el entero 10.
	}
	return retorno;
}

// Como esta función, haremos muchas del tipo esUnNickName, esDNI, etc...
// Verifica que en la cadena haya números.
// Este tipo de función devuelve verdadero (1) o falso (0).
static int esNumerica(char* cadena) // Determina si una cadena de texto contiene solamente números.
{
	int retorno = 1; // Inicializo el retorno en 1, VERDADERO.
	int i = 0;

	// CASO PARTICULAR:
	// Si estoy en la primer posición del array, es válido tener un número negativo, pero SOLO en la primera, por eso hago el if a continuación:

	if(cadena[0] == '-') // Si cadena en la posición 0 es igual a un negativo...
	{
		i = 1; // ...haremos que la cuenta arranque a partir de uno.
	}
	// Tengo que iterar hasta el \0.
	for( ; cadena[i] != '\0' ; i++) // Mientras que cadena en posición i sea distinto a \0, que siga iterando e incrementando la i.
	{ // Si es distinto a \0, entro al for.
		if(cadena[i] > '9' || cadena[i] < 0) // Si cadena en la posición i, estoy en ERROR. Si lo que encontré en la cadena es más grande que 9, rompo, si lo que encontré es más chico que 0, rompo.
		{
			retorno = 0; // Coloco el retorno en 0, o sea FALSO.
			break; // Y hago un break.
		}
	}
	return retorno;
}

// stdin es un archivo y nosotros vamos a leer el flujo de información que pasa por ese archivo.
// fgets leemos el string de un archivo.
// Le paso la cadena dnode quiero dejar la info
// cuantos caracteres quiero leer de ese archivo
// puntero al archivo, en este caso stdin

// Permite pasar una cadena, siempre le pasamos un string. Tiene sentido que le pasemos una longitud.
static int myGets(char* cadena, int longitud)
{
	fflush(stdin); // Sino no funciona, no sé por qué.
	// fgets nos permite leer de un archivo una cadena de caracteres.
	// Leo del stdin una cadena de caracteres.
	// Como primer parámetro quiere saber dónde dejar la información, como segundo parámetro quiere la longitud, y como tercero quiere saber de dónde leer, en este caso stdin.
	fgets(cadena, longitud, stdin);
	// Preguntamos cuánto mide la cadena, y en la posición anterior a la última ponemos el \0 y pisamos el ENTER.
	// Así logramos que la función se comporte como hacía el scanf.
	cadena[strlen(cadena)-1] = '\0';
	// strncpy guarda el destino, el origen y el tamaño que no puedo desbordar.
	// strncpy(cadena, buffer, longitud);
	return 0;
}

int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar; // Variable de intercambio con el usuario, donde leeré y guardaré el dato que el usuario ingresa.

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do // Me asegura que la primera vez se va a cumplir aunque reintentos venga cargado en 0.
		{
			printf("%s", mensaje); // Recibo un dato string, el mensaje del usuario.
			fflush(stdin); // __fpurge(stdin); en Linux. Esto va siempre antes de la lectura del scanf.
			scanf("%c", &bufferChar); // Leo lo que recibo del usuario, y lo asigno a la dirección de memoria de bufferInt.
			if(bufferChar >= minimo && bufferChar <= maximo) // Si lo que hay dentro de bufferInt es mayor/igual al mínimo, y menor/igual al máximo...
			{
				retorno = 0; // Salió todo bien, por eso el retorno devuelve 0.
				*pResultado = bufferChar; // Le asigno al puntero, lo que hay en bufferInt.
				break; // Esto haría que deje de reintentar con la segunda forma.
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--; // Si viene en 1, lo decremento y sería mayor o igual a 0.
			}
		}while(reintentos >= 0);
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

int utn_getFloat(float *pResultado, char *mensaje,char *mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	float bufferFloat;
	int i;

	for(i=0 ; i<=reintentos; i++)
	{
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}

int calcularMayor(int* pResultado, int n1, int n2)
{
	int retorno = 0; // Inicialmente retorna 0.
	if(pResultado != NULL) // Primero chequea que el puntero sea válido y no apunte a NULL, que no tenga dirección de memoria inválida, en ese caso no puedo hacer nada.
	{
		if(n1 == n2) // Primero compara si son iguales.
		{
			retorno = 0; // Si son iguales, retorna 0.
		}
		else // En el caso de que no sean iguales...
		{
			if(n1>n2) // Si el número 1 es mayor...
			{
				*pResultado = n1; // ...entra acá.
			}
			else // Si el mayor es el número 2...
			{
				*pResultado = n2; // ...entra acá.
			}
			retorno = 1; // En este caso, la variable de retorno es 1 porque así lo pide la consigna.
		}
	}
	return retorno;
}

int calcularMaximo(/* Modo profesional: int *pArray */int pArray [], int cantidadElementos, int *pResultado)
{
	int retorno = -1; // Siempre primero hacer el retorno
	int maximo;
	// Luego, verificar qué es lo que recibimos
	if(pArray != NULL && cantidadElementos > 0 && pResultado != NULL)
	{
		// Acá escribir lo que haga falta para imprimir por pantalla cual es el máximo. Hacer la función del maximo.
		for(int i = 0; i < cantidadElementos; i++) // Mientras que, estando en la posición
		{
			// Preguntarme ante qué condiciones se encontró el nuevo máximo
			if(i == 0 || pArray[i] > maximo) // Si en la posición del array i hay un número que es más grande que el máximo, y la variable i es igual a 0...
			{
				maximo = pArray[i]; // ...en máximo guardo lo que tiene el array en esa posición.
			}
		}
		*pResultado = maximo;
		retorno = 0; // Está todo OK
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
