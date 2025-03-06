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

void createEmptyList(tList *l) {
   l -> lastPosition= LNULL;
}


bool isEmptyList(tList l) {
    return l.lastPosition == LNULL; //retorna verdadero si la posición de la lista está vacía.
}


tPosL first(tList l) {
    if (isEmptyList(l)) {
        return LNULL; //si está vacía no devolvemos nada.
    }
    return 0; //solo funciona en listas estáticas, ya que siempre pos 0 será la primera.
}


tPosL last(tList l) {
    return l.lastPosition; //recogemos la última posición
}


tPosL next(tPosL p, tList l) {
 if(p ==  l.lastPosition) {
 return LNULL; //en el caso de que la posición indicada sea la última de la lista
 } else {
 return ++p;
 }
}


tPosL previous(tPosL p, tList l) {
   if(p == 0) {
   return LNULL; //en el caso de que se introudzca el primer elemento de la lista
   } else {
    return --p;
    }
}


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


void deleteAtPosition(tPosL p, tList *l) {
    //según la posición a eliminar, la detectamos y sustituimos su contenido por el de la posición siguiente,
    //haciendo esta acción sucesivamente hasta el final de la lista
    for (tPosL i = p; i < l -> lastPosition; i++) {
        l -> data[i] = l -> data[i + 1];
    }
    l -> lastPosition--; //reducimos en uno el tamaño de la lista
}


tItemL getItem(tPosL p, tList l) {
   return l.data[p]; //según la posición indicada retorna el contenido de dicha posición en la lista
}


void updateItem(tItemL d, tPosL p, tList *l) {
    l ->data[p] = d; //cambia el contenido del elemento de la posición indicada a el indicado d
}


tPosL findItem(tConsoleId consoleId, tList l) {
    if (isEmptyList(l))
        return LNULL;

    for (tPosL p = 0; p <= l.lastPosition; p++) {
        if (strcmp(l.data[p].consoleId, consoleId) == 0)
            return p;
    }
    return LNULL;
}

