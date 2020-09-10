/*
 * utn.c
 *
 *  Created on: 9 sep. 2020
 *      Author: Hzkr
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// get float - int - char
int getInt(char mensaje[])
{
    int xInt;
    printf("%s", mensaje);
    scanf("%d", &xInt);

    return xInt;
}

char getChar(char mensaje[])
{
    char xChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &xChar);

    return xChar;
}

float getFloat(char mensaje[])
{
    float xFloat;
    printf("%s", mensaje);
    scanf("%f", &xFloat);

    return xFloat;
}

//calculos
float funcionSuma(float numeroUno, float numeroDos)
{
    float suma;
    suma= numeroUno+numeroDos;
    return suma;
}

float funcionResta(float numeroUno, float numeroDos)
{
    float resta;
    resta= numeroUno-numeroDos;
    return resta;
}

float funcionDividir(float numeroUno, float numeroDos)
{
    float dividir;

    if(numeroDos==0)
    {
        printf("AVISO. No se puede dividir por 0 \n");
    }
    else
    {
        dividir= numeroUno/numeroDos;
    }

    return dividir;
}

float funcionMultiplicar(float numeroUno, float numeroDos)
{
    float multiplicar;
    multiplicar= numeroUno*numeroDos;
    return multiplicar;
}

// factorizacion

int funcionFactorial(float numero)
{
    float factorial;

    if (numero==0)
    {
        factorial= 1;
    }
    else if (numero<0)
    {
        factorial= 0;
    }
    else
    {
    factorial= numero*funcionFactorial(numero-1);
    }

    return factorial;
}
