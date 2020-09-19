/*
 ============================================================================
Crear un programa que permita registrar el valor de temperatura m�xima de cada d�a de un mes.
Definir un array de floats de 31 posiciones. Cada posici�n corresponder� a un d�a del mes.
Hacer un programa con un men� de dos opciones:

1. Imprimir array.
2. Cargar array.

Al elegir la opci�n 1, se imprimir� el �ndice y el valor de cada posici�n del array.
Al elegir la opci�n 2, que le pida al usuario que ingrese un n�mero de d�a (1 al 31), y luego
que ingrese un valor de temperatura. Almacenar el valor en el �ndice correspondiente.

Ambas opciones deben volver al menu principal.

Utilizar la funci�n utn_getNumeroFloat() de la biblioteca utn.h
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define TAMA�O 31

int main(void)
{
	setbuf(stdout,NULL);
	float temperaturasDias[TAMA�O]; // Si tiene 31 posiciones, el �ndice valido es de 0 a 30.
	int opcionesMenu;
	int i;
	int dia;
	float temp;

	do
	{
		printf("Men� de opciones\n", "1 - Imprimir el array\n", "2 - Cargar el array\n", "3 - Salir\n");

		if(utn_getNumero(&opcionesMenu, "Ingrese la opci�n deseada: ", "ERROR. Elija una opci�n entre 1 y 3", 1, 3, 2)==0)
		{
			switch(opcionesMenu)
			{
				// En vez del c�digo de abajo, podr�a haber hecho una funci�n que reciba el array y lo imprima.
				case 1: // Imprimir el array
					for(i=0 ; i<TAMA�O ; i++) // For desde 0 hasta el tama�o del array (en este caso 31)
					{
						printf("Indice: %d -- Valor: %.df\n", i, temperaturasDias[i]); // Al �ndice le pasa el valor de i, y al valor le pas� el valor del array en la posici�n i
						// Si yo quisiera imprimir en vez del valor del �ndice, el valor del d�a, ser�a as�...
						// printf("D�a: %d -- Valor: %.df\n", i+1, temperaturasDias[i]);
					}
				break;
				case 2: // Cargar el array
					// Primero le pido el d�a,
					if(utn_getNumero(&dia, "Ingrese el d�a [1-31]: ", "ERROR. D�a no v�lido.", 1, 31, 2)==0) // Si el d�a que ingres� fue valido.. (porque hay un 0, recordar que si la funci�n retornaba 0 es porque obtuvo un n�mero)...
					{
						// Le pido la temperatura, y la guardo en una variable auxiliar (&temp)
						if(utn_getFloat(&temp, "Ingrese la temperatura: ", "Error, ingrese una temperatura correcta", 0, 100, 2) == 0)
						{
							// Ahora cargar la temperatura en el array, en la posici�n que corresponde.
							temperaturasDias[dia-1] = temp; // Tengo que restarle 1 para hacer la correspondencia entre d�a e �ndice.
						}
					}
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
