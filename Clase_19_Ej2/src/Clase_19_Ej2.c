/*
 ============================================================================
Escribir un archivo con un byte que valga 108
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct{
	char name[8];
	int edad;
}Empleado;

/*
int main(void) {

	// char variable = 108; // Con char variable puedo escribir hasta el 255, ya el 256 me tira overflow.
	// int variable = 255;
	// int numeros[5] = {255, 8, 7, 50, 78};

	Empleado emp;
	emp.edad = 9;
	sprintf(emp.name, "Flaco");

	 Devuelve un puntero al archivo, y se lo pasaremos a otras funciones que nos permitirán
	 hacer cosas con ese archivo, como leerlo, escribirlo, etcétera.


	FILE* filePuntero = fopen("archivo.sarasa", "w"); // Ruta relativa
	if(filePuntero != NULL)
	{
		// Uso funciones para leer y escribir el archivo
		// fprintf();
		// fwrite();

		fwrite();
		 * Recibe un puntero a los datos que voy a escribir en el archivo.
		 * Recibe la cantidad de bytes a leer
		 * Recibe cuántos elementos va a escribir
		 * Recibe el puntero a FILE


		//fwrite(&variable, 1, 1, filePuntero);
		//fwrite(&variable, sizeof(int), 1, filePuntero);
		//fwrite(numeros, sizeof(int), 5, filePuntero); // Explicado en hora 08:13 de la clase.
		fwrite(&emp, sizeof(Empleado), 1, filePuntero);

		// Cierro el archivo
		fclose(filePuntero); // Una vez que se cierra, no se puede hacer nada más con el archivo. Hay que volver a abrirlo.

	printf("Datos escritos:\n");
	printf("Edad: %d - Nombre: %s\n", emp.edad, emp.name);

	// Le borro los datos para probar
	emp.edad = 0;
	sprintf(emp.name, "   ");

	printf("\nDatos borrados:\n");
	printf("Edad: %d - Nombre: %s\n", emp.edad, emp.name);
	}
	return EXIT_SUCCESS;
}
*/

/*
int main(void) {

	// fwrite() y fread() trabajan con variables.
	// fprintf() y fscanf() trabajan SOLO con texto.

	Empleado emp;

	FILE* filePuntero = fopen("archivo.sarasa", "rb"); // Ruta relativa
	if(filePuntero != NULL)
	{
		// fread()
		fread(&emp, sizeof(Empleado), 1, filePuntero);

		// fscanf()

	}

	printf("Empleado:\n");
	printf("Edad: %d - Nombre: %s\n", emp.edad, emp.name);

	fclose(filePuntero);

	return EXIT_SUCCESS;
}
*/

int main(void) {

	setbuf(stdout,NULL);

	char cadena[64];
	sprintf(cadena, "Flaquito");

	printf("La cadena vale: %s\n", cadena);


	FILE* fp = fopen("prueba.txt", "w");
	/*
	if(fp != NULL)
	{
		fwrite(cadena, strlen(cadena), 1, fp); // Para usar strlen tengo que incluir "string.h"
		fclose(fp);
	}
	*/

	Empleado emp;
	emp.edad = 9;
	sprintf(emp.name, "Flaco");

	if(fp != NULL)
	{
		// printf("%s", cadena); // Imprime por consola.
		// fprintf(fp, "%s", cadena); // En vez de salir por la consola, sale por el archivo.

		printf("%s - %d\n", emp.name, emp.edad);
		fprintf(fp, "%s - %d\n", emp.name, emp.edad);

		fclose(fp);
	}


	return EXIT_SUCCESS;
}

/*
// Array de punteros para el TP 3.

Empleado* empleados[8];

new()

		for(int i = 0 ; i < 8 ; i++)
		{
			fwrite(&empleados[i], sizeof(Empleado), 1, fp);
		}

		for(int i = 0 ; i < 8 ; i++)
		{
			fread(&aux[i], sizeof(Empleado), 1, fp);
		}

		new(parametros desde auxiliar)
*/
