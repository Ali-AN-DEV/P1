/*
TITLE: PROGRAMMING II LABS                   SUBTITLE: P1

AUTHOR 1: Ali Abu-afash Nayef  LOGIN 1: ali.nayef@udc.es

AUTHOR 2: Pedro Rodríguez Raposo  LOGIN 2: pedro.rodriguez.raposo@udc.es

GROUP: 1.2                                                        DATE: 20/02/2025
*/

#include <stdbool.h>
#include "static_list.h"
#include "string.h"


//Implementación de las operaciones

/****
*Objetivo: Determinar si la lista esta vacía
*Entradas:
 -l: lista
*Salidas:
 -true si la lista está vacía, false en el caso contrario
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: No modifica la lista
****/
void createEmptyList(tList *l) {
   l -> lastPosition= LNULL; //se crea una lista vacía asignando su último elemento como lnull
}

/****
*Objetivo: Determinar si la lista esta vacía
*Entradas:
 -l: lista
*Salidas:
 -true si la lista está vacía, false en el caso contrario
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: No modifica la lista
****/
bool isEmptyList(tList l) {
    return l.lastPosition == LNULL; //retorna TRUE si la lista está vacía.
}

/****
*Objetivo: Devolver la posición del primer elemento de la lista
*Entradas:
 -l: lista
*Salidas:
 -LNULL si la lista está vacía
 -posición 0 si la lista no está vacía
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: nada
****/
tPosL first(tList l) {
    if (isEmptyList(l)) {
        return LNULL; //si está vacía no devolvemos nada.
    }
    return 0; //solo funciona en listas estáticas, ya que siempre pos 0 será la primera.
}

/****
*Objetivo: Devolver la posición del último elemento de la lista.
*Entradas:
 -l: lista
*Salidas:
 -l.lastPosition (LNULL si la lista está vacía)
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: No modifica la lista
****/
tPosL last(tList l) {
    return l.lastPosition; //recogemos la última posición
}

/****
*Objetivo: Devolver la posición siguiente a una posición dada en la lista
*Entradas:
 -p: posición en la lista
 -l: lista
*Salidas:
 -LNULL si p es la última posición
 -Posición siguiente a p si no es la última
*Precondiciones: La posición p debe ser válida en la lista
*Poscondiciones: No modifica la lista
****/
tPosL next(tPosL p, tList l) {
 if(p ==  l.lastPosition) {
 return LNULL; //en el caso de que la posición indicada sea la última de la lista
 } else {
 return ++p;//le suma una posición a la indicada, devolviendo la posición siguiente
 }
}

/****
*Objetivo: Devolver la posición anterior a una posición dada en la lista
*Entradas:
 -p: posición en la lista
 -l: lista
*Salidas:
 -LNULL si p es la primera posición (0)
 -Posición anterior a p si no es la primera
*Precondiciones: La posición p debe ser válida en la lista
*Poscondiciones: No modifica la lista
****/
tPosL previous(tPosL p, tList l) {
   if(p == 0) {
   return LNULL; //en el caso de que se introudzca el primer elemento de la lista
   } else {
    return --p;//le resta una posición a la indicada, devolviendo la posición anterior
    }
}

/****
*Objetivo: Insertar un elemento en una posición específica de la lista
*Entradas:
 -d: item a insertar
 -p: posición donde insertar (LNULL para insertar al final)
 -l: puntero a la lista
*Salidas:
 -true si se insertó correctamente
 -false si la lista está llena
*Precondiciones: La posición p debe ser válida en la lista o LNULL
*Poscondiciones: Si hay espacio, la lista incluye el elemento en la posición indicada y la lastPosition aumenta en 1.
                Si la lista está llena, se mantiene sin cambios.
****/
bool insertItem(tItemL d, tPosL p, tList *l) {

    if (l -> lastPosition == MAX - 1) {
        return false;

    } else {
        l -> lastPosition++;  //aumentamos el tamaño de la lista en uno
        if (p == LNULL) { //en el caso de querer insertarlo en la última posición
            l -> data[l -> lastPosition] = d;

        } else { //caso general
            for (tPosL i = l -> lastPosition; i > p; i--) {
                l -> data[i] = l -> data[i - 1];

            }
            l -> data[p] = d;
        }
        return true;
    }
}

/****
*Objetivo: Eliminar el elemento de una posición específica de la lista
*Entradas:
 -p: posición del elemento a eliminar
 -l: puntero a la lista
*Salidas: No hay valor de retorno
*Precondiciones: La lista no está vacía y la posición p es válida
*Poscondiciones: El elemento en la posición p es eliminado, los elementos posteriores se desplazan una posición
               y lastPosition disminuye en 1
****/
void deleteAtPosition(tPosL p, tList *l) {
    //según la posición a eliminar, la detectamos y sustituimos su contenido por el de la posición siguiente,
    //haciendo esta acción sucesivamente hasta el final de la lista
    for (tPosL i = p; i < l -> lastPosition; i++) {
        l -> data[i] = l -> data[i + 1];
    }
    l -> lastPosition--; //reducimos en uno el tamaño de la lista
}

/****
*Objetivo: Obtener el elemento en una posición específica de la lista
*Entradas:
 -p: posición del elemento a obtener
 -l: lista
*Salidas:
 -El elemento en la posición p
*Precondiciones: La posición p debe ser válida en la lista
*Poscondiciones: No modifica la lista
****/
tItemL getItem(tPosL p, tList l) {
   return l.data[p]; //según la posición indicada retorna el contenido de dicha posición en la lista
}

/****
*Objetivo: Actualizar el elemento en una posición específica de la lista
*Entradas:
 -d: nuevo valor para el elemento
 -p: posición del elemento a actualizar
 -l: puntero a la lista
*Salidas: No hay valor de retorno
*Precondiciones: La posición p debe ser válida en la lista
*Poscondiciones: El elemento en la posición p es actualizado con el valor d
****/
void updateItem(tItemL d, tPosL p, tList *l) {
    l ->data[p] = d; //cambia el contenido del elemento de la posición indicada a el indicado d
}

/****
*Objetivo: Buscar un elemento en la lista por su identificador de consola
*Entradas:
 -consoleId: identificador de consola a buscar
 -l: lista
*Salidas:
 -Posición del elemento si se encuentra
 -LNULL si no se encuentra o la lista está vacía
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: No modifica la lista
****/
tPosL findItem(tConsoleId consoleId, tList l) {
    if (isEmptyList(l))
        return LNULL; //si la lista es vacía no hay nada que retornar

    for (tPosL p = 0; p <= l.lastPosition; p++) {
        if (strcmp(l.data[p].consoleId, consoleId) == 0)
            return p; //retornamos la posición del elemento el cual al comparar las strings de la información del consoleId del
                      //objeto a comparar con el comparador coincida.
    }
    return LNULL; //si en el bucle no encontramos ninguna coincidencia retornamos LNULL
}

