/*
 ============================================================================
 Name        : TP1_Prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "utn.h"

int main()
{
	setbuf(stdout,NULL);
    char opcion;
    float numeroUno=0;
    float numeroDos=0;

    int estadoNumeroUno= 0;
    int estadoNumeroDos= 0;

    float suma= 0;
    float resta= 0;
    float division= 0;
    float multiplicacion= 0;
    float factorialUno=0;
    float factorialDos=0;

    do
    {
        printf("(1)Ingresar el primer numero \n");
        printf("(2)Ingresar el segundo numero \n");
        printf("(3)Calcular todas las operaciones \n");
        printf("(4)Informar resultados \n");
        printf("(5)Salir \n");

        printf("\nEl primer numero es: %f \n", numeroUno);
        printf("El segundo numero es: %f \n", numeroDos);

        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5')
            {
                printf("Opcion incorrecta.\n\n");
                printf("Elija una opcion: ");
                fflush(stdin);
                scanf("%c", &opcion);
            }


        switch(opcion)
        {
        case '1':
            numeroUno= getFloat("Ingrese el primer numero: ");
            estadoNumeroUno= 1;
            break;

        case '2':
            numeroDos= getFloat("Ingrese el segundo numero: ");
            estadoNumeroDos= 1;
            break;

        case '3':
            if(estadoNumeroUno==1 && estadoNumeroDos==1)
            {
                suma= funcionSuma(numeroUno, numeroDos);
                resta= funcionResta(numeroUno, numeroDos);
                division= funcionDividir(numeroUno, numeroDos);
                multiplicacion= funcionMultiplicar(numeroUno, numeroDos);
                factorialUno= funcionFactorial(numeroUno);
                factorialDos= funcionFactorial(numeroDos);


                if (numeroUno<0)
                {
                    printf("AVISO: No se puede realizar el factorial de un numero negativo. \n");
                }

                if (numeroDos<0)
                {
                    printf("AVISO: No se puede realizar el factorial de un numero negativo. \n");
                }

                printf("\nSe han realizado todos los calculos.\n\n");

            }
            else
            {
                printf("AVISO: No se ha ingresado numeros. \n");
            }


            break;

        case '4':
            printf("\nLa suma es: %.2f \n", suma);
            printf("La resta es: %.2f \n", resta);
            printf("La division es: %.2f \n", division);
            printf("La multiplicacion es: %.2f \n", multiplicacion);
            printf("El factorial del primer numero es: %.2f \n", factorialUno);
            printf("El factorial del segundo numero es: %.2f \n", factorialDos);

            printf("\n\tLos numeros han vuelto a 0\n\n");
            numeroUno = 0;
            numeroDos = 0;
            suma= 0;
            resta= 0;
            division= 0;
            multiplicacion= 0;
            factorialUno=0;
            factorialDos=0;

            break;

        case '5':
            opcion='5';
            printf("Saliendo... \n");
            break;

        default:
            printf("Error. La opcion es invalida. \n");
            break;
        }//end switch

        system("pause");
        system("cls");

    } while(opcion!='5');

    return 0;
}//end main
