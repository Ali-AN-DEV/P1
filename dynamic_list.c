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

void createEmptyList(tList *l) {
    *l = LNULL; //sec crea una lista con elementos nulos.
}

bool isEmptyList(tList l) {
    return l == LNULL; //retorna l en caso de que la lista esté vacía
}

tPosL first(tList l) {
    return l; //retorna el primer valor de l. Si este es nu,,lo, devuelve LNULL
}

tPosL last(tList l) {
    tPosL p;

    if (isEmptyList(l)) {
        return LNULL;//si la lista esta vacía, devuelve nulo.
    }

    for (p = l; p->next != LNULL; p = p->next);
    //avanza desde la primera posición hasta llegar a una
    //cuya siguiente sea nula, y por ende sea la última.
    return p;
}

tPosL next(tPosL p, tList l) {
    if (p == LNULL) {
        return LNULL;//en caso de p no sea una posición válida.
    }
    return p->next; //la posición p pasa a ser la siguiente a la introducida, devuelve p.
}

tPosL previous(tPosL p, tList l) {
    tPosL q;

    if (p == l) {
        return LNULL;//en caso de p ya sea la primera posición y no tenga previas.
    }

    for (q = l; q != LNULL && q->next != p; q = q->next);
    //avanza desde la primera posición hasta llegar a una cuya siguiente sea p,
    //y por ende q sea la posición previa a p
    return q;
}

bool createNode(tPosL *p) {
    *p = malloc(sizeof(tNode));
    return *p != LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *l) { //cambiada, daba problemas
    tPosL q, r;

    if (!createNode(&q)) {
        return false;//devuelve false al no haberse insertado el elemento
    }

    q->data = d;
    q->next = LNULL;

    if (isEmptyList(*l)) {
        // CASO 1: Lista vacía
        *l = q;
    } else if (p == LNULL) {
        // CASO 2: Insertar al final
        r = last(*l);
        r->next = q;
    } else if (p == *l) {
        // CASO 3: Insertar al principio
        q->next = *l;
        *l = q;
    } else {
        // CASO 4: Insertar antes de una posición (dentro de la lista)
        // Intercambiamos los datos y ajustamos los punteros
        q->data = p->data;
        p->data = d;
        q->next = p->next;
        p->next = q;//se inserta en la posición posterior a p.
    }

    return true;
}

void deleteAtPosition(tPosL p, tList *l) {
    tPosL q;

    if (p == *l) {
        // Eliminar el primer elemento
        *l = p->next;
    } else {
        // Eliminar un elemento que no es el primero
        q = previous(p, *l);
        q->next = p->next;
    }

    free(p);//destruye la variable p
}

tItemL getItem(tPosL p, tList l) {
    return p->data;
}

void updateItem(tItemL d, tPosL p, tList *l) {
    p->data = d;
}

tPosL findItem(tConsoleId id, tList l) {
    tPosL p;

    for (p = l; p != LNULL; p = p->next) {
        if (strcmp(p->data.consoleId, id) == 0) {
            return p;
        }
    }

    return LNULL;
}