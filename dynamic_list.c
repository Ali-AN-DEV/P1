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
}

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
    if (p == LNULL) {
        return LNULL;
    }
    return p->next;
};


tPosL previous(tPosL p, tListL l) {
    if (p == l) { // Si p es el primero no hay anterior
        return LNULL;
    } else {
        tPosL q;
        for (q = l; q != LNULL && q->next != p; q = q->next) {
            // Iterando hasta encontrar el nodo cuyo siguiente es p
        }
        return q; // Retornamos el nodo encontrado o LNULL si no se encontró
    }
}


bool insertItem(tItemL d, tPosL p, tListL *l) {
    tPosL nuevoNodo;

    if (!createNode(&nuevoNodo)) {
        return false;
    }

    // Añadimos la información al nodo
    nuevoNodo->data = d;

    // Caso 1: Lista vacía o inserción al principio
    if (*l == LNULL || p == *l) {
        nuevoNodo->next = *l;
        *l = nuevoNodo;
    }
    // Caso 2: Inserción al final
    else if (p == LNULL) {
        tPosL ultimo = last(*l);
        ultimo->next = nuevoNodo;
        nuevoNodo->next = LNULL;
    }
    // Caso 3: Inserción en medio
    else {
        nuevoNodo->next = p->next;
        p->next = nuevoNodo;
    }

    return true;
}


void deleteAtPosition(tPosL p, tListL *l) {
    tPosL q;

    if (p == *l) { // Eliminar el primer elemento
        *l = p->next;
        free(p);
    } else { // Eliminar en medio o al final
        // Buscamos el nodo anterior a p
        q = previous(p, *l);
        q->next = p->next;
        free(p);
    }
}


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

tPosL findItem(tConsoleId id, tListL l) {
    tPosL p;

    for (p = l; p != LNULL; p = p->next) {
        // Compara las strings de las IDconsola y si coinciden retorna la posición.
        if (strcmp(p->data.consoleId, id) == 0) {
            return p;
        }
    }

    return LNULL;
}