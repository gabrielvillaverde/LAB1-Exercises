/*
 ============================================================================
 Name        : pruebaArchivos.c
 Author      : Flaco
 Version     :
 Copyright   : GNU
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"


int parseAlumnos(char* nombreArchivo,Alumno* arrayDePunterosAlumnos[], int len)
{
	// LECTURA EN MODO TEXTO DE DATOS SEPARADOS POR COMA
	// (PARSER)
	int ret=-1;
	char b[128];
	char c[128];
	char a[128];
	int i=0;
	Alumno* pA;

	if(nombreArchivo!=NULL && arrayDePunterosAlumnos!=NULL && len>0)
	{
		FILE* fp = fopen(nombreArchivo,"r");
		if(fp!=NULL)
		{
			do
			{
				if(fscanf(fp,"%[^,],%[^,],%[^\n]\n",a,b,c)==3)
				{
					pA = alumno_newParametros(b,atof(c),atoi(a));
					if(pA!=NULL)
					{
						arrayDePunterosAlumnos[i] = pA;
						i++;
						if(i>=len)
							break; // ya llene todo el array
					}
				}
				else
					break;

			}
			while(feof(fp)==0);

			fclose(fp);

			ret=i; // retorno la cantidad de alumnos que lei
		}
	}
	return ret;
}










int main(void) {

	Alumno* arrayDePunterosAlumnos[100];
	int j;
	int cantidadLeida;

	alumno_initArray(arrayDePunterosAlumnos,100);

	cantidadLeida = parseAlumnos("archivo.txt",arrayDePunterosAlumnos, 100);

	printf("cantidad leida:%d\n",cantidadLeida);

	// Imprimir el array de alumnos
	for(j=0; j<cantidadLeida; j++)
	{
		printf("nombre:%s altura:%f\n",arrayDePunterosAlumnos[j]->nombre,arrayDePunterosAlumnos[j]->altura);
	}




	/*
	FILE* fp;
	int i;
			//"D:\\carpeta\\archivo.txt"
		  //"/home/ernesto/archivo.txt"
	fp = fopen("archivo.txt","rb");
	if(fp!=NULL)
	{
		// lo usamos
		// MODO TEXTO
		// 1 fn para leer y 1 fn para escribir
		i = 12345678756454;
		//fprintf(fp,"%d",i); // TEXTO
		//fwrite(&i,sizeof(int),1,fp); //binario




		// LECTURA BINARIA DINAMICA
		Alumno a;
		a.id=999999;
		a.altura=0.0;
		sprintf(a.nombre,"jojojo");

		int fin=1;
		do{
			fin = fread(&a,sizeof(Alumno),1,fp);
			if(fin==1)
			{
				listaAlumnos[i] = alumno_newParametros(a.nombre,a.altura,a.id);
				//listaAlumnos[i]=a;
				i++;
			}
		}
		//while(fin!=0);
		while(feof(fp)==0);


		// ESCRITURA BINARIA CON ARRAY DE PUNTEROS
		for(i=0; i<LEN; i++)
		{
			fwrite(listaAlumnos[i],sizeof(Alumno),1,fp);
		}


		// ESCRITURA MODO TEXTO
		char nombreAux[50];
		float alturaAux;
		char idAux[32];
		for(i=0; i<LEN; i++)
		{
			alumno_getIdTxt(listaAlumnos[i],idAux);
			alumno_getNombre(listaAlumnos[i],nombreAux);
			alumno_getAltura(listaAlumnos[i],&alturaAux);

			printf("%s,%s,%f\n",nombreAux,idAux,alturaAux);
			fprintf(fp,"%s,%s,%f\n",nombreAux,idAux,alturaAux);
		}

		printf("id:%d nombre:%s altura:%f\n",a.id,a.nombre,a.altura);

		// lo cerramos
		fclose(fp);
	}
	else
	{
		printf("Error abriendo archivo\n");
	}
	*/


	return EXIT_SUCCESS;
}

