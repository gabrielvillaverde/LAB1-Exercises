/*
 ============================================================================
Array de ordenamiento hecho por Ernesto, es prácticamente el mismo que
el de Clase_05_Ej4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ordenar(int array[], int len)
{
	int indice;
	// 8 2 3 1 9 5 8 7
	// 2 8 3 1 9 5 8 7
	// 2 3 8 1 9 5 8 7
	// 2 3 1 8 9 5 8 7
	// 2 3 1 8 9 5 8 7
	// 2 3 1 8 5 9 8 7
	// 2 3 1 8 5 8 9 7
	// 2 3 1 8 5 8 7 9
//otra pasadita
	// 2 3 1 8 5 8 7 9
	// 2 1 3 8 5 8 7 9
	// 2 1 3 8 5 8 7 9
	// 2 1 3 5 8 8 7 9
	// 2 1 3 5 8 8 7 9
	// 2 1 3 5 8 7 8 9
	// 2 1 3 5 8 7 8 9
//otra pasadita
	// 2 1 3 5 8 7 8 9
	// 1 2 3 5 8 7 8 9
	// 1 2 3 5 8 7 8 9
	// 1 2 3 5 8 7 8 9
	// 1 2 3 5 8 7 8 9
	// 1 2 3 5 7 8 8 9
	// 1 2 3 5 7 8 8 9
	// 1 2 3 5 7 8 8 9
	//termine!

	int aux; //8
	// comparacion 1
	// 8 2 3 1 9 5 8 7
	// 2 2 3 1 9 5 8 7
	// 2 8 3 1 9 5 8 7
	// comparacion 2
	// 2 8 3 1 9 5 8 7
	// 2 3 8 1 9 5 8 7
	// len vale 8 = tamaño de array
	int flagEstadoDesordenado=1;

	while(flagEstadoDesordenado==1)// no esta ordenado
	{
		flagEstadoDesordenado=0;
		// la pasadita
		for(indice=0 ; indice<(len-1)  ; indice++)
		{
			if(array[indice] > array[indice+1])
			{
				// intercambiar (swap)
				aux = array[indice];
				array[indice] = array[indice+1];
				array[indice+1] = aux;
				flagEstadoDesordenado=1;
			}
		}
		//_____________

		// itero el array y me fijo si pos+1 > pos
		// y cambio el flag

	}
	// cuantas veces tengo que hacer esto???
	//

}
