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

// Funciones est�ticas:
// Static es como si la funci�n fuese de uso SOLAMENTE para el archivo utn.c, y no se puede llamar desde el main por ejemplo. Adem�s su prototipo no hay que declararlo en el .h, hacerlo arriba de todo en el .c como prototipo.

// Busca como resultado un entero
// Llama a la que obtiene un string cualquiera de la terminal
static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096]; // Lo declaro as� de grande para asegurarme de que el usuario ingresar� menos caracteres que esa cantidad.

	fflush(stdin);
	// Llamo a la funci�n myGets y le paso el buffer y el tama�o que no quiero desbordar.
	if(myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer)) // Si myGets me devuelve un 0 es porque lo que la mand� a hacer lo hizo bien, y adem�s si es num�rica, entro al c�digo. La funci�n esNumerica me indica que lo que hay en buffer son solamente n�meros.
	{ // Si son n�meros...
		retorno = 0; // Todo OK.
		*pResultado = atoi(buffer); // ...los puedo convertir. Con atoi convierto texto en un entero. Cuando una cadena contiene solamente n�meros, la transforma en un entero. atoi transforma un array de strings a entero.
		// La funci�n atoi convierte un array de caracteres (una cadena, un string), en un n�mero entero.
		// Si ingresas el texto "10", te lo convierte en el entero 10.
	}
	return retorno;
}

// Como esta funci�n, haremos muchas del tipo esUnNickName, esDNI, etc...
// Verifica que en la cadena haya n�meros.
// Este tipo de funci�n devuelve verdadero (1) o falso (0).
static int esNumerica(char* cadena) // Determina si una cadena de texto contiene solamente n�meros.
{
	int retorno = 1; // Inicializo el retorno en 1, VERDADERO.
	int i = 0;

	// CASO PARTICULAR:
	// Si estoy en la primer posici�n del array, es v�lido tener un n�mero negativo, pero SOLO en la primera, por eso hago el if a continuaci�n:

	if(cadena[0] == '-') // Si cadena en la posici�n 0 es igual a un negativo...
	{
		i = 1; // ...haremos que la cuenta arranque a partir de uno.
	}
	// Tengo que iterar hasta el \0.
	for( ; cadena[i] != '\0' ; i++) // Mientras que cadena en posici�n i sea distinto a \0, que siga iterando e incrementando la i.
	{ // Si es distinto a \0, entro al for.
		if(cadena[i] > '9' || cadena[i] < 0) // Si cadena en la posici�n i, estoy en ERROR. Si lo que encontr� en la cadena es m�s grande que 9, rompo, si lo que encontr� es m�s chico que 0, rompo.
		{
			retorno = 0; // Coloco el retorno en 0, o sea FALSO.
			break; // Y hago un break.
		}
	}
	return retorno;
}

// stdin es un archivo y nosotros vamos a leer el flujo de informaci�n que pasa por ese archivo.
// fgets leemos el string de un archivo.
// Le paso la cadena dnode quiero dejar la info
// cuantos caracteres quiero leer de ese archivo
// puntero al archivo, en este caso stdin

// Permite pasar una cadena, siempre le pasamos un string. Tiene sentido que le pasemos una longitud.
static int myGets(char* cadena, int longitud)
{
	fflush(stdin); // Sino no funciona, no s� por qu�.
	// fgets nos permite leer de un archivo una cadena de caracteres.
	// Leo del stdin una cadena de caracteres.
	// Como primer par�metro quiere saber d�nde dejar la informaci�n, como segundo par�metro quiere la longitud, y como tercero quiere saber de d�nde leer, en este caso stdin.
	fgets(cadena, longitud, stdin);
	// Preguntamos cu�nto mide la cadena, y en la posici�n anterior a la �ltima ponemos el \0 y pisamos el ENTER.
	// As� logramos que la funci�n se comporte como hac�a el scanf.
	cadena[strlen(cadena)-1] = '\0';
	// strncpy guarda el destino, el origen y el tama�o que no puedo desbordar.
	// strncpy(cadena, buffer, longitud);
	return 0;
}

int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar; // Variable de intercambio con el usuario, donde leer� y guardar� el dato que el usuario ingresa.

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do // Me asegura que la primera vez se va a cumplir aunque reintentos venga cargado en 0.
		{
			printf("%s", mensaje); // Recibo un dato string, el mensaje del usuario.
			fflush(stdin); // __fpurge(stdin); en Linux. Esto va siempre antes de la lectura del scanf.
			scanf("%c", &bufferChar); // Leo lo que recibo del usuario, y lo asigno a la direcci�n de memoria de bufferInt.
			if(bufferChar >= minimo && bufferChar <= maximo) // Si lo que hay dentro de bufferInt es mayor/igual al m�nimo, y menor/igual al m�ximo...
			{
				retorno = 0; // Sali� todo bien, por eso el retorno devuelve 0.
				*pResultado = bufferChar; // Le asigno al puntero, lo que hay en bufferInt.
				break; // Esto har�a que deje de reintentar con la segunda forma.
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--; // Si viene en 1, lo decremento y ser�a mayor o igual a 0.
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
	if(pResultado != NULL) // Primero chequea que el puntero sea v�lido y no apunte a NULL, que no tenga direcci�n de memoria inv�lida, en ese caso no puedo hacer nada.
	{
		if(n1 == n2) // Primero compara si son iguales.
		{
			retorno = 0; // Si son iguales, retorna 0.
		}
		else // En el caso de que no sean iguales...
		{
			if(n1>n2) // Si el n�mero 1 es mayor...
			{
				*pResultado = n1; // ...entra ac�.
			}
			else // Si el mayor es el n�mero 2...
			{
				*pResultado = n2; // ...entra ac�.
			}
			retorno = 1; // En este caso, la variable de retorno es 1 porque as� lo pide la consigna.
		}
	}
	return retorno;
}

int calcularMaximo(/* Modo profesional: int *pArray */int pArray [], int cantidadElementos, int *pResultado)
{
	int retorno = -1; // Siempre primero hacer el retorno
	int maximo;
	// Luego, verificar qu� es lo que recibimos
	if(pArray != NULL && cantidadElementos > 0 && pResultado != NULL)
	{
		// Ac� escribir lo que haga falta para imprimir por pantalla cual es el m�ximo. Hacer la funci�n del maximo.
		for(int i = 0; i < cantidadElementos; i++) // Mientras que, estando en la posici�n
		{
			// Preguntarme ante qu� condiciones se encontr� el nuevo m�ximo
			if(i == 0 || pArray[i] > maximo) // Si en la posici�n del array i hay un n�mero que es m�s grande que el m�ximo, y la variable i es igual a 0...
			{
				maximo = pArray[i]; // ...en m�ximo guardo lo que tiene el array en esa posici�n.
			}
		}
		*pResultado = maximo;
		retorno = 0; // Est� todo OK
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
