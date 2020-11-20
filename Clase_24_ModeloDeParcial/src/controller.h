/*
 * controller.h
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Envio.h"
#include "LinkedList.h"

int controller_loadTexto(LinkedList* pArray, char* ruta);
int controller_printOne(void* shipping);
int controller_printList(LinkedList* pArray);



#endif /* CONTROLLER_H_ */


/***********  NOTAS  ******************/

// texto   / fprintf y fscanf
// binario/ fwrite y fread

//funcion que calcule por cada envio el costo //1 solo p Element
//ll_get
//calcularcosto
//int ll_set(LinkedList* this, int index,void* pElement)
//ll_map (paso funcion)

//punto 4
/*
int controller_nose(LinkedList* pArray)
{
	int returnAux = ERROR;
	if(pArray != NULL)
	{
	 1 - utn_getName()//ingrese zona
	{
		llclone
		llfilter // por zona compara
	}
	fopen()"w"/escribo en archivo con nombre zona ingreasa// controller guardar
	}
	return returnAux;
}*/

//"entidad zonas" //punto 5
/**
 * \brief Checks if alredy exists a rubro in the list
 * \param listRubro Rubro* Pointer to array of rubros
 * \param lenRubro int Array rubros length
 * \param rubro int rubro to check if exists
 * \return Return (-1) if Error [flag isEmpty is TRUE] - (0) if Ok
 *//*
static int rubroIsInList(Rubro* listRubro, int lenRubro, int rubro)
{
    int result = FALSE;
    int i;
    for (i = 0; i < lenRubro; i++)
    {
        if (listRubro[i].isEmpty == FALSE && listRubro[i].rubro == rubro)
        {
            result = TRUE; //alredy exists
            break;
        }
    }
    return result;
}
*/
/**
 * \brief Generates a list of rubro
 * \param listPublication Publication* Pointer to array of publications
 * \param lenPublication int Array publications length
 * \param listRubro Rubro* Pointer to array of rubros
 * \param lenRubro int Array rubros length
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *//*
int zona_generateList(Publication* listPublication[], int lenPublication,Rubro *listRubro, int lenRubro)
{
    int result = ERROR;
    int i;
    int indexRubro = 0;
    int bufferRubro;
    if (listRubro != NULL && lenRubro > 0 && listPublication != NULL && lenPublication > 0 && rubro_init(listRubro, lenRubro) == SUCCESS)
    {
        for (i = 0; i < lenPublication; i++)
        {
            publi_getRubro(listPublication[i],&bufferRubro);
            if (listPublication[i] != NULL && rubroIsInList(listRubro, lenRubro, bufferRubro) == FALSE)
            {
                listRubro[indexRubro].rubro = listPublication[i]->rubro;
                listRubro[indexRubro].isEmpty = FALSE;
                indexRubro++;
            }
        }
        result = SUCCESS;
    }
    return result;
}*/
