/*
 ============================================================================
Bibliotecas:

Funci�n:
Retorna 1 si el sexo es correcto 'f' o 'm'

int validarSexo(char sexoParametro)
en la biblioteca "validacion.h", hacer el ".c"

Funci�n:
Retorna un sexo v�lido ('f' o 'm'), pide el dato por "scanf" y lo valida usando la funci�n "validarSexo"

char pedirSexo()
en la bilioteca "funciones.h", hacer el ".c"

#Llamar a la funci�n en el Main y mostrar el sexo ingresado
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "sabado.h" // Incluye la biblioteca

int main(void) {

	setbuf(stdout,NULL); // Windows

	char sexoParametro; // Declaro la variable para el par�metro del sexo como un char

		pedirSexo(&sexoParametro); // Llamo a la funci�n pedirSexo y el resultado lo asigno a la variable sexoParametro
		printf("Sexo informado: %c", sexoParametro); // A trav�s de un printf, muestro el sexo que ingres� el usuario en la variable sexoParametro

	return EXIT_SUCCESS;
}
