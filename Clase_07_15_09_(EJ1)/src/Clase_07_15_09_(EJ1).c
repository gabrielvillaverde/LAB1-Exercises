/*
 ============================================================================
 Pide un nombre
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h> // Para trabajar siempre con string.
#include "utn.h"

#define LONG_NOMBRE 50

int main(void)
{
	setbuf(stdout,NULL);
	char nombre[LONG_NOMBRE];

	// El límite es siempre la longitud total -1.
	if(utn_getNombre(nombre,"\nNombre?","\nError",2,LONG_NOMBRE-1) == 0) // Si me devuelve 0, está todo bien.
	{
		printf("%s",nombre);
	}
	else
	{
		printf("\nTODO MAL");
	}

	return EXIT_SUCCESS;
}

/*
int main(void)
{
	// Si quiero un nombre de 49 caracteres, pongo 50 porque la última está destinada para el \0.
	char nombre[5] = "BAAAA";
	char nombre2[6] = "AAAA";
	int resultadoCmp;

	// Primer parámetro es el destino, el segundo es el origen, y el último es un parámetro adicional que es el límite
	strncpy(nombre,nombre2,4); // En este caso, el límite es 4 (creo que podría usarse también el sizeof()-1.
	printf("%s",nombre);

	// strncmp es string compare (CREO).
	// strncmp devuelve números negativos, positivos, y 0. Pero hace algo más importante que no escuché, compara?

	// ASI SE COMPARAN CADENAS DE CARACTERES:
	resultadoCmp = strncmp(nombre,nombre2,LONG_NOMBRE-1);
	if(resultadoCmp==0)
	{
		printf("Son iguales");
	}
	else if(resultadoCmp > 0)
	{
		printf("Nombre es más grande");
	}
	else if(resultadoCmp < 0)
	{
		printf("El segundo nombre es más grande");
	}

	// SIZEOF: Me dice cuánto ocupa en memoria.

	// PROHIBIDO USAR LIBRERIAS DE STRING.H QUE NO TENGAN LIMITE, SIEMPRE CON LIMITE.

	// Función que determina cuántos caracteres tiene una cadena:
	// Me dice cuántos caracteres tiene la variable nombre.
	strnlen(nombre,LONG_NOMBRE-1); // LONG_NOMBRE -1 es la longitud total que le permite a la variable nombre, -1 porque el último espacio está destinado al \0.

	// Hace un printf adentro de una variable, con esto podemos armar el string que se nos ocurra y guardarlo en una variable string.
	sprintf(nombre,"%f hola %d - %s",2.22,10,"HOLA");
	// "2.22 hola 10 - HOLA"
	// Ahora la variable nombre tiene todo lo que está a su derecha.

	// Ejemplo de snprintf:
	snprintf(nombreApellido,"%s,%s",nombre,apellido);
	snprintf(nombre,LONG_NOMBRE-1,"\n%s,%s","Pepe","Sanchez");
	printf("%s",nombre);
	return EXIT_SUCCESS;
}
 *
 */
