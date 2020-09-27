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
		printf("Menú de opciones\n", "1 - Imprimir datos\n", "2 - Cargar datos\n", "3 - Salir\n");

		if(utn_getNumero(&opcionesMenu, "Ingrese la opción deseada: ", "ERROR. Elija una opción entre 1 y 3", 1, 3, 2)==0)
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
			printf("No te quedan más intentos.");
		}
	}
	while(opcionesMenu != 3);


	return EXIT_SUCCESS;
}

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
