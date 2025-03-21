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


/****
*Objetivo: Crear una lista vacía dinámica
*Entradas:
 -l: puntero a la lista a inicializar
*Salidas:
 -Lista inicializada (vacía)
*Precondiciones: La lista debe estar correctamente definida y accesible
*Poscondiciones: La lista queda inicializada como vacía (LNULL)
****/
void createEmptyList(tList *l) {
    *l = LNULL; //sec crea una lista con elementos nulos.
}


/****
*Objetivo: Determinar si la lista dinámica está vacía
*Entradas:
 -l: lista
*Salidas:
 -true si la lista está vacía, false en el caso contrario
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: No modifica la lista
****/
bool isEmptyList(tList l) {
    return l == LNULL; //retorna l en caso de que la lista esté vacía
}

/****
*Objetivo: Devolver la posición del primer elemento de la lista dinámica
*Entradas:
 -l: lista
*Salidas:
 -l (primer nodo de la lista)
 -LNULL si la lista está vacía
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: No modifica la lista
****/
tPosL first(tList l) {
    return l; //retorna el primer valor de l. Si este es nu,,lo, devuelve LNULL
}


/****
*Objetivo: Devolver la posición del último elemento de la lista dinámica
*Entradas:
 -l: lista
*Salidas:
 -Posición del último elemento de la lista
 -LNULL si la lista está vacía
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: No modifica la lista
****/
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


/****
*Objetivo: Devolver la posición siguiente a una posición dada en la lista dinámica
*Entradas:
 -p: posición en la lista
 -l: lista
*Salidas:
 -Posición siguiente a p
 -LNULL si p es la última posición o no es válida
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: No modifica la lista
****/
tPosL next(tPosL p, tList l) {
    if (p == LNULL) {
        return LNULL;//en caso de p no sea una posición válida.
    }
    return p->next; //la posición p pasa a ser la siguiente a la introducida, devuelve p.
}

/****
*Objetivo: Devolver la posición anterior a una posición dada en la lista dinámica
*Entradas:
 -p: posición en la lista
 -l: lista
*Salidas:
 -Posición anterior a p
 -LNULL si p es la primera posición o no es válida
*Precondiciones: La lista debe estar inicializada y p debe ser válida
*Poscondiciones: No modifica la lista
****/
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

//función auxiliar para el insertItem
/****
*Objetivo: Crear un nuevo nodo para la lista dinámica
*Entradas:
 -p: puntero a la posición donde se almacenará el nuevo nodo
*Salidas:
 -true si se pudo crear el nodo
 -false si no hay memoria disponible
*Precondiciones: p debe ser un puntero válido
*Poscondiciones: Si hay memoria disponible, p contiene la dirección del nuevo nodo
****/
bool createNode(tPosL *p) {
    *p = malloc(sizeof(tNode));
    return *p != LNULL;
}


/****
*Objetivo: Insertar un elemento en una posición específica de la lista dinámica
*Entradas:
 -d: item a insertar
 -p: posición donde insertar (antes de ella, LNULL para insertar al final)
 -l: puntero a la lista
*Salidas:
 -true si se insertó correctamente
 -false si no hay memoria disponible
*Precondiciones: La posición p debe ser válida en la lista o LNULL
*Poscondiciones: Si hay memoria disponible, la lista incluye el elemento en la posición indicada
****/
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

/****
*Objetivo: Eliminar el elemento de una posición específica de la lista dinámica
*Entradas:
 -p: posición del elemento a eliminar
 -l: puntero a la lista
*Salidas: No hay valor de retorno
*Precondiciones: La lista no está vacía y la posición p es válida
*Poscondiciones: El elemento en la posición p es eliminado y la memoria ocupada es liberada
****/
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

    free(p);//destruye la variable p, eliminando el elemento de su posición.
}

/****
*Objetivo: Obtener el elemento en una posición específica de la lista dinámica
*Entradas:
 -p: posición del elemento a obtener
 -l: lista
*Salidas:
 -El elemento en la posición p
*Precondiciones: La posición p debe ser válida en la lista
*Poscondiciones: No modifica la lista
****/
tItemL getItem(tPosL p, tList l) {
    return p->data;//devuelve el contenido asociado a la posición indicada.
}

/****
*Objetivo: Actualizar el elemento en una posición específica de la lista dinámica
*Entradas:
 -d: nuevo valor para el elemento
 -p: posición del elemento a actualizar
 -l: puntero a la lista
*Salidas: No hay valor de retorno
*Precondiciones: La posición p debe ser válida en la lista
*Poscondiciones: El elemento en la posición p es actualizado con el valor d
****/
void updateItem(tItemL d, tPosL p, tList *l) {
    p->data = d;//accede al contenido asociado a la posición indicada y lo cambia por d.
}

/****
*Objetivo: Buscar un elemento en la lista dinámica por su identificador de consola
*Entradas:
 -id: identificador de consola a buscar
 -l: lista
*Salidas:
 -Posición del elemento si se encuentra
 -LNULL si no se encuentra o la lista está vacía
*Precondiciones: La lista debe estar inicializada
*Poscondiciones: No modifica la lista
****/
tPosL findItem(tConsoleId id, tList l) {
    tPosL p;

    for (p = l; p != LNULL; p = p->next) {
        //Pasa por todas las posiciones de la lista desde la primera.
        //Para al encontrar una posición en la que el elemento tenga asociado un identificador
        //igual al indicado.
        if (strcmp(p->data.consoleId, id) == 0) {
            return p;
        }
    }

    return LNULL;//devuelve LNULL si pasa por toda la lista y no ha encontrado un id que se corresponda.
}