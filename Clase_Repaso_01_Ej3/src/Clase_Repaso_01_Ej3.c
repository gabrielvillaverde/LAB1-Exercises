/*
 ============================================================================
Bibliotecas:

Función:
Retorna 1 si el sexo es correcto 'f' o 'm'

int validarSexo(char sexoParametro)
en la biblioteca "validacion.h", hacer el ".c"

Función:
Retorna un sexo válido ('f' o 'm'), pide el dato por "scanf" y lo valida usando la función "validarSexo"

char pedirSexo()
en la bilioteca "funciones.h", hacer el ".c"

#Llamar a la función en el Main y mostrar el sexo ingresado
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "sabado.h" // Incluye la biblioteca

int main(void) {

	setbuf(stdout,NULL); // Windows

	char sexoParametro; // Declaro la variable para el parámetro del sexo como un char

		pedirSexo(&sexoParametro); // Llamo a la función pedirSexo y el resultado lo asigno a la variable sexoParametro
		printf("Sexo informado: %c", sexoParametro); // A través de un printf, muestro el sexo que ingresó el usuario en la variable sexoParametro

	return EXIT_SUCCESS;
}
