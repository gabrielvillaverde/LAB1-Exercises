/*
 ============================================================================
Crear un programa que permita registrar el valor de temperatura máxima de cada día de un mes.
Definir un array de floats de 31 posiciones. Cada posición corresponderá a un día del mes.
Hacer un programa con un menú de dos opciones:

1. Imprimir array.
2. Cargar array.

Al elegir la opción 1, se imprimirá el índice y el valor de cada posición del array.
Al elegir la opción 2, que le pida al usuario que ingrese un número de día (1 al 31), y luego
que ingrese un valor de temperatura. Almacenar el valor en el índice correspondiente.

Ambas opciones deben volver al menu principal.

Utilizar la función utn_getNumeroFloat() de la biblioteca utn.h
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define TAMANO 31

int main(void)
{
	setbuf(stdout,NULL);
	float temperaturasDias[TAMANO]; // Si tiene 31 posiciones, el índice valido es de 0 a 30.
	int opcionesMenu;
	int i;
	int dia;
	float temp;

	do
	{
		if(utn_getNumero(&opcionesMenu, "Menú de opciones\n1 - Imprimir el array\n2 - Cargar el array\n3 - Salir\n", "ERROR. Elija una opción entre 1 y 3", 1, 3, 2)==0)
		{
			switch(opcionesMenu)
			{
				// En vez del código de abajo, podría haber hecho una función que reciba el array y lo imprima.
				case 1: // Imprimir el array
					for(i=0 ; i<TAMANO ; i++) // For desde 0 hasta el tamaño del array (en este caso 31)
					{
						printf("Indice: %d -- Valor: %.2f\n", i, temperaturasDias[i]); // Al índice le pasa el valor de i, y al valor le pasó el valor del array en la posición i
						// Si yo quisiera imprimir en vez del valor del índice, el valor del día, sería así...
						// printf("Día: %d -- Valor: %.df\n", i+1, temperaturasDias[i]);
					}
				break;
				case 2: // Cargar el array
					// Primero le pido el día,
					if(utn_getNumero(&dia, "Ingrese el día [1-31]: ", "ERROR. Día no válido.", 1, 31, 2)==0) // Si el día que ingresó fue valido.. (porque hay un 0, recordar que si la función retornaba 0 es porque obtuvo un número)...
					{
						// Le pido la temperatura, y la guardo en una variable auxiliar (&temp)
						if(utn_getFloat(&temp, "Ingrese la temperatura: ", "Error, ingrese una temperatura correcta", 0, 100, 2) == 0)
						{
							// Ahora cargar la temperatura en el array, en la posición que corresponde.
							temperaturasDias[dia-1] = temp; // Tengo que restarle 1 para hacer la correspondencia entre día e índice.
						}
					}
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
