/******************************************************************************
Pedirle al usuario los datos de 3 alumnos e imprimir esos datos por pantalla

Dar de alta alumnos

Dos funciones separadas:

Función de cargar
Función de imprimir

getNombre para obtener nombre
getNumero para obtener número

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define LONG_NOMBRE 50

// Defino la estructura Alumno, que guarda dos tipos de variables, char e int
typedef struct{
	char nombre[LONG_NOMBRE];
	int legajo;
}Alumno;

// Prototipos de mis funciones:
int cargarAlumno(Alumno* pArray,int lenArray,int indice);
void imprimirAlumno(Alumno* pArray,int lenArray);

int main(void){
	setbuf(stdout,NULL);
	Alumno arrayAlumnos[5]; // Declaro un array de Alumnos del tipo Alumno (cada elemento va a tener un nombre y un legajo)
	int i = 0;
	int opcion;
	do{
		printf("MENU:\n\n"
				"1-Cargar Alumnos.\n"
				"2-Imprimir Alumnos.\n"
				"3-Salir\n");
		if(!utn_getNumero(&opcion,"\nElija una opcion(1-3): ","\nOpcion inválida!\n",1,3,5)){
			switch(opcion){
			case 1:
				if(i != 5){
					if(!cargarAlumno(arrayAlumnos,5,i)){
						i++;
					}else{
						printf("\nHubo un error al cargar los alumnos!\n");
					}
				}else{
					printf("\nYa no se puede cargar mas!\n");
				}
				break;
			case 2:
				imprimirAlumno(arrayAlumnos,5);
				break;
			}
		}else{
			printf("\nSe agoto el numero de reintentos.Saliendo del programa\n");
			break;
		}
	}while(opcion != 3);

	return EXIT_SUCCESS;
}

int cargarAlumno(Alumno* pArray,int lenArray,int indice){
	int retorno = -1;
	Alumno auxAlumno;
	if(pArray != NULL && lenArray > 0){
		if(!utn_getNombre(auxAlumno.nombre,"\nIngrese nombre del alumno: ","\nNombre invalido!\n",3,50)){
			if(!utn_getNumero(&auxAlumno.legajo,"\nIngrese N° de Legajo(1-100):","\nLegajo invalido!\n",1,100,3)){
				pArray[indice] = auxAlumno;
				retorno = 0;
			}else{
				printf("\nSe acabaron los reintentos para ingresar el legajo\n");
			}
		}else{
			printf("\nSe acabaron los reintentos para ingresar el nombre\n");
		}
	}
	return retorno;
}

void imprimirAlumno(Alumno* pArray,int lenArray){
	int i;
	if(pArray != NULL && lenArray > 0){
		for(i=0;i<lenArray;i++){
			printf("INDICE: %d    -    N°LEGAJO: %d   -   Nombre: %s   \n",i,pArray[i].legajo,pArray[i].nombre);
		}
	}
}
