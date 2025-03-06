/*
TITLE: PROGRAMMING II LABS                   SUBTITLE: P1

AUTHOR 1: Ali Abu-afash Nayef  LOGIN 1: ali.nayef@udc.es

AUTHOR 2: Pedro Rodríguez Raposo  LOGIN 2: pedro.rodriguez.raposo@udc.es

GROUP: 1.2                                                        DATE: 05/03/2025
*/

#include "dynamic_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void createEmptyList(tListL *l) {
    *l = LNULL;
};

bool isEmptyList(tListL l) {
return l == LNULL;
};

tPosL first(tListL l)
{
    return l; //l es el primer elemento
};

tPosL last(tListL l) {
    tPosL p;
    if (l == LNULL) {
        return LNULL;
    }

    //Recorrer la lista hasta la última posición
    for (p = l; p->next != LNULL; p = p->next) { //siendo p la pos del primer elemento, y p además no es el último, comprobar el siguiente.
        //únicamente para iterar hasta el final de la lista
    }
    return p;
};

tPosL next(tPosL p, tListL l) {
    return p->next;
};


tPosL previous(tPosL p, tListL l){
    tPosL q;
    if (p == l) { //si p es el primero no hay anterior
        return LNULL;
    } else {
        for (q = l;  q != LNULL && q->next != p; q = q->next);  //siendo q pos del primer elemento no nulo y que su siguiente no sea la posición p pedida, q es la siguiente posición.
         return q;
    }
};


bool insertItem(tItemL d, tPosL p, tListL *l)
{
    tPosL nuevoNodo, q;

    if (!createNode(&nuevoNodo)) {
        return false;
    }

    //Añadimos la información al nodo
    nuevoNodo->data = d;

    // Insertar elemento en lista vacía o al principio
    if (*l == LNULL || p == LNULL) {
        nuevoNodo->next = *l;
        *l = nuevoNodo;
    }

    // Cuando se inserte en el medio o al final
    else {
        nuevoNodo->next = p->next;
        p->next = nuevoNodo;
    }

    return true;
};


void deleteAtPosition(tPosL p, tListL *l) {

tPosL q;
 if(p == *l) { // Se elimina el primer elemento de la lista
   *l = (*l)->next;
 }  else if (p->next == LNULL) { // Se elimina el elemento de la última posición
     for(q = *l; q-> next-> next != LNULL; q = q->next);
     q->next = LNULL;
 } else {
   q = p->next;
   p->data = q->data;
   p->next = q->next;
   p = q;
 }
 free(p);

};


tItemL getItem(tPosL p, tListL l) {
 return p -> data;
} ;
void updateItem(tItemL d, tPosL p, tListL *l) {
  p->data = d;
};

bool createNode(tPosL *p) {
    *p = malloc(sizeof(tNode));
    return *p != LNULL;
};

tPosL findItem(tItemL d, tListL l) {
    tPosL p;

    for (p = l; p != LNULL; p = p->next) {
        //Compara las strings de las IDconsola y si coinciden retorna la posición.
        if (strcmp(p->data.consoleId, d.consoleId) == 0) {
            return p;
        }
    }

    return LNULL;
}