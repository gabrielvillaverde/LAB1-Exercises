/*
 ============================================================================
Cadenas de caracteres

Un string en C es un array de caracteres.
\0 = Indica que un texto termin�.
Si quiero un texto de 10 letras, tengo que hacer un array de 11.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para trabajar con strings en el array.

int main(void) {

	setbuf(stdout,NULL);
	int auxInt;
	// char nombre[11]= "ZZZZZZZZZZZ"; // Este array es capaz de guardar 10 caracteres como m�ximo. La posici�n 11 est� reservada para el \0.
	// char apellido[11]="PEREZ";
	// char auxiliar[30]="";
	// char buffer[256];
	// int i;

	// Para copiar lo que hay dentro del array, tengo que utilizar al funci�n: strcpy (string copy), aunque es considerada insegura.

	// Abajo se indica c�mo copiar dentro de la variable nombre el string "JUAN".
	// NO VA: strcpy(nombre,"JUAN"); // Esta funci�n recibe dos par�metros, el destino y el origen.
	// NO VA: strcpy(auxiliar,nombre);

	// Como �ltimo par�metro se le puede poner un l�mite de hasta d�nde copiar.

	// strncpy es mucho m�s seguro que strcpy, se usar� esta.
	// strncpy(auxiliar, nombre, sizeof(auxiliar)); // Sizeof me dice cu�nto mide auxiliar.
	// La funci�n strncpy me permite copiar un string en otro, en este caso, nombre en auxiliar.

	// strnlen la utilizar� para saber si lo que el usuario ingresa EXCEDE lo que le pedimos.

	// Concatenar texto: strncat
	// strncat(nombre, "LALA", sizeof(nombre)); // Estoy logrando que a nombre, que ya val�a Juan, le agrego LALALA. Y para no pasarme le paso el sizeof.

	// Es como printf pero puede guardar dentro de un array de caracteres.
	// Debemos pasarle como primer par�metro un array.
	// sprintf(auxiliar, "MI SIZE OF ES %d", sizeof(auxiliar));

	// printf("%s", auxiliar);

	// printf("\nSIZE Nombre mide %d y auxiliar mide %d",sizeof(nombre),sizeof(auxiliar));

	while(1) // Me va a pedir n�meros hasta el infinito, solo para probar el programa.
	{
		// Si esta funci�n me devolvi� 0, est� todo bien y hago un printf.
		if(utn_getNumero(&auxInt,"NUMERO?\n","ERROR\n",-2,2,2) == 0)
		{
			printf("El n�mero es %d", auxInt);
		}
	}
	return EXIT_SUCCESS;
}
