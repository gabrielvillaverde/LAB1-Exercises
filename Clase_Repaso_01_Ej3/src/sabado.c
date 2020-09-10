/*
 * sabado.c
 *
 *  Created on: 8 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>

int validarSexo(char* pSexoSeleccionado) // Función para VALIDAR el sexo, con un puntero que guarda lo que ingresó el usuario en la variable sexo
{
	char sexo; // Declaro la variable del tipo char para guardar el tipo de sexo (f o m)
	printf("\nIngrese su sexo: "); // Solicito al usuario que ingrese el sexo
	fflush(stdin); // Limpio el buffer
	scanf("%c", &sexo); // Por medio de un scanf, asigno lo que ingresó el usuario como un char a la dirección de memoria de la variable sexo
	while(sexo != 'f' && sexo != 'm') // Validación del sexo, mientras que sexo sea distinto de 'f' y 'm'...
	{
		printf("\nERROR: Ingrese un sexo válido f - m: "); // ...dará un mensaje de error, pidiendo que ingrese nuevamente los datos
		fflush(stdin); // Vuelvo a limpiar el buffer
		scanf("%c", &sexo); // Vuelvo a declarar el scanf, para que si esta vez ingresó bien los datos, le asigne lo que ingresó el usuario a la dirección de memoria de la variable sexo como char
	}
	*pSexoSeleccionado = sexo; // Declaro un puntero que guarde lo que el usuario ingresó en la variable sexo
	return 1;

}

char pedirSexo(char* pSexoPedido) // Función para PEDIR el sexo, con un puntero que guarda lo que ingresó el usuario en la variable sexoPedido
{
	char sexoPedido; // Declaro la variable del tipo char para guardar el sexo pedido, esta vez sé que sí o sí el usuario ingresó 'f' o 'm' por la función hecha en la línea 11
	validarSexo(&sexoPedido); // Llamo a la función validarSexo, que verifica 'f' o 'm' en la dirección de memoria de sexoPedido
	*pSexoPedido = sexoPedido; // Declaro un puntero que guarde lo que hay en sexoPedido
	return *pSexoPedido; // Retorna el puntero
}
