/*
 * sabado.c
 *
 *  Created on: 8 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>

int validarSexo(char* pSexoSeleccionado) // Funci�n para VALIDAR el sexo, con un puntero que guarda lo que ingres� el usuario en la variable sexo
{
	char sexo; // Declaro la variable del tipo char para guardar el tipo de sexo (f o m)
	printf("\nIngrese su sexo: "); // Solicito al usuario que ingrese el sexo
	fflush(stdin); // Limpio el buffer
	scanf("%c", &sexo); // Por medio de un scanf, asigno lo que ingres� el usuario como un char a la direcci�n de memoria de la variable sexo
	while(sexo != 'f' && sexo != 'm') // Validaci�n del sexo, mientras que sexo sea distinto de 'f' y 'm'...
	{
		printf("\nERROR: Ingrese un sexo v�lido f - m: "); // ...dar� un mensaje de error, pidiendo que ingrese nuevamente los datos
		fflush(stdin); // Vuelvo a limpiar el buffer
		scanf("%c", &sexo); // Vuelvo a declarar el scanf, para que si esta vez ingres� bien los datos, le asigne lo que ingres� el usuario a la direcci�n de memoria de la variable sexo como char
	}
	*pSexoSeleccionado = sexo; // Declaro un puntero que guarde lo que el usuario ingres� en la variable sexo
	return 1;

}

char pedirSexo(char* pSexoPedido) // Funci�n para PEDIR el sexo, con un puntero que guarda lo que ingres� el usuario en la variable sexoPedido
{
	char sexoPedido; // Declaro la variable del tipo char para guardar el sexo pedido, esta vez s� que s� o s� el usuario ingres� 'f' o 'm' por la funci�n hecha en la l�nea 11
	validarSexo(&sexoPedido); // Llamo a la funci�n validarSexo, que verifica 'f' o 'm' en la direcci�n de memoria de sexoPedido
	*pSexoPedido = sexoPedido; // Declaro un puntero que guarde lo que hay en sexoPedido
	return *pSexoPedido; // Retorna el puntero
}
