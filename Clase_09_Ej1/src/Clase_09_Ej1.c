/*
 ============================================================================
Estructuras

Pedirle al usuario los datos de 3 alumnos e imprimir esos datos por pantalla

alta de alumnos
dar de alta alumnos, en la pos 4 cargame este, 8 este, etc
que todo el tiempo me de la opcion de cargar o imprimir

en 2 funciones separadas

funcion cargar
funcion imprimir

getNombre para obtener nombre
getNumero para obtener numero
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"

#define LONG_NOMBRE 50
#define LIMITE_BUFFER_STRING 1000

// La estructura debe llevar un nombre
typedef struct
{
	char nombre[LONG_NOMBRE];
	int legajo;
}Alumno;

int main(void)
{
	setbuf(stdout,NULL);

	Alumno arrayAlumnos[5];
	int opcionesMenu;
	int i;
	char nombre;

	do
	{
		printf("Men� de opciones\n", "1 - Imprimir datos\n", "2 - Cargar datos\n", "3 - Salir\n");

		if(utn_getNumero(&opcionesMenu, "Ingrese la opci�n deseada: ", "ERROR. Elija una opci�n entre 1 y 3", 1, 3, 2)==0)
		{
			switch(opcionesMenu)
			{
				case 1: // Imprimir datos

				break;
				case 2: // Cargar el array

			}
		}
		else
		{
			printf("No te quedan m�s intentos.");
		}
	}
	while(opcionesMenu != 3);


	return EXIT_SUCCESS;
}

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
